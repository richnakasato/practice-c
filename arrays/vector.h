#ifndef VECTOR_H
#define VECTOR_H

const int init_capacity = 4
const int max_capacity  = 1024
const int growth_factor = 2

typedef struct {
  int* arr;
  int capacity;
  int size;
} Vector;

// constructor - create and return a new vector
Vector* new_vector();

// destructor - destroy vector and free memory
void destroy_vector(Vector* vec);

// get(i) - returns val at element i with bounds checking
int get(Vector* vec, int idx);

// set(i, val) - sets val at element i with bounds checking
int set(Vector* vec, int idx, int val);

// pushback(val) - add an element to end of vector
void pushback(Vector* vec, int val);

// remove(i) - removes element at i and returns val
int remove(Vector* vec, int idx);

// size() - returns size of vector
int size(Vector* vec);
