#pragma once
//ʹ��˳���ʵ�����Ա�
#include <malloc.h>
#include <stdio.h>
//����״̬
#define OK 1
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2
#define LIST_INIT_LENGTH 100
#define LISTINCREMENT 10
//������ݽṹ����
typedef int status;
typedef int ElemType;
typedef struct {//ʹ��˳��� *elem�൱��һ������
	ElemType* elem;
	int length;
	int maxLength = LIST_INIT_LENGTH;
}SqList;
typedef struct {//lists���е������Ա�����ݽṹ
	char name[20];
	SqList L;
} list;
typedef struct {//ʹ��lists�����������Ա�
	struct {//lists���е������Ա�����ݽṹ
		char name[20];
		SqList L;
	} elem[10];
	int number;//ͳ�Ƹ���
}LISTS;//ͬʱ���������Ա�
LISTS lists;






