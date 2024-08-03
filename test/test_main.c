#include <stdio.h>
#include "main.h"

int main() {
    int len;

    len = _printf("Hello, %s!\n", "world");
    printf("Printed %d characters.\n", len);

    len = _printf("Character: %c\n", 'A');
    printf("Printed %d characters.\n", len);

    len = _printf("Percent sign: %%\n");
    printf("Printed %d characters.\n", len);

    return 0;
}
