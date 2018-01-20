#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct {
  int* arr;
  int capacity;
  int size;
} vector;

// constructor - create and return a new vector
vector* vector_new();

// destructor - destroy vector and free memory
void vector_destroy(vector* v);

// returning size of vector
int vector_size(vector* v);

// checks bounds of vector
bool vector_bounds(vector* v, int idx);

// return val for element at idx
int vector_get(vector* v, int idx);

// push a val onto the back of the vector
void vector_pushback(vector* v, int val);

// set element at idx to val
void vector_set(vector* v, int idx, int val);


// TEST =======================================================

void run_all_tests();

void test_vector_new();

void test_vector_size();

void test_vector_bounds();

void test_vector_get();

void test_vector_pushback();

void test_vector_set();

#endif // VECTOR_H
