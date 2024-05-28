#include "test.h"

START_TEST(test_s21_determinant_1) {
  matrix_t A;
  double result, reference = 0.0;
  int response = 0;

  s21_create_matrix(3, 3, &A);

  double n[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  response = s21_determinant(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_double_eq_tol(result, reference, 0.000001);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t A;
  double result = 0, reference = -2.886000;
  int response = 0;

  s21_create_matrix(3, 3, &A);

  double n[3][3] = {{1.3, 1.3, 1.3}, {1.4, 2, 1.4}, {5.2, 2, 1.5}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  response = s21_determinant(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_double_eq_tol(result, reference, 0.000001);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t A;
  int response = 0;

  s21_create_matrix(2, 2, &A);

  response = s21_determinant(&A, NULL);

  ck_assert_int_eq(response, Error);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  matrix_t A;
  double result;
  int response = 0;

  s21_create_matrix(2, 3, &A);

  response = s21_determinant(&A, &result);

  ck_assert_int_eq(response, CalcError);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t A;
  double result;
  int response = 0;

  s21_create_matrix(7, 7, &A);

  double n[7][7] = {{1, 0, 0, 0, 0, 0, 4},   {2, 0, 1, 21, 0, 0, 0},
                    {0, 12, 2, 4, 0, 3, 0},  {0, 0, 0, 0, 2, 23, 0},
                    {0, 0, 23, 6, 42, 0, 0}, {2, 0, 0, 0, 0, 7, 0},
                    {0, 0, 0, 0, 0, 0, 23}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  response = s21_determinant(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_double_eq_tol(result, -1843128, 0.000001);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  matrix_t A;
  double result;
  int response = 0;

  s21_create_matrix(1, 1, &A);

  double n[1][1] = {{1.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  response = s21_determinant(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_double_eq_tol(result, 1.0, 0.000001);

  s21_free_matrix(&A);
}
END_TEST

Suite *s21_s21_determinant(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_determinant");

  /* Core test case */
  tc_core = tcase_create("test_s21_determinant");

  tcase_add_test(tc_core, test_s21_determinant_1);
  tcase_add_test(tc_core, test_s21_determinant_2);
  tcase_add_test(tc_core, test_s21_determinant_3);
  tcase_add_test(tc_core, test_s21_determinant_4);
  tcase_add_test(tc_core, test_s21_determinant_5);
  tcase_add_test(tc_core, test_s21_determinant_6);

  suite_add_tcase(s, tc_core);

  return s;
}
