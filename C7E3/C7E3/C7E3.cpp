// C7E3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

int ascii_to_integer(char *string) {
	int result = 0;
	while (*string >= '0' && *string <= '9') {
		result += *string - '0';
		result *= 10;
		string++;
	}
	if (*string == '\0')
		return 0;
	return result / 10;
}

int main()
{
	printf("%d", ascii_to_integer("11"));
    return 0;
}

