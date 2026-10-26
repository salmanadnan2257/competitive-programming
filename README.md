# Competitive Programming

398 of my C++ solutions to contest problems from Codeforces, CSES, AtCoder and CS Academy, filed by topic, plus the contest template most of them are written in. The data-structure solutions are stress-tested against brute force: a script feeds each one random inputs and checks every answer against a slow, obviously-correct version.

## Why

I spent about eight months doing competitive programming full time, eight-plus hours a day, starting with CS 334 (competitive programming) at Habib University and carrying on after it. The work lived in a folder of practice directories with no version control: copies of the same file in three topic folders, empty placeholders for problems I never got to, half-finished attempts. This repository is that work cleaned up into something a reader can browse and a machine can check.

This was solo work by Salman Adnan.

## What's in it

```
solutions/
  practice/          problems worked by topic
    two-pointers       7
    bitmasks           8
    prefix-sums       14
    number-theory     51
    graphs            67
    dynamic-programming 56
    range-queries      8   (the CSES Range Queries section, all stress-tested)
    mixed            104   (mixed-topic sets)
    atcoder            3
    cs-academy         8
  contests/
    codeforces        33   (8 rounds, from Div. 4 up to a combined Div. 1 + 2)
    atcoder           12   (6 Beginner and Regular contests)
  course-cs334/      CS 334 at Habib University
    class-contests    12
    labs               7
    problem-sets       8
template/
  main-cpp-template.cpp   the last version of my contest template
stress/
  stress.py          random inputs vs brute force for the range-query solutions
tools/
  build_all.py       compiles every file and reports what fails
```

File names follow the problem: `problem-27-ring-road.cpp` is the 27th problem in that topic set, Codeforces' "Ring Road".

## How a solution is laid out

Most files (269 of the 398) are written inside a version of my template, with one `solve()` filled in under a `SOLVE` banner; the other 129, mostly early number theory, CS 334 and dynamic programming work, are standalone files that don't use it. The template grew over time: a typical file carries about 85 lines of it above the `SOLVE` banner, and the version in `template/` is the last and largest, 639 lines, with fast I/O, type aliases (`ll`, `vll`, `pll`), loop macros, variadic `re(...)` and `ps(...)` for reading and printing, and a library of helpers I wanted within reach during a contest, such as `binpowmod` and modular inverse, a sieve, `ncr` over precomputed factorials, CRT, discrete log by baby-step giant-step, matrix power, LCA and topological sort. The blocks guarded by `LOCAL` (timing the run, reading from a local file) only switch on when I compile with my own defines; on a judge `LOCAL` is undefined and none of it runs.

So when you open a file, scroll to the `SOLVE` banner. Everything above it is shared.

## The range-query solutions

These eight are the CSES Range Queries problems, and they are where the data structures live:

| Problem | Approach |
|---|---|
| Dynamic Range Sum Queries | Fenwick tree, point assign done as a point add of the difference |
| Dynamic Range Minimum Queries | segment tree, point update, range min |
| Range Xor Queries | prefix XOR, answer is `p[b] ^ p[a-1]` |
| Range Update Queries | lazy segment tree, range add, point query |
| Forest Queries | 2D prefix sums with inclusion-exclusion |
| Hotel Queries | max segment tree, descend to the leftmost hotel with enough rooms |
| Range Updates and Sums | lazy segment tree with two tags, add and assign |
| Polynomial Queries | lazy segment tree storing an arithmetic progression `c + d*i` |

## Setup

You need a C++17 compiler that takes g++ flags and Python 3.8 or newer. Nothing else: no packages, no environment variables, no network. (That is why there is no `requirements.txt` or `.env.example`.)

Compile and run one solution the way a judge would:

```
g++ -std=gnu++17 -O2 -o sol solutions/practice/range-queries/problem-6-hotel-queries.cpp
printf '3 5\n3 3 2\n1 4 1 3 2\n' | ./sol
```

## Checking it

```
python3 tools/build_all.py          # every solution plus the template must compile
python3 stress/stress.py            # range-query solutions vs brute force, 500 cases each
python3 stress/stress.py --cases 1000 --only polynomial-queries
```

Both scripts read `CXX` if you want a compiler other than `g++`. The stress seed is fixed, so a failure reproduces exactly, and the failing input is printed.

Verified on 2026-10-25 in a clean `gcc:13` container (g++ 13.5, Python 3.11): all 398 solutions and the template compile with `-std=gnu++17 -O2`, and all eight range-query solutions agree with brute force on 1,000 random cases each. To make sure the stress test can actually fail, I broke the minimum query (`min` swapped for `max` in the segment tree merge) and it failed on the first case.

What was not verified here: that each solution is accepted by its judge. No verdicts are stored in this repository, and the stress test only covers the eight range-query problems. Everything else is checked for compiling, nothing more.

## Challenges

- **Two lazy tags on one node.** Range Updates and Sums mixes "add x to [a, b]" with "set [a, b] to x", and the order matters: an add after a set must change the set value, a set after an add must wipe the add. The node keeps both tags, `lazy` for a pending add and `is_set` for a pending assignment, and `apply` folds an add into `is_set` when one is already there instead of stacking it. `is_set` uses -1 for "no assignment", which only works because CSES guarantees values of at least 1.
- **Lazy propagation of a progression.** Polynomial Queries adds 1, 2, 3, ... across a range, so the pending update on a node is not a constant. I store it as `c + d*i` in absolute index terms (for a query starting at L, c = 1 - L and d = 1), so two pending progressions on the same node just add coefficient-wise, and a node's sum grows by `c*len + d*(sum of its indices)`.
- **Finding the first hotel without a binary search.** Hotel Queries needs the leftmost hotel with at least r free rooms, then takes the rooms. Binary searching on prefix maxima costs O(log² n) per group. The solution keeps a max segment tree instead and walks down from the root, going left whenever the left child's maximum is big enough, which finds the hotel in O(log n); a point update then takes the rooms off that hotel.
- **Point assignment on a Fenwick tree.** A Fenwick tree only knows how to add, but Dynamic Range Sum Queries assigns. The solution keeps a plain copy of the array next to the tree and turns "set k to u" into "add u minus the old value at k".
- **Making the folder publishable.** The original folder had 480 candidate `.cpp` files. 19 were byte-identical copies sitting in a second topic folder, 17 were empty placeholders, 5 were editor backups, and 3 were unfinished attempts that never compiled (`count-the-arrays`, `subtree-queries` and `cs-academy-subarray-removal`), alongside folders of scratch work. I compiled all of them, kept only the files that build, removed exact duplicates (keeping the copy in the folder where the problem belongs), and left the rest out rather than finish them now and pass that off as the original work.

## What I learned

- Most segment tree bugs are in what a lazy tag means, not in the recursion. Writing down exactly what state a pending tag represents (Polynomial Queries' `c + d*i`, the add-versus-assign order above) made the code short; trying to patch cases one at a time never did.
- A segment tree can answer "where" as well as "how much". The Hotel Queries descent finds a position by using the stored aggregate to choose a direction, which is cheaper than binary searching over range queries.
- When updates are point-only, a Fenwick tree is less code and a smaller constant than a segment tree. Range add with point query does not need a lazy tree at all: a Fenwick tree over the difference array does it.
- A brute-force check is worth writing before trusting a fast solution. Every stress case here runs in milliseconds, and a wrong merge fails on the first one.

## What I'd do differently

- **Carry less template.** Every template-based file carries its helpers inline, usually about 85 lines and up to 629 in the late ones, to use a handful of them. That buries the actual solution, and every file also includes `bits/stdc++.h`, so building all 398 in one container took several minutes. A small header kept in one place, plus a precompiled `bits/stdc++.h`, would fix both.
- **Pick the simpler structure.** Range Update Queries uses a full lazy segment tree where a Fenwick tree on the difference array is a third of the code. Dynamic Range Minimum Queries has a `build()` that runs in O(n), but `solve()` fills the tree with n point updates in O(n log n) instead and never calls it.
- **Keep the judge's verdict.** Nothing records whether a file was accepted, so the repository can only prove the code compiles and, for eight problems, agrees with brute force. Saving the verdict and the problem link next to each solution at submission time would have cost nothing.
- **Version control from day one.** The duplicates, backups and placeholders above are what a folder without history fills up with.
