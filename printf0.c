#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    const char *p;

    va_start(args, format);

    for (p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            if (*p == '\0') break;
            switch (*p) {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    if (s == NULL) s = "(null)";
                    while (*s) {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default: {
                    putchar('%');
                    putchar(*p);
                    count += 2;
                    break;
                }
            }
        } else {
            putchar(*p);
            count++;
        }
    }

    va_end(args);
    return count;
}

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
