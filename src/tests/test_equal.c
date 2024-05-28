#include "test.h"

START_TEST(test_s21_eq_matrix_1) {
  matrix_t A, B;
  int response = SUCCESS;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1;
      B.matrix[i][j] = 1;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_free_matrix(&A);
  s21_free_matrix(&B);

  ck_assert_int_eq(response, SUCCESS);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
  matrix_t A, B;
  int response = SUCCESS;
  double item = 0.1234567;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = item;
      B.matrix[i][j] = item;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_free_matrix(&A);
  s21_free_matrix(&B);

  ck_assert_int_eq(response, SUCCESS);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
  matrix_t A, B;
  int response = SUCCESS;
  double item = 0.1234567;
  double item1 = 0.1234568;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = item;
      B.matrix[i][j] = item1;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_free_matrix(&A);
  s21_free_matrix(&B);

  ck_assert_int_eq(response, FAILURE);
}
END_TEST

START_TEST(test_s21_eq_matrix_4) {
  matrix_t A, B;
  int response = SUCCESS;
  double item = 0.1234567;
  double item1 = 0.12345678;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = item;
      B.matrix[i][j] = item1;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_free_matrix(&A);
  s21_free_matrix(&B);

  ck_assert_int_eq(response, SUCCESS);
}
END_TEST

START_TEST(test_s21_eq_matrix_5) {
  matrix_t A, B;
  int response = SUCCESS;
  double item = 0.1234567;
  double item1 = 0.12345678;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = item;
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = item1;
    }
  }

  response = s21_eq_matrix(&A, &B);

  s21_free_matrix(&A);
  s21_free_matrix(&B);

  ck_assert_int_eq(response, FAILURE);
}
END_TEST

START_TEST(test_s21_eq_matrix_6) {
  matrix_t A;
  int response = SUCCESS;

  s21_create_matrix(2, 3, &A);

  response = s21_eq_matrix(&A, NULL);

  s21_free_matrix(&A);

  ck_assert_int_eq(response, FAILURE);
}
END_TEST

START_TEST(test_s21_eq_matrix_7) {
  matrix_t A, B;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 2.0256354;
      B.matrix[i][j] = 2.0256354;
    }
  }

  A.matrix[0][0] = 2.02563548;

  int result = s21_eq_matrix(&A, &B);

  s21_free_matrix(&A);
  s21_free_matrix(&B);

  ck_assert_int_eq(1, result);
}
END_TEST

Suite *s21_s21_eq_matrix(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_eq_matrix");

  /* Core test case */
  tc_core = tcase_create("test_s21_eq_matrix");

  tcase_add_test(tc_core, test_s21_eq_matrix_1);
  tcase_add_test(tc_core, test_s21_eq_matrix_2);
  tcase_add_test(tc_core, test_s21_eq_matrix_3);
  tcase_add_test(tc_core, test_s21_eq_matrix_4);
  tcase_add_test(tc_core, test_s21_eq_matrix_5);
  tcase_add_test(tc_core, test_s21_eq_matrix_6);
  tcase_add_test(tc_core, test_s21_eq_matrix_7);

  suite_add_tcase(s, tc_core);

  return s;
}
