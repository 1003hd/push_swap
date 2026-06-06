*This project has been created as part of the 42 curriculum by aselezen, baserbet.*

# push_swap

A sorting program that orders a stack of integers using a limited, predefined set of stack operations, while keeping the number of operations as low as possible.

---

# Description

The goal of `push_swap` is to sort data on a stack using only two stacks (`a` and `b`) and a restricted instruction set. The challenge is not only to sort correctly, but to do so with the **fewest possible operations**.

The program receives a list of integers as arguments, computes a sequence of operations that sorts them, and prints that sequence to standard output (`stdout`). The output can then be fed into the `checker` program to verify correctness.

This implementation goes beyond a single algorithm: it ships **multiple sorting strategies** and an **adaptive dispatcher** that selects the best one based on how disordered the input is. An optional **benchmark mode** reports the chosen strategy, its complexity, and the operation count.

The project focuses on:
- stack-based data manipulation,
- algorithmic cost optimization,
- sorting algorithm design and trade-offs,
- linked-list management in C,
- input parsing and robust error handling.

---

# Features

## Allowed Operations

| Operation | Description |
|---|---|
| `sa` / `sb` / `ss` | Swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top element from one stack to the other |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both up (first becomes last) |
| `rra` / `rrb` / `rrr` | Reverse rotate `a` / `b` / both down (last becomes first) |

## Sorting Strategies

| Strategy | Flag | Algorithm | Complexity |
|---|---|---|---|
| Simple | `--simple` | Selection sort | O(n²) |
| Medium | `--medium` | Chunk-based sort | O(n·√n) |
| Complex | `--complex` | Radix sort | O(n log n) |
| Adaptive | `--adaptive` *(default)* | Picks a strategy from input disorder | O(n log n) |

The **adaptive** strategy measures the input's *disorder* and selects:
- `--simple` when disorder `< 20%`,
- `--medium` when disorder `< 80%`,
- `--complex` otherwise.

## Benchmark Mode

`--bench` prints diagnostics to standard error (`stderr`): input disorder, selected strategy and its complexity, total operation count, and a per-operation breakdown. The operation stream itself stays on `stdout`, so benchmarking does not interfere with piping into a checker.

---

# Project Structure

| File | Description |
|---|---|
| `push_swap.h` | Header: data structures and prototypes |
| `push_swap.c` | Program entry point and error helper |
| `parsing.c`, `parsing_utils.c` | Argument parsing and validation |
| `create_stacks.c` | Stack allocation and freeing |
| `operation_stacks.c` | `sa` / `sb` / `ss` and helpers |
| `push_stacks.c` | `pa` / `pb` |
| `rotate_stacks.c` | `ra` / `rb` / `rr` |
| `reverse_rotate_stacks.c` | `rra` / `rrb` / `rrr` |
| `simple_sort.c` | Selection sort strategy |
| `medium_sort.c` | Chunk-based sort strategy |
| `complex_sort.c` | Radix sort strategy |
| `strategy.c` | Flag parsing, strategy dispatch, benchmark output |
| `utils.c` | Disorder computation and shared helpers |
| `libft/` | Custom C standard library |
| `Makefile` | Build rules |

---

# Instructions

## Compilation

Build the program:

```bash
make
```

This generates the `push_swap` executable.

Useful Makefile rules:

```bash
make        # build push_swap
make clean  # remove object files
make fclean # remove object files and the executable
make re     # rebuild everything
```

## Execution

```bash
./push_swap [strategy flag] [--bench] <integers...>
```

- Integers are passed as arguments (space-separated, or as a single quoted string).
- Strategy flag is optional; defaults to `--adaptive`.
- On invalid input the program prints `Error` to `stderr`.

---

# Usage Examples

> Lines prefixed with `[bench]` are printed by the optional benchmark mode (to `stderr`). The operation stream stays on `stdout`.

Default selection (`--adaptive`) and operation count:

```bash
$> ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
```

Force the simple (O(n²)) strategy:

```bash
$> ./push_swap --simple 5 4 3 2 1
```

Force the complex (O(n log n)) strategy and verify with the checker:

```bash
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
OK
```

`push_swap` with a large input:

```bash
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
6784
```

Run with benchmark enabled; pipe operations to the checker while saving the benchmark to a file:

```bash
$> shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
OK
$> cat bench.txt
[bench] disorder: 49.93%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops: 7997
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 4840 rb: 1098 rr: 0 rra: 0 rrb: 1059 rrr: 0
```

Same idea on a small input:

```bash
$> ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
OK
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

Error management (non-numeric argument, duplicate value):

```bash
$> ./push_swap --adaptive 0 one 2 3
Error
$> ./push_swap --simple 3 2 3
Error
```

---

# Technical Choices

## Stacks as Linked Lists

Both stacks are modeled as a `t_stack` struct wrapping a `t_list` head with a cached `size`. This keeps push/rotate operations O(1) and avoids reallocation during sorting.

## Adaptive Dispatch

Rather than committing to one algorithm, the program estimates input disorder once (`compute_disorder`) and routes to the cheapest strategy expected to handle it well. This keeps small or nearly-sorted inputs cheap while still scaling to large random inputs via radix sort.

## Operation Counting

Every operation function accepts an optional `t_counts *` (pass `NULL` to skip). This makes benchmarking opt-in with zero overhead on the normal path.

---

# Resources

## Documentation & References

- 42 School `push_swap` subject

- Sorting algorithms overview
  https://en.wikipedia.org/wiki/Sorting_algorithm

- Radix sort
  https://en.wikipedia.org/wiki/Radix_sort

- Selection sort
  https://en.wikipedia.org/wiki/Selection_sort

- push_swap visualizer (for debugging and intuition)
  https://github.com/o-reo/push_swap_visualizer

## AI Usage

AI tools were used as supplementary learning and debugging assistance during development.

Used for:
- clarifying edge cases in argument parsing and integer overflow handling,
- improving README formatting and project documentation.

AI-generated code was not copied directly into the final implementation.

---

# Notes

- The error message `Error\n` is written to file descriptor `2` (`stderr`).
- The project follows the 42 Norm requirements.
- Compatible with standard compilation flags:

```bash
-Wall -Wextra -Werror
```
</content>
</invoke>
