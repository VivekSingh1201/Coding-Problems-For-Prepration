# Coding Preparation

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

- Topic folders use lowercase kebab-case.
- Problem files use lowercase kebab-case with a `.cpp` extension.
- Legacy source prefixes are preserved when available: `as-##-...`, `tg-##-...`, and `dp-##-...`.
- Standalone topic files that do not belong to a numbered sequence use plain kebab-case, such as `sorting/bubble-sort.cpp` and `system-design/lru-cache.cpp`.
- The numeric portion is a legacy identifier inside a topic and is not guaranteed to be globally unique across the whole repository.

## Compile Example

```bash
mkdir -p build
g++ problems/math/as-03-integer-to-roman.cpp -std=c++17 -o build/as-03-integer-to-roman
./build/as-03-integer-to-roman
```
