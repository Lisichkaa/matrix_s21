#include "test.h"

START_TEST(test_s21_create_matrix_1) {
  matrix_t A;
  int response = 0;

  response = s21_create_matrix(3, 3, &A);

  ck_assert_int_eq(response, 0);
  s21_free_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  int response = 0;

  response = s21_create_matrix(3, 3, NULL);

  ck_assert_int_eq(response, 1);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  matrix_t A;
  int response = 0;

  response = s21_create_matrix(0, 3, &A);

  ck_assert_int_eq(response, 1);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  matrix_t A;
  int response = 0;

  response = s21_create_matrix(3, -1, &A);

  ck_assert_int_eq(response, 1);
}
END_TEST

Suite *s21_s21_create_matrix(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_create_matrix");

  /* Core test case */
  tc_core = tcase_create("test_s21_create_matrix");

  tcase_add_test(tc_core, test_s21_create_matrix_1);
  tcase_add_test(tc_core, test_s21_create_matrix_2);
  tcase_add_test(tc_core, test_s21_create_matrix_3);
  tcase_add_test(tc_core, test_s21_create_matrix_4);

  suite_add_tcase(s, tc_core);

  return s;
}
