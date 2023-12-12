#include "s21_string.h"

void s21_to_lower(const char *str){
    char output[s21_strlen(str) + 1];
    for (size_t i = 0; i < s21_strlen(str); i++)
    {   
        output[i] = str[i];
        if ('A' <= str[i] && 'Z' >= str[i]){
            output[i] -= ('A'-'a');
        }
        printf("%c",output[i]);
    }
    
}
