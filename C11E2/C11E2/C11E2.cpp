// C11E2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#define MAX 10
int* store_int() {	//my version 题意没理解好
	int size = 0, num = 0;
	scanf("%d", &size);
	printf("size = %d\n", size);
	int *si = (int*)malloc(size * sizeof(int));
	if (!si) {
		printf("error");
		return NULL;
	}
	int *p = si;
	*si++ = size;
	
	printf("*p = %d\n", *p);
	while (scanf("%d", &num) == 1)
		*si++ = num;
	printf("%d\n", *p);
	return p;
}

int* readInt() {
	int size = MAX;
	int *array = (int*)malloc(sizeof(int) * (size + 1));
	if (array == NULL)
		return NULL;
	int cnt = 0, num = 0;
	
	while (scanf("%d", &num) == 1) {
		cnt++;
		if (cnt > size) {
			size += MAX;
			array = (int *)realloc(array, sizeof(int) * (size + 1));
			if (array == NULL)
				return NULL;
		}
		array[cnt] = num;
	}

	if (cnt < size) {
		size = cnt;
		array = (int *)realloc(array, sizeof(int) * (size + 1));
		if (array == NULL)
			return NULL;
	}
	array[0] = cnt;
	return array;

}
int main()
{
	int *a;
	a = readInt();
	int *p = a;
//	printf("%d ", *p);
	for (int i = 0; i <= *a; i++, p++)
		printf("%d ", *p);
    return 0;
}

