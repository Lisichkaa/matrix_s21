#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>

#include "../s21_matrix.h"

Suite *s21_s21_create_matrix(void);

Suite *s21_s21_eq_matrix(void);

Suite *s21_s21_sum_matrix(void);
Suite *s21_s21_sub_matrix(void);

Suite *s21_s21_mult_number(void);
Suite *s21_s21_mult_matrix(void);

Suite *s21_s21_transpose(void);

Suite *s21_s21_addition(void);

Suite *s21_s21_determinant(void);

Suite *s21_s21_inverse_matrix(void);

#endif