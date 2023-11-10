// This is an assertion-based test client for the deque-split module

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include "deque-split.h"

// is_even(n) determines if n is even
bool is_even(int n) {
  return n % 2 == 0; 
}

int main(void) {
  int numbers[6] = {4, 8, 15, 16, 23, 42};
  const int numbers_len = 6;  
  struct deque *d1 = deque_create();
  for (int i = 0; i < numbers_len; ++i) {
    deque_insert_back(numbers[i], d1); 
  }

  struct deque *d2 = deque_split(d1, is_even);
  deque_print(d1); // uncomment to see results
  assert(d2);
  deque_print(d2); // uncomment to see results
  assert(!deque_is_empty(d1));
  assert(!deque_is_empty(d2));
  assert(deque_front(d1) == 4);
  assert(deque_back(d1) == 42);
  assert(deque_front(d2) == 15);
  assert(deque_back(d2) == 23);
  
  deque_destroy(d1);
  deque_destroy(d2);
}
