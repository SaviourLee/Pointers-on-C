// C4E7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deblank(char *string) {
#if 0
	bool space_flag = false;
	char replace[100];
	int str_index;
	int rep_index = 0;
	for (str_index = 0; string[str_index] != '\0'; ++str_index) {
		if (string[str_index] == ' ') {
			//			printf("index: %d\n", str_index);
			for (int j = str_index; string[j] == ' '; j++) {
				//				printf("-%c-\n", string[j]);
				str_index++;
			}
			replace[rep_index] = ' ';
			rep_index++;
		}
		//		printf("str_index: %d, rep_index: %d\n", str_index, rep_index);
		replace[rep_index] = string[str_index];
		rep_index++;
	}
	replace[rep_index] = '\0';
	strcpy(string, replace);

#endif
	char *src = string;
	char *des = string++;
	char ch;
	while ((ch = *src++) != '\0') {
//		printf("-%c-\n", *src);
		if (ch == ' ') {
			if (src == string || des[-1] != ' ')	//如果本空格前一个字符不是空格，则向dst写入一个空格
				*des++ = ' ';
		}
		else
			*des++ = ch;
	}
	*des = '\0';
}

int main() {
	char str[100] = " ab    cc   d  dd      e";
	deblank(str);
	printf("%s", str);
	int a = 2;
	printf("%d", sizeof(a = 6));
	printf("%d", a);

	return 0;
}
