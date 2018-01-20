#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

int main() {
  vector* my_vector = vector_new();
  printf("vector size: %d\n", my_vector->size);
  printf("vector capacity: %d\n", my_vector->capacity);

  vector_destroy(my_vector);
  my_vector = NULL;

  run_all_tests();
}
