#include "../proj_test.h"

START_TEST(transpose_test_1) {
  matrix_t A, B, R;
  proj_create_matrix(1, 1, &A);
  proj_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 1.25;

  proj_transpose(&A, &R);
  ck_assert_int_eq(proj_eq_matrix(&R, &B), SUCCESS);
  proj_remove_matrix(&A);
  proj_remove_matrix(&B);
  proj_remove_matrix(&R);
}

END_TEST

START_TEST(transpose_test_2) {
  matrix_t A, B, R;
  proj_create_matrix(3, 3, &A);
  proj_create_matrix(3, 3, &B);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  proj_transpose(&A, &R);

  B.matrix[0][0] = 0.25;
  B.matrix[1][0] = 1.25;
  B.matrix[2][0] = 2.25;
  B.matrix[0][1] = 3.25;
  B.matrix[1][1] = 4.25;
  B.matrix[2][1] = 5.25;
  B.matrix[0][2] = 6.25;
  B.matrix[1][2] = 7.25;
  B.matrix[2][2] = 8.25;

  ck_assert_int_eq(proj_eq_matrix(&R, &B), SUCCESS);
  proj_remove_matrix(&A);
  proj_remove_matrix(&B);
  proj_remove_matrix(&R);
}

END_TEST

START_TEST(transpose_incorrect) {
  matrix_t A, B;
  proj_create_matrix(1, 1, &A);
  proj_create_matrix(1, 1, &B);
  A.columns = -1;

  int ret = proj_transpose(&A, &B);
  ck_assert_int_eq(ret, INCORRECT_MATRIX);
  proj_remove_matrix(&A);
  proj_remove_matrix(&B);
}

END_TEST

START_TEST(null_transpose) {
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = proj_transpose(B, R);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite *test_transpose() {
  Suite *s = suite_create("transpose");
  TCase *tc = tcase_create("transpose_tcase");

  tcase_add_test(tc, transpose_test_1);
  tcase_add_test(tc, transpose_test_2);
  tcase_add_test(tc, transpose_incorrect);
  tcase_add_test(tc, null_transpose);

  suite_add_tcase(s, tc);
  return s;
}
