#include "s21_string.h"
// Размер буфера по умолчанию
#define BUFFSIZE 1024
typedef struct {
  int spec;             // support Specifiers below
  int width;            // ширина
  int length;           // разные типы интов
  int sign;             // плюс или минус ширина
  char buff[BUFFSIZE];  // массив для мусора
  int i;                // индекс мусорного массива
  char zvezda;          // это игнор
} SSCANF;
void cleaning(SSCANF *params) {
  params->spec = 0;
  params->width = 0;
  params->length = 0;
  params->sign = 0;
  params->i = 0;  //индекс массива
  params->zvezda = '\0';
  // Инициализация массива buff нулями
  for (int j = 0; j < BUFFSIZE; ++j) {
    params->buff[j] = 0;
  }
}
int PARSER(const char *str,
           SSCANF *Param) {  //ЗДЕСЬ МЫ ПЕРЕДАЕМ ФОРМАТНУЮ СТРОКУ И
                             //ДВИЖЕМСЯ,ПОКА НЕ СОБЕРЕМ СЕЦИФИКАТОР
  int shift = 1;
  while (!Param->spec) {
    if (s21_strchr("GosexcdiuEfgXpn%", str[shift]))
      Param->spec = str[shift];
    else if (s21_strchr("hlL", str[shift]))
      Param->length = str[shift];
    else if ('0' <= str[shift] && str[shift] <= '9')
      Param->width = Param->width * 10 + str[shift] - '0';
    else if (str[shift] == '*')
      Param->zvezda = str[shift];
    if (!Param->spec) shift++;
  }
  return shift;
}

int CHAR_FUNC(va_list *argc, int *count, const char *str, int *str_index) {
  char *char_ptr = va_arg(args, char *);
  *char_ptr = str[str_index];
  str_index++;
  count++;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  int count = 0, format_index = 0, width = 0, str_index = 0;
  va_start(args, format);
  SSCANF Param = {0};
  cleaning(&Param);
  while (format[format_index] != '\0') {
    if (format[format_index] == '%' && format[format_index + 1] != '\0') {
      format_index += PARSER(format, &Param);
    } else
      Param.buff[Param.i++] =
          format[format_index];  // это увеличение индекса массива для ненужных
                                 // символов

    format_index += PARSER(format, &Param);  //движемся по форматной строке
    //теперь условие обработки благодаря нашей замечательной структуре
    if (Param.spec != 0) {
      if (Param.spec ==
          'c') {  // самая простая обработка, поэтому засунул в начало
        char *char_ptr = va_arg(args, char *);
        *char_ptr = str[str_index];
        str_index++;
        count++;
      }

      return count;
    }
