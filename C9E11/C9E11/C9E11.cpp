// C9E11.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char const whitespace[] = " \n\r\f\t\v";
int countThe() {
	int cnt = 0;
	char str[100];
/*
	while (*str != '\0') {
		while (isspace(*str)) {
			str++;
		}
		if (*str == 't' && *(str+1) == 'h' && *(str+2) == 'e') {
			cnt++;
		}
		str++;
	}
	*/
	while (gets_s(str, 100)) {
		char *word;

		for (word = strtok(str, whitespace); word != NULL; word = strtok(NULL, whitespace)){
			//printf("%s", str);
			if (strcmp(word, "the") == 0) {
				cnt++;
				
			}
		}
	}
//	printf("%d", cnt);
	return cnt;
}

int main()
{
	char sentence[] = "the The THe tHe the";
	printf("%d\n", countThe());
    return 0;
}

