#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int print_string(char *str);
int print_char(char ch);
int print_dec(int n);
int print_bin(unsigned int n);

#endif
