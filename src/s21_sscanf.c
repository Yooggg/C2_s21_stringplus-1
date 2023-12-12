#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (str[str_index] == format[format_index] ) { // проебка случайное совпадние 
      str_index++;
      format_index++;
      continue;
    }

    if (format[format_index] == ' ') {
      while (format[format_index] == ' ' && format[format_index + 1] != '\0') {
        format_index++;
      }
      continue;
    }

    if (format[format_index] == '%' && format[format_index + 1] != '\0') {
      format_index++;  // пошел дальше процентика '%'
      if(format[format_index] == '*')  
      { 
        while(str[str_index] != ' ' && str[str_index] != '\0')   {
        str_index++;
      }  
      

        continue;

      }
      switch (format[format_index]) {
    case 'c': {
                    char *char_ptr = va_arg(args, char *);
                    *char_ptr = str[str_index];
                    str_index++;
                    count++;
                    break;
                }
        case 'd': {
          int *int_ptr = va_arg(args, int *);
          *int_ptr = atoi(str + str_index);
          str_index += int_counter(*int_ptr);
          count++;
          break;
        }
        case 'f': {
          float *float_ptr = va_arg(args, float *);
          *float_ptr = strtof(str + str_index, NULL);
          str_index += double_counter(*float_ptr);
          count++;
          break;
        }
        case 's': {
       
            
          if (str[str_index] != '\0') {
            char *str_arg = va_arg(args, char *);
            int str_len = 0;
            while (str[str_index] != '\0' &&
                   str[str_index] != '\n') {
                                         //"1234 5678 abcd 1A FF";
                if(str[str_index] == ' ' && str_len == 0){
                  str_index++;
                    continue;
                }

              str_arg[str_len] = str[str_index];
              str_len++;
              str_index++;
               if(str[str_index] == ' '){
            
            break;
            }
            }
             str_arg[str_len] = '\0';
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
          count++;
          break;
        }
        case 'e':
        case 'E': {
       
          char *endptr;
          float *float_ptr = va_arg(args, float *);
          *float_ptr = strtold(str + str_index, &endptr);
          str_index = endptr - str;
          count++;
          break;
        }
        case 'g':
        case 'G': {
        
          float *float_ptr = va_arg(args, float *);
          *float_ptr = strtod(str + str_index, NULL);
          str_index += double_counter(*float_ptr);
          count++;
          break;
        }
        case 'u': {
    
          char *endptr;
          unsigned int *uint_ptr = va_arg(args, unsigned int *);
          *uint_ptr = strtoul(str + str_index, &endptr, 10);
          str_index = endptr - str;
          count++;
          break;
        }
        case 'o': {
         
          char *endptr;
          unsigned int *uint_ptr = va_arg(args, unsigned int *);
          *uint_ptr = strtoul(str + str_index, &endptr, 8);
          str_index = endptr - str;
          count++;
          break;
        }
        case 'x':
        case 'X': {
     
          char *endptr;
          
          unsigned int *uint_ptr = va_arg(args, unsigned int *);
          *uint_ptr = strtoul(str + str_index, &endptr, 16);
          str_index = endptr - str;
          

          count++;
          break;
        }
        case 'p': {
      
          char *endptr;
          void **void_ptr = va_arg(args, void **);
          *void_ptr = (void *)strtoul(str + str_index, &endptr, 16);
          str_index = endptr - str;
          count++;
          break;
        }
        case 'n': {
 
          int *int_ptr = va_arg(args, int *);
          *int_ptr = str_index;
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
    // Test 4: Ignore String and Character
    char input4[] = "Ignore This String 'C'";
    char ignoredString4[50], ignoredChar4;
    s21_sscanf(input4, "%*s %s %*s %*c %c", ignoredString4, &ignoredChar4);
    printf("Test 4 (s21_sscanf): %s %c\n", ignoredString4, ignoredChar4);

    sscanf(input4, "%*s %s %*s %*c %c", ignoredString4, &ignoredChar4);
    printf("Test 4 (sscanf): %s %c\n\n", ignoredString4, ignoredChar4);

    // Test 5: Ignore Multiple Characters and Integers
    char input5[] = "Ignore: AB -123 CD 456";
    char ignoredChars5[10];
    int ignoredInt5a, ignoredInt5b;
    s21_sscanf(input5, "Ignore: %*c %*c %*d %*s %*c %d %s %d", &ignoredInt5a, ignoredChars5, &ignoredInt5b);
    printf("Test 5 (s21_sscanf): %d %s %d\n", ignoredInt5a, ignoredChars5, ignoredInt5b);

    sscanf(input5, "Ignore: %*c %*c %*d %*s %*c %d %s %d", &ignoredInt5a, ignoredChars5, &ignoredInt5b);
    printf("Test 5 (sscanf): %d %s %d\n\n", ignoredInt5a, ignoredChars5, ignoredInt5b);

    return 0;
}
