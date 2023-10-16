#pragma once
#include "datastr.h"
#include "define.h"
#include <stdio.h>
#include <stdlib.h>

status InitList(LinkList& head) {//������һ��ͷָ��
	if (head != NULL) return INFEASIBLE;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	head->elem = 0;
	return OK;
}

status DestroyList(LinkList& L) {
	if (L == NULL) return INFEASIBLE;
	while (L != NULL) {
		LNode* destNode;
		destNode = L;
		L = L->next;
		free(destNode);//�ͷŶ�Ӧ�ڴ�ռ�
	}
	return OK;
}

status ClearList(LinkList& L) {//������������ȣ�ֻ��Ҫ����ͷָ��
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* target = L->next;//�ӵ�һ����㿪ʼɾ��
	while (target != NULL) {
		LNode* temp = target;
		target = target->next;
		free(temp);
	}
	return OK;
}

status ListEmpty(LinkList& L) {//�ж��Ƿ�Ϊ��
	if (L == NULL) return INFEASIBLE;
	if (L->next == NULL) return YES;
	else return NO;
}

int ListLength(LinkList& L) {
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	int length = 0;
	while (node != NULL) {
		length++;
		node = node->next;
	}
	return length;
}

status GetElem(LinkList& L, int i) {//e�������Ԫ�ص�ֵ
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L;
	ElemType e = 0;
	for (int m = 0; m < i; m++) {
		if (node->next == NULL) return INFEASIBLE;
		node = node->next;
	}
	e = node->elem;
	return e;
}

status LocateElem(LinkList& L, ElemType e) {//�ҵ���ȵ�ֵ������λ��
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	int location = 0;
	while (node != NULL) {
		location++;//��һ�ֱ�Ϊ1
		if (node->elem == e) return location;
		node = node->next;
	}
	return INFEASIBLE;
}

status PriorElem(LinkList L, ElemType cur_e) {
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	if (node->elem == cur_e) return INFEASIBLE;
	node = node->next;
	ElemType pre_e = 0;
	while (node != NULL) {
		if (node->elem == cur_e) {
			pre_e = node->pre->elem;
			return pre_e;
		}
		node = node->next;
	}
	return INFEASIBLE;
}

status NextElem(LinkList L, ElemType cur_e) {
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	ElemType next_e = 0;
	while (node->next != NULL) {
		if (node->elem == cur_e) {
			next_e = node->next->elem;
			return next_e;
		}
		node = node->next;
	}
	return INFEASIBLE;
}

status ListInsert(LinkList& L, int i, ElemType e) {//�ڵ�i��λ��֮ǰ����e����i-1��λ��֮��
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	LNode* InsNode = (LNode*)malloc(sizeof(LNode));
	InsNode->elem = e;
	if (i == 1) {//�޸�һ��ǰ��ָ��
		L->next = InsNode;
		InsNode->pre = L;
		InsNode->next = node;
		node->pre = InsNode;
		return OK;
	}
	int cnt = 0;
	while (node != NULL) {
		if (cnt == i - 1) {
			InsNode->pre = node->pre;
			InsNode->next = node;
			node->pre->next = InsNode;
			node->pre = InsNode;
			return OK;
		}
		node = node->next;
		cnt++;
	}
	return INFEASIBLE;
}

status ListDelete(LinkList& L,int i) {//ɾ����i��Ԫ��
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	ElemType e = 0;
	if (i == 1) {
		e = node->elem;
		L->next = node->next;
		node->next->pre = L;
		free(node);
		return e;
	}
	int cnt = 1;
	while (node != NULL) {
		if (cnt == i) {
			node->pre->next = node->next;
			node->next = node->pre;
			e = node->elem;
			free(node);
			return e;
		}
		node = node->next;
		cnt++;
	}
	return INFEASIBLE;
}

status ListTraverse(LinkList& L) {
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	int i = 0;
	while (node != NULL) {
		printf("���ǵ�%d����㣬������Ԫ��Ϊ%d\n", i, node->elem);
		node = node->next;
	}
	return OK;
}

status ReverseList(LinkList& L) {
	if (L == NULL || L->next == NULL) return INFEASIBLE; // ����Ϊ�ջ�ֻ��һ���ڵ㣬���跭ת

	LNode* current = L->next;
	LNode* previous = NULL;
	LNode* next = NULL;

	while (current != NULL) {
		next = current->next; // ������һ���ڵ��ָ��
		current->next = previous; // ��ת��ǰ�ڵ��ָ��
		previous = current; // ���� previous ָ��
		current = next; // ���� current ָ��
	}

	// ����ͷ���� next ָ�룬ָ���µ�����ͷ
	L->next = previous;

	return OK;
}

status RemoveNthFromEnd(LinkList& L, int n)
{//�Ƴ�������n����� 
	if (L == NULL) {//�ж������Ƿ�Ϊ�� 
		return INFEASIBLE;
	}
	else {
		LNode* p, * q;
		p = L;
		int i = 0;
		while (p) {
			i++;
			p = p->next;
		}
		//�Ӻ���ǰ�ҵ�������n����� 
		int leng;
		leng = i - n + 1;
		p = L;
		q = L->next;
		for (i = 1; i < leng - 1; i++) {
			p = q;
			q = q->next;
		}
		p->next = q->next;//�Ƴ������㣬�������ָ���� 
		free(q);
		return OK;
	}
}

status sortList(LinkList& L) {
	if (L != NULL) {//�ж������Ƿ�Ϊ�� 
		LNode* p, * q;
		p = L->next;
		int leng = ListLength(L);
		int j = 0, flag = 0, s = 0;
		int num[100] = { 0 };
		//���������ݵ������� 
		while (p) {
			num[j] = p->elem;
			++j;
			p = p->next;
		}
		//����ð������ 
		for (int i = 0; i < leng; i++)
		{
			for (int j = i + 1; j < leng; j++)
			{
				if (num[j] < num[i]) {
					flag = num[i];
					num[i] = num[j];
					num[j] = flag;
				}
			}
		}
		q = L->next;
		//���µ������� 
		while (q) {
			q->elem = num[s];
			++s;
			q = q->next;
		}
		return OK;
	}
	else return INFEASIBLE;
}

status SaveList(LinkList L, char FileName[])
// 16 ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{

	if (L==NULL) return INFEASIBLE;
	else {//�ж������Ƿ�Ϊ�� 
		FILE* pf = fopen("FileName", "w");//�����ָ����ļ����в��� 
		LinkList S;
		S = L;
		while (S)
		{
			//��Ԫ�ط���filname����wд����� 
			fprintf(pf, "%d ", S->elem);
			S = S->next;//����һ������ָ�� 
		}
		fclose(pf);//�������˹ر��ļ�ָ�� 
		return OK;
	}
}
