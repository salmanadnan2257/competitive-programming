#!/usr/bin/env python3
"""Compile every solution in the repository and report what fails.

    python3 tools/build_all.py              # all of solutions/ plus the template
    python3 tools/build_all.py -j 4         # fewer parallel compiles
    CXX=clang++ python3 tools/build_all.py

Each file is compiled on its own with the flags a judge uses (-std=gnu++17 -O2).
Binaries go to a temporary directory and are thrown away; the point is only that
every file in the tree builds. Exit status is 1 if any file fails.
"""

import argparse
import os
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("-j", "--jobs", type=int, default=os.cpu_count() or 4)
    args = ap.parse_args()

    cxx = os.environ.get("CXX", "g++")
    files = sorted((ROOT / "solutions").rglob("*.cpp")) + [ROOT / "template" / "main-cpp-template.cpp"]

    with tempfile.TemporaryDirectory() as tmp:
        def build(i_f):
            i, f = i_f
            r = subprocess.run([cxx, "-std=gnu++17", "-O2", "-o", os.path.join(tmp, str(i)), str(f)],
                               capture_output=True, text=True)
            return f, r.returncode, r.stderr

        with ThreadPoolExecutor(args.jobs) as pool:
            results = list(pool.map(build, enumerate(files)))

    failed = [(f, err) for f, code, err in results if code != 0]
    for f, err in failed:
        first = next((l for l in err.splitlines() if "error" in l), err.strip()[:200])
        print(f"FAIL {f.relative_to(ROOT)}\n     {first}")
    print(f"{len(files) - len(failed)} of {len(files)} files compile with {cxx} -std=gnu++17 -O2")
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
