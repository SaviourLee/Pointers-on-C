// C8Q8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
extern int *a;
extern int b[];


int main()
{
	int x, y;
//	x = a[3];
	printf("%x\n", (int)&b);
	printf("%x\n", (int)b);
	y = b[3];
//	printf("%x\n", (int)b);
	printf("%x\n", (int)b+3);
	printf("%x\n", (int)y);
    return 0;
}

