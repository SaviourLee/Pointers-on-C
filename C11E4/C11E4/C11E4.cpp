// C11E4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node *next;
}listNode;

listNode *addNode(int x) {
//	L->next = (node *)malloc(sizeof(node));
//	L->next->num = x;
	listNode *p = (node *)malloc(sizeof(node));
	if (!p) {
		printf("malloc failed!");
		return NULL;
	}
	p->num = x;
	return p;
}
int main()
{
	listNode *L = NULL;
	L = addNode(1);
    return 0;
}

