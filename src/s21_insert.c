#include "s21_string.h"
#include <string.h>
void *s21_insert(const char *src, const char *str, size_t start_index){
    size_t length = s21_strlen(src) + s21_strlen(str) + 1;
    char* product = (char*)malloc(length);
    s21_strncpy(product, src, start_index);
    product[start_index] = '\0';
    strcat(product, str);
    strcat(product, src + start_index);
    s21_strncpy((char *)src, product, length);
    free(product);
    return (void *)src;
}
