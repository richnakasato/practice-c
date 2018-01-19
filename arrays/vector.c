// vector implementation

Vector* new_vector() {
  Vector* vec = (Vector*)malloc(sizeof(Vector));
  vec->arr = (int*)malloc(init_capacity * sizeof(int));
  vec->capacity = init_capacity;
  vec->size = 0;
  return vec;
}

void destroy_vector(Vector* vec) {
  if (vec != NULL) {
    if (vec->arr != NULL) {
      free(vec->arr);
    }
    free(vec);
  }
  return;
}

bool inbounds(Vector* vec, int idx) {
  return (idx >= 0 && idx < vec->size)
}

// not sure how to handle out of bounds return value
int get(Vector* vec, int idx) {
  if (!inbounds(vec, idx)) {
    return -1; // ERROR
  }
  return vec->arr[idx];
}

int set(Vector* vec, int idx, int val) {
  if (!inbounds(vec, idx)) {
    return -1; // ERROR
  }
  vec->arr[idx] = val;
  return 0;
}

void pushback(Vector* vec, int val) {
  if (!inbounds(vec, idx)) {
    return;
  }
  // only works if sizing is fine...
  vec->arr[vec->size] = val;

}
