#include "test.h"

START_TEST(test_s21_transpose_1) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &reference);

  double n[3][2] = {{1.0, 4.0}, {2.0, 5.0}, {3.0, 6.0}};
  double r[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  for (int i = 0; i < reference.rows; i++) {
    for (int j = 0; j < reference.columns; j++) {
      reference.matrix[i][j] = r[i][j];
    }
  }

  response = s21_transpose(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  matrix_t A;
  int response = 0;

  s21_create_matrix(2, 2, &A);

  response = s21_transpose(&A, NULL);

  ck_assert_int_eq(response, Error);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_transpose_3) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(5, 2, &A);
  s21_create_matrix(2, 5, &reference);

  double n[5][2] = {{1.0, 4.0}, {2.0, 5.0}, {3.0, 6.0}, {2.0, 5.0}, {3.0, 6.0}};
  double r[2][5] = {{1.0, 2.0, 3.0, 2.0, 3.0}, {4.0, 5.0, 6.0, 5.0, 6.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  for (int i = 0; i < reference.rows; i++) {
    for (int j = 0; j < reference.columns; j++) {
      reference.matrix[i][j] = r[i][j];
    }
  }

  response = s21_transpose(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

Suite *s21_s21_transpose(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_transpose");

  /* Core test case */
  tc_core = tcase_create("test_s21_transpose");

  tcase_add_test(tc_core, test_s21_transpose_1);
  tcase_add_test(tc_core, test_s21_transpose_2);
  tcase_add_test(tc_core, test_s21_transpose_3);

  suite_add_tcase(s, tc_core);

  return s;
}
