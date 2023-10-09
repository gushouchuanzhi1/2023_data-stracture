#pragma once
#include "define.h"
// 传参使用&L而不使用L，前者将线性表的地址传入，可以直接对L进行修改，而后者只是将L的副本传入
// 本质上并不没有改变L本身，所以不能达到对其修改的目的。

//（1）初始化表：函数名称是InitList(L)；初始条件是线性表L不存在；操作结果是构造一个空的线性表；
status InitList(SqList& L) {
	if (L.elem) return ERROR;
	L.elem = (ElemType*)malloc(LIST_INIT_LENGTH * sizeof(ElemType));//给elem的数组分配空间
	L.length = 0;
	L.maxLength = LIST_INIT_LENGTH;
	return OK;
}
//（2）销毁表：函数名称是DestroyList(L)；初始条件是线性表L已存在；操作结果是销毁线性表L；
status DestroyList(SqList& L) {
	if (L.elem != NULL) {//直接释放，并且要设置NULL和0，避免悬空指针并且重置数据
		free(L.elem);
		L.elem = NULL;
		L.length = 0;
		L.maxLength = 0;
		return OK;
	}
	return ERROR;
}
//（3）清空表：函数名称是ClearList(L)；初始条件是线性表L已存在；操作结果是将L重置为空表；
status ClearList(SqList& L) {
	if (L.elem != NULL) {
		L.length = 0;
		return OK;
	}
	return ERROR;
}
//（4）判定空表：函数名称是ListEmpty(L)；初始条件是线性表L已存在；操作结果是若L为空表则返回TRUE,否则返回FALSE；
status ListEmpty(SqList& L) {
	if (L.elem == NULL) return ERROR;
	else {
		if (L.length == 0) return true;
		else return false;
	}
}
//（5）求表长：函数名称是ListLength(L)；初始条件是线性表已存在；操作结果是返回L中数据元素的个数；
int ListLength(SqList& L) {
	if (L.elem == NULL) return ERROR;
	else return L.length;
}
//（6）获得元素：函数名称是GetElem(L,i,e)；初始条件是线性表已存在，1≤i≤ListLength(L)；操作结果是用e返回L中第i个数据元素的值；
ElemType GetElem(SqList& L, int i, ElemType e) {
	if (L.elem == NULL) return ERROR;
	else if (i >= 1 && i <= L.length) {
		e = L.elem[i - 1];
		return e;
	}
	else return ERROR;
}
//（7）查找元素：函数名称是LocateElem(L,e,compare())；初始条件是线性表已存在；
// 操作结果是返回L中第1个与e满足关系compare（）关系的数据元素的位序，若这样的数据元素不存在，则返回值为0；
ElemType LocateElem(SqList& L, ElemType e) {
	if (L.elem == NULL) return ERROR;
	else {
		for (int i = 0; i < L.length; i++) {
			if (L.elem[i] == e) return i + 1;
			else return 0;
		}
	}
}
//（8）获得前驱：函数名称是PriorElem(L,cur_e,pre_e)；初始条件是线性表L已存在；
// 操作结果是若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义；
ElemType PriorElem(SqList& L, ElemType cur_e, ElemType pre_e) {
	if (L.elem == NULL) return ERROR;
	else if (L.elem[0] == cur_e) return ERROR;
	else {
		for (int i = 1; i < L.length; i++) {
			int pre = L.elem[i - 1];
			if (L.elem[i] == cur_e) return pre_e = pre;
			else continue;
		}
		return ERROR;
	}
}
//（9）获得后继：函数名称是NextElem(L,cur_e,next_e)；初始条件是线性表L已存在；
// 操作结果是若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义；
ElemType NextElem(SqList& L, ElemType cur_e, ElemType next_e) {
	if (L.elem == NULL) return ERROR;
	else if (L.elem[L.length - 1] == cur_e) return ERROR;
	else {
		for (int i = 0; i < L.length - 1; i++) {
			int next = L.elem[i + 1];
			if (L.elem[i] == cur_e) return next_e = next;
			else continue;
		}
		return ERROR;
	}
}
//（10）插入元素：函数名称是ListInsert(L,i,e)；初始条件是线性表L已存在，
// 1≤i≤ListLength(L)+1；操作结果是在L的第i个位置之前插入新的数据元素e。
status ListInsert(SqList& L, int i, ElemType e) {
	if (L.elem == NULL) return ERROR;
	else {
		if (L.length = L.maxLength) {//如果要额外申请内存空间
			ElemType* newbase = (ElemType*)realloc(L.elem, (L.maxLength + LISTINCREMENT) * sizeof(ElemType));
			L.elem = newbase;
			L.length++;
			L.maxLength += LISTINCREMENT;
		}//对顺序表进行修改
		for (int i = L.length - 1; i >= i - 1; i--) {
			L.elem[i + 1] = L.elem[i];
		}
		L.elem[i - 1] = e;
		L.length++;
		return OK;
	}
}
//（11）删除元素：函数名称是ListDelete(L,i,e)；初始条件是线性表L已存在且非空，
// 1≤i≤ListLength(L)；操作结果：删除L的第i个数据元素，用e返回其值；
ElemType ListDelete(SqList& L, int i, ElemType e) {
	if (L.elem == NULL) return ERROR;
	else if (i >= 1 && i <= L.length) {//j=i-1
		for (int j = i - 1; j < L.length - 1; j++) {
			L.elem[j] = L.elem[j + 1];
		}
		L.length--;
		return OK;
	}
	else return ERROR;
}
//（13）遍历表：函数名称是ListTraverse(L,visit())，初始条件是线性表L已存在；
// 操作结果是依次对L的每个数据元素调用函数visit()。
void visit(ElemType e) {
	printf("%d ", e);
}
status ListTraverse(SqList& L) {
	if (L.elem == NULL) return ERROR;
	else {
		for (int i = 0; i < L.length; i++) {
			visit(L.elem[i]);
		}
		return OK;
	}
}
// 函数名称是MaxSubArray(L); 初始条件是线性表L已存在且非空，
// 请找出一个具有最大和的连续子数组（子数组最少包含一个元素），操作结果是其最大和；
// 算法思想：同时建立一个dp[length]的数组，dp[i]代表以elem[i]为末尾的最大和，
// 只需要比较dp[i - 1] + L.elem[i] >= L.elem[i]大小即可，谁大将dp[i]更新为谁。
int MaxSubArray(SqList& L) {
	int max = 0;
	if (L.elem == NULL) return ERROR;
	int dp[1000] = { 0 };
	dp[0] = L.elem[0];
	max = dp[0];
	for (int i = 1; i < L.length; i++) {
		if (dp[i - 1] + L.elem[i] >= L.elem[i]) {
			dp[i] = dp[i - 1] + L.elem[i];
		}
		else dp[i] = L.elem[i];
	}
	for (int j = 0; j < L.length; j++) {
		if (max <= dp[j]) max = dp[j];
		else continue;
	}
	return max;
}
//和为K的子数组：函数名称是SubArrayNum(L,k); 
//初始条件是线性表L已存在且非空, 操作结果是该数组中和为k的连续子数组的个数；
int SubArrayNum(SqList& L, int k) {//时间复杂度为O(n的平方)，直接两次遍历求elem[j]~elem[i]之间的和
	if (L.elem == NULL) return ERROR;
	int count = 0;
	for (int i = 0; i < L.length; i++) {
		int sum = 0;
		for (int j = i; j >= 0; j--) {
			sum = sum + L.elem[j];
			if (sum == k) {
				count++;
			}
		}
	}
	return count;
}
//顺序表排序：函数名称是sortList(L)；初始条件是线性表L已存在；操作结果是将L由小到大排序；
status sortList(SqList& L) {
	if (L.elem == NULL) return ERROR;
	for (int i = 0; i < L.length - 1; i++) {
		for (int j = 1; j < L.length; j++) {
			if (L.elem[j] <= L.elem[i]) {
				int temp = L.elem[i];
				L.elem[i] = L.elem[j];
				L.elem[j] = temp;
			}
		}
	} 
	return OK;
}
//实现多个线性表管理：设计相应的数据结构管理多个线性表的查找、添加、移除等功能。
status InitLists(LISTS& lists) {
	
}
status LocateList(LISTS& lists,char* name) {
	if (lists.elem == NULL) return ERROR;
	for (int i = 0; i < lists.number; i++) {
		if (lists.elem[i].name == name) return i + 1;
	}
	return ERROR;
}
status RemoveList(LISTS& lists, int number) {
	if (lists.elem == NULL) return ERROR;
	if (number < lists.number && number > 0) {
		int i = 0;
		for (i = number - 1; i < lists.number - 1; i++) {
			lists.elem[i] = lists.elem[i + 1];
		}
		free(lists.elem + i + 1);
		lists.number--;
		return OK;
	}
	else if (number = lists.number) {
		free(lists.elem + lists.number - 1);
		lists.number--;
		return OK;
	}
	return ERROR;
}



