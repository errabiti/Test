#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int _putch(char c);
int print_string(char *s);
int len(int num);
int print_int(int n);
int _printf(const char *format, ...);
#endif /* MAIN_H */
