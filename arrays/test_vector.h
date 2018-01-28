#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include "vector.h"

void run_all_tests();

void test_can_create_vector();

void test_created_vector_has_size_zero();

void test_created_vector_has_capacity();

void test_destroy_vector_invalidates();

void test_cant_destroy_null_vector();

void test_cant_get_size_of_null_vector();

void test_cant_get_size_with_null_arg();

void test_can_get_size_of_new_vector();

void test_can_set_valid_idx_in_vector();

void test_cant_set_invalid_idx_in_vector();


void test_vector_size();

void test_vector_capacity();

void test_vector_isempty();

//void test_vector_get();

void test_vector_pushback();

#endif // TEST_VECTOR_H
