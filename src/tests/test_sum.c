#include "test.h"

START_TEST(test_s21_sum_matrix_1) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1;
      B.matrix[i][j] = 1;
      reference.matrix[i][j] = 2;
    }
  }

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_sum_matrix_2) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
      B.matrix[i][j] = j;
      reference.matrix[i][j] = i + j;
    }
  }

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_sum_matrix_3) {
  matrix_t A, B;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  response = s21_sum_matrix(&A, &B, NULL);

  ck_assert_int_eq(response, Error);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_4) {
  matrix_t A, B, result;
  int response = 0;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 3, &B);

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, CalcError);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
}
END_TEST

START_TEST(test_s21_sum_matrix_5) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &reference);

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&reference);
  s21_free_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_6) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  s21_create_matrix(10, 10, &reference);

  double k = -1.0;
  double n = 1.0;

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      B.matrix[i][j] = n;
      reference.matrix[i][j] = k + n;
      k *= 0.00123;
      n /= 0.00123;
    }
  }

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_sum_matrix_7) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  s21_create_matrix(10, 10, &reference);

  double k = -1.0;

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 0;
      B.matrix[i][j] = k;
      reference.matrix[i][j] = k;
      k *= 0.00123;
    }
  }

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_sum_matrix_8) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  s21_create_matrix(10, 10, &reference);

  double k = -187.817346;
  double n = 5.13980465;

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      B.matrix[i][j] = n;
      reference.matrix[i][j] = k + n;
      k *= 0.001232456;
      n /= 0.001230948576;
    }
  }

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_sum_matrix_9) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      B.matrix[i][j] = 1;
      reference.matrix[i][j] = 1;
    }
  }

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_sum_matrix_10) {
  matrix_t A, B, result;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  response = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
}
END_TEST

Suite *s21_s21_sum_matrix(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sum_matrix");

  /* Core test case */
  tc_core = tcase_create("test_s21_sum_matrix");

  tcase_add_test(tc_core, test_s21_sum_matrix_1);
  tcase_add_test(tc_core, test_s21_sum_matrix_2);
  tcase_add_test(tc_core, test_s21_sum_matrix_3);
  tcase_add_test(tc_core, test_s21_sum_matrix_4);
  tcase_add_test(tc_core, test_s21_sum_matrix_5);
  tcase_add_test(tc_core, test_s21_sum_matrix_6);
  tcase_add_test(tc_core, test_s21_sum_matrix_7);
  tcase_add_test(tc_core, test_s21_sum_matrix_8);
  tcase_add_test(tc_core, test_s21_sum_matrix_9);
  tcase_add_test(tc_core, test_s21_sum_matrix_10);

  suite_add_tcase(s, tc_core);

  return s;
}
