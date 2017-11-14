// C6E1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
char *find_char(char const *source, char const *chars) {
	if (source == NULL || chars == NULL)
		return NULL;
	if (source == '\0' || chars == '\0')
		return NULL;

	while (*source != '\0') {
		char const *p = chars;
		while (*p!= '\0') {
			if (*source == *p)
				return (char*)source;
			p++;
		}
		source++;
	}
	return NULL;



}

int main()
{
	int i = 1;

    return 0;
}

