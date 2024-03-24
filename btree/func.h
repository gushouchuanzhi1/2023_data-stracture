#pragma once
#include "def.h"

status InitBiTree(Node* t) {
	t = (Node*)malloc(sizeof(Node));
	(*t)->lchild = NULL;
	(*t)->rchild = NULL;
	(*t)->value = 0;
	return OK;
}

//带有空节点的前序遍历
status CreateBiTree(Node* t) {
	printf("please enter your BiTree by char!\n");
	char ch;
	scanf("%c", ch);
	if (ch == '#') {
		*t == NULL;
		return OK;
	}
	else {
		*t = malloc(sizeof(Node));
		(*t)->name[0] = ch;
		CreateBiTree(&((*t)->lchild));
		CreateBiTree(&((*t)->rchild));
	}
}



