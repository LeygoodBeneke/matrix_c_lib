#include "../proj_test.h"

START_TEST(create_matrix_1) {
  matrix_t matrix = {};
  int rows = 10, cols = 10;
  int r_value = proj_create_matrix(rows, cols, &matrix);
  FOR(rows, cols)
  ck_assert_float_eq_tol(matrix.matrix[i][j], 0.0, 1e-7);
  ck_assert_int_eq(r_value, 0);
  proj_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t matrix = {};
  int r_value = proj_create_matrix(-3, 3, &matrix);
  ck_assert_int_eq(r_value, 1);
  proj_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t matrix = {};
  int r_value = proj_create_matrix(3, -3, &matrix);
  ck_assert_int_eq(r_value, 1);
  proj_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_4) {
  matrix_t matrix = {};
  int r_value = proj_create_matrix(-3, -3, &matrix);
  ck_assert_int_eq(r_value, 1);
  proj_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_5) {
  matrix_t matrix = {};
  int r_value = proj_create_matrix(0, 0, &matrix);
  ck_assert_int_eq(r_value, 1);
  proj_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_6) {
  matrix_t matrix = {};
  int rows = 50, cols = 50;
  int r_value = proj_create_matrix(rows, cols, &matrix);
  FOR(rows, cols)
  ck_assert_float_eq_tol(matrix.matrix[i][j], 0.0, 1e-7);
  ck_assert_int_eq(r_value, 0);
  proj_remove_matrix(&matrix);
}
END_TEST

Suite *test_create_matrix() {
  Suite *s = suite_create("create_matrix");
  TCase *tc = tcase_create("create_matrix_tcase");

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  tcase_add_test(tc, create_matrix_5);
  tcase_add_test(tc, create_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}
