# From other sources

These 30 files are not my own original solutions. I kept them because I learned from them: some are reference solutions I studied while working the same problems myself, and many of the rest I edited along the way. They are kept apart so nothing here is mistaken for my work, and none of them count toward the totals in the main README.

## cses-dp-priyansh-agarwal/ (20 files)

Reference solutions to the CSES Dynamic Programming problems, each headed `/* Priyansh Agarwal*/`. They came as one folder of downloaded solution code (all 20 files carry the same timestamp), next to a folder of notes from YouTube. My own solutions to the same problems are in `practice/dynamic-programming/`, for example `problem-6-dice-combinations.cpp` and `problem-8-minimizing-coins.cpp`.

## contest-problems/ (10 files)

| File | Why it is here |
|---|---|
| `the-intriguing-obsession.cpp` | Written inside galen_colin's public template (it has his `galen_colin_local` guard) |
| `codeforces-round-1016-shorten-the-array.cpp` | jiangly's template and style (`i64`, `u64`, `u128` aliases) |
| `atcoder-beginner-contest-400-problem-g.cpp` | Someone else's template, which includes a `templates/debug.h` that was never in my setup |
| `it-restaurants.cpp` | Someone else's setup: reads `../IO/c.in`, a path that does not exist in my folders |
| `card-game.cpp` | Looks like editorial code (layout and style), not mine |
| `photoshoot-for-gorillas.cpp` | Not in my style (`#define int long long`, fixed global arrays) |
| `codeforces-round-1017-problem-h.cpp` | Not in my style |
| `unforgivable-curse-easy-version.cpp` | Not in my style |
| `cs-academy-subarray-removal.cpp` | A second version of a problem whose attempt in my template never compiled (so it is not in this repository), not in my style |
| `cs-academy-and-closure.cpp` | A second version of a problem I also solved in my template (`practice/mixed/problem-94-...`), not in my style |

They all compile with the rest of the repository (`tools/build_all.py` builds everything under `solutions/`), but none of them are stress-tested.
