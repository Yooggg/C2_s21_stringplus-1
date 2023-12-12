#include "test_string.h"

START_TEST(strlen_1){
    char test1[] = "SCHOOL21";
    ck_assert_int_eq(s21_strlen(test1),strlen(test1));
}
END_TEST

START_TEST(strlen_2){
    char test2[] = "1234567890987654321234567898765434565";
    ck_assert_int_eq(s21_strlen(test2),strlen(test2));
}
END_TEST


START_TEST(strlen_3){
    char test3[] = "\0\0";
    ck_assert_int_eq(s21_strlen(test3),strlen(test3));
}
END_TEST


START_TEST(strlen_4){
    char test4[] = "I LUBLU BOLSHIH AND SHEKASTUE!!!!!";
    ck_assert_int_eq(s21_strlen(test4),strlen(test4));
}
END_TEST



START_TEST(strlen_5){
    char test5[] = "\n\n\n\0";
    ck_assert_int_eq(s21_strlen(test5),strlen(test5));
}
END_TEST

Suite *strlen_suite(void){
    Suite *s = suite_create("SUITE_STRLEN");
    TCase *tc;
    tc = tcase_create("TC_STRLEN");
  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);
    suite_add_tcase(s,tc);
    return s;
}
