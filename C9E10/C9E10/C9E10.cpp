// C9E10.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
int palindrome(char *string) {
	char *end = string + strlen(string) - 1;
//	while (*(end + 1) != '\0')	//找到最后一个字符
//		end++;

	while (string > end) {
		while (!isalpha(*string))
			string++;
		while (!isalpha(*end))
			end--;
		if (toupper(*string) != toupper(*end))
			return FALSE;
		string++;
		end--;
	}
	return TRUE;
}

int main()
{
    return 0;
}

