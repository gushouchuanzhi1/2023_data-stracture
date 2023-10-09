#pragma once
//使用顺序表实现线性表
#include <malloc.h>
#include <stdio.h>
//定义状态
#define OK 1
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2
#define LIST_INIT_LENGTH 100
#define LISTINCREMENT 10
//相关数据结构定义
typedef int status;
typedef int ElemType;
typedef struct {//使用顺序表 *elem相当于一个数组
	ElemType* elem;
	int length;
	int maxLength = LIST_INIT_LENGTH;
}SqList;
typedef struct {//lists中有单个线性表的数据结构
	char name[20];
	SqList L;
} list;
typedef struct {//使用lists来管理多个线性表
	struct {//lists中有单个线性表的数据结构
		char name[20];
		SqList L;
	} elem[10];
	int number;//统计个数
}LISTS;//同时管理多个线性表
LISTS lists;






