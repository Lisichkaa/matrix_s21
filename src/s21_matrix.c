#include "s21_matrix.h"
#include <math.h>

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int errorCode = Error;

  if (result != NULL && rows > 0 && columns > 0) {
    errorCode = OK;
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(result->rows, sizeof(double *));
    for (int i = 0; i < result->rows; i++) {
      result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
    }
  }

  return errorCode;
}

// void free_matrix(int *matrix, int rows) {
//   for (int i = 0; i < rows; i++) {
//     free(matrix[i]);
//   }
//   free(matrix);
// }
void copy_matrix(matrix_t *source, matrix_t *dist) {
  s21_create_matrix(source->rows, source->columns, dist);
  for (int i = 0; i < dist->rows; i++) {
    for (int j = 0; j < dist->columns; j++) {
      dist->matrix[i][j] = source->matrix[i][j];
    }
  }
}

void s21_free_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
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
        if (fabs(diff) >= EPSILON && A->matrix[i][j] != -0) {
          errorCode = FAILURE;
        }
      }
    }
  }

  return errorCode;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = OK;

  if (A == NULL || B == NULL || result == NULL) {
    errorCode = Error;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    errorCode = CalcError;
  } else {
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
  int errorCode = OK;

  if (A == NULL || B == NULL || result == NULL) {
    errorCode = Error;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    errorCode = CalcError;
  } else {
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

  if (A != NULL && result != NULL) {
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

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int errorCode = OK;

  if (A == NULL || B == NULL || result == NULL) {
    errorCode = Error;
  } else if (A->columns != B->rows) {
    errorCode = CalcError;
  } else {
    s21_create_matrix(A->rows, B->columns, result);

    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return errorCode;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int errorCode = Error;

  if (A != NULL && result != NULL) {
    errorCode = OK;
    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < result->rows; ++i) {
      for (int j = 0; j < result->columns; ++j) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return errorCode;
}

double get_minor(int row, int column, matrix_t *A) {
  matrix_t result;
  s21_create_matrix(A->columns - 1, A->rows - 1, &result);

  int a = 0;
  int b = 0;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i != row && j != column) {
        result.matrix[a][b] = A->matrix[i][j];
        b++;
      }
    }
    if (i != row) {
      a++;
      b = 0;
    }
  }

  double d = 0;
  s21_determinant(&result, &d);

  s21_free_matrix(&result);
  return d;
}

double algebraic_addition(int row, int column, matrix_t *A) {
  return ((row + column) & 1 ? -1 : 1) * get_minor(row, column, A);
}

int s21_addition(matrix_t *A, matrix_t *result) {
  int errorCode = OK;

  if (A == NULL || result == NULL) {
    errorCode = Error;
  } else if (A->rows != A->columns) {
    errorCode = CalcError;
  } else {
    s21_create_matrix(A->columns, A->rows, result);

    if (A->rows == 1 && A->columns == 1) {
      result->matrix[0][0] = 1;
    } else {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = algebraic_addition(i, j, A);
        }
      }
    }
  }

  return errorCode;
}

int s21_determinant(matrix_t *A, double *result) {
  int errorCode = OK;

  if (A == NULL || result == NULL) {
    errorCode = Error;
  } else if (A->rows != A->columns) {
    errorCode = CalcError;
  } else {
    errorCode = OK;
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      matrix_t temp;
      copy_matrix(A, &temp);
      int sign = 1;

      for (int i = 1; i < temp.rows; i++) {
        for (int j = i; j < temp.columns; j++) {
          double *basis = malloc(sizeof(double) * temp.columns);
          for (int k = 0; k < temp.columns; k++) {
            basis[k] = temp.matrix[i - 1][k];
          }

          if (basis[i - 1] == 0) {
            for (int k = 0; k < temp.columns; k++) {
              temp.matrix[i - 1][k] = temp.matrix[i][k];
              temp.matrix[i][k] = basis[k];
            }
            sign *= -1;
            free(basis);
            continue;
          }

          double factor = temp.matrix[j][i - 1] / basis[i - 1];

          for (int k = 0; k < temp.columns; k++) {
            basis[k] *= factor;
            temp.matrix[j][k] -= basis[k];
          }
          free(basis);
        }
      }

      *result = 1;

      for (int k = 0; k < temp.columns; k++) {
        *result *= temp.matrix[k][k];
      }

      *result *= sign;
      s21_free_matrix(&temp);
    }
  }

  return errorCode;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int errorCode = OK;

  if (A == NULL || result == NULL) {
    errorCode = Error;
  } else if (A->rows != A->columns) {
    errorCode = CalcError;
  } else {
    double determinant;
    s21_determinant(A, &determinant);

    if (determinant != 0) {
      matrix_t buff;

      s21_addition(A, result);
      s21_transpose(result, &buff);
      s21_free_matrix(result);
      s21_mult_number(&buff, 1 / determinant, result);
      s21_free_matrix(&buff);
    } else {
      errorCode = CalcError;
    }
  }

  return errorCode;
}