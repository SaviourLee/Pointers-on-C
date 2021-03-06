// C9E5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>

void my_strncat(char *dest, char *src, int dest_len) {
	int length = strlen(dest);
	char *dst = dest + length;//指向最后一个\0
	int size = dest_len - length - 1;
	if (size > 0)
		strncpy(dst, src, size);
/*	if (size > 0) {
		while (size--) {
			*dst++ = *src++;
		}
		*dst = '\0';
	}
*/

}

char* my_strcpy_end(char *dest, char* src) {
	while (*dest != '\0' && *src != '\0') {
		*dest++ = *src++;
	}
	return dest;
}

char* my_strnchr(char const *str, int ch, int which) {
	int cnt = 0;
	int length = strlen(str);
	while(length--) {
		if (*str++ == ch) {
			cnt++;
			if (cnt == which)
				return (char*)str;
		}
	}
	return NULL;
}

int count_chars(char const *str, char const *chars) {
	int cnt = 0;
	while(*chars != '\0') {
		if(strchr(str, *chars) != NULL)
			cnt++;
		chars++;
	}
	return cnt;
}
int main()
{
	char a[100] = "abcddeafd";
	char b[] = "def";
//	my_strcpy_end(a, b);
//	printf("%s\n", a);
	printf("%d\n", count_chars(a, b));
    return 0;
}

