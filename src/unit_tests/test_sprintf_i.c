
#include "test_string.h"

// Тест-кейс 1: Обычное положительное число
START_TEST(s21_sprintf_i_1) {
    char result[50];
    int value = 12345;
    int standard_result = sprintf(result, "%i", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%i", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 2: Отрицательное число
START_TEST(s21_sprintf_i_2) {
    char result[50];
    int value = -54321;
    int standard_result = sprintf(result, "%i", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%i", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 3: Ноль
START_TEST(s21_sprintf_i_3) {
    char result[50];
    int value = 0;
    int standard_result = sprintf(result, "%i", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%i", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 4: Максимальное положительное значение для int
START_TEST(s21_sprintf_i_4) {
    char result[50];
    int value = INT_MAX;
    int standard_result = sprintf(result, "%i", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%i", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 5: Минимальное отрицательное значение для int
START_TEST(s21_sprintf_i_5) {
    char result[50];
    int value = INT_MIN;
    int standard_result = sprintf(result, "%i", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%i", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_i_suite(void) {
    Suite *s = suite_create("SUITE_sprintf_i");
    TCase *tc;
    tc = tcase_create("TC_sprintf_i");
    tcase_add_test(tc, s21_sprintf_i_1);
    tcase_add_test(tc, s21_sprintf_i_2);
    tcase_add_test(tc, s21_sprintf_i_3);
    tcase_add_test(tc, s21_sprintf_i_4);
    tcase_add_test(tc, s21_sprintf_i_5);
    suite_add_tcase(s, tc);
    return s;
}
