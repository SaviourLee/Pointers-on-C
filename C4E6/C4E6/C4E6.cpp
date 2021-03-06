// C4E6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
int substr(char dst[], char src[], int start, int len){
	//if (start < 0 || len < 0) {	//如果输入不合法
	//	dst[0] = '\0';
	//	return 0;
	//}
	//for (int i = 0; i < len; i++) {
	//	if (src[i + start] == '\0') {
	//		dst[i] = '\0';
	//		return i;
	//	}
	//	dst[i] = src[i + start];
	//}
	//return len;
	int index;
	if (start >= 0 && len > 0) {
		for (index = 0; index < start && src[index] != '\0'; index++) //重要，检查是否超过了src末尾
			;
		while (len >0 && src[index] != '\0') {
			dst[index - start] = src[index];
			index++;
			len--;
		}
	}
	dst[index - start] = '\0';
	return index - start;
}

int main()
{
    return 0;
}

