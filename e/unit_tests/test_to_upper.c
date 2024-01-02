#include "test_string.h"
// Тест-кейс 1: Преобразование строки в верхний регистр
START_TEST(test_to_upper_1) {
    const char str[] = "Hello, World!";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "HELLO, WORLD!");
    free(result);
}
END_TEST

// Тест-кейс 2: Преобразование пустой строки (должен вернуть пустую строку)
START_TEST(test_to_upper_2) {
    const char str[] = "";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "");
    free(result);
}
END_TEST

// Тест-кейс 3: Преобразование строки из одного символа
START_TEST(test_to_upper_3) {
    const char str[] = "a";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "A");
    free(result);
}
END_TEST

// Тест-кейс 4: Преобразование строки с табуляцией (табуляция должна заменяться на 4 пробела)
START_TEST(test_to_upper_4) {
    const char str[] = "Hello\tWorld!";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "HELLO    WORLD!");
    free(result);
}
END_TEST

// Тест-кейс 5: Преобразование строки с символами, не являющимися буквами
START_TEST(test_to_upper_5) {
    const char str[] = "123!@#";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "123!@#");
    free(result);
}
END_TEST

// Тест-кейс 6: Преобразование строки с разными регистрами
START_TEST(test_to_upper_6) {
    const char str[] = "mIxEdCaSe";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "MIXEDCASE");
    free(result);
}
END_TEST

// Тест-кейс 7: Преобразование строки с пробелами
START_TEST(test_to_upper_7) {
    const char str[] = "  spaced  out  ";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "  SPACED  OUT  ");
    free(result);
}
END_TEST

// Тест-кейс 8: Преобразование строки с нуль-символом (должен вернуть пустую строку)
START_TEST(test_to_upper_8) {
    const char str[] = "Hello\0World!";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "");
    free(result);
}
END_TEST

// Тест-кейс 9: Преобразование строки с длинными пробелами
START_TEST(test_to_upper_9) {
    const char str[] = "    long     spaces    ";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "    LONG     SPACES    ");
    free(result);
}
END_TEST

// Тест-кейс 10: Преобразование строки с переводом строки
START_TEST(test_to_upper_10) {
    const char str[] = "Line1\nLine2";
    void *result = s21_to_upper(str);
    ck_assert_str_eq(result, "LINE1\nLINE2");
    free(result);
}
END_TEST

Suite *to_upper_suite(void) {
    Suite *s;
    TCase *tc_to_upper;

    s = suite_create("to_upper_suite");
    tc_to_upper = tcase_create("to_upper_tests");

    tcase_add_test(tc_to_upper, test_to_upper_1);
    tcase_add_test(tc_to_upper, test_to_upper_2);
    tcase_add_test(tc_to_upper, test_to_upper_3);
    tcase_add_test(tc_to_upper, test_to_upper_4);
    tcase_add_test(tc_to_upper, test_to_upper_5);
    tcase_add_test(tc_to_upper, test_to_upper_6);
    tcase_add_test(tc_to_upper, test_to_upper_7);
    tcase_add_test(tc_to_upper, test_to_upper_8);
    tcase_add_test(tc_to_upper, test_to_upper_9);
    tcase_add_test(tc_to_upper, test_to_upper_10);

    suite_add_tcase(s, tc_to_upper);

    return s;
}