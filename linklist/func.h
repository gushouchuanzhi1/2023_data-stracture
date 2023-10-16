#pragma once
#include "datastr.h"
#include "define.h"
#include <stdio.h>
#include <stdlib.h>

status InitList(LinkList& head) {//仅创建一个头指针
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
		free(destNode);//释放对应内存空间
	}
	return OK;
}

status ClearList(LinkList& L) {//与销毁链表相比，只需要保留头指针
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* target = L->next;//从第一个结点开始删除
	while (target != NULL) {
		LNode* temp = target;
		target = target->next;
		free(temp);
	}
	return OK;
}

status ListEmpty(LinkList& L) {//判断是否为空
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

status GetElem(LinkList& L, int i) {//e返回这个元素的值
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

status LocateElem(LinkList& L, ElemType e) {//找到相等的值，返回位序
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	int location = 0;
	while (node != NULL) {
		location++;//第一轮变为1
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

status ListInsert(LinkList& L, int i, ElemType e) {//在第i个位置之前插入e，第i-1个位置之后
	if (L == NULL || L->next == NULL) return INFEASIBLE;
	LNode* node = L->next;
	LNode* InsNode = (LNode*)malloc(sizeof(LNode));
	InsNode->elem = e;
	if (i == 1) {//修改一下前后指针
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

status ListDelete(LinkList& L,int i) {//删除第i个元素
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
		printf("这是第%d个结点，其数据元素为%d\n", i, node->elem);
		node = node->next;
	}
	return OK;
}

status ReverseList(LinkList& L) {
	if (L == NULL || L->next == NULL) return INFEASIBLE; // 链表为空或只有一个节点，无需翻转

	LNode* current = L->next;
	LNode* previous = NULL;
	LNode* next = NULL;

	while (current != NULL) {
		next = current->next; // 保存下一个节点的指针
		current->next = previous; // 反转当前节点的指向
		previous = current; // 更新 previous 指针
		current = next; // 更新 current 指针
	}

	// 更新头结点的 next 指针，指向新的链表开头
	L->next = previous;

	return OK;
}

status RemoveNthFromEnd(LinkList& L, int n)
{//移除倒数第n个结点 
	if (L == NULL) {//判断链表是否为空 
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
		//从后往前找到倒数第n个结点 
		int leng;
		leng = i - n + 1;
		p = L;
		q = L->next;
		for (i = 1; i < leng - 1; i++) {
			p = q;
			q = q->next;
		}
		p->next = q->next;//移除这个结点，调整结点指针域 
		free(q);
		return OK;
	}
}

status sortList(LinkList& L) {
	if (L != NULL) {//判断链表是否为空 
		LNode* p, * q;
		p = L->next;
		int leng = ListLength(L);
		int j = 0, flag = 0, s = 0;
		int num[100] = { 0 };
		//将链表数据导入数组 
		while (p) {
			num[j] = p->elem;
			++j;
			p = p->next;
		}
		//暴力冒泡排序法 
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
		//重新导入链表 
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
// 16 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{

	if (L==NULL) return INFEASIBLE;
	else {//判断链表是否为空 
		FILE* pf = fopen("FileName", "w");//定义出指针对文件进行操作 
		LinkList S;
		S = L;
		while (S)
		{
			//将元素放入filname进行w写入操作 
			fprintf(pf, "%d ", S->elem);
			S = S->next;//向下一个继续指针 
		}
		fclose(pf);//最后别忘了关闭文件指针 
		return OK;
	}
}
