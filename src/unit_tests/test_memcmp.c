#include "test_string.h"

// Тест-кейс 1: Сравнение двух одинаковых строк
START_TEST(memcmp_1) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    size_t n = strlen(str1) + 1;  // Включая нулевой символ

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 2: Сравнение строк разной длины
START_TEST(memcmp_2) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello!";
    size_t n = strlen(str1) + 1;  // Включая нулевой символ

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 3: Сравнение строк с использованием части блока памяти
START_TEST(memcmp_3) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello!";
    size_t n = 6;  // Сравниваем только первые 6 байт

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 4: Сравнение пустых строк
START_TEST(memcmp_4) {
    char str1[] = "";
    char str2[] = "";
    size_t n = 1;  // Включая нулевой символ

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 5: Сравнение двух строк с одинаковым началом
START_TEST(memcmp_5) {
    char str1[] = "CommonPrefix123";
    char str2[] = "CommonPrefix456";
    size_t n = 13;  // Сравниваем первые 13 байт

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 6: Сравнение двух строк, где первая длиннее!!!
START_TEST(memcmp_6) {
    char str1[] = "LongerString123";
    char str2[] = "Short123";
    size_t n = 9;  // Сравниваем первые 9 байт

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 7: Сравнение двух строк, где вторая длиннее !!!!
START_TEST(memcmp_7) {
    char str1[] = "Short123";
    char str2[] = "LongerString123";
    size_t n = 9;  // Сравниваем первые 9 байт

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 8: Сравнение строк, где первый символ различен
START_TEST(memcmp_8) {
    char str1[] = "Apple";
    char str2[] = "Banana";
    size_t n = 6;  // Сравниваем первые 6 байт

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 9: Сравнение строк, где различие в средней части
START_TEST(memcmp_9) {
    char str1[] = "Programming";
    char str2[] = "Programmers";
    size_t n = 11;  // Сравниваем первые 11 байт

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// Тест-кейс 10: Сравнение строк, где различие в конце
START_TEST(memcmp_10) {
    char str1[] = "End123";
    char str2[] = "End456";
    size_t n = 7;  // Сравниваем первые 7 байт

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *memcmp_suite(void) {
    Suite *s = suite_create("SUITE_MEMCMP");
    TCase *tc;
    tc = tcase_create("TC_MEMCMP");
    tcase_add_test(tc, memcmp_1);
    tcase_add_test(tc, memcmp_2);
    tcase_add_test(tc, memcmp_3);
    tcase_add_test(tc, memcmp_4);
    tcase_add_test(tc, memcmp_5);
    tcase_add_test(tc, memcmp_6);
    tcase_add_test(tc, memcmp_7);
    tcase_add_test(tc, memcmp_8);
    tcase_add_test(tc, memcmp_9);
    tcase_add_test(tc, memcmp_10);
    suite_add_tcase(s, tc);
    return s;
}
