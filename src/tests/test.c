#include "test.h"

int main() {
  int number_failed = 0;
  SRunner *sr;

  Suite *matrix_suite = s21_s21_create_matrix();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_eq_matrix();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_sum_matrix();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_sub_matrix();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_mult_number();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_mult_matrix();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_transpose();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_addition();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_determinant();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  matrix_suite = s21_s21_inverse_matrix();
  sr = srunner_create(matrix_suite);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return 0;
}
