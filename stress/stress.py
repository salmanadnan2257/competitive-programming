#!/usr/bin/env python3
"""Stress-test the range-query solutions against brute force.

Each problem below is a CSES "Range Queries" task. For each one: a generator that
writes a random small input, and a brute-force answer written the slow, obvious way
(loop over the range). The compiled solution and the brute force must agree on every
case, compared token by token so trailing spaces and newlines do not matter.

    python3 stress/stress.py                 # every problem, 500 cases each
    python3 stress/stress.py --cases 2000 --only hotel-queries
    CXX=clang++ python3 stress/stress.py     # any compiler that takes g++ flags

The seed is fixed, so a failure reproduces exactly; the failing input is printed.
"""

import argparse
import os
import random
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "solutions" / "practice" / "range-queries"


def arr(rng, n, lo=1, hi=10**9):
    # mostly small values so collisions and ties happen, sometimes huge ones so a
    # 32-bit overflow would show
    if rng.random() < 0.5:
        hi = 10
    return [rng.randint(lo, hi) for _ in range(n)]


def rng_range(rng, n):
    a = rng.randint(1, n)
    b = rng.randint(1, n)
    return min(a, b), max(a, b)


# ---- 1. Dynamic Range Sum Queries: "1 k u" sets, "2 a b" sums ----
def gen_sum(rng):
    n, q = rng.randint(1, 12), rng.randint(1, 15)
    lines = [f"{n} {q}", " ".join(map(str, arr(rng, n)))]
    for _ in range(q):
        if rng.random() < 0.5:
            lines.append(f"1 {rng.randint(1, n)} {rng.choice(arr(rng, 1))}")
        else:
            lines.append("2 %d %d" % rng_range(rng, n))
    return "\n".join(lines) + "\n"


def brute_sum(inp, agg=sum):
    t = inp.split()
    n, q = int(t[0]), int(t[1])
    a = list(map(int, t[2:2 + n]))
    p, out = 2 + n, []
    for _ in range(q):
        typ, x, y = int(t[p]), int(t[p + 1]), int(t[p + 2])
        p += 3
        if typ == 1:
            a[x - 1] = y
        else:
            out.append(agg(a[x - 1:y]))
    return out


# ---- 2. Dynamic Range Minimum Queries: same shape, min instead of sum ----
def brute_min(inp):
    return brute_sum(inp, agg=min)


# ---- 3. Range Xor Queries: static array, "a b" ----
def gen_xor(rng):
    n, q = rng.randint(1, 12), rng.randint(1, 15)
    lines = [f"{n} {q}", " ".join(map(str, arr(rng, n)))]
    lines += ["%d %d" % rng_range(rng, n) for _ in range(q)]
    return "\n".join(lines) + "\n"


def brute_xor(inp):
    t = list(map(int, inp.split()))
    n, q = t[0], t[1]
    a, out = t[2:2 + n], []
    for i in range(q):
        x, y = t[2 + n + 2 * i], t[3 + n + 2 * i]
        v = 0
        for e in a[x - 1:y]:
            v ^= e
        out.append(v)
    return out


# ---- 4. Range Update Queries: "1 a b u" adds u on [a, b], "2 k" reads one ----
def gen_rangeadd(rng):
    n, q = rng.randint(1, 12), rng.randint(1, 15)
    lines = [f"{n} {q}", " ".join(map(str, arr(rng, n)))]
    for _ in range(q):
        if rng.random() < 0.5:
            a, b = rng_range(rng, n)
            lines.append(f"1 {a} {b} {rng.choice(arr(rng, 1))}")
        else:
            lines.append(f"2 {rng.randint(1, n)}")
    return "\n".join(lines) + "\n"


def brute_rangeadd(inp):
    t = list(map(int, inp.split()))
    n, q = t[0], t[1]
    a, p, out = t[2:2 + n], 2 + n, []
    for _ in range(q):
        if t[p] == 1:
            for i in range(t[p + 1] - 1, t[p + 2]):
                a[i] += t[p + 3]
            p += 4
        else:
            out.append(a[t[p + 1] - 1])
            p += 2
    return out


# ---- 5. Forest Queries: n x n grid of '.' and '*', count trees in a rectangle ----
def gen_forest(rng):
    n, q = rng.randint(1, 8), rng.randint(1, 15)
    lines = [f"{n} {q}"]
    lines += ["".join(rng.choice(".*") for _ in range(n)) for _ in range(n)]
    for _ in range(q):
        y1, y2 = rng_range(rng, n)
        x1, x2 = rng_range(rng, n)
        lines.append(f"{y1} {x1} {y2} {x2}")
    return "\n".join(lines) + "\n"


def brute_forest(inp):
    t = inp.split()
    n, q = int(t[0]), int(t[1])
    g = t[2:2 + n]
    out = []
    for i in range(q):
        y1, x1, y2, x2 = map(int, t[2 + n + 4 * i: 6 + n + 4 * i])
        out.append(sum(g[y][x] == "*" for y in range(y1 - 1, y2) for x in range(x1 - 1, x2)))
    return out


# ---- 6. Hotel Queries: each group takes the first hotel with enough rooms ----
def gen_hotel(rng):
    n, m = rng.randint(1, 12), rng.randint(1, 15)
    return f"{n} {m}\n{' '.join(map(str, arr(rng, n)))}\n{' '.join(map(str, arr(rng, m)))}\n"


def brute_hotel(inp):
    t = list(map(int, inp.split()))
    n, m = t[0], t[1]
    h, out = t[2:2 + n], []
    for r in t[2 + n:2 + n + m]:
        for i, rooms in enumerate(h):
            if rooms >= r:
                h[i] -= r
                out.append(i + 1)
                break
        else:
            out.append(0)
    return out


# ---- 7. Range Updates and Sums: "1 a b x" adds, "2 a b x" sets, "3 a b" sums ----
def gen_addset(rng):
    n, q = rng.randint(1, 12), rng.randint(1, 20)
    lines = [f"{n} {q}", " ".join(map(str, arr(rng, n)))]
    for _ in range(q):
        typ = rng.randint(1, 3)
        a, b = rng_range(rng, n)
        lines.append(f"{typ} {a} {b}" + (f" {rng.choice(arr(rng, 1))}" if typ < 3 else ""))
    return "\n".join(lines) + "\n"


def brute_addset(inp):
    t = list(map(int, inp.split()))
    n, q = t[0], t[1]
    a, p, out = t[2:2 + n], 2 + n, []
    for _ in range(q):
        typ, x, y = t[p], t[p + 1], t[p + 2]
        if typ == 3:
            out.append(sum(a[x - 1:y]))
            p += 3
            continue
        v = t[p + 3]
        p += 4
        for i in range(x - 1, y):
            a[i] = a[i] + v if typ == 1 else v
    return out


# ---- 8. Polynomial Queries: "1 a b" adds 1, 2, 3, ... across [a, b] ----
def gen_poly(rng):
    n, q = rng.randint(1, 12), rng.randint(1, 15)
    lines = [f"{n} {q}", " ".join(map(str, arr(rng, n)))]
    for _ in range(q):
        lines.append("%d %d %d" % ((rng.randint(1, 2),) + rng_range(rng, n)))
    return "\n".join(lines) + "\n"


def brute_poly(inp):
    t = list(map(int, inp.split()))
    n, q = t[0], t[1]
    a, out = t[2:2 + n], []
    for i in range(q):
        typ, x, y = t[2 + n + 3 * i: 5 + n + 3 * i]
        if typ == 1:
            for k in range(x - 1, y):
                a[k] += k - (x - 1) + 1
        else:
            out.append(sum(a[x - 1:y]))
    return out


PROBLEMS = {
    "dynamic-range-sum-queries": ("problem-1-dynamic-range-sum-queries.cpp", gen_sum, brute_sum),
    "dynamic-range-minimum-queries": ("problem-2-dynamic-range-minimum-queries.cpp", gen_sum, brute_min),
    "range-xor-queries": ("problem-3-range-xor-queries.cpp", gen_xor, brute_xor),
    "range-update-queries": ("problem-4-range-update-queries.cpp", gen_rangeadd, brute_rangeadd),
    "forest-queries": ("problem-5-forest-queries.cpp", gen_forest, brute_forest),
    "hotel-queries": ("problem-6-hotel-queries.cpp", gen_hotel, brute_hotel),
    "range-updates-and-sums": ("problem-7-range-updates-and-sums.cpp", gen_addset, brute_addset),
    "polynomial-queries": ("problem-8-polynomial-queries.cpp", gen_poly, brute_poly),
}


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--cases", type=int, default=500)
    ap.add_argument("--seed", type=int, default=2025)
    ap.add_argument("--only", help="run just this problem (a key from the table)")
    args = ap.parse_args()

    cxx = os.environ.get("CXX", "g++")
    names = [args.only] if args.only else list(PROBLEMS)
    failed = 0
    with tempfile.TemporaryDirectory() as tmp:
        for name in names:
            src, gen, brute = PROBLEMS[name]
            exe = Path(tmp) / name
            subprocess.run([cxx, "-std=gnu++17", "-O2", "-o", str(exe), str(SRC / src)], check=True)
            rng = random.Random(f"{args.seed}:{name}")
            for case in range(args.cases):
                inp = gen(rng)
                got = subprocess.run([str(exe)], input=inp, capture_output=True, text=True, timeout=10).stdout.split()
                want = list(map(str, brute(inp)))
                if got != want:
                    print(f"FAIL {name} case {case}\n--- input\n{inp}--- expected\n{' '.join(want)}\n--- got\n{' '.join(got)}")
                    failed += 1
                    break
            else:
                print(f"ok   {name}: {args.cases} random cases match brute force")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
