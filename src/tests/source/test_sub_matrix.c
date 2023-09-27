#include "../proj_test.h"

START_TEST(sub_test_1) {
  matrix_t A, B, R, R2;
  proj_create_matrix(1, 1, &A);
  proj_create_matrix(1, 1, &B);
  proj_create_matrix(1, 1, &R2);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 2.25;

  R2.matrix[0][0] = -1;

  proj_sub_matrix(&A, &B, &R);

  ck_assert(fabs(R.matrix[0][0] - R2.matrix[0][0]) < 1e-7);

  proj_remove_matrix(&A);
  proj_remove_matrix(&B);
  proj_remove_matrix(&R);
  proj_remove_matrix(&R2);
}
END_TEST

START_TEST(sub_test_2) {
  matrix_t A, B, R, R2;
  proj_create_matrix(3, 3, &A);
  proj_create_matrix(3, 3, &B);
  proj_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  B.matrix[0][0] = 9.25;
  B.matrix[0][1] = 8.25;
  B.matrix[0][2] = 7.25;
  B.matrix[1][0] = 6.25;
  B.matrix[1][1] = 5.25;
  B.matrix[1][2] = 4.25;
  B.matrix[2][0] = 3.25;
  B.matrix[2][1] = 2.25;
  B.matrix[2][2] = 1.25;

  R2.matrix[0][0] = -9.0;
  R2.matrix[0][1] = -7.0;
  R2.matrix[0][2] = -5.0;
  R2.matrix[1][0] = -3.0;
  R2.matrix[1][1] = -1.0;
  R2.matrix[1][2] = 1.0;
  R2.matrix[2][0] = 3.0;
  R2.matrix[2][1] = 5.0;
  R2.matrix[2][2] = 7.0;

  proj_sub_matrix(&A, &B, &R);

  ck_assert_int_eq(proj_eq_matrix(&R, &R2), SUCCESS);
  proj_remove_matrix(&A);
  proj_remove_matrix(&B);
  proj_remove_matrix(&R);
  proj_remove_matrix(&R2);
}
END_TEST

START_TEST(sub_test_incorrect_matrix) {
  matrix_t A, B, R;
  proj_create_matrix(1, 1, &A);
  proj_create_matrix(2, 1, &B);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 2.25;

  int res = proj_sub_matrix(&A, &B, &R);

  ck_assert_int_eq(res, CALCULATION_ERROR);

  proj_remove_matrix(&A);
  proj_remove_matrix(&B);
}
END_TEST

START_TEST(null_sub) {
  matrix_t *A = NULL;
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = proj_sub_matrix(A, B, R);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite *test_sub_matrix() {
  Suite *s = suite_create("sub_matrix");
  TCase *tc = tcase_create("sub_matrix_tcase");

  tcase_add_test(tc, sub_test_1);
  tcase_add_test(tc, sub_test_2);
  tcase_add_test(tc, sub_test_incorrect_matrix);
  tcase_add_test(tc, null_sub);

  suite_add_tcase(s, tc);
  return s;
}
