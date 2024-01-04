#include "s21_string.h"

#define S21_LONG_MAX_STR_DEC "9223372036854775807"
#define S21_LONG_MIN_STR_DEC "9223372036854775808"
#define S21_ULONG_MAX_STR_DEC "18446744073709551615"
#define S21_LONG_MAX_STR_HEX "7fffffffffffffff"
#define S21_LONG_MIN_STR_HEX "8000000000000000"
#define S21_ULONG_MAX_STR_HEX "ffffffffffffffff"
#define S21_LONG_MAX_STR_OCT "777777777777777777777"
#define S21_LONG_MIN_STR_OCT "1000000000000000000000"
#define S21_ULONG_MAX_STR_OCT "1777777777777777777777"

void scnClearParameters(ScnParams *Param) {
  Param->spec = 0;
  Param->width = 0;
  Param->length = 0;
  Param->signBit = 0;
  Param->i = 0;
  Param->suppress = 0;
}

/*
Функция посимвольно считывает строку формата, записывая считанные данные в
соответствующие поля структуры Param
*/
int scnParser(const char *str, ScnParams *Param) {
  int shift = 1;
  while (!Param->spec) {
    if (s21_strchr("cdieEfgGosuxXpn%", str[shift]))
      Param->spec = str[shift];
    else if (s21_strchr("hlL", str[shift]))
      Param->length = str[shift];
    else if ('0' <= str[shift] && str[shift] <= '9')
      Param->width = Param->width * 10 + str[shift] - '0';
    else if (str[shift] == '*')
      Param->suppress = str[shift];
    if (!Param->spec) shift++;
  }
  return shift;
}

/*
Функция возвращает true, если c является пробельным символом:
[\t][ASCII 9] горизонтальная табуляция,
[\n][ASCII 10] новая строка (new line),
[\v][ASCII 11] вертикальная табуляция,
[\f][ASCII 12] новая страница (new page),
[\r][ASCII 13] возврат каретки,
[ ][ASCII 32] пробел (space)
*/
bool s21_isspace(int c) {
  bool result = false;
  if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
    result = true;
  return result;
}

// Функция возвращает количество пробельных символов
int skipBlankSpace(const char *s) {
  int i = 0;
  for (; s[i]; i++)
    if (!s21_isspace(s[i])) break;
  return i;
}

/*
Функция сравнивает паттерн сохраненный в буфере со строкой, если паттерн
(разделитель) не совпадает, то возвращает ошибку, в этом случае указатель
остановится на последнем совпадающем символе.
*/
int searchPattern(const char *s, ScnParams *Param, int *shift) {
  int error = 1;
  if (Param->i) {
    for (int j = 0; j < Param->i;) {
      int skip = skipBlankSpace(Param->buff + j);
      if (skip) {
        *shift += skipBlankSpace(s + *shift);
        j += skip;
        skip = 0;
      } else if (Param->buff[j] == s[*shift]) {
        (*shift)++;
        j++;
      } else {
        error = 0;
        break;
      }
    }
  }
  if (!s21_strchr("c%", Param->spec)) *shift += skipBlankSpace(s + *shift);
  return error;
}

int s21_strToChr(const char *s, int *hit, ScnParams *Param, va_list *argptr) {
  int i = 0;
  if (*hit == 0 && *s == '\0')
    *hit = -1;
  else {
    if (s[i]) {
      if (Param->suppress) {
        (void)s[i++];
      } else {
        *va_arg(*argptr, char *) = s[i++];
        ++*hit;
      }
    }
  }
  return i;
}

/*
Функция определяет какое основание имеет число:
если число начинается с '0x', то base 16;
если число начинается с '0', то base 8;
в остальных случаях считаем, что base 10.
*/
int defineBaseForSpec_i(const char *s) {
  int base = Decimal;
  char buf[2];
  int i = 0;
  for (; i < 2 && s[i] != '\0'; i++) buf[i] = s21_toLowerCase(s[i]);
  if (i == 2)
    if (buf[0] == '0') {
      if (buf[1] == 'x')
        base = Hexadecimal;
      else
        base = Octal;
    }
  return base;
}

// Функция возвращает основание системы счисления для целочисленных типов в
// зависимости от объявленного спецификатора
int defineIntegerBase(const char *s, ScnParams *Param) {
  int base;
  if (Param->spec == 'd' || Param->spec == 'u')
    base = Decimal;
  else if (Param->spec == 'o')
    base = Octal;
  else if (Param->spec == 'i') {
    if (Param->width == 1)
      base = Decimal;
    else
      base = defineBaseForSpec_i(s);
  } else {
    base = Hexadecimal;
    if (Param->spec == 'p') Param->length = 'l';
  }
  return base;
}

// Функция возвращает количество ведущих нулей в числе
int skipLeadingZeros(const char *s, ScnParams *Param) {
  int i = 0;
  for (; s[i] && (!Param->width || i < Param->width); i++)
    if (s[i] != '0') break;
  return i;
}

// Функция возвращает true, если символ является цифрой (0-9) или буквой a-f,
// соответствующей числу 10-15 для шестнадцатиричной системы счисления
bool s21_is_digit(char c, int base) {
  bool result;
  if (base == Decimal)
    result = ('0' <= c && c <= '9');
  else if (base == Octal)
    result = ('0' <= c && c <= '7');
  else {
    result = (s21_is_digit(c, Decimal) || ('a' <= c && c <= 'f'));
  }
  return result;
}

/*
Функция проверяет, что символ является цифрой десятичной, восьмеричной или
шестнадцатеричной системы счисления. Буквы английского алфавита соответствующие
цифрам 10-15 шестнадцатиричной системы приводятся к нижнему регистру. Затем
буква конвертируется в число в десятичной системе вычитанием соответствующего
символа из таблицы ASCII. Если символ цифра 0-9, то число получается вычитанием
символа '0', если символ буква a-f, то вычитанием символа 'W'.
*/
bool NumberConverter(char c, int base, int *tmp) {
  bool result;
  bool is_digit = false;
  c = s21_toLowerCase(c);

  if (base == Decimal)
    result = is_digit = s21_is_digit(c, base);
  else if (base == Octal)
    result = is_digit = s21_is_digit(c, base);
  else {
    is_digit = ('0' <= c && c <= '9');
    result = (is_digit || s21_is_digit(c, base));
  }

  if (result) {
    if (is_digit)
      *tmp = c - '0';
    else
      *tmp = c - 'W';
  }

  return result;
}

// Функция копирует строку src в dest, завершая строку нуль-терминатором
char *s21_strcpy(char *dest, const char *src) {
  char *ptr = dest;
  for (; *src; dest++, src++) *dest = *src;
  *dest = '\0';
  return ptr;
}

/*
Функция проверяет произошло ли переполнение для типа long int. Если считано
символов больше, чем может быть представлено в шестнадцатиричном, восьмиричном
представлении числа или десятичном (для знакового или беззнакового типа), то это
переполнение. Иначе посимвольно сравниваем строку s со строковой константой для
соответствующего типа.
*/
bool overflowCheck(const char *s, ScnParams *Param, int count, int base) {
  bool result;
  char buf[23];
  int len;
  if (Param->spec == 'u') {
    s21_strcpy(buf, S21_ULONG_MAX_STR_DEC);
    len = 20;
  } else if (base == Decimal) {
    if (Param->signBit == '-')
      s21_strcpy(buf, S21_LONG_MIN_STR_DEC);
    else
      s21_strcpy(buf, S21_LONG_MAX_STR_DEC);
    len = 19;
  } else if (base == Octal) {
    len = 22;
    if (Param->spec == 'i') {
      if (Param->signBit == '-')
        s21_strcpy(buf, S21_LONG_MIN_STR_OCT);
      else {
        s21_strcpy(buf, S21_LONG_MAX_STR_OCT);
        len = 21;
      }
    } else
      s21_strcpy(buf, S21_ULONG_MAX_STR_OCT);
  } else {
    if (Param->spec == 'i') {
      if (Param->signBit == '-')
        s21_strcpy(buf, S21_LONG_MIN_STR_HEX);
      else
        s21_strcpy(buf, S21_LONG_MAX_STR_HEX);
    } else
      s21_strcpy(buf, S21_ULONG_MAX_STR_HEX);
    len = 16;
  }
  if (count > len)
    result = true;
  else if (count == len)
    result = (s21_strncmp(s, buf, len) >= 0);
  else
    result = false;
  return result;
}

// Функция возвращает максимальное или минимальное значение или максимальное
// беззнаковое значение для типа long int
long int overflowReplace(ScnParams *Param, long int value) {
  if (Param->spec == 'd' || Param->spec == 'i') {
    if (Param->signBit == '-')
      value = LONG_MIN;
    else
      value = LONG_MAX;
  } else
    value = ULONG_MAX;
  return value;
}

// Сохранение значения целочисленного типа по указателю в зависимости от
// объявленного спецификатора длины
void assignIntegerValue(ScnParams *Param, va_list *argptr, long value) {
  if (Param->length == 'l')
    *va_arg(*argptr, long *) = value;
  else if (Param->length == 'h')
    *va_arg(*argptr, short int *) = value;
  else
    *va_arg(*argptr, int *) = value;
}

/*
Функция присваивает значение переменной по указателю в зависимости от
определенного спецификатора. Возвращает количество прочитанных символов, которые
удалось преобразовать в число. В зависимости от спецификатора число переводится
систему счисления с основанием 8, 10 или 16.
*/
int s21_strToInt(const char *s, int *hit, ScnParams *Param, va_list *argptr) {
  int i = 0;

  if (*hit == 0 && *s == '\0')
    *hit = -1;
  else {
    long result = 0L;
    if (s[i] == '-' || s[i] == '+') Param->signBit = s[i++];

    int base = defineIntegerBase(s + i, Param);

    if (base == Hexadecimal)
      if (s[i] == '0' && (s21_toLowerCase(s[i + 1]) == 'x')) i += 2;

    if (!Param->width || i < Param->width)
      i += skipLeadingZeros(s + i, Param);  // skip leading zeros
    int j = 0;
    for (int tmp; s[i] && (!Param->width || i < Param->width); i++, j++) {
      if (NumberConverter(s[i], base, &tmp))
        result = result * base + tmp;
      else
        break;
    }

    if (Param->signBit == '-') result = ~result + 1L;

    if (overflowCheck(s + i - j, Param, j, base))
      result = overflowReplace(Param, result);

    if (i == 1 && Param->signBit) i = 0;

    if (i) {
      if (Param->suppress)
        (void)result;
      else {
        assignIntegerValue(Param, argptr, result);
        ++*hit;
      }
    }
  }
  return i;
}

void s21_n_Spec(const int *bytes, ScnParams *Param, va_list *argptr) {
  long result = *bytes;
  assignIntegerValue(Param, argptr, result);
}

int s21_strToStr(const char *s, int *hit, ScnParams *Param, va_list *argptr) {
  int i = 0;

  if (*hit == 0 && *s == '\0')
    *hit = -1;
  else {
    if (Param->suppress) {
      for (; s[i] && (!Param->width || i < Param->width); i++)
        if (s21_isspace(s[i])) break;
    } else {
      char *ptr = va_arg(*argptr, char *);
      for (; s[i] && (!Param->width || i < Param->width); i++) {
        if (s21_isspace(s[i]))
          break;
        else
          ptr[i] = s[i];
      }
      ptr[i] = '\0';
    }

    if (i)
      if (!Param->suppress) ++*hit;
  }
  return i;
}

// Функция возвращает true если в строке встретились первые буквы ключевых слов
// NAN или INF
bool checkSpecialValues(const char *s, int *index) {
  bool result;
  char tmp = s21_toLowerCase(s[*index]);
  if (tmp == 'n' || tmp == 'i')
    result = true;
  else
    result = false;
  return result;
}

// Функция присваивает значение NAN или INF в переменную result
long double assignSpecialValues(const char *s, ScnParams *Param, int *index) {
  long double result = 0.0L;
  if (!Param->width || *index + 3 < Param->width) {
    int i = 0;
    char buf[3];
    for (; i < 3 && s[i] != '\0'; i++) buf[i] = s21_toLowerCase(s[i]);
    if (i == 3) {
      bool assignFlag = true;
      if (s21_strncmp(buf, "nan", 3) == 0)
        result = NAN;
      else if (s21_strncmp(buf, "inf", 3) == 0)
        result = INFINITY;
      else
        assignFlag = false;
      if (assignFlag) (*index) += 3;
    }
  }
  return result;
}

// Функция переводит строковое представление числа в тип long double, чтение
// продолжается до тех пор, пока в строке встречаются цифры
long double calculator(const char *s, ScnParams *Param, int *index) {
  long double result = 0.0L;
  for (; s[*index] && (!Param->width || *index < Param->width); (*index)++) {
    if ('0' <= s[*index] && s[*index] <= '9')
      result = result * Decimal + s[*index] - '0';
    else
      break;
  }
  return result;
}

void exponentiation(const char *s, ScnParams *Param, int *index,
                    long double *result) {
  if (!Param->width || *index < Param->width) {
    bool sign;
    (*index)++;
    if ((sign = (s[*index] == Minus)) || s[*index] == Plus)
      if (!Param->width || *index < Param->width) (*index)++;

    long double tmp = calculator(s, Param, index);
    if (sign)
      for (; tmp > 0.0L; tmp -= 1.0L) *result /= 10.0;
    else
      for (; tmp > 0.0L; tmp -= 1.0L) *result *= 10.0;
  }
}

/*
Функция конвертирует строковое представление числа с плавающей точкой в число
типа long double. Вначале считывается целая часть числа, далее, если встречается
символ '.', считывается дробная часть числа. Если встречается символ 'e', значит
число представлено в экспоненциальном виде.
*/
long double calculations(const char *s, ScnParams *Param, int *index) {
  long double result = calculator(s, Param, index);
  if (!Param->width || Param->width > 1) {
    if (s[*index] == '.') {
      (*index)++;
      long double tmp = calculator(s, Param, index);
      while (tmp >= 1.0L) tmp /= 10.0L;
      result += tmp;
    }
    if (s[*index] == 'e' || s[*index] == 'E') {
      if (*index == 0 || ((*index == 1 || (*index == 2 && Param->signBit)) &&
                          s[*index - 1] == '.'))
        *index = 0;
      else
        exponentiation(s, Param, index, &result);
    }
  }
  return result;
}

int s21_strToFP(const char *s, int *hit, ScnParams *Param, va_list *argptr) {
  int i = 0;

  if (*hit == 0 && *s == '\0')
    *hit = -1;
  else {
    long double result;

    if (s[i] == '-' || s[i] == '+') Param->signBit = s[i++];

    if (checkSpecialValues(s, &i))
      result = assignSpecialValues(s + i, Param, &i);
    else {
      if (!Param->width || i < Param->width)
        i += skipLeadingZeros(s + i, Param);  // skip leading zeros
      result = calculations(s, Param, &i);
    }

    if (Param->signBit == '-') result = -result;

    if (i == 1 && Param->signBit) i = 0;

    if (i) {
      if (Param->suppress)
        (void)result;
      else {
        if (Param->length == 'L')
          *va_arg(*argptr, long double *) = result;
        else if (Param->length == 'l')
          *va_arg(*argptr, double *) = result;
        else
          *va_arg(*argptr, float *) = result;
        ++*hit;
      }
    }
  }

  return i;
}

int s21_percent_Spec(const char *s) {
  int i = 0;
  if (s[i] == '%') i++;
  return i;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list argptr;
  va_start(argptr, format);
  int fields = 0;
  ScnParams Param = {0};
  scnClearParameters(&Param);
  int bytes = 0;
  int error = 1;
  for (char *c = (char *)format; *c && fields != -1 && error; c++) {
    if (*c == '%')
      c += scnParser(c, &Param);
    else
      Param.buff[Param.i++] = *c;

    if (Param.spec) {
      int bs = 0;  // skip blank space or pattern
      error = searchPattern(str + bytes, &Param, &bs);
      bytes += bs;
      if (!error) break;
      if (Param.spec == 'c') {
        bytes += error = s21_strToChr(str + bytes, &fields, &Param, &argptr);
      } else if (s21_strchr("diuoxXp", Param.spec)) {
        bytes += error = s21_strToInt(str + bytes, &fields, &Param, &argptr);
      } else if (Param.spec == 'n') {
        s21_n_Spec(&bytes, &Param, &argptr);
      } else if (Param.spec == 's') {
        bytes += error = s21_strToStr(str + bytes, &fields, &Param, &argptr);
      } else if (s21_strchr("eEfgG", Param.spec)) {
        bytes += error = s21_strToFP(str + bytes, &fields, &Param, &argptr);
      } else
        bytes += error = s21_percent_Spec(str + bytes);

      scnClearParameters(&Param);
    }
  }
  va_end(argptr);
  return fields;
}

/*
sscanf Specifiers:
No  Specifier   sprintf output
1     <c>       Character
2     <d>       Signed decimal integer
3     <i>       Signed integer (may be decimal, octal or hexadecimal)
4     <e>       Decimal floating point or scientific notation
                (mantissa/exponent)
5     <E>       Decimal floating point or scientific notation
                (mantissa/exponent)
6     <f>       Decimal floating point or scientific notation
                (mantissa/exponent)
7     <g>       Decimal floating point or scientific notation
                (mantissa/exponent)
8     <G>       Decimal floating point or scientific notation
                (mantissa/exponent)
9     <o>       Unsigned octal
10    <s>       String of characters
11    <u>       Unsigned decimal integer
12    <x>       Unsigned hexadecimal integer (any letters)
13    <X>       Unsigned hexadecimal integer (any letters)
14    <p>       Pointer address
15    <n>       Number of characters scanned until %n occurs
16    <%>       Character %

sscanf Width Description
1   <number>    Minimum number of characters to be printed. If the value to be
                printed is shorter than this number, the result is padded with
                blank spaces. The value is not truncated even if the result is
                larger.
2     <*>       In sprintf the * sign means, that the width is not specified in
                the format string, but as an additional integer value argument
                preceding the argument that has to be formatted. In sscanf the *
                sign placed after % and before the format specifier reads data
                of the specified type, but suppresses their assignment.

sscanf Length Description
1     <h>       The argument is interpreted as a short int or unsigned short int
                (only applies to integer specifiers: i, d, o, u, x and X).
2     <l>       The argument is interpreted as a long int or unsigned long int
                for integer specifiers (i, d, o, u, x and X), and as a wide
                character or wide character string for specifiers c and s.
3     <L>       The argument is interpreted as a long double (only applies to
                floating point specifiers − e, E, f, g and G).
*/