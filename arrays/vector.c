// vector implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "vector.h"

// CONST ======================================================

const int new_capacity = 4;
const int max_capacity = 1024;
const int growth_factor = 2;


// IMPL =======================================================

vector* vector_new() {
  vector* v = (vector*)malloc(sizeof(vector));
  v->arr = (int*)malloc(new_capacity * sizeof(int));
  v->capacity = new_capacity;
  v->size = 0;
  return v;
}

void vector_destroy(vector* v) {
  if (v != NULL) {
    if (v->arr != NULL) {
      free(v->arr);
    }
    free(v);
  }
  return;
}

int vector_size(vector* v) {
  return (v == NULL) ? 0 : v->size;
}

bool vector_bounds(vector* v, int idx) {
  return (v != NULL && idx >= 0 && idx < v->size);
}

int vector_get(vector* v, int idx) {
  if (!vector_bounds(v, idx)) {
    return 0;
  }
  return v->arr[idx];
}

void vector_pushback(vector* v, int val) {
  if (v == NULL) {
    return;
  }
  if (v->size == v->capacity) {
    int new_size = v->capacity * growth_factor * sizeof(int);
    int* new_arr = (int*)malloc(new_size);
    memcpy(new_arr, v->arr, new_size);
    free(v->arr);
    v->arr = new_arr;
    v->capacity = v->capacity * growth_factor;
  }
  v->arr[v->size] = val;
  v->size++;
  return;
}

void vector_set(vector* v, int idx, int val) {
  if (!vector_bounds(v, idx)) {
    return;
  }
  v->arr[idx] = val;
}


// TEST =======================================================

void run_all_tests() {
  test_vector_new();
  test_vector_size();
  test_vector_bounds();
  test_vector_get();
  test_vector_pushback();
}

void test_vector_new() {
  vector* test = vector_new();
  int size = test->size;
  int capacity = test->capacity;
  assert(size == 0);
  assert(capacity == new_capacity);
  vector_destroy(test);
}

void test_vector_size() {
  vector* test = vector_new();
  int size = vector_size(test);
  assert(size == 0);
  vector_destroy(test);

  vector* nothing = NULL;
  size = vector_size(nothing);
  assert(size == 0);
}

void test_vector_bounds() {
  vector* test = vector_new();
  bool is_bounds = vector_bounds(test, new_capacity);
  assert(is_bounds == false);
  is_bounds = vector_bounds(test, new_capacity-1);
  assert(is_bounds == false);
  is_bounds = vector_bounds(test, 0);
  assert(is_bounds == false);
  vector_pushback(test, 10);
  is_bounds = vector_bounds(test, 0);
  assert(is_bounds == true);
}

void test_vector_get() {
  vector* test = vector_new();
  vector_pushback(test, 10);
  int val = vector_get(test, 0);
  assert(val == 10);
}

void test_vector_pushback() {
  vector* test = vector_new();
  vector_pushback(test, 1);
  vector_pushback(test, 2);
  vector_pushback(test, 3);
  vector_pushback(test, 4);
  vector_pushback(test, 5);
  vector_pushback(test, 6);
  vector_pushback(test, 7);
  vector_pushback(test, 8);
  vector_pushback(test, 9);
  vector_pushback(test, 10);
  int size = vector_size(test);
  assert(size == 10);
  for (int i=0; i<size; ++i) {
    assert(vector_get(test, i) == i+1);
  }
}

