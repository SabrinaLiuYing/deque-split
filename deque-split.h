// This module provides the deque_split function

// SEASHELL_READONLY

#include <stdbool.h>

// see deque.h for the TRANSPARENT definition
struct deque;

// deque_split(lst, keep) removes all elements v from lst such that keep(v)
//   is false and returns a new deque containing all of the 
//   removed elements, in the same order that they were in within lst
// note: returns an empty deque if keep(v) is true for all v
// requires: lst is a valid deque (not NULL)
//           keep is a valid function pointer (not NULL)
// effects: may modify lst
//          allocates memory (caller must call deque_destroy)
// time: O(n) where n is the number of elements in lst
//       (assuming that keep is O(1))
struct deque *deque_split(struct deque *lst, bool (*keep)(int)); 
