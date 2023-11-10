/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// NONE
//
// Name: Ying Liu
// login ID: y2862liu
/////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// NOTE: the structure definitions in deque.h are TRANSPARENT so you may
//       modify the contents of a deque directly
#include "deque.h"
#include "deque-split.h"

struct deque *deque_split(struct deque *lst, bool (*keep)(int)) {
  assert(lst);
  assert(keep);
  struct deque *deq = deque_create();
  struct llnode *node = lst->front;
  struct deque *replace = deque_create();
  while(node){
    deque_insert_back(node->item, replace);
    if(! keep(node->item)){
      deque_insert_back(node->item, deq);
      deque_remove_back(replace);
    }
    deque_remove_front(lst);
    node = lst->front;
  }
  lst->front = replace->front;
  lst->back = replace->back;
  free(replace);
  return deq;
}