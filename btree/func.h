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
status CreateBiTree(Node* t, char definition[]) {
	int len = sizeof(definition) / sizeof(definition[0]);


}



