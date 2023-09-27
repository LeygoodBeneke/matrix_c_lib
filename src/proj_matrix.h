#include <stdlib.h>
#include <math.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int proj_create_matrix(int rows, int columns, matrix_t *result);
void proj_remove_matrix(matrix_t *A);
int proj_eq_matrix(matrix_t *A, matrix_t *B);
int proj_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int proj_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int proj_mult_number(matrix_t *A, double number, matrix_t *result);
int proj_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int proj_transpose(matrix_t *A, matrix_t *result);
int proj_calc_complements(matrix_t *A, matrix_t *result);
int proj_determinant(matrix_t *A, double *result);
int proj_inverse_matrix(matrix_t *A, matrix_t *result);

int double_equal(double first, double second);
int is_incorrect_matrix(const matrix_t *A);
int is_matrix_size_equal(const matrix_t *A, const matrix_t *B);
