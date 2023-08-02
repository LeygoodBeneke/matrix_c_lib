#ifndef SRC_S21_TEST_H
#define SRC_S21_TEST_H

#define FOR(i_max, j_max) \
	for (int i = 0; i < i_max; i++) \
		for (int j = 0; j < j_max; j++) \

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../s21_matrix.h"

Suite *test_create_matrix();
Suite *test_remove_matrix();
Suite *test_eq_matrix();
Suite *test_sum_matrix();
Suite *test_sub_matrix();
Suite *test_mult_number();
Suite *test_mult_matrix();
Suite *test_transpose();
Suite *test_calc_complements();
Suite *test_determinant();
Suite *test_inverse_matrix();

#endif

