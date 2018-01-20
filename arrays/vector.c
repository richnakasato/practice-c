// vector implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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


// TEST =======================================================

void test_vector_new() {
  vector* test = vector_new();
  int size = test->size;
  int capacity = test->capacity;
  assert(size == 0);
  assert(capacity == new_capacity);
  vector_destroy(test);
}

//// not sure how to handle out of bounds return value
//int get(Vector* vec, int idx) {
//  if (!inbounds(vec, idx)) {
//    return -1; // ERROR
//  }
//  return vec->arr[idx];
//}
//
//int set(Vector* vec, int idx, int val) {
//  if (!inbounds(vec, idx)) {
//    return -1; // ERROR
//  }
//  vec->arr[idx] = val;
//  return 0;
//}
//
//void pushback(Vector* vec, int val) {
//  if (!inbounds(vec, val)) { // this is wrong!
//    return;
//  }
//  // only works if sizing is fine...
//  vec->arr[vec->size] = val;
//
//}
//
//int (Vector* vec, int idx) {
//  return 0;
//}
//
//int size(Vector* vec) {
//  return 0;
//}
//
//// supporting functions
//bool inbounds(Vector* vec, int idx) {
//  return (idx >= 0 && idx < vec->size);
//}
