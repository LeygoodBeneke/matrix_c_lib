#include "../s21_test.h"

START_TEST(incorrect_matrix_1) {
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  s21_create_matrix(5, 5, &m1);
  s21_create_matrix(6, 6, &m2);

  matrix_t result = {0};
  int mul_code = s21_mult_matrix(&m1, &m2, &result);
  ck_assert_int_eq(mul_code, CALCULATION_ERROR);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(incorrect_matrix_2) {
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  s21_create_matrix(5, 5, &m1);
  s21_create_matrix(6, 6, &m2);
  m1.columns = -100;

  matrix_t result = {0};
  int mul_code = s21_mult_matrix(&m1, &m2, &result);
  ck_assert_int_eq(mul_code, INCORRECT_MATRIX);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test_1) {
  matrix_t A, B, R, R2;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &R2);

  A.matrix[0][0] = -1;
  B.matrix[0][0] = 2;

  R2.matrix[0][0] = -2;

  s21_mult_matrix(&A, &B, &R);

  ck_assert(fabs(R.matrix[0][0] - R2.matrix[0][0]) < 1e-7);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}

END_TEST

START_TEST(mult_matrix_test_2) {
  matrix_t A, B, R, R2;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 4;

  R2.matrix[0][0] = 6;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 4;
  R2.matrix[1][0] = 51;
  R2.matrix[1][1] = 44;
  R2.matrix[1][2] = 37;
  R2.matrix[2][0] = 96;
  R2.matrix[2][1] = 83;
  R2.matrix[2][2] = 70;

  s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}

END_TEST

START_TEST(mult_matrix_test_3) {
  matrix_t A, B, R, R2;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 4, &B);
  s21_create_matrix(3, 4, &R2);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 7;
  B.matrix[0][3] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 4;
  B.matrix[1][3] = 7;

  R2.matrix[0][0] = 6;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 4;
  R2.matrix[0][3] = 7;
  R2.matrix[1][0] = 51;
  R2.matrix[1][1] = 44;
  R2.matrix[1][2] = 37;
  R2.matrix[1][3] = 49;
  R2.matrix[2][0] = 96;
  R2.matrix[2][1] = 83;
  R2.matrix[2][2] = 70;
  R2.matrix[2][3] = 91;

  s21_mult_matrix(&A, &B, &R);

  ck_assert_int_eq(s21_eq_matrix(&R, &R2), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}

END_TEST

START_TEST(null_mult_mat) {
  matrix_t *A = NULL;
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = s21_mult_matrix(A, B, R);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}

END_TEST
Suite *test_mult_matrix() {
  Suite *s = suite_create("mult_matrix");
  TCase *tc = tcase_create("mult_matrix_tcase");

  tcase_add_test(tc, incorrect_matrix_1);  // mult_matrix
  tcase_add_test(tc, incorrect_matrix_2);
  tcase_add_test(tc, mult_matrix_test_1);
  tcase_add_test(tc, mult_matrix_test_2);
  tcase_add_test(tc, mult_matrix_test_3);
  tcase_add_test(tc, null_mult_mat);

  suite_add_tcase(s, tc);
  return s;
}
