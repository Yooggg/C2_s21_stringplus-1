#include <stdio.h>

#include "read_width.h"

extern void readNumberWithWidth(const char *str, void *data_ptr, char type,
                                int width);

int main() {
  char input[] = "Number: 12345.67";
  int int_result;
  float float_result;

  readNumberWithWidth(input + 8, &int_result, 'd', 5);
  printf("Read integer with width: %d\n", int_result);

  readNumberWithWidth(input + 8, &float_result, 'f', 8);
  printf("Read float with width: %.2f\n", float_result);

  return 0;
}