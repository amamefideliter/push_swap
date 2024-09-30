# push_swap
### Introduction

The push_swap project is a sorting algorithm implementation that sorts a stack of integers using a set of operations on two stacks (stack a and stack b). The goal is to achieve the sorting in as few operations as possible.

### Operations
- `sa` (swap a): Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` (swap b): Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss`: Perform sa and sb at the same time.
- `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- `rr`: Perform `ra` and `rb` at the same time.
- `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr`: Perform `rra` and `rrb` at the same time.

### Approach
The solution employs the following strategy:

1. Cost Calculation: For each element in stack b, calculate the cost of pushing it back into stack a in its correct position.
2. Optimized Move: Execute the move with the lowest cost, ensuring efficient sorting with minimal operations.

### Checker
In addition to the sorting algorithm, a checker has been implemented. The checker verifies whether the sequence of operations provided to the program actually results in a sorted stack.
