#pragma once

typedef int status;
typedef int ElemType;

struct LNode {//ÿ�������һ��ָ����һ������ָ��
	struct LNode* pre;//ָ��ǰ��
	ElemType elem;
	struct LNode* next;//ָ�����
};
typedef struct LNode LNode, * LinkList;//��struct LNode����ֱ�Ӹĳ�ΪLNode��һ�������͵�ָ��LinkList
/*��Ч��
typedef struct LNode {
	ElemType elem;
	struct LNode* next;
}LNode,*LinkList;*/
typedef struct Lists {//���������������������������
	struct ListElem
	{
		char name[20];
		LinkList L;
	} elem[10];
	int length = 0;
};



