// C6Q7.cpp: 定义控制台应用程序的入口点。
//
//Chapter6 Question7 
//The answer has an error on v.
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **h = NULL;
	int *i = (int *)&h;
	h = (int **)&i;
	printf(" &h = %d\n", (int)&h);
	printf("  h = %d\n", (int)h);
	printf(" *h = %d\n", (int)*h);
	printf("**h = %d\n", (int)**h);
    return 0;
}

