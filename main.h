#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct format {
	char spec;
	int (*handler)();
} conversion;

int _printf(const char *format, ...);
int print_string(va_list args);
int print_char(va_list args);
int print_dec(int n);
int print_bin(unsigned int n);

#endif
