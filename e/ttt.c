#include <stdio.h>

int main() {
  const char *input = "   12345a123kfg";
  int num;

  int result = sscanf(input, "%8d", &num);

  if (result == 1) {
    printf("Число: %d\n", num);
  } else {
    printf("Не удалось интерпретировать число.\n");
  }

  return 0;
}