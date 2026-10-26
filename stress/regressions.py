#!/usr/bin/env python3
"""Regression tests for the solutions that had bugs fixed on 2026-10-26.

Each fixed solution is run on random small inputs and its answer is checked
against a brute force written from the problem statement (or, where several
answers are allowed, against a checker). The template's helpers are checked
the same way.

    python3 stress/regressions.py              # 400 cases per problem
    python3 stress/regressions.py --sanitize   # also build with AddressSanitizer and UBSan
    CXX=clang++ python3 stress/regressions.py
"""
import argparse, itertools, os, random, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
R = str(ROOT / 'solutions') + '/'
ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
ap.add_argument('--sanitize', action='store_true')
ARGS = ap.parse_args()
CXX = os.environ.get('CXX', 'g++')
SAN = ['-fsanitize=address,undefined', '-fno-sanitize-recover=all', '-g'] if ARGS.sanitize else []
TMP = tempfile.mkdtemp()
rng = random.Random(20261027)
results = []


def build(src, name):
    out = os.path.join(TMP, name)
    cmd = [CXX, '-std=gnu++17', '-O2', '-o', out, src] + SAN
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        print(r.stderr[-2000:]); raise SystemExit('compile failed: ' + src)
    return out


def run(exe, inp):
    r = subprocess.run([exe], input=inp, capture_output=True, text=True, timeout=20,
                       env=dict(os.environ, ASAN_OPTIONS='detect_leaks=0'))
    if r.returncode:
        raise RuntimeError(f'exit {r.returncode}\n{r.stderr[-1500:]}\ninput:\n{inp}')
    return r.stdout


def check(name, path, gen, verify, cases=400):
    exe = build(R + path, name)
    for c in range(cases):
        inp, ctx = gen()
        try:
            out = run(exe, inp)
        except RuntimeError as e:
            results.append((name, False, f'case {c}: crashed: ' + str(e).splitlines()[0] + '\ninput:\n' + inp)); return
        try:
            ok, msg = verify(inp, ctx, out)
        except Exception as e:
            ok, msg = False, f'malformed output ({type(e).__name__})'
        if not ok:
            results.append((name, False, f'case {c}: {msg}\ninput:\n{inp}\noutput:\n{out}'))
            return
    results.append((name, True, f'{cases} cases'))


def toks(s): return s.split()

# ---------- 1. Waste Sorting: c1 c2 c3 / a1..a5 ----------
def g_waste():
    T = rng.randint(1, 5); lines = [str(T)]; ctx = []
    for _ in range(T):
        c = [rng.randint(0, 6) for _ in range(3)]; a = [rng.randint(0, 5) for _ in range(5)]
        lines += [' '.join(map(str, c)), ' '.join(map(str, a))]; ctx.append((c, a))
    return '\n'.join(lines) + '\n', ctx
def v_waste(inp, ctx, out):
    want = []
    for (c1, c2, c3), (a1, a2, a3, a4, a5) in ctx:
        ok = any(a1 + k4 <= c1 and a2 + k5 <= c2 and a3 + (a4 - k4) + (a5 - k5) <= c3
                 for k4 in range(a4 + 1) for k5 in range(a5 + 1))
        want.append('YES' if ok else 'NO')
    return [t.upper() for t in toks(out)] == want, f'want {want}'

# ---------- 3. Carousel: minimum colours and a valid colouring ----------
def g_car():
    T = rng.randint(1, 4); lines = [str(T)]; ctx = []
    for _ in range(T):
        n = rng.randint(3, 8); t = [rng.randint(1, 3) for _ in range(n)]
        lines += [str(n), ' '.join(map(str, t))]; ctx.append(t)
    return '\n'.join(lines) + '\n', ctx
def v_car(inp, ctx, out):
    tk = toks(out); p = 0
    for t in ctx:
        n = len(t); k = int(tk[p]); col = list(map(int, tk[p + 1:p + 1 + n])); p += 1 + n
        best = next(kk for kk in (1, 2, 3) if any(
            all(t[i] == t[(i + 1) % n] or cc[i] != cc[(i + 1) % n] for i in range(n))
            for cc in itertools.product(range(1, kk + 1), repeat=n)))
        if k != best: return False, f'k={k}, minimum is {best}'
        if any(not 1 <= x <= k for x in col): return False, 'colour out of range'
        if any(t[i] != t[(i + 1) % n] and col[i] == col[(i + 1) % n] for i in range(n)): return False, 'invalid colouring'
    return True, ''

# ---------- 4. Sum in the Tree ----------
def g_tree():
    n = rng.randint(2, 7); par = [0] + [rng.randint(1, i) for i in range(1, n)]
    a = [rng.randint(0, 3) for _ in range(n)]
    depth = [1] * n; s = [0] * n
    for v in range(n):
        if v: depth[v] = depth[par[v] - 1] + 1; s[v] = s[par[v] - 1] + a[v]
        else: s[v] = a[v]
    shown = [s[v] if depth[v] % 2 == 1 else -1 for v in range(n)]
    if rng.random() < 0.3:   # sometimes make it inconsistent
        v = rng.randrange(n); shown[v] = rng.randint(0, 6) if depth[v] % 2 else -1
    inp = f'{n}\n{" ".join(str(par[i]) for i in range(1, n))}\n{" ".join(map(str, shown))}\n'
    return inp, (n, par, shown, depth)
def v_tree(inp, ctx, out):
    n, par, shown, depth = ctx; best = None; M = max(shown + [0])
    for a in itertools.product(range(M + 1), repeat=n):
        s = [0] * n
        for v in range(n): s[v] = (s[par[v] - 1] if v else 0) + a[v]
        if all(shown[v] == -1 or shown[v] == s[v] for v in range(n)):
            best = sum(a) if best is None else min(best, sum(a))
    want = -1 if best is None else best
    return int(toks(out)[0]) == want, f'want {want}'

# ---------- 5. Yet Another Broken Keyboard ----------
def g_kb():
    n = rng.randint(1, 15); s = ''.join(rng.choice('xyz') for _ in range(n)); ks = rng.sample('xyz', rng.randint(1, 3))
    return f'{n} {len(ks)}\n{s}\n{" ".join(ks)}\n', (s, set(ks))
def v_kb(inp, ctx, out):
    s, ks = ctx; want = sum(all(ch in ks for ch in s[i:j]) for i in range(len(s)) for j in range(i + 1, len(s) + 1))
    return int(toks(out)[0]) == want, f'want {want}'

# ---------- 6. Static Range Sum Queries ----------
def g_srs():
    n, q = rng.randint(1, 10), rng.randint(1, 10); a = [rng.randint(1, 10**9) for _ in range(n)]
    qs = [sorted((rng.randint(1, n), rng.randint(1, n))) for _ in range(q)]
    return f'{n} {q}\n{" ".join(map(str, a))}\n' + ''.join(f'{x} {y}\n' for x, y in qs), (a, qs)
def v_srs(inp, ctx, out):
    a, qs = ctx; want = [str(sum(a[x - 1:y])) for x, y in qs]; return toks(out) == want, f'want {want}'

# ---------- 7. AND Reconstruction ----------
def g_and():
    T = rng.randint(1, 4); lines = [str(T)]; ctx = []
    for _ in range(T):
        n = rng.randint(2, 5); a = [rng.randint(0, 7) for _ in range(n - 1)]
        lines += [str(n), ' '.join(map(str, a))]; ctx.append(a)
    return '\n'.join(lines) + '\n', ctx
def v_and(inp, ctx, out):
    tk = toks(out); p = 0
    for a in ctx:
        n = len(a) + 1
        exists = any(all(b[i] & b[i + 1] == a[i] for i in range(n - 1)) for b in itertools.product(range(8), repeat=n))
        if tk[p] == '-1':
            if exists: return False, f'printed -1 but a solution exists for {a}'
            p += 1; continue
        b = list(map(int, tk[p:p + n])); p += n
        if not all(0 <= x < 2**30 for x in b) or any(b[i] & b[i + 1] != a[i] for i in range(n - 1)):
            return False, f'invalid b {b} for {a}'
    return p == len(tk), 'extra output'

# ---------- 8. Shohag Loves XOR (Easy) ----------
def g_sh():
    T = rng.randint(1, 5); ctx = [(rng.randint(1, 60), rng.randint(1, 200)) for _ in range(T)]
    if rng.random() < 0.2: ctx.append((rng.randint(1, 10**6), 10**18))
    return f'{len(ctx)}\n' + ''.join(f'{x} {m}\n' for x, m in ctx), ctx
def v_sh(inp, ctx, out):
    want = []
    for x, m in ctx:
        lim = min(m, 4 * x + 10)   # brute force well past the 2x cutoff the fix relies on
        cnt = sum(1 for y in range(1, lim + 1) if y != x and (x % (x ^ y) == 0 or y % (x ^ y) == 0))
        want.append(str(cnt))
    return toks(out) == want, f'want {want}'

# ---------- 9. Vlad and Division ----------
def g_vlad():
    T = rng.randint(1, 4); ctx = []
    for _ in range(T):
        n = rng.randint(1, 8); base = [rng.randint(0, 2**31 - 1) for _ in range(3)]
        a = [rng.choice(base + [2**31 - 1 - b for b in base] + [0, 2**31 - 1]) for _ in range(n)]
        ctx.append(a)
    return f'{T}\n' + ''.join(f'{len(a)}\n{" ".join(map(str, a))}\n' for a in ctx), ctx
def v_vlad(inp, ctx, out):
    want = []
    for a in ctx:   # a group holds at most two numbers, and two only if they are bitwise complements in 31 bits
        from collections import Counter
        c = Counter(a); pairs = sum(min(c[v], c[2**31 - 1 - v]) for v in c if v < 2**31 - 1 - v)
        want.append(str(len(a) - pairs))
    return toks(out) == want, f'want {want}'

# ---------- 10. Turtle and an Infinite Sequence ----------
def g_inf():
    T = rng.randint(1, 5); ctx = [(rng.randint(0, 40), rng.randint(0, 40)) for _ in range(T)]
    if rng.random() < 0.3: ctx.append((rng.randint(0, 10**9), rng.randint(0, 10**9)))
    return f'{len(ctx)}\n' + ''.join(f'{n} {m}\n' for n, m in ctx), ctx
def v_inf(inp, ctx, out):
    want = []
    for n, m in ctx:
        if n + m <= 100:   # simulate the process itself
            a = list(range(n + m + 2))
            for _ in range(m):
                a = [a[0] | a[1]] + [a[i - 1] | a[i] | a[i + 1] for i in range(1, len(a) - 1)] + [a[-1]]
            want.append(str(a[n]))
        else:              # closed form: OR of every value in [max(0, n-m), n+m]
            l, r, v = max(0, n - m), n + m, 0
            for b in range(32):
                x = l if l >> b & 1 else ((l >> b) | 1) << b
                if x <= r: v |= 1 << b
            want.append(str(v))
    return toks(out) == want, f'want {want}'

# ---------- 11. Sakurako's Field Trip ----------
def g_sak():
    T = rng.randint(1, 4); ctx = []
    for _ in range(T):
        n = rng.randint(2, 10); ctx.append([rng.randint(1, 3) for _ in range(n)])
    return f'{T}\n' + ''.join(f'{len(a)}\n{" ".join(map(str, a))}\n' for a in ctx), ctx
def v_sak(inp, ctx, out):
    want = []
    for a in ctx:
        n = len(a); best = n
        for mask in range(1 << (n // 2)):
            b = a[:]
            for i in range(n // 2):
                if mask >> i & 1: b[i], b[n - 1 - i] = b[n - 1 - i], b[i]
            best = min(best, sum(b[i] == b[i + 1] for i in range(n - 1)))
        want.append(str(best))
    return toks(out) == want, f'want {want}'

# ---------- 12. ABC 396 C: black count >= white count, maximise the sum ----------
def g_abc():
    n, m = rng.randint(1, 6), rng.randint(1, 6)
    b = [rng.randint(-10**9, 10**9) if rng.random() < 0.2 else rng.randint(-9, 9) for _ in range(n)]
    w = [rng.randint(-9, 9) for _ in range(m)]
    return f'{n} {m}\n{" ".join(map(str, b))}\n{" ".join(map(str, w))}\n', (b, w)
def v_abc(inp, ctx, out):
    b, w = ctx; best = 0
    for mb in range(1 << len(b)):
        for mw in range(1 << len(w)):
            if bin(mb).count('1') >= bin(mw).count('1'):
                best = max(best, sum(b[i] for i in range(len(b)) if mb >> i & 1) + sum(w[i] for i in range(len(w)) if mw >> i & 1))
    return int(toks(out)[0]) == best, f'want {best}'

# ---------- 13. Least Prefix Sum ----------
def g_lps():
    T = rng.randint(1, 2); ctx = []
    for _ in range(T):
        if rng.random() < 0.5:
            n = rng.randint(1, 10); m = rng.randint(1, n); a = [rng.randint(-9, 9) for _ in range(n)]
        else:   # long arrays that need many flips: positives before m, negatives after
            n = rng.randint(12, 16); m = rng.randint(4, n - 4)
            a = [rng.randint(1, 9) for _ in range(m)] + [rng.randint(-9, -1) for _ in range(n - m)]
        ctx.append((m, a))
    return f'{T}\n' + ''.join(f'{len(a)} {m}\n{" ".join(map(str, a))}\n' for m, a in ctx), ctx
def v_lps(inp, ctx, out):
    want = []
    for m, a in ctx:
        n = len(a); best = n
        for mask in range(1 << n):
            if bin(mask).count('1') >= best: continue
            b = [-x if mask >> i & 1 else x for i, x in enumerate(a)]
            p = list(itertools.accumulate(b))
            if all(p[m - 1] <= p[k] for k in range(n)): best = bin(mask).count('1')
        want.append(str(best))
    return toks(out) == want, f'want {want}'

# ---------- 14. Star Sky ----------
def g_star():
    n, q, c = rng.randint(1, 8), rng.randint(1, 8), rng.randint(1, 10)
    stars = [(rng.randint(1, 6), rng.randint(1, 6), rng.randint(0, c)) for _ in range(n)]
    qs = []
    for _ in range(q):
        x1, x2 = sorted((rng.randint(1, 6), rng.randint(1, 6))); y1, y2 = sorted((rng.randint(1, 6), rng.randint(1, 6)))
        qs.append((rng.randint(0, 10**9), x1, y1, x2, y2))
    inp = f'{n} {q} {c}\n' + ''.join(f'{x} {y} {s}\n' for x, y, s in stars) + ''.join(' '.join(map(str, t)) + '\n' for t in qs)
    return inp, (c, stars, qs)
def v_star(inp, ctx, out):
    c, stars, qs = ctx
    want = [str(sum((s + t) % (c + 1) for x, y, s in stars if x1 <= x <= x2 and y1 <= y <= y2)) for t, x1, y1, x2, y2 in qs]
    return toks(out) == want, f'want {want}'

# ---------- 16. ARC 194 A: push or pop, pop only when the stack is non-empty ----------
def g_arc():
    n = rng.randint(1, 10); a = [rng.randint(-9, 9) for _ in range(n)]
    return f'{n}\n{" ".join(map(str, a))}\n', a
def v_arc(inp, a, out):
    best = None
    for ops in itertools.product((0, 1), repeat=len(a)):
        st = []; ok = True
        for x, op in zip(a, ops):
            if op == 0: st.append(x)
            elif st: st.pop()
            else: ok = False; break
        if ok: best = sum(st) if best is None else max(best, sum(st))
    return int(toks(out)[0]) == best, f'want {best}'

# ---------- 15. IT Restaurants: every (a, b) reaching the maximum, increasing a ----------
def g_itr():
    n = rng.randint(3, 8); edges = [(i, rng.randrange(i)) for i in range(1, n)]
    return f'{n}\n' + ''.join(f'{u + 1} {v + 1}\n' for u, v in edges), (n, edges)
def v_itr(inp, ctx, out):
    n, edges = ctx; best = -1; pairs = set()
    for col in itertools.product((0, 1, 2), repeat=n):
        a, b = col.count(1), col.count(2)
        if a == 0 or b == 0 or any({col[u], col[v]} == {1, 2} for u, v in edges): continue
        if a + b > best: best, pairs = a + b, {(a, b)}
        elif a + b == best: pairs.add((a, b))
    want = sorted(pairs); exp = [str(len(want))] + [str(x) for p in want for x in p]
    return toks(out) == exp, f'want {exp}'

check('it-restaurants', 'practice/graphs/problem-42-it-restaurants.cpp', g_itr, v_itr, 300)
# ---------- 16. Hamiiid, Haaamid... Hamid: minimax over the whole game ----------
def g_hamid():
    n = rng.randint(2, 8); x = rng.randint(1, n)
    s = ''.join('.' if i == x - 1 else rng.choice('.#') for i in range(n))
    return f'1\n{n} {x}\n{s}\n', (n, x, s)
def v_hamid(inp, ctx, out):
    import functools
    n, x, s = ctx; INF = 10**9
    @functools.lru_cache(None)
    def days(walls, pos, d):   # each day Mani builds a wall, then Hamid runs left or right
        if d == 0: return INF
        best = -1
        for w in [c for c in range(n) if c != pos and not (walls >> c) & 1] or [None]:
            ww = walls | (1 << w) if w is not None else walls
            res = INF
            for step in (-1, 1):
                c = pos + step
                while 0 <= c < n and not (ww >> c) & 1: c += step
                res = min(res, 1 if not 0 <= c < n else 1 + days(ww & ~(1 << c), c, d - 1))
            best = max(best, res)
        return best
    want = days(sum(1 << i for i, ch in enumerate(s) if ch == '#'), x - 1, n + 3)
    return toks(out) == [str(want)], f'want {want}'

check('hamid', 'contests/codeforces/11-round-1041-div-1-+-div-2/problem-b-hamiiid-haaamid-...- -hamid.cpp', g_hamid, v_hamid, 300)
check('waste-sorting', 'practice/mixed/problem-65-waste-sorting.cpp', g_waste, v_waste)
check('carousel', 'practice/graphs/problem-5-carousel.cpp', g_car, v_car, 300)
check('sum-in-the-tree', 'practice/graphs/problem-36-sum-in-the-tree.cpp', g_tree, v_tree, 300)
check('broken-keyboard', 'practice/dynamic-programming/problem-14-yet-another-broken-keyboard.cpp', g_kb, v_kb)
check('static-range-sums', 'practice/dynamic-programming/problem-29-static-range-sum-queries.cpp', g_srs, v_srs)
check('and-reconstruction', 'course-cs334/class-contests/contest-7/problem-b-and-reconstruction.cpp', g_and, v_and, 300)
check('shohag-xor', 'course-cs334/class-contests/contest-7/problem-c-shohag-loves-xor-easy-version.cpp', g_sh, v_sh)
check('vlad-division', 'course-cs334/labs/lab-05/problem-e-vlad-and-division.cpp', g_vlad, v_vlad)
check('infinite-sequence', 'course-cs334/labs/lab-05/problem-d-and-an-infinite-sequence.cpp', g_inf, v_inf)
check('sakurako', 'course-cs334/labs/lab-04/problem-e-sakurakos-field-trip.cpp', g_sak, v_sak)
check('abc396-c', 'contests/atcoder/2-beginner-contest-396/problem-c.cpp', g_abc, v_abc)
check('least-prefix-sum', 'practice/prefix-sums/problem-m-least-prefix-sum.cpp', g_lps, v_lps)
check('star-sky', 'practice/prefix-sums/problem-f-star-sky.cpp', g_star, v_star)
check('arc194-a', 'contests/atcoder/3-regular-contest-194-div-2/problem-a.cpp', g_arc, v_arc)

def template_helpers():
    src = os.path.join(TMP, 'template_check.cpp')
    Path(src).write_text(TEMPLATE_CHECK.replace('TEMPLATE_PATH', str(ROOT / 'template' / 'main-cpp-template.cpp')))
    exe = build(src, 'template_check')
    r = subprocess.run([exe], capture_output=True, text=True, timeout=60)
    results.append(('template-helpers', r.returncode == 0, r.stdout.strip()))

TEMPLATE_CHECK = r'''
#define main template_main
#include "TEMPLATE_PATH"
#undef main
int main(){
    mt19937_64 g(12345); auto R=[&](ll lo,ll hi){ return uniform_int_distribution<ll>(lo,hi)(g); };
    ll bad=0, checks=0;
    // discrete log against brute force
    for(int it=0; it<4000; it++){
        ll m=R(1,500), a=R(0,m), b=R(0,m);
        if(__gcd(a%m==0?m:a%m, m)!=1 && m!=1) continue;
        ll want=-1, cur=1%m;
        for(ll x=0; x<=2*m; x++){ if(cur==b%m){ want=x; break; } cur=cur*(a%m)%m; }
        ll got=discrete_log_bsgs(a,b,m); checks++;
        if(got!=want){ if(bad<5) printf("dlog a=%lld b=%lld m=%lld got %lld want %lld\n",a,b,m,got,want); bad++; }
    }
    // CRT against brute force, including non-prime moduli
    for(int it=0; it<3000; it++){
        int k=R(1,3); vll m,a; ll prod=1;
        while((int)m.size()<k){ ll x=R(2,30); bool ok=1; for(ll y:m) if(__gcd(x,y)!=1) ok=0; if(ok){ m.pb(x); a.pb(R(-40,40)); prod*=x; } }
        ll got=crt(a,m), want=-1;
        for(ll x=0;x<prod;x++){ bool ok=1; rep(i,0,k) if(((x-a[i])%m[i]+m[i])%m[i]) ok=0; if(ok){ want=x; break; } }
        checks++; if(got!=want){ if(bad<10) printf("crt got %lld want %lld\n",got,want); bad++; }
    }
    // factorial: exact through 20, -1 beyond
    ll f=1; for(ll n=0;n<=25;n++){ if(n) f=(n<=20? f*n : -1); ll want=(n<=20? f : -1); checks++; if(factorial(n)!=want || compute_factorial(n)!=want){ printf("fact %lld\n",n); bad++; } }
    // the forward-declared names now resolve to the definitions
    vector<vll> A={{1,1},{1,0}}; checks++; if(math_pow(A,10,1000000007)[0][1]!=55){ puts("matpow"); bad++; }
    checks++; if(countDivisors(360)!=24){ puts("countDivisors"); bad++; }
    precompute_factorials(10); checks++; if(ncr(10,3)!=120){ puts("ncr"); bad++; }
    printf("%lld checks, %lld failures\n",checks,bad);
    return bad!=0;
}
'''

template_helpers()

for name, ok, msg in results:
    print(('ok  ' if ok else 'FAIL'), name + ':', msg if ok else '\n' + msg)
sys.exit(0 if all(ok for _, ok, _ in results) else 1)
