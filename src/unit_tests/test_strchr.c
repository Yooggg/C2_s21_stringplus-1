#include "test_string.h"

// Тест-кейс 1: Поиск существующего символа в строке
START_TEST(strchr_1) {
    char str1[] = "Hello, World!";
    char search_char = 'W';

    ck_assert_ptr_eq(s21_strchr(str1, search_char), strchr(str1, search_char));
}
END_TEST

// Тест-кейс 2: Поиск символа, который отсутствует в строке
START_TEST(strchr_2) {
    char str2[] = "Testing";
    char search_char = 'A';

    ck_assert_ptr_eq(s21_strchr(str2, search_char), strchr(str2, search_char));
}
END_TEST

// Тест-кейс 3: Поиск нулевого символа в строке
START_TEST(strchr_3) {
    char str3[] = "String\0with\0null\0characters";
    char search_char = '\0';

    ck_assert_ptr_eq(s21_strchr(str3, search_char), strchr(str3, search_char));
}
END_TEST

// Тест-кейс 4: Поиск символа за пределами длины строки
START_TEST(strchr_4) {
    char str4[] = "Short";
    char search_char = 'T';

    ck_assert_ptr_eq(s21_strchr(str4, search_char), strchr(str4, search_char));
}
END_TEST

// Тест-кейс 5: Поиск символа в пустой строке
START_TEST(strchr_5) {
    char str5[] = "";
    char search_char = 'A';

    ck_assert_ptr_eq(s21_strchr(str5, search_char), strchr(str5, search_char));
}
END_TEST

// Тест-кейс 6: Поиск первого вхождения символа 'a' в строке с несколькими 'a'
START_TEST(strchr_6) {
    char str6[] = "abacabadabacaba";
    char search_char = 'a';

    ck_assert_ptr_eq(s21_strchr(str6, search_char), strchr(str6, search_char));
}
END_TEST

// Тест-кейс 7: Поиск первого вхождения символа в строке, где символ встречается один раз
START_TEST(strchr_7) {
    char str7[] = "X";
    char search_char = 'X';

    ck_assert_ptr_eq(s21_strchr(str7, search_char), strchr(str7, search_char));
}
END_TEST

// Тест-кейс 8: Поиск первого вхождения символа в строке, где символ встречается в начале
START_TEST(strchr_8) {
    char str8[] = "CommonPrefix123";
    char search_char = 'C';

    ck_assert_ptr_eq(s21_strchr(str8, search_char), strchr(str8, search_char));
}
END_TEST

// Тест-кейс 9: Поиск первого вхождения символа в строке, где символ встречается в конце
START_TEST(strchr_9) {
    char str9[] = "End123";
    char search_char = '3';

    ck_assert_ptr_eq(s21_strchr(str9, search_char), strchr(str9, search_char));
}
END_TEST

// Тест-кейс 10: Поиск первого вхождения символа в строке, где символ не встречается
START_TEST(strchr_10) {
    char str10[] = "Hello, World!";
    char search_char = 'Z';

    ck_assert_ptr_eq(s21_strchr(str10, search_char), strchr(str10, search_char));
}
END_TEST

Suite *strchr_suite(void) {
    Suite *s = suite_create("SUITE_STRCHR");
    TCase *tc;
    tc = tcase_create("TC_STRCHR");
    tcase_add_test(tc, strchr_1);
    tcase_add_test(tc, strchr_2);
    tcase_add_test(tc, strchr_3);
    tcase_add_test(tc, strchr_4);
    tcase_add_test(tc, strchr_5);
    tcase_add_test(tc, strchr_6);
    tcase_add_test(tc, strchr_7);
    tcase_add_test(tc, strchr_8);
    tcase_add_test(tc, strchr_9);
    tcase_add_test(tc, strchr_10);
    suite_add_tcase(s, tc);
    return s;
}
