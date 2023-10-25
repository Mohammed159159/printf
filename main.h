#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int print_string(char *str);
int print_char(char c);
int print_dec(int n);
int print_bin(unsigned int n);
int printf_rot13(va_list args);
int printf_string(va_list val);
int printf_pointer(va_list val);
#endif
