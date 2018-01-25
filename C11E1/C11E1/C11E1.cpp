// C11E1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

void* my_calloc(int n, size_t sz) {
	char* p = (char*)malloc(n * sz);
	if (!p) {
		printf("Error calloc space");
		return NULL;
	}
	char *a = p;
	while(n--)
		*a++ = '\0';
	return p;

}

int main()
{
	int n = 5;
	while (n--) {
		printf("%d", n);
	}
    return 0;
}

