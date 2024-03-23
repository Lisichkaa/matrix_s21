#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int errorCode = Error;

  if (result != NULL && rows > 0 && columns > 0) {
    errorCode = OK;
    result->rows = rows;
    result->columns = columns;
    // result->matrix = allocate_memory(rows, columns, result->matrix);
    allocate_memory(rows, columns, result->matrix);
  }

  return errorCode;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      free_matrix(A->matrix, A->rows);
      // for (int i = 0; i < A->rows; i++) {
      //     free(A->matrix[i]);
      // }
    }
    // free(A->matrix);
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int errorCode = FAILURE;

  if (A != NULL && B != NULL && A->rows == B->rows &&
      A->columns == B->columns) {
    errorCode = SUCCESS;
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        double diff = A->matrix[i][j] - B->matrix[i][j];
        if (fabs(diff) >= EPSILON) {
            errorCode = FAILURE;
        }
      }
    }
  }

  return errorCode;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int errorCode = Error;
  
  if(A != NULL && result != NULL) {
    errorCode = 
    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            result->matrix[i][j] = A->matrix[j][i];
        }
    }
  }

  return errorCode;
}


void free_matrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// double **
void allocate_memory(int rows, int columns, double **matrix) {
  matrix = (double **)malloc(rows * sizeof(double *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (double *)malloc(columns * sizeof(double *));
  }
  // return matrix;
}