#include "test.h"

START_TEST(test_s21_mult_matrix_1) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &reference);

  double n[3][2] = {{1.0, 4.0}, {2.0, 5.0}, {3.0, 6.0}};
  double m[2][3] = {{1.0, -1.0, 1.0}, {2.0, 3.0, 4.0}};
  double r[3][3] = {{9.0, 11.0, 17.0}, {12.0, 13.0, 22.0}, {15.0, 15.0, 27.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = m[i][j];
    }
  }

  for (int i = 0; i < reference.rows; i++) {
    for (int j = 0; j < reference.columns; j++) {
      reference.matrix[i][j] = r[i][j];
    }
  }

  response = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t A, B, result;
  int response = 0;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 4, &B);

  response = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(response, CalcError);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t A, B, result;
  int response = 0;

  s21_create_matrix(2, 2, &A);

  response = s21_mult_matrix(&A, NULL, &result);

  ck_assert_int_eq(response, Error);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_matrix_4) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(4, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(4, 2, &reference);

  double n[4][2] = {{1.5, 1.5}, {1.5, 1.5}, {13.0, 13.0}, {13.0, 4.0}};
  double m[2][2] = {{5.67, 5.67}, {5.67, 6.329845}};
  double r[4][2] = {{17.01, 17.9997675},
                    {17.01, 17.9997675},
                    {147.42, 155.997985},
                    {96.39, 99.02938}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = m[i][j];
    }
  }

  for (int i = 0; i < reference.rows; i++) {
    for (int j = 0; j < reference.columns; j++) {
      reference.matrix[i][j] = r[i][j];
    }
  }

  response = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_mult_matrix_5) {
  matrix_t A, B, result, reference;
  int response = 0;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &reference);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1.5;
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = 5.67;
    }
  }

  for (int i = 0; i < reference.rows; i++) {
    for (int j = 0; j < reference.columns; j++) {
      reference.matrix[i][j] = 17.01;
    }
  }

  response = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&B);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

Suite *s21_s21_mult_matrix(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_mult_matrix");

  /* Core test case */
  tc_core = tcase_create("test_s21_mult_matrix");

  tcase_add_test(tc_core, test_s21_mult_matrix_1);
  tcase_add_test(tc_core, test_s21_mult_matrix_2);
  tcase_add_test(tc_core, test_s21_mult_matrix_3);
  tcase_add_test(tc_core, test_s21_mult_matrix_4);
  tcase_add_test(tc_core, test_s21_mult_matrix_5);

  suite_add_tcase(s, tc_core);

  return s;
}
