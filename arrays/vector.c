#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "vector.h"

const int start_capacity = 16;
const int growth_factor = 2;

bool is_vp_valid(vector* vp) {
  return (vp != NULL && vp->arr != NULL);
}

bool is_vpp_valid(vector** vpp) {
  return (vpp != NULL && *vpp != NULL && (*vpp)->arr != NULL);
}

bool is_idx_valid(vector* vp, int idx) {
  return (is_vp_valid(vp) && vp->sz > idx);
}

bool vector_create(vector** vpp) {
  *vpp = (vector*)malloc(sizeof(vector));
  if(*vpp == NULL) {
    return false;
  }
  (*vpp)->arr = (int*)malloc(start_capacity * sizeof(int));
  if((*vpp)->arr == NULL) {
    free(*vpp);
    return false;
  }
  (*vpp)->cap = start_capacity;
  (*vpp)->sz = 0;
  return true;
}

bool vector_destroy(vector** vpp) {
  if(!is_vpp_valid(vpp)) {
    return false;
  }
  free((*vpp)->arr);
  free(*vpp);
  *vpp = NULL;
  return true;
}

bool vector_size(vector* vp, int* szp) {
  if(!is_vp_valid(vp) || szp == NULL) {
    return false;
  }
  *szp = vp->sz;
  return true;
}

bool vector_capacity(vector* vp, int *capp) {
  if(!is_vp_valid(vp) || capp == NULL) {
    return false;
  }
  *capp = vp->cap;
  return true;
}

bool vector_isempty(vector* vp, bool* isemptyp) {
  if(!is_vp_valid(vp) || isemptyp == NULL) {
    return false;
  }
  *isemptyp = (vp->sz == 0);
  return true;
}

bool vector_get(vector* vp, int idx, int* valp) {
  if(!is_idx_valid(vp, idx) || valp == NULL) {
    return false;
  }
  *valp = vp->arr[idx];
  return true;
}

bool vector_pushback(vector** vpp, int val) {
  if(!is_vpp_valid(vpp)) {
    return false;
  }
  if((*vpp)->sz == (*vpp)->cap) {
    int sizeup = (*vpp)->cap * growth_factor;
    if(!vector_resize(vpp, sizeup)) {
      return false;
    }
  }
  int idx = (*vpp)->sz;
  (*vpp)->arr[idx] = val;
  (*vpp)->sz++;
  return true;
}

bool vector_resize(vector** vpp, int cap) {
  if(!is_vpp_valid(vpp)) {
    return false;
  }
  int* deleteme = (*vpp)->arr;
  (*vpp)->arr = (int*)malloc(cap * sizeof(int));
  if((*vpp)->arr == NULL) {
    return false;
  }
  int lhs = (*vpp)->sz;
  int rhs = cap;
  int sz = (lhs <= rhs) ? lhs : rhs;
  for(int i=0; i<sz; ++i) {
     (*vpp)->arr[i] = deleteme[i];
  }
  for(int i=sz; i<cap; ++i) {
     (*vpp)->arr[i] = 0;
  }
  (*vpp)->cap = cap;
  free(deleteme);
  return true;
}

bool vector_set(vector* vp, int idx, int val) {
  if(!is_idx_valid(vp, idx)) {
    return false;
  }
  vp->arr[idx] = val;
  return true;
}

void vector_print(vector* vp) {
  if(!is_vp_valid(vp)) {
    printf("Invalid vector!\n");
    return;
  }
  printf("vec: sz=%d, cap=%d, arr=", vp->sz, vp->cap);
  if(vp->sz == 0) {
    printf("Empty vector!\n");
    return;
  }
  for(int i=0; i<vp->sz; ++i) {
    if(i==0) {
      printf("|");
    }
    printf("%d|", vp->arr[i]);
  }
  printf("\n");
  return;
}

//int vector_size(vector* v) {
//  return (v == NULL) ? 0 : v->size;
//}
//
//bool vector_bounds(vector* v, int idx) {
//  return (v != NULL && idx >= 0 && idx < v->size);
//}
//
//int vector_get(vector* v, int idx) {
//  if (!vector_bounds(v, idx)) {
//    printf("Error: Out of bounds!\n");
//    exit(EXIT_FAILURE);
//  }
//  return v->arr[idx];
//}
//
//void vector_pushback(vector* v, int val) {
//  if (v == NULL) {
//    return;
//  }
//  if (v->size == v->capacity) {
//    int old_size = v->capacity * sizeof(int);
//    int new_size = old_size * growth_factor;
//    int* new_arr = (int*)malloc(new_size);
//    memcpy(new_arr, v->arr, old_size);
//    free(v->arr);
//    v->arr = new_arr;
//    v->capacity = v->capacity * growth_factor;
//  }
//  v->arr[v->size] = val;
//  v->size++;
//  return;
//}
//
//void vector_set(vector* v, int idx, int val) {
//  if (!vector_bounds(v, idx)) {
//    return;
//  }
//  v->arr[idx] = val;
//}
