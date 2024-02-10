The homework consists of several tasks. You need to submit an archive with the solutions for these tasks.

If done completely, this homework is worth 30 points.

# Task 1: Clojure DB (1 point for each query, 12 points max.)

You are given the database about cities and countries. You need to answer some queries about them in Clojure. See `task1.clj` for more details.

For this task, submit `task1.clj`.

# Task 2: Math in Clojure (11 points max.)

Solve the following subtasks and submit each subtask in a separate file. File name must be equal to `task2_x.clj`, where `x` is the number of subtask.

## Subtask 2.1 (2 points)

Fibonacci numbers are defined as follows:

```
f(0) = 1,
f(1) = 1,
f(n) = f(n-1) + f(n-2), for n >= 2.
```

Print first six Fibonacci numbers divisible by 7.

## Subtask 2.2 (2 points)

Generate first 100 pairs `(x y)` such that `1 <= x <= y`. The ordering is as follows. First, the triples are ordered by `x + y`. first, then, if their `x + y` are equal, they must be ordered by `x`.

## Subtask 2.3 (4 points)

Generate first 100 Pythagorean triples (i.e. pairs `(x y z)` such that `1 <= x <= y <= z` and `x*x + y*y = z*z`). The ordering is as follows. First, the triples are ordered by `x + y + z`. first, then, if their `x + y + z` are equal, they must be ordered by `x`.

## Subtask 2.4 (3 points)

Write a function which checks whether a given number is prime, in `O(sqrt N)` time. Then, generate first 100 prime numbers.

Hint: use `loop` and `recur` to write such function.

# Task 3: Concurrent File System Scanning (7 points)

In `task3.clj`, you are given a simple function that traverses the file system and prints the names of the files which contain the string `hello`.

You need to rewrite the program in such a way that file system traversal is done in parallel, using multiple threads.

The directory `test/` contains an example directory, in which our program searches for the files.

For this task, submit a modified `task3.clj`.
