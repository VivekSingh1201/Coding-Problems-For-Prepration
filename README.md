# Coding Preparation

Organized C++ practice problems and study resources for Coding preparation.
Organized C++ practice problems grouped by topic. The repository currently contains 84 solution files under `problems/`.

## Repository Layout

```text
problems/
  arrays-and-hashing/
  binary-search/
  dynamic-programming/
  greedy-and-sorting/
  math/
  sliding-window/
  sorting/
  stacks/
  strings/
  system-design/
  trees/
```

## Problem Sets

- `problems/arrays-and-hashing`: 26 array, hashing, matrix, and prefix-sum style problems
- `problems/binary-search`: 3 binary-search based problems
- `problems/greedy-and-sorting`: 5 greedy and sorting problems
- `problems/math`: 1 math-based problem
- `problems/sliding-window`: 3 sliding-window problems
- `problems/stacks`: 3 stack problems
- `problems/strings`: 9 string problems
- `problems/trees`: 7 binary-tree problems
- `problems/arrays-and-hashing`: 30 problems
- `problems/binary-search`: 3 problems
- `problems/dynamic-programming`: 8 problems
- `problems/greedy-and-sorting`: 6 problems
- `problems/math`: 5 problems
- `problems/sliding-window`: 3 problems
- `problems/sorting`: 3 problems
- `problems/stacks`: 3 problems
- `problems/strings`: 13 problems
- `problems/system-design`: 3 problems
- `problems/trees`: 7 problems

## Naming Convention

- `as-##-...`: files that originally came from the old `Array and String` folder
- `tg-##-...`: files that originally came from the old `Tree and Graph` folder

This keeps the old numbering traceable while making filenames readable on GitHub.
- Topic folders use lowercase kebab-case.
- Problem files use lowercase kebab-case with a `.cpp` extension.
- Legacy source prefixes are preserved when available: `as-##-...`, `tg-##-...`, and `dp-##-...`.
- Standalone topic files that do not belong to a numbered sequence use plain kebab-case, such as `sorting/bubble-sort.cpp` and `system-design/lru-cache.cpp`.
- The numeric portion is a legacy identifier inside a topic and is not guaranteed to be globally unique across the whole repository.

## Compile Example

```bash
g++ problems/greedy-and-sorting/as-06-buy-and-sell-stock-multiple-transactions.cpp -std=c++17 -o build/as-06
./build/as-06
mkdir -p build
g++ problems/math/as-03-integer-to-roman.cpp -std=c++17 -o build/as-03-integer-to-roman
./build/as-03-integer-to-roman
```