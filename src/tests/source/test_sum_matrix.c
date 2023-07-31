#include "../s21_test.h"

START_TEST(sum_matrix_1) {
	matrix_t matrix_1 = {}, matrix_2 = {}, result = {};
	int rows = 10, cols = 10;
	int r_value = s21_create_matrix(rows, cols, &matrix_1) + s21_create_matrix(rows, cols, &matrix_2);
	FOR(rows, cols) {
		matrix_1.matrix[i][j] = i + j;
		matrix_2.matrix[i][j] = i + j;
	}
	ck_assert_int_eq(r_value, 0);
	ck_assert_int_eq(s21_sum_matrix(&matrix_1, &matrix_2, &result), 1);
	FOR(rows, cols) {
		ck_assert_int_eq(result.matrix[i][j], i + j + i + j);
	}
	s21_remove_matrix(&matrix_1);
	s21_remove_matrix(&matrix_2);
	s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_2) {
	matrix_t matrix_1 = {}, matrix_2 = {}, result = {};
	int rows = 10, cols = 10;
	int r_value = s21_create_matrix(rows, cols, &matrix_1) + s21_create_matrix(rows, cols, &matrix_2);
	FOR(rows, cols) {
		matrix_1.matrix[i][j] = i + j;
		matrix_2.matrix[i][j] = i * j;
	}
	ck_assert_int_eq(r_value, 0);
	ck_assert_int_eq(s21_sum_matrix(&matrix_1, &matrix_2, &result), 0);
	FOR(rows, cols) {
		ck_assert_int_eq(result.matrix[i][j], i + j + i * j);
	}
	s21_remove_matrix(&matrix_1);
	s21_remove_matrix(&matrix_2);
	s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_3) {
	matrix_t matrix_1 = {}, matrix_2 = {}, result = {};
	int rows = 10, cols = 10;
	int r_value = s21_create_matrix(rows, cols, &matrix_1) + s21_create_matrix(rows, cols + 1, &matrix_2);
	FOR(rows, cols) {
		matrix_1.matrix[i][j] = i + j;
		matrix_2.matrix[i][j] = i * j;
	}
	ck_assert_int_eq(r_value, 0);
	ck_assert_int_eq(s21_sum_matrix(&matrix_1, &matrix_2, &result), 1);
	s21_remove_matrix(&matrix_1);
	s21_remove_matrix(&matrix_2);
	s21_remove_matrix(&result);
}
END_TEST

Suite *test_sum_matrix() {
  Suite *s = suite_create("sum_matrix");
  TCase *tc = tcase_create("sum_matrix_tcase");

  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2);
  tcase_add_test(tc, sum_matrix_3);

  suite_add_tcase(s, tc);
  return s;
}

