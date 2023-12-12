#include "test_string.h"

START_TEST(strncpy_1) {
    const char src[] = "Hello, World!";
    char dest[20];
    s21_strncpy(dest, src, 20);
    ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(strncpy_2) {
    const char src[] = "Hello, World!";
    char dest[5];
    s21_strncpy(dest, src, 5);
    ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(strncpy_3) {
    const char src[] = "abc\0def";
    char dest[8];
    s21_strncpy(dest, src, 8);
    ck_assert_mem_eq(dest, src, 8);
}
END_TEST

START_TEST(strncpy_4) {
    const char src[] = "Testing";
    char dest[5];
    s21_strncpy(dest, src, 5);
    ck_assert_str_eq(dest, "Testi");
}
END_TEST

START_TEST(strncpy_5) {
    const char src[] = "";
    char dest[5];
    s21_strncpy(dest, src, 5);
    ck_assert_str_eq(dest, "");
}
END_TEST

START_TEST(strncpy_6) {
    const char src[] = "123";
    char dest[2];
    s21_strncpy(dest, src, 2);
    ck_assert_str_eq(dest, "12");
}
END_TEST

START_TEST(strncpy_7) {
    const char src[] = "AaBbCc";
    char dest[10];
    s21_strncpy(dest, src, 10);
    ck_assert_str_eq(dest, "AaBbCc");
}
END_TEST

START_TEST(strncpy_8) {
    const char src[] = "Special@Characters!";
    char dest[20];
    s21_strncpy(dest, src, 20);
    ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(strncpy_9) {
    const char src[] = "Line\nBreak";
    char dest[12];
    s21_strncpy(dest, src, 12);
    ck_assert_str_eq(dest, "Line\nBreak");
}
END_TEST

START_TEST(strncpy_10) {
    const char src[] = "Hello\tTab!";
    char dest[20];
    s21_strncpy(dest, src, 20);
    ck_assert_str_eq(dest, src);
}
END_TEST

Suite *strncpy_suite(void) {
    Suite *s = suite_create("SUITE_STRNCPY");
    TCase *tc;
    tc = tcase_create("TC_STRNCPY");
    tcase_add_test(tc, strncpy_1);
    tcase_add_test(tc, strncpy_2);
    tcase_add_test(tc, strncpy_3);
    tcase_add_test(tc, strncpy_4);
    tcase_add_test(tc, strncpy_5);
    tcase_add_test(tc, strncpy_6);
    tcase_add_test(tc, strncpy_7);
    tcase_add_test(tc, strncpy_8);
    tcase_add_test(tc, strncpy_9);
    tcase_add_test(tc, strncpy_10);
    suite_add_tcase(s, tc);
    return s;
}
