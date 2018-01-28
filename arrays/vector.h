#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct {
  int* arr;
  int cap;
  int sz;
} vector;

// creates and sets vector, returns operation status
bool vector_create(vector** vpp);

// destroys and nulls vector, returns operation status
bool vector_destroy(vector** vpp);

// gets size, returns operation status
bool vector_size(vector* vp, int* szp);

// gets capacity, returns operation status
bool vector_capacity(vector* vp, int* capp);

// checks if empty, returns operation status
bool vector_isempty(vector* vp, bool* isemptyp);

// gets val at idx, returns operation status
bool vector_get(vector* vp, int idx, int* valp);

// sets val at idx, returns operation status
bool vector_set(vector* v, int idx, int val);

// inserts val at tail, returns operation status
bool vector_pushback(vector** vpp, int val);

// inserts val at head, returns operation status
//bool vector_pushfront(vector** v, int val);

// gets val at tail and removes it, returns operation status
//bool vector_popback(vector** v, int *val);

// deletes slot at idx (shifting left), returns operation status
//bool vector_delete(vector** v, int idx);

// deletes all slots with val (shifting left), return operation status
//bool vector_remove(vector** v, int val);

// sets capacity of vector to c (truncating if necessary), returns operation status
bool vector_resize(vector** vpp, int cap);

// prints all elements in the vector to std out
void vector_print(vector* vp);

#endif // VECTOR_H
