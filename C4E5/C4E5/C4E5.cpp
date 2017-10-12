// C4E5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_LENGTH 128
int main()
{
	char line[MAX_LENGTH];
	char before[MAX_LENGTH];
	bool flag = false;		//通过标志位巧妙判断是否是第三次连续重复
	//gets_s(line);
	//strcpy(before, line);
	if(gets_s(before)!= NULL){	//与以上两句的功能相同
		while (gets_s(line) != NULL) {
			if (strcmp(line, before)) {	//如果两行不相等，则更新before
				strcpy(before, line);
				flag = false;
			}
			else if (!flag) {	//如果两行相等并且之前输出过
				printf("%s", line);
				flag = true;
			}
		}	
	}
    return 0;
}

