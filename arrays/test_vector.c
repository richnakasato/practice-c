#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "test_vector.h"

void run_all_tests() {
  test_can_create_vector();
  test_created_vector_has_size_zero();
  test_created_vector_has_capacity();
  test_destroy_vector_invalidates();
  test_cant_destroy_null_vector();
  test_cant_get_size_of_null_vector();
  test_cant_get_size_with_null_arg();
  test_can_get_size_of_new_vector();
  test_can_set_valid_idx_in_vector();
  test_cant_set_invalid_idx_in_vector();

}

void test_can_create_vector() {
  vector* test = NULL;
  bool created = vector_create(&test);
  assert(created && test != NULL);
  vector_print(test);
  bool destroyed = vector_destroy(&test);
  if(!destroyed) { printf("Issue destroying vector!\n"); }
}

void test_created_vector_has_size_zero() {
  vector* test = NULL;
  bool created = vector_create(&test);
  int size = -1;
  bool got_size = vector_size(test, &size);
  assert(created && got_size && size == 0);
  vector_print(test);
  bool destroyed = vector_destroy(&test);
  if(!destroyed) { printf("Issue destroying vector!\n"); }
}

void test_created_vector_has_capacity() {
  vector* test = NULL;
  bool created = vector_create(&test);
  int capacity = -1;
  bool got_capacity = vector_capacity(test, &capacity);
  assert(created && got_capacity && capacity != 0);
  vector_print(test);
  bool destroyed = vector_destroy(&test);
  if(!destroyed) { printf("Issue destroying vector!\n"); }
}

void test_destroy_vector_invalidates() {
  vector* test = NULL;
  bool created = vector_create(&test);
  bool destroyed = vector_destroy(&test);
  assert(created && destroyed && test == NULL);
  vector_print(test);
}

void test_cant_destroy_null_vector() {
  vector* test = NULL;
  bool destroyed = vector_destroy(&test);
  assert(!destroyed && test == NULL);
  vector_print(test);
}

void test_cant_get_size_of_null_vector() {
  vector* test = NULL;
  bool created = vector_create(&test);
  int dontcare;
  bool got_size = vector_size(NULL, &dontcare);
  assert(created && !got_size);
  vector_print(test);
  bool destroyed = vector_destroy(&test);
  if(!destroyed) { printf("Issue destroying vector!\n"); }
}

void test_cant_get_size_with_null_arg() {
  vector* test = NULL;
  bool created = vector_create(&test);
  bool got_size = vector_size(test, NULL);
  assert(created && !got_size);
  vector_print(test);
  bool destroyed = vector_destroy(&test);
  if(!destroyed) { printf("Issue destroying vector!\n"); }
}

void test_can_get_size_of_new_vector() {
  vector* test = NULL;
  bool created = vector_create(&test);
  int size = -1;
  bool got_size = vector_size(test, &size);
  assert(created && got_size && size == 0);
  vector_print(test);
  bool destroyed = vector_destroy(&test);
  if(!destroyed) { printf("Issue destroying vector!\n"); }
}

void test_can_set_valid_idx_in_vector() {
  vector* test = NULL;
  bool created = vector_create(&test);
  bool pushed_back = true;
  for(int i=0; i<16; ++i) {
    pushed_back &= vector_pushback(&test, i);
  }
  bool set_val = vector_set(test, 7, 99);
  assert(created && pushed_back && set_val);
  vector_print(test);
  bool destroyed = vector_destroy(&test);
  if(!destroyed) { printf("Issue destroying vector!\n"); }
}

void test_cant_set_invalid_idx_in_vector() {
  vector* test = NULL;
  bool created = vector_create(&test);
  bool pushed_back = true;
  for(int i=0; i<16; ++i) {
    pushed_back &= vector_pushback(&test, i);
  }
  bool set_val = vector_set(test, 17, 99);
  assert(created && pushed_back && !set_val);
  vector_print(test);
  bool destroyed = vector_destroy(&test);
  if(!destroyed) { printf("Issue destroying vector!\n"); }
}



void test_vector_size() { // {{{
  vector* test = NULL;
  bool created = vector_create(&test);
  assert(created);

  // getting size of a NULL vector shouldn't work
  int dontcare;
  bool got_size = vector_size(NULL, &dontcare);
  assert(!got_size);

  // getting size of a vector with a NULL arg shouldn't work
  got_size = vector_size(test, NULL);
  assert(!got_size);

  // getting size of valid vector should work
  int size = -1;
  got_size = vector_size(test, &size);
  assert(got_size);

  // size of new valid vector should be 0
  assert(size == 0);

  // TODO: test adding elements and size is correct

  // TODO: test removing elements and size if correct

  bool destroyed = vector_destroy(&test);
  assert(destroyed);
  return;
} // }}}

void test_vector_capacity() { // {{{
  vector* test = NULL;
  bool created = vector_create(&test);
  assert(created);

  // getting capacity of a NULL vector shouldn't work
  int dontcare;
  bool got_capacity = vector_capacity(NULL, &dontcare);
  assert(!got_capacity);

  // getting capacity of a vector with a NULL arg shouldn't work
  got_capacity = vector_capacity(test, NULL);
  assert(!got_capacity);

  // getting capacity of valid vector should work
  int capacity = -1;
  got_capacity = vector_capacity(test, &capacity);
  assert(got_capacity);

  // capacity of new valid vector should be 16
  assert(capacity == 16);

  // TODO: test adding elements over capacity and capacity adjusts

  // TODO: test removing elements under 1/4 capacity and capacity adjusts

  bool destroyed = vector_destroy(&test);
  assert(destroyed);
  return;
} // }}}

void test_vector_isempty() { // {{{
  vector* test = NULL;
  bool created = vector_create(&test);
  assert(created);

  // getting capacity of a NULL vector shouldn't work
  bool dontcare;
  bool checked_empty = vector_isempty(NULL, &dontcare);
  assert(!checked_empty);

  // getting capacity of a vector with a NULL arg shouldn't work
  checked_empty = vector_isempty(test, NULL);
  assert(!checked_empty);

  // checking for empty should work
  bool is_empty = false;
  checked_empty = vector_isempty(test, &is_empty);
  assert(checked_empty);

  // new vector should be empty
  assert(is_empty);

  // TODO: test adding elements makes a vector not empty

  // TODO: test removing all elements makes a vector empty again

  bool destroyed = vector_destroy(&test);
  assert(destroyed);
  return;
} // }}}

void test_vector_pushback() { // {{{
  vector* test = NULL;
  bool created = vector_create(&test);
  assert(created);

  // pushing to a NULL vector shouldn't work
  int dontcare = 0;
  bool pushed_back = vector_pushback(NULL, dontcare);
  assert(!pushed_back);

  // pushing to a vector should work
  int value = 99;
  pushed_back = vector_pushback(&test, value);
  assert(pushed_back);

  // new size should be 1
  int size = 0;
  bool got_size = vector_size(test, &size);
  assert(got_size);
  assert(size == 1);

  // pushing 16 more values should up capacity
  for(int i=0; i<16; ++i) {
    pushed_back = vector_pushback(&test, i);
  }
  int capacity;
  bool got_capacity = vector_capacity(test, &capacity);
  assert(got_capacity);
  assert(capacity == 32);

  vector_print(test);

  // direct inspection shows [99,0,...,15]
  for(int i=0; i<17; ++i) {
    if(i==0) {
      assert(test->arr[i] == 99);
    }
    else {
      assert(test->arr[i] == i-1);
    }
  }

  bool destroyed = vector_destroy(&test);
  assert(destroyed);
  return;
} // }}}

//void run_all_tests() {
//  test_vector_new();
//  test_vector_size();
//  test_vector_bounds();
//  test_vector_get();
//  test_vector_pushback();
//}
//
//void test_vector_new() {
//  vector* test = vector_new();
//  int size = test->size;
//  int capacity = test->capacity;
//  assert(size == 0);
//  assert(capacity == new_capacity);
//  vector_destroy(test);
//}
//
//void test_vector_size() {
//  vector* test = vector_new();
//  int size = vector_size(test);
//  assert(size == 0);
//  vector_destroy(test);
//
//  vector* nothing = NULL;
//  size = vector_size(nothing);
//  assert(size == 0);
//}
//
//void test_vector_bounds() {
//  vector* test = vector_new();
//  bool is_bounds = vector_bounds(test, new_capacity);
//  assert(is_bounds == false);
//  is_bounds = vector_bounds(test, new_capacity-1);
//  assert(is_bounds == false);
//  is_bounds = vector_bounds(test, 0);
//  assert(is_bounds == false);
//  vector_pushback(test, 10);
//  is_bounds = vector_bounds(test, 0);
//  assert(is_bounds == true);
//  is_bounds = vector_bounds(test, 1);
//  assert(is_bounds == false);
//}
//
//void test_vector_get() {
//  vector* test = vector_new();
//  vector_pushback(test, 10);
//  int val = vector_get(test, 0);
//  assert(val == 10);
//  //val = vector_get(test, 1); // exit program
//}
//
//void test_vector_pushback() {
//  vector* test = vector_new();
//  for (int i=0; i<10; ++i) {
//    vector_pushback(test, i+1);
//  }
//  int size = vector_size(test);
//  assert(size == 10);
//  for (int i=0; i<size; ++i) {
//    assert(vector_get(test, i) == i+1);
//  }
//}
