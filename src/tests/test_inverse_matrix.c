#include "test.h"

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  double n[3][3] = {{2.0, 5.0, 7.0}, {6.0, 3.0, 4.0}, {5.0, -2.0, -3.0}};
  double r[3][3] = {
      {1.0, -1.0, 1.0}, {-38.0, 41.0, -34.0}, {27.0, -29.0, 24.0}};

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

  response = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  double n[3][3] = {{1.3, 1.3, 1.3}, {1.4, 2, 1.4}, {5.2, 2, 1.5}};
  double r[3][3] = {{-100.0 / 1443.0, -25.0 / 111.0, 10.0 / 37.0},
                    {-70.0 / 39.0, 5.0 / 3.0, 0.0},
                    {3800.0 / 1443.0, -160.0 / 111.0, -10.0 / 37.0}};

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

  response = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t A, B, result;
  int response = 0;

  s21_create_matrix(2, 2, &A);

  response = s21_inverse_matrix(&A, NULL);

  ck_assert_int_eq(response, Error);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
  matrix_t A, B, result;
  int response = 0;

  s21_create_matrix(2, 3, &A);

  response = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(response, CalcError);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_5) {
  matrix_t A, result;
  int response = 0;

  s21_create_matrix(7, 7, &A);

  double n[7][7] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = n[i][j];
    }
  }

  response = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(response, CalcError);

  s21_free_matrix(&A);
}
END_TEST

Suite *s21_s21_inverse_matrix(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_inverse_matrix");

  /* Core test case */
  tc_core = tcase_create("test_s21_inverse_matrix");

  tcase_add_test(tc_core, test_s21_inverse_matrix_1);
  tcase_add_test(tc_core, test_s21_inverse_matrix_2);
  tcase_add_test(tc_core, test_s21_inverse_matrix_3);
  tcase_add_test(tc_core, test_s21_inverse_matrix_4);
  tcase_add_test(tc_core, test_s21_inverse_matrix_5);

  suite_add_tcase(s, tc_core);

  return s;
}
