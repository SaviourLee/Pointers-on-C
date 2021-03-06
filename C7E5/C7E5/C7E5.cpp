// C7E5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <stdio.h>
#include <string.h>
#include <stdarg.h>
void print_interger(int val) {
	printf("%d", val);
}
void print_float(float val) {
	printf("%f", val);
}

void print(char* format, ...) {
	va_list var;
	
	va_start(var, format);
	char ch;
	while ( (ch = *format++) != '\0') {
		if (ch != '%') {
			putchar(ch);
			continue;
		}
//		format++;
		switch (*format) {
		case 'f':
			print_float(va_arg(var, float));
			break;
		case 'd':
			print_interger(va_arg(var, int));
			break;
		case 'c':
			putchar(va_arg(var, char));
			break;
		case 's':
			char *str = va_arg(var, char*);
			while (*str != '\0')
				putchar(*str++);
			break;
		}
		format++;

	}

	va_end(var);

}

int main()
{
	print("%s, /% %d",  "afdaf", 1);
    return 0;
}

