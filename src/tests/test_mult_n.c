#include "test.h"

START_TEST(test_s21_mult_n_1) {
  matrix_t A, result, reference;
  int response = 0;
  int n = 5;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1;
      reference.matrix[i][j] = 5;
    }
  }

  response = s21_mult_number(&A, n, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_mult_n_2) {
  matrix_t A, result, reference;
  int response = 0;
  int n = 5.98374265765;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      reference.matrix[i][j] = i * n;
    }
  }

  response = s21_mult_number(&A, n, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_mult_n_3) {
  matrix_t A;
  int response = 0;
  int n = 5.98374265;

  s21_create_matrix(3, 3, &A);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }

  response = s21_mult_number(&A, n, NULL);

  ck_assert_int_eq(response, Error);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_n_4) {
  matrix_t A, result, reference;
  int response = 0;
  int n = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }

  response = s21_mult_number(&A, n, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_mult_n_5) {
  matrix_t A, result, reference;
  int response = 0;
  int n = 0.0000009;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      reference.matrix[i][j] = i * n;
    }
  }

  response = s21_mult_number(&A, n, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

Suite *s21_s21_mult_number(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_mult_number");

  /* Core test case */
  tc_core = tcase_create("test_s21_mult_number");

  tcase_add_test(tc_core, test_s21_mult_n_1);
  tcase_add_test(tc_core, test_s21_mult_n_2);
  tcase_add_test(tc_core, test_s21_mult_n_3);
  tcase_add_test(tc_core, test_s21_mult_n_4);

  suite_add_tcase(s, tc_core);

  return s;
}
