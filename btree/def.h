#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_SIZE 10
#define OK 1
#define ERROR 0
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2


typedef int status;
typedef int KeyType;

typedef struct BiNode {
	Node* lchild;
	char name[20];
	KeyType value;
	Node* rchild;
}Node, *Node;

typedef struct Tree {
	Node* root;
	char name[20];
}Tree,*Tree;

typedef struct Forest {
	Tree trees[MAX_SIZE];
	int num;
	int ForestSize;
};






