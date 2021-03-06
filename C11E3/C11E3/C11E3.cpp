// C11E3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAX 100
#define DELTA 1
char *storeStr() {
	char *str = (char *)malloc(MAX * sizeof(char));
	scanf("%s", str);
	return str;
}

char *readString() {
	int len = 0;
	static int bufferSize = 0;
	static char *buf = NULL;
	char *ret = buf;
	char ch;
	do{
		ch = getchar();
		if (ch == '\n' || ch == EOF)
			ch = '\0';
		if (len >= bufferSize) {
			bufferSize += DELTA;
			buf = (char *)realloc(buf, bufferSize);
			printf("realloc()\n");
			assert(buf != NULL);
			ret = buf + len;  //重要！如果buf的地址因为realloc改变了，此时必须重新对ret赋值！！
		}
		*ret++ = ch;
		len++;
	} while (ch != '\0');
//	ret = (char *)malloc(bufferSize);
//	assert(ret != NULL);
//	strcpy(ret, buf);
	return buf;
}


int main()
{
	char *string;
	string = readString();
	printf("%s", string);
//	free(string);
	string = readString();
	printf("%s", string);
	free(string);
    return 0;
}

