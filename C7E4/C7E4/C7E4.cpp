// C7E4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
int max_list(int firstNum, ...) {
	va_list var;
	
	va_start(var, firstNum);
	int max = firstNum;
	int num = 1;
	while (num > 0) {
		num = va_arg(var, int);
		if (num > max)
			max = num;
	}
	va_end(var);
	return max;
}

int main()
{
	printf("%d", max_list(1, 6, 3, 4, 5, -1));
    return 0;
}

