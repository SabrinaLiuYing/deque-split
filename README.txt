-----------------------------------------------------------------------------
// SEASHELL_READONLY

* Your coding style will NOT be graded for this question.
* Your testing methodology will NOT be graded for this question.
* All assignment rules and policies are in place for this question.
* There is no public test. Marmoset only ensures that your code "runs".
-----------------------------------------------------------------------------
* For this and EVERY other question, you may define helper functions
-----------------------------------------------------------------------------

In this question you will be returning to the deque from Assignment 9.

You have been provided with a completed implementation in deque.ll, but
this deque is TRANSPARENT so you may modify the contents of a deque directly.

You must implement the function deque_split that splits a deque into two
deques, using a function pointer to decide which values remain in the original,
and which are removed and added to the new deque.

For example (as seen in test-split.c)

If numbers is deque [4, 8, 15, 16, 23, 42] and the is_even function is defined,
then deque_split(numbers, is_even) should mutate numbers to be

[4, 8, 16, 42]

and return a new deque equal to

[15, 23]

Note that the 15, 23 (the odd numbers) are in the same relative order they were
in within the original deque.  

For this example, if the numbers in the deque were all even, then the
returned deque would be an empty deque.
