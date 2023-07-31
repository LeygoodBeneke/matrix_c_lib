#include "s21_matrix.h"
#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int flag = OK;
    if (rows <= 0 || columns <= 0)
        flag = INCORRECT_MATRIX;
    else {
        result->rows = columns;
        result->columns = columns;
        result->matrix = calloc(rows, sizeof(double*));
        for (unsigned int i = 0; i < rows; i++)
            result->matrix[i] = (double*)calloc(columns, sizeof(double));
    }
    return flag;
}

void s21_remove_matrix(matrix_t *A) {
    for (unsigned int i = 0; i < A->rows; i++)
        free(A->matrix[i]);
    free(A->matrix);
    A->rows = A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int flag = is_matrix_size_equal(A, B);
    if (flag == SUCCESS) {
        unsigned int i = 0, j = 0, idx = 0;
        while (i < A->rows && double_equal(A->matrix[i][j], B->matrix[i][j])) {
            idx++;
            i = idx / A->columns;
            j = idx % A->columns;
        }
        if (i < A->rows) flag = FAILURE;
    }
    return flag;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = is_incorrect_matrix(A) || is_incorrect_matrix(B);
    if (flag == OK)
        flag = !is_matrix_size_equal(A, B) ? CALCULATION_ERROR : 0;
    if (flag == OK) {
        s21_create_matrix(A->rows, A->columns, result);
        for (unsigned int i = 0; i < A->rows; i++)
            for (unsigned int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
    return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = is_incorrect_matrix(B);
    if (flag == OK) {
        for (unsigned int i = 0; i < B->rows; i++)
            for (unsigned int j = 0; j < B->columns; j++)
                B->matrix[i][j] *= -1.0;
        flag = s21_sum_matrix(A, B, result);
    }
    return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int flag = is_incorrect_matrix(A);
    if (flag == OK) {
        s21_create_matrix(A->rows, A->columns, result);
        for (unsigned int i = 0; i < A->rows; i++)
            for (unsigned int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] * number;
    }
    return flag;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = is_incorrect_matrix(A) || is_incorrect_matrix(B);
    if (flag == OK)
        flag = A->columns != B->rows ? CALCULATION_ERROR : 0;
    if (flag == OK) {
        s21_create_matrix(A->rows, B->columns, result);
        for (unsigned int i = 0; i < A->rows; i++)
            for (unsigned int j = 0; j < B->columns; j++)
                for (unsigned int l = 0; l < A->columns; l++)
                    result->matrix[i][j] += A->matrix[i][l] * B->matrix[l][j];
    }
    return flag;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
    int flag = is_incorrect_matrix(A);
    if (flag == OK) {
        s21_create_matrix(A->columns, A->rows, result);
        for (unsigned int i = 0; i < A->rows; i++)
            for (unsigned int j = 0; j < A->columns; j++)
                result->matrix[j][i] += A->matrix[i][j];
    }
    return flag;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    return 0;
}

int s21_determinant(matrix_t *A, double *result) {
    return 0;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    return 0;
}

int double_equal(double first, double second) {
    return fabs(first - second) <= 1e-7;
}

int is_incorrect_matrix(matrix_t *A) {
    return A->rows <= 0 || A->columns <=0;
}

int is_matrix_size_equal(matrix_t *A, matrix_t *B) {
    return (A->columns == B->columns) && (A->rows == B->rows);
}
