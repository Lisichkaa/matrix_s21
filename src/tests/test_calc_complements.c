#include "test.h"

START_TEST(test_s21_addition_1) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  double n[3][3] = {{1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}, {5.0, 2.0, 1.0}};
  double r[3][3] = {{0.0, 10.0, -20.0}, {4.0, -14.0, 8.0}, {-8.0, -2.0, 4.0}};

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

  response = s21_addition(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_addition_2) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &reference);

  double n[3][3] = {{1.1, 1.2, 1.2}, {1.3, 1.1, 1.2}, {1.3, 1.3, 1.1}};
  double r[3][3] = {
      {-0.35, 0.13, 0.26}, {0.24, -0.35, 0.13}, {0.12, 0.24, -0.35}};

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

  response = s21_addition(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_addition_3) {
  matrix_t A, B, result;
  int response = 0;

  s21_create_matrix(2, 2, &A);

  response = s21_addition(&A, NULL);

  ck_assert_int_eq(response, Error);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_addition_4) {
  matrix_t A, B, result;
  int response = 0;

  s21_create_matrix(2, 3, &A);

  response = s21_addition(&A, &result);

  ck_assert_int_eq(response, CalcError);

  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_addition_5) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(7, 7, &A);
  s21_create_matrix(7, 7, &reference);

  double n[7][7] = {{1, 0, 0, 0, 0, 0, 4},   {2, 0, 1, 21, 0, 0, 0},
                    {0, 12, 2, 4, 0, 3, 0},  {0, 0, 0, 0, 2, 23, 0},
                    {0, 0, 23, 6, 42, 0, 0}, {2, 0, 0, 0, 0, 7, 0},
                    {0, 0, 0, 0, 0, 0, 23}};
  double r[7][7] = {
      {-1843128, -1871740, 11151504, -355488, -6055992, 526608, 0},
      {0, 25760, 23184, -88872, 0, 0, 0},
      {0, -153594, 0, 0, 0, 0, 0},
      {0, -256956, 1704024, -81144, -921564, 0, 0},
      {0, 12236, -81144, 3864, 0, 0, 0},
      {0, 910110, -5598936, 266616, 3027996, -263304, 0},
      {320544, 325520, -1939392, 61824, 1053216, -91584, -80136}};

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

  response = s21_addition(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_addition_6) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &reference);

  double n[1][1] = {{5}};
  double r[1][1] = {{1}};

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

  response = s21_addition(&A, &result);

  ck_assert_int_eq(response, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

START_TEST(test_s21_addition_7) {
  matrix_t A, result, reference;
  int response = 0;

  s21_create_matrix(17, 17, &A);
  s21_create_matrix(17, 17, &reference);

  double n[1][1] = {{5}};
  double r[1][1] = {{1}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1;
    }
  }

  for (int i = 0; i < reference.rows; i++) {
    for (int j = 0; j < reference.columns; j++) {
      reference.matrix[i][j] = 1;
    }
  }

  response = s21_addition(&A, &result);

  ck_assert_int_eq(response, OK);
  // ck_assert_int_eq(s21_eq_matrix(&result, &reference), 1);

  s21_free_matrix(&A);
  s21_free_matrix(&result);
  s21_free_matrix(&reference);
}
END_TEST

Suite *s21_s21_addition(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_addition");

  /* Core test case */
  tc_core = tcase_create("test_s21_addition");

  tcase_add_test(tc_core, test_s21_addition_1);
  tcase_add_test(tc_core, test_s21_addition_2);
  tcase_add_test(tc_core, test_s21_addition_3);
  tcase_add_test(tc_core, test_s21_addition_4);
  tcase_add_test(tc_core, test_s21_addition_5);
  tcase_add_test(tc_core, test_s21_addition_6);
  tcase_add_test(tc_core, test_s21_addition_7);

  suite_add_tcase(s, tc_core);

  return s;
}
