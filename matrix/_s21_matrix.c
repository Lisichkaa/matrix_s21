#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int response = 0;

  if (result != NULL && rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **)calloc(result->rows, sizeof(double *));
    for (int i = 0; i < result->rows; i++) {
      result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
    }

  } else {
    response = 1;
  }

  return response;
}

void s21_remove_matrix(matrix_t *A) {
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
  int response = SUCCESS;

  if (A == NULL || B == NULL || A->columns != B->columns ||
      A->rows != B->rows) {
    response = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 0.0000001 &&
            A->matrix[i][j] != -0) {
          response = FAILURE;
        }
      }
    }
  }

  return response;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int response = OK;

  if (A == NULL || B == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    response = CALC_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return response;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int response = OK;

  if (A == NULL || B == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    response = CALC_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return response;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int response = OK;

  if (A == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else {
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return response;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int response = OK;

  if (A == NULL || B == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    response = CALC_ERROR;
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

  return response;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int response = OK;

  if (A == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else {
    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return response;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int response = OK;

  if (A == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    response = CALC_ERROR;
  } else {
    s21_create_matrix(A->columns, A->rows, result);

    if (A->rows == 1 && A->columns == 1) {
      result->matrix[0][0] = 1;
    } else {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = calc_algebraic_addition(i, j, A);
        }
      }
    }
  }

  return response;
}

void copy_matrix(matrix_t *source, matrix_t *dist) {
  s21_create_matrix(source->rows, source->columns, dist);
  for (int i = 0; i < dist->rows; i++) {
    for (int j = 0; j < dist->columns; j++) {
      dist->matrix[i][j] = source->matrix[i][j];
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int response = OK;

  if (A == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    response = CALC_ERROR;
  } else {
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
          double *matrixStroke = malloc(sizeof(double) * temp.columns);
          for (int k = 0; k < temp.columns; k++) {
            matrixStroke[k] = temp.matrix[i - 1][k];
          }

          if (matrixStroke[i - 1] == 0) {
            for (int k = 0; k < temp.columns; k++) {
              temp.matrix[i - 1][k] = temp.matrix[i][k];
              temp.matrix[i][k] = matrixStroke[k];
            }
            sign *= -1;
            free(matrixStroke);
            continue;
          }

          double fact = temp.matrix[j][i - 1] / matrixStroke[i - 1];

          for (int k = 0; k < temp.columns; k++) {
            matrixStroke[k] *= fact;
            temp.matrix[j][k] -= matrixStroke[k];
          }

          free(matrixStroke);
        }
      }

      *result = 1;

      for (int k = 0; k < temp.columns; k++) {
        *result *= temp.matrix[k][k];
      }

      *result *= sign;
      s21_remove_matrix(&temp);
    }
  }

  return response;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int response = OK;

  if (A == NULL || result == NULL) {
    response = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    response = CALC_ERROR;
  } else {
    double D;
    s21_determinant(A, &D);

    if (D != 0) {
      matrix_t temp;

      s21_calc_complements(A, result);
      s21_transpose(result, &temp);
      s21_remove_matrix(result);
      s21_mult_number(&temp, 1 / D, result);
      s21_remove_matrix(&temp);
    } else {
      response = CALC_ERROR;
    }
  }

  return response;
}

double calc_algebraic_addition(int row, int column, matrix_t *A) {
  return ((row + column) & 1 ? -1 : 1) * get_minor(row, column, A);
}

double get_minor(int row, int column, matrix_t *A) {
  matrix_t result;
  s21_create_matrix(A->columns - 1, A->rows - 1, &result);

  int a = 0, b = 0;

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

  s21_remove_matrix(&result);
  return d;
}