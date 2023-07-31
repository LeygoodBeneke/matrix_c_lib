#include "../s21_test.h"

START_TEST(create_matrix_1) {
	matrix_t *matrix = NULL;
	s21_create_matrix(3, 3, matrix);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ck_assert_float_eq_tol(matrix->matrix[i][j], 0.0, 1e-7);
	s21_remove_matrix(matrix);
}
END_TEST

Suite *test_create_matrix() {
  Suite *s = suite_create("create_matrix");
  TCase *tc = tcase_create("create_matrix_tcase");

  tcase_add_test(tc, create_matrix_1);

  suite_add_tcase(s, tc);
  return s;
}

