#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "project.h"

// CONST =======================================================================

const int some_const = 0;


// IMPLS =======================================================================

void project_new() {
  return;
}


// TESTS =======================================================================

void test_project_new() {
  project_new();
  assert(some_const == 0);
}
