#pragma once

typedef int status;
typedef int ElemType;

struct LNode {//每个结点有一个指向下一个结点的指针
	struct LNode* pre;//指向前驱
	ElemType elem;
	struct LNode* next;//指向后续
};
typedef struct LNode LNode, * LinkList;//将struct LNode类型直接改称为LNode和一个该类型的指针LinkList
/*等效于
typedef struct LNode {
	ElemType elem;
	struct LNode* next;
}LNode,*LinkList;*/
typedef struct Lists {//管理多个链表，这里采用数组来保存
	struct ListElem
	{
		char name[20];
		LinkList L;
	} elem[10];
	int length = 0;
};



