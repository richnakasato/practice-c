#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
  int* arr;
  int capacity;
  int size;
} vector;

// constructor - create and return a new vector
vector* vector_new();

// destructor - destroy vector and free memory
void vector_destroy(vector* v);

//// get(i) - returns val at element i with bounds checking
//int get(Vector* vec, int idx);
//
//// set(i, val) - sets val at element i with bounds checking
//int set(Vector* vec, int idx, int val);
//
//// pushback(val) - add an element to end of vector
//void pushback(Vector* vec, int val);
//
//// remove(i) - removes element at i and returns val
//int remove(Vector* vec, int idx);
//
//// size() - returns size of vector
//int size(Vector* vec);

// TEST =======================================================

void test_vector_new();

#endif // VECTOR_H
