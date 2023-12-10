#include "test_string.h"

// Тест-кейс 1: Поиск существующего символа в строке
START_TEST(memchr_1) {
    char test1[] = "Hello, World!";
    char search_char = 'W';
    ck_assert_ptr_eq(s21_memchr(test1, search_char, strlen(test1)), memchr(test1, search_char, strlen(test1)));
}
END_TEST

// Тест-кейс 2: Поиск символа в строке, который отсутствует
START_TEST(memchr_2) {
    char test2[] = "Testing";
    char search_char = 'A';
    ck_assert_ptr_eq(s21_memchr(test2, search_char, strlen(test2)), memchr(test2, search_char, strlen(test2)));
}
END_TEST

// Тест-кейс 3: Поиск нулевого символа в строке
START_TEST(memchr_3) {
    char test3[] = "String\0with\0null\0characters";
    char search_char = '\0';
    ck_assert_ptr_eq(s21_memchr(test3, search_char, strlen(test3)), memchr(test3, search_char, strlen(test3)));
}
END_TEST

// Тест-кейс 4: Поиск символа за пределами длины строки
START_TEST(memchr_4) {
    char test4[] = "Short";
    char search_char = 'T';
    ck_assert_ptr_eq(s21_memchr(test4, search_char, 2), memchr(test4, search_char, 2));
}
END_TEST

// Тест-кейс 5: Поиск символа в пустой строке
START_TEST(memchr_5) {
    char test5[] = "";
    char search_char = 'A';
    ck_assert_ptr_eq(s21_memchr(test5, search_char, 0), memchr(test5, search_char, 0));
}
END_TEST

// Тест-кейс 6: Поиск символа в строке, содержащей множество символов
START_TEST(memchr_6) {
    char test6[] = "abacabadabacaba";
    char search_char = 'd';
    ck_assert_ptr_eq(s21_memchr(test6, search_char, strlen(test6)), memchr(test6, search_char, strlen(test6)));
}
END_TEST

// Тест-кейс 7: Поиск символа, когда длина строки равна 1
START_TEST(memchr_7) {
    char test7[] = "X";
    char search_char = 'X';
    ck_assert_ptr_eq(s21_memchr(test7, search_char, 1), memchr(test7, search_char, 1));
}
END_TEST

// Тест-кейс 8: Поиск символа в строке, где символ встречается несколько раз
START_TEST(memchr_8) {
    char test8[] = "abacabadabacaba";
    char search_char = 'a';
    ck_assert_ptr_eq(s21_memchr(test8, search_char, strlen(test8)), memchr(test8, search_char, strlen(test8)));
}
END_TEST

// Тест-кейс 9: Поиск символа, когда длина строки больше, чем реальное количество символов
START_TEST(memchr_9) {
    char test9[] = "Short";
    char search_char = 'T';
    ck_assert_ptr_eq(s21_memchr(test9, search_char, 10), memchr(test9, search_char, 10));
}
END_TEST

// Тест-кейс 10: Поиск символа в строке с использованием нулевой длины
START_TEST(memchr_10) {
    char test10[] = "Hello";
    char search_char = 'H';
    ck_assert_ptr_eq(s21_memchr(test10, search_char, 0), memchr(test10, search_char, 0));
}
END_TEST

Suite *memchr_suite(void) {
    Suite *s = suite_create("SUITE_MEMCHR");
    TCase *tc;
    tc = tcase_create("TC_MEMCHR");
    tcase_add_test(tc, memchr_1);
    tcase_add_test(tc, memchr_2);
    tcase_add_test(tc, memchr_3);
    tcase_add_test(tc, memchr_4);
    tcase_add_test(tc, memchr_5);
    tcase_add_test(tc, memchr_6);
    tcase_add_test(tc, memchr_7);
    tcase_add_test(tc, memchr_8);
    tcase_add_test(tc, memchr_9);
    tcase_add_test(tc, memchr_10);
    suite_add_tcase(s, tc);
    return s;
}
