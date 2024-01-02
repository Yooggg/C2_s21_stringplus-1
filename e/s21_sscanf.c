#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readNumberWithWidth(const char *str, int *int_ptr, int width) {
    int value = 0;
    int sign = 1;
    int i = 0;
    
    // Определяем знак числа
    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    // Пропускаем нули перед числом (если они есть)
    while (str[i] == '0') {
        i++;
    }

    // Считываем число, учитывая указанную ширину поля
    int count = 0;
    while (str[i] >= '0' && str[i] <= '9' && count < width) {
        value = value * 10 + (str[i] - '0');
        i++;
        count++;
    }

    // Пропускаем оставшуюся часть числа, если она превышает указанную ширину
    while (str[i] >= '0' && str[i] <= '9') {
        i++;
    }

    *int_ptr = value * sign;
}

int int_counter(int a) {
    int count = 0;
    while (a > 0) {
        a = a / 10;
        count++;
    }
    return count;
}

int double_counter(double a) {
    char drob_buffer[1000];
    sprintf(drob_buffer, "%g", a);
    return strlen(drob_buffer);
}


int s21_sscanf(const char *str, const char *format, ...) {
    va_list args;
    int count = 0;
    size_t str_index = 0, format_index = 0;
    va_start(args, format);

    while (format[format_index] != '\0') {
        if (format[format_index] == '%' && format[format_index + 1] != '\0') {
            format_index++;  // переходим к символу после '%'
            int width = 0;
            if (format[format_index] >= '0' && format[format_index] <= '9') {
                width = format[format_index] - '0'; // получаем ширину поля
                format_index++;
            }
            switch (format[format_index]) {
case 'd': { // целое число
    int *int_ptr = va_arg(args, int *);
    readNumberWithWidth(str + str_index, int_ptr, width > 0 ? width : 0);
    int digits = int_counter(*int_ptr);
    str_index += (width > 0 && width > digits) ? width : digits; // учитываем ширину поля
    count++;
    break;
}
case 'f': { // вещественное число
    float *float_ptr = va_arg(args, float *);
    *float_ptr = strtof(str + str_index, NULL);
    int double_width = double_counter(*float_ptr);
    str_index += (width > 0 && width > double_width) ? width : double_width; // учитываем ширину поля
    count++;
    break;
}
                case 'c': {
                    char *char_ptr = va_arg(args, char *);
                    *char_ptr = str[str_index];
                    str_index++;
                    count++;
                    break;
                }
        case 's': {
          if (str[str_index] != '\0') {
            char *str_arg = va_arg(args, char *);
            int str_len = 0;
            while (str[str_index] != '\0' && str[str_index] != '\n' && str_len < width) {
              if (str[str_index] == ' ' && str_len == 0) {
                str_index++;
                continue;
              }
              str_arg[str_len] = str[str_index];
              str_len++;
              str_index++;
            }
            str_arg[str_len] = '\0';
            str_index += (width > str_len) ? width - str_len : 0; // учитываем ширину поля
            count++;
          } else {
            printf("ERROR: Not enough characters in str.\n");
            break;
          }
          break;
        }
        case 'i': {
        
          char *endptr;
          int *int_ptr = va_arg(args, int *);
          *int_ptr = strtol(str + str_index, &endptr, 0);
          str_index = endptr - str;
          str_index += width; 
          count++;
          break;
        }
        case 'e':
        case 'E': {
       
          char *endptr;
          float *float_ptr = va_arg(args, float *);
          *float_ptr = strtold(str + str_index, &endptr);
          str_index = endptr - str;
          str_index += width; 
          count++;
          break;
        }
        case 'g':
        case 'G': {
        
          float *float_ptr = va_arg(args, float *);
          *float_ptr = strtod(str + str_index, NULL);
          str_index += double_counter(*float_ptr);
          str_index += width; 
          count++;
          break;
        }
        case 'u': {
        
            char *endptr;
            unsigned int *uint_ptr = va_arg(args, unsigned int *);
            *uint_ptr = strtoul(str + str_index, &endptr, 10);
            str_index = endptr - str;
            int digits = endptr - (str + str_index); 
            str_index += width - digits; 
            count++;
            break;
        }

        case 'o': {
         
          char *endptr;
          unsigned int *uint_ptr = va_arg(args, unsigned int *);
          *uint_ptr = strtoul(str + str_index, &endptr, 8);
          str_index = endptr - str;
          int digits = endptr - (str + str_index); 
          str_index += width - digits; 
          count++;
          break;
        }
        case 'x':
        case 'X': {
     
          char *endptr;
          
          unsigned int *uint_ptr = va_arg(args, unsigned int *);
          *uint_ptr = strtoul(str + str_index, &endptr, 16);
          str_index = endptr - str;
          int digits = endptr - (str + str_index); 
          str_index += width - digits; 
          count++;
          break;
        }
        case 'p': {
      
          char *endptr;
          void **void_ptr = va_arg(args, void **);
          *void_ptr = (void *)strtoul(str + str_index, &endptr, 16);
          str_index = endptr - str;
          int digits = endptr - (str + str_index); 
          str_index += width - digits; 
          count++;
          break;
        }
        case 'n': {
 
          int *int_ptr = va_arg(args, int *);
          *int_ptr = str_index;
          break;
        }
        case '%':{
            char *char_ptr = va_arg(args, char *);
            *char_ptr = '%';
            count++;
            break;
        }
        default:
          printf("ERROR: Unsupported format specifier.\n");
          break;
      }
      format_index++;
    } else {
      format_index++;
    }
  }

  va_end(args);

  return count;
}

int main() {
    // Test 1: Reading integer with width
    char input1[] = "Number: 12345";
    int number1;
    s21_sscanf(input1, "Number: %5d", &number1);
    printf("Test 1 (s21_sscanf): Read number with width: %d\n", number1);

    sscanf(input1, "Number: %5d", &number1);
    printf("Test 1 (sscanf): Read number with width: %d\n\n", number1);

    // Test 2: Reading string with width
    char input2[] = "Text: HelloWorld";
    char text2[10];
    s21_sscanf(input2, "Text: %9s", text2);
    printf("Test 2 (s21_sscanf): Read text with width: %s\n", text2);

    sscanf(input2, "Text: %9s", text2);
    printf("Test 2 (sscanf): Read text with width: %s\n\n", text2);

    // Test 3: Reading float with width
    char input3[] = "Float: 12.345";
    float float3;
    s21_sscanf(input3, "Float: %6f", &float3);
    printf("Test 3 (s21_sscanf): Read float with width: %.3f\n", float3);

    sscanf(input3, "Float: %6f", &float3);
    printf("Test 3 (sscanf): Read float with width: %.3f\n\n", float3);

    // Test 4: Reading hexadecimal number with width
    char input4[] = "Hex: ABCDEF";
    unsigned int hex4;
    s21_sscanf(input4, "Hex: %4x", &hex4);
    printf("Test 4 (s21_sscanf): Read hex with width: %x\n", hex4);

    sscanf(input4, "Hex: %4x", &hex4);
    printf("Test 4 (sscanf): Read hex with width: %x\n\n", hex4);

    return 0;
}
