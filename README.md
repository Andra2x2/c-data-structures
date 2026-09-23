# C Data Structures

Compact C11 examples of a stack, circular queue, singly linked list, and insertion sort. The demo prints predictable output so you can compare behavior while reading the code.

## Build and run

Requires a C compiler such as GCC (on Windows, use a GCC installation such as MinGW-w64).

```bash
gcc -std=c11 -Wall -Wextra -Werror main.c structures.c -o demo
```

Linux/macOS: `./demo`. Windows PowerShell: `./demo.exe`.

```text
Stack (LIFO): 30 20 10
Queue (FIFO): 10 20 30
List after removing 20: 10 30
Insertion sort: 3 8 12 25 42
```

## What each example shows

| Structure | Behavior | Cost |
|---|---|---|
| Stack | Last item pushed is the first popped | O(1) push/pop |
| Circular queue | Oldest item leaves first; freed slots are reused | O(1) enqueue/dequeue |
| Linked list | Nodes are allocated and linked dynamically | O(n) append/remove |
| Insertion sort | Insert each next value into its sorted position | O(n²) worst case |

Stack and queue capacity is five. Operations return `false` on full/empty conditions. Initialize them with `{0}`. Linked-list append reports allocation failure; `list_free` releases all nodes and resets the head.

The API assumes valid, non-null structure/output pointers and properly initialized data. `insertion_sort(NULL, 0)` is allowed. This is educational single-threaded code.

## Test

```bash
gcc -std=c11 -Wall -Wextra -Werror test.c structures.c -o tests
```

Run `./tests` on Linux/macOS or `./tests.exe` on Windows.

Expected: `All C structure checks passed`.

Tests exercise full/empty boundaries, FIFO/LIFO order, queue wraparound, list removal, duplicates and negative values in sorting.

## Files

- `structures.h`: types, constants, public function declarations.
- `structures.c`: implementation.
- `main.c`: runnable demonstration.
- `test.c`: assertions for edge cases.
