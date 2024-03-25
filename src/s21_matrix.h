#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 0.0000001

typedef struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

enum ErrorCode{
    OK, 
    Error,  // incorrect matrix
    CalcError  // mismatched matrix sizes; matrix for which calculations cannot be performed, etc.
};

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void allocate_memory(int rows, int columns, double** matrix);

#endif  //S21_MATRIX_H
