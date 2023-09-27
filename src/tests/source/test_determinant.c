#include "../proj_test.h"

START_TEST(determinant_test_1) {
  matrix_t A;
  double B, R = 1.25;
  proj_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.25;

  proj_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_2) {
  matrix_t A;
  double B, R = -69;
  proj_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  proj_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);

  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_3x3_1) {
  matrix_t A;
  double B, R = -2;
  proj_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = -5;
  A.matrix[1][1] = -7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = -6;

  proj_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_3x3_2) {
  matrix_t A;
  double B, R = 25;
  proj_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = -6;

  proj_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_3x3_3) {
  matrix_t A;
  double B, R = 23;
  proj_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = -6;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = -6;

  proj_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_3x3_4) {
  matrix_t A;
  double B, R = -8;
  proj_create_matrix(3, 3, &A);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = -5;
  A.matrix[1][2] = -7;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 5;

  proj_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_4x4) {
  matrix_t A;
  double B, R = 18;
  proj_create_matrix(4, 4, &A);

  A.matrix[0][0] = 3;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = -5;
  A.matrix[0][3] = 8;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = -6;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = -5;
  A.matrix[2][2] = -7;
  A.matrix[2][3] = 5;
  A.matrix[3][0] = -4;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = -6;

  proj_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_5x5) {
  matrix_t A;
  double B, R = -69.0 / 4.0;
  proj_create_matrix(5, 5, &A);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[0][3] = 3.25;
  A.matrix[0][4] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[1][3] = 5.25;
  A.matrix[1][4] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;
  A.matrix[2][3] = 6.25;
  A.matrix[2][4] = 6.25;
  A.matrix[3][0] = 6.25;
  A.matrix[3][1] = 7.25;
  A.matrix[3][2] = 8.25;
  A.matrix[3][3] = 6.25;
  A.matrix[3][4] = 7.25;
  A.matrix[4][0] = 6.25;
  A.matrix[4][1] = 7.25;
  A.matrix[4][2] = 8.25;
  A.matrix[4][3] = 6;
  A.matrix[4][4] = 8.25;

  proj_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_not_square) {
  matrix_t A;
  double B;
  proj_create_matrix(4, 5, &A);
  int res = proj_determinant(&A, &B);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  proj_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_4x4_2) {
  matrix_t a;
  double number;
  proj_create_matrix(4, 4, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[0][3] = 13;
  a.matrix[1][0] = 4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 6;
  a.matrix[1][3] = 16;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 8;
  a.matrix[2][2] = 90;
  a.matrix[2][3] = 19;
  a.matrix[3][0] = 1;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = 7;
  a.matrix[3][3] = 17;

  proj_determinant(&a, &number);
  ck_assert_int_eq(number, 13608);
  proj_remove_matrix(&a);
}
END_TEST

START_TEST(null_determinate) {
  matrix_t *B = NULL;
  double re = 0;
  int res = proj_determinant(B, &re);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite *test_determinant() {
  Suite *s = suite_create("determinant");
  TCase *tc = tcase_create("determinant_tcase");

  tcase_add_test(tc, determinant_test_1);  // determinant
  tcase_add_test(tc, determinant_test_2);
  tcase_add_test(tc, determinant_test_3x3_1);
  tcase_add_test(tc, determinant_test_3x3_2);
  tcase_add_test(tc, determinant_test_3x3_3);
  tcase_add_test(tc, determinant_test_3x3_4);
  tcase_add_test(tc, determinant_test_4x4);
  tcase_add_test(tc, determinant_test_4x4_2);
  tcase_add_test(tc, determinant_test_5x5);
  tcase_add_test(tc, determinant_not_square);
  tcase_add_test(tc, null_determinate);

  suite_add_tcase(s, tc);
  return s;
}
