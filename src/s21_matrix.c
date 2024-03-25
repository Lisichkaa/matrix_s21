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

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = Error;

  if (A->columns != B->columns || A->rows != B->rows) {
    errorCode = CalcError;
  } else {
    errorCode = OK;
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
    }
  }

  return errorCode;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = Error;

  if (A->columns != B->columns || A->rows != B->rows) {
    errorCode = CalcError;
  } else {
    errorCode = OK;
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
    }
  }

  return errorCode;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int errorCode = Error;

  if (A != NULL || result != NULL) {
    errorCode = OK;
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return errorCode;
}

//The product of A = m × k by B = k × n is a matrix C = m × n = A × B of size m × n whose elements 
//are defined by the equation C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + ... + A(i,k) × B(k,j).
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = Error;

  if (A != NULL || B != NULL || result != NULL) {
    errorCode = OK;
    s21_create_matrix(A->rows, B->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][k] * B->matrix[k][j];
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

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int errorCode = Error;

  if (A->rows != A->columns) {
    errorCode = CalcError;
  } else if (A != NULL || result != NULL){
    int errorCode = OK;
    s21_create_matrix(A->columns, A->rows, result);

    if (A->rows == 1 && A->columns == 1) {
      result->matrix[0][0] = 1;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          //result->matrix[i][j] = calc_algebraic_addition(i, j, A);
        }
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