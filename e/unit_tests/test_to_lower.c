#include "test_string.h"
// Тест-кейс 1: Преобразование строки в нижний регистр
START_TEST(test_to_lower_1) {
    const char str[] = "Hello, World!";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, "hello, world!");
    free(result);
}
END_TEST

// Тест-кейс 2: Преобразование пустой строки (должен вернуть пустую строку)
START_TEST(test_to_lower_2) {
    const char str[] = " ";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, " ");
    free(result);
}
END_TEST

// Тест-кейс 3: Преобразование строки из одного символа
START_TEST(test_to_lower_3) {
    const char str[] = "A";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, "a");
    free(result);
}
END_TEST

// Тест-кейс 4: Преобразование строки с табуляцией (табуляция должна заменяться на 4 пробела)
START_TEST(test_to_lower_4) {
    const char str[] = "Hello\tWorld!";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, "hello    world!");
    free(result);
}
END_TEST

// Тест-кейс 5: Преобразование строки с символами, не являющимися буквами
START_TEST(test_to_lower_5) {
    const char str[] = "123!@#";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, "123!@#");
    free(result);
}
END_TEST

// Тест-кейс 6: Преобразование строки с разными регистрами
START_TEST(test_to_lower_6) {
    const char str[] = "MiXeDCaSe";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, "mixedcase");
    free(result);
}
END_TEST

// Тест-кейс 7: Преобразование строки с пробелами
START_TEST(test_to_lower_7) {
    const char str[] = "  Spaced  Out  ";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, "  spaced  out  ");
    free(result);
}
END_TEST

// Тест-кейс 8: Преобразование строки с нуль-символом
START_TEST(test_to_lower_8) {
    const char *str = NULL;
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, NULL);
    free(result);
}
END_TEST

// Тест-кейс 9: Преобразование строки с длинными пробелами
START_TEST(test_to_lower_9) {
    const char str[] = "    Long     Spaces    ";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, "    long     spaces    ");
    free(result);
}
END_TEST

// Тест-кейс 10: Преобразование строки с переводом строки
START_TEST(test_to_lower_10) {
    const char str[] = "Line1\nLine2";
    void *result = s21_to_lower(str);
    ck_assert_str_eq(result, "line1\nline2");
    free(result);
}
END_TEST

Suite *to_lower_suite(void) {
    Suite *s;
    TCase *tc_to_lower;

    s = suite_create("to_lower_suite");
    tc_to_lower = tcase_create("to_lower_tests");

    tcase_add_test(tc_to_lower, test_to_lower_1);
    tcase_add_test(tc_to_lower, test_to_lower_2);
    tcase_add_test(tc_to_lower, test_to_lower_3);
    tcase_add_test(tc_to_lower, test_to_lower_4);
    tcase_add_test(tc_to_lower, test_to_lower_5);
    tcase_add_test(tc_to_lower, test_to_lower_6);
    tcase_add_test(tc_to_lower, test_to_lower_7);
    tcase_add_test(tc_to_lower, test_to_lower_8);
    tcase_add_test(tc_to_lower, test_to_lower_9);
    tcase_add_test(tc_to_lower, test_to_lower_10);

    suite_add_tcase(s, tc_to_lower);

    return s;
}