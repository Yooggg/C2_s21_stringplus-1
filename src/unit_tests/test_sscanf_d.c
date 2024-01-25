#include "test_string.h"

START_TEST(sscanf_test_1) {
  const char *input = "123";
  int value;
  int result = s21_sscanf(input, "%d", &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 123);
}
END_TEST

START_TEST(sscanf_test_2) {
  const char *input = "   -456";
  int value;
  int result = s21_sscanf(input, "%d", &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, -456);
}
END_TEST

START_TEST(sscanf_test_3) {
  const char *input = " 789 ";
  int value;
  int result = s21_sscanf(input, "%d", &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 789);
}
END_TEST

START_TEST(sscanf_test_4) {
  const char *input = "12 34 56";
  int value1, value2, value3;
  int result = s21_sscanf(input, "%d %d %d", &value1, &value2, &value3);
  ck_assert_int_eq(result, 3);
  ck_assert_int_eq(value1, 12);
  ck_assert_int_eq(value2, 34);
  ck_assert_int_eq(value3, 56);
}
END_TEST

START_TEST(sscanf_test_5) {
  const char *input = "-789";
  int value;
  int result = s21_sscanf(input, "%3d", &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, -78);  // Ширина ограничена 3 символами
}
END_TEST

START_TEST(sscanf_test_6) {
  const char *input = "42  56";
  int value1, value2;
  int result = s21_sscanf(input, "%2d %d", &value1, &value2);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(value1, 42);  // Ширина ограничена 2 символами
  ck_assert_int_eq(value2, 56);
}
END_TEST

START_TEST(sscanf_test_7) {
  const char *input = "   1000";
  short int shortValue;
  int result = s21_sscanf(input, "%5hd", &shortValue);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(shortValue, 1000);
}
END_TEST

START_TEST(sscanf_test_8) {
  const char *input = "   12345";
  long int longValue;
  int result = s21_sscanf(input, "%ld", &longValue);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(longValue, 12345);
}
END_TEST

START_TEST(sscanf_test_9) {
  const char *input = "123 456 789";
  int value1, value2, value3;
  int result = s21_sscanf(input, "%2d %d %d", &value1, &value2, &value3);
  ck_assert_int_eq(result, 3);
  ck_assert_int_eq(value1, 12);  // Ширина первого значения - 2
  ck_assert_int_eq(value2, 3);  // Ширина второго значения - 3
  ck_assert_int_eq(value3, 456);
}
END_TEST

START_TEST(sscanf_test_10) {
  const char *input = "42 56";
  short int shortValue1, shortValue2;
  int result = s21_sscanf(input, "%2hd %hd", &shortValue1, &shortValue2);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(shortValue1, 42);  // Ширина первого значения - 2
  ck_assert_int_eq(shortValue2, 56);
}
END_TEST

START_TEST(sscanf_test_11) {
  char a[40] = {'\0'}, c[40] = {'\0'}, d[40] = {'\0'};
  wchar_t b[40] = {'\0'};
  char a2[40] = {'\0'}, c2[40] = {'\0'}, d2[40] = {'\0'};
  wchar_t b2[40] = {'\0'};
  const char str[] = "lol kek cheburek morzh pisos";
  sscanf(str, "%3s %ls %3c %*s %s", a, b, c, d);
  s21_sscanf(str, "%3s %ls %3c %*s %s", a2, b2, c2, d2);
  ck_assert_str_eq(a, a2);
  ck_assert_str_eq(c, c2);
  ck_assert_str_eq(d, d2);
}
END_TEST

START_TEST(sscanf_test_12) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "1778 012 0x1111 -10 pisos";
  int r1 = sscanf(str, "%x%x%x%x", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%x%x%x%x", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_13) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "1778 012 0x1Aa8 -10 pisos";
  int r1 = sscanf(str, "%i%i%i%i", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%i%i%i%i", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_14) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "1775 012 0 -10 pisos";
  int r1 = sscanf(str, "%o%o%o%o", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%o%o%o%o", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_15) {
  int integer = 5;
  int *p1a = &integer;
  int *p2a;
  int *p3a;
  char temp[50] = {'\0'};
  sprintf(temp, "%p", p1a);
  sscanf(temp, "%p", &p2a);
  s21_sscanf(temp, "%p", &p3a);
  ck_assert_ptr_eq(p2a, p3a);
}
END_TEST

START_TEST(sscanf_test_16) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "-12345%    -000456000    111    0005 pisos";
  int r1 = s21_sscanf(str, "%d%% %d %n %d", &a1, &b1, &c1, &d1);
  int r2 = sscanf(str, "%d%% %d %n %d", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_17) {
  float a1, b1, a2, b2;
  double c1, c2;
  long double d1, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1.1;
  const char str[] = "-12345.445 12.34e+07 -0.0 1234e-07 pisos";
  s21_sscanf(str, "%f%f%lf%Lf", &a1, &b1, &c1, &d1);
  sscanf(str, "%f%f%lf%Lf", &a2, &b2, &c2, &d2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_18) {
  unsigned int a1, b1, a2, b2;
  unsigned short c1, c2;
  unsigned long d1, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "0 0002 -1 -1234 666 pisos";
  int r1 = sscanf(str, "%*u%u%u%hu%lu", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%*u%u%u%hu%lu", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *sscanf_suite_d(void) {
  Suite *s = suite_create("SUITE_SSCANF");
  TCase *tc;
  tc = tcase_create("TC_SSCANF");
  tcase_add_test(tc, sscanf_test_1);
  tcase_add_test(tc, sscanf_test_2);
  tcase_add_test(tc, sscanf_test_3);
  tcase_add_test(tc, sscanf_test_4);
  tcase_add_test(tc, sscanf_test_5);
  tcase_add_test(tc, sscanf_test_6);
  tcase_add_test(tc, sscanf_test_7);
  tcase_add_test(tc, sscanf_test_8);
  tcase_add_test(tc, sscanf_test_9);
  tcase_add_test(tc, sscanf_test_10);
  tcase_add_test(tc, sscanf_test_11);
  tcase_add_test(tc, sscanf_test_12);
  tcase_add_test(tc, sscanf_test_13);
  tcase_add_test(tc, sscanf_test_14);
  tcase_add_test(tc, sscanf_test_15);
  tcase_add_test(tc, sscanf_test_16);
  tcase_add_test(tc, sscanf_test_17);
  tcase_add_test(tc, sscanf_test_18);
  suite_add_tcase(s, tc);
  return s;
}
