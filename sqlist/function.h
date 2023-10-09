#pragma once
#include "define.h"
// ����ʹ��&L����ʹ��L��ǰ�߽����Ա�ĵ�ַ���룬����ֱ�Ӷ�L�����޸ģ�������ֻ�ǽ�L�ĸ�������
// �����ϲ���û�иı�L�������Բ��ܴﵽ�����޸ĵ�Ŀ�ġ�

//��1����ʼ��������������InitList(L)����ʼ���������Ա�L�����ڣ���������ǹ���һ���յ����Ա�
status InitList(SqList& L) {
	if (L.elem) return ERROR;
	L.elem = (ElemType*)malloc(LIST_INIT_LENGTH * sizeof(ElemType));//��elem���������ռ�
	L.length = 0;
	L.maxLength = LIST_INIT_LENGTH;
	return OK;
}
//��2�����ٱ�����������DestroyList(L)����ʼ���������Ա�L�Ѵ��ڣ�����������������Ա�L��
status DestroyList(SqList& L) {
	if (L.elem != NULL) {//ֱ���ͷţ�����Ҫ����NULL��0����������ָ�벢����������
		free(L.elem);
		L.elem = NULL;
		L.length = 0;
		L.maxLength = 0;
		return OK;
	}
	return ERROR;
}
//��3����ձ�����������ClearList(L)����ʼ���������Ա�L�Ѵ��ڣ���������ǽ�L����Ϊ�ձ�
status ClearList(SqList& L) {
	if (L.elem != NULL) {
		L.length = 0;
		return OK;
	}
	return ERROR;
}
//��4���ж��ձ�����������ListEmpty(L)����ʼ���������Ա�L�Ѵ��ڣ������������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
status ListEmpty(SqList& L) {
	if (L.elem == NULL) return ERROR;
	else {
		if (L.length == 0) return true;
		else return false;
	}
}
//��5�����������������ListLength(L)����ʼ���������Ա��Ѵ��ڣ���������Ƿ���L������Ԫ�صĸ�����
int ListLength(SqList& L) {
	if (L.elem == NULL) return ERROR;
	else return L.length;
}
//��6�����Ԫ�أ�����������GetElem(L,i,e)����ʼ���������Ա��Ѵ��ڣ�1��i��ListLength(L)�������������e����L�е�i������Ԫ�ص�ֵ��
ElemType GetElem(SqList& L, int i, ElemType e) {
	if (L.elem == NULL) return ERROR;
	else if (i >= 1 && i <= L.length) {
		e = L.elem[i - 1];
		return e;
	}
	else return ERROR;
}
//��7������Ԫ�أ�����������LocateElem(L,e,compare())����ʼ���������Ա��Ѵ��ڣ�
// ��������Ƿ���L�е�1����e�����ϵcompare������ϵ������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
ElemType LocateElem(SqList& L, ElemType e) {
	if (L.elem == NULL) return ERROR;
	else {
		for (int i = 0; i < L.length; i++) {
			if (L.elem[i] == e) return i + 1;
			else return 0;
		}
	}
}
//��8�����ǰ��������������PriorElem(L,cur_e,pre_e)����ʼ���������Ա�L�Ѵ��ڣ�
// �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��壻
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
//��9����ú�̣�����������NextElem(L,cur_e,next_e)����ʼ���������Ա�L�Ѵ��ڣ�
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��壻
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
//��10������Ԫ�أ�����������ListInsert(L,i,e)����ʼ���������Ա�L�Ѵ��ڣ�
// 1��i��ListLength(L)+1�������������L�ĵ�i��λ��֮ǰ�����µ�����Ԫ��e��
status ListInsert(SqList& L, int i, ElemType e) {
	if (L.elem == NULL) return ERROR;
	else {
		if (L.length = L.maxLength) {//���Ҫ���������ڴ�ռ�
			ElemType* newbase = (ElemType*)realloc(L.elem, (L.maxLength + LISTINCREMENT) * sizeof(ElemType));
			L.elem = newbase;
			L.length++;
			L.maxLength += LISTINCREMENT;
		}//��˳�������޸�
		for (int i = L.length - 1; i >= i - 1; i--) {
			L.elem[i + 1] = L.elem[i];
		}
		L.elem[i - 1] = e;
		L.length++;
		return OK;
	}
}
//��11��ɾ��Ԫ�أ�����������ListDelete(L,i,e)����ʼ���������Ա�L�Ѵ����ҷǿգ�
// 1��i��ListLength(L)�����������ɾ��L�ĵ�i������Ԫ�أ���e������ֵ��
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
//��13������������������ListTraverse(L,visit())����ʼ���������Ա�L�Ѵ��ڣ�
// ������������ζ�L��ÿ������Ԫ�ص��ú���visit()��
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
// ����������MaxSubArray(L); ��ʼ���������Ա�L�Ѵ����ҷǿգ�
// ���ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ�����������������ͣ�
// �㷨˼�룺ͬʱ����һ��dp[length]�����飬dp[i]������elem[i]Ϊĩβ�����ͣ�
// ֻ��Ҫ�Ƚ�dp[i - 1] + L.elem[i] >= L.elem[i]��С���ɣ�˭��dp[i]����Ϊ˭��
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
//��ΪK�������飺����������SubArrayNum(L,k); 
//��ʼ���������Ա�L�Ѵ����ҷǿ�, ��������Ǹ������к�Ϊk������������ĸ�����
int SubArrayNum(SqList& L, int k) {//ʱ�临�Ӷ�ΪO(n��ƽ��)��ֱ�����α�����elem[j]~elem[i]֮��ĺ�
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
//˳������򣺺���������sortList(L)����ʼ���������Ա�L�Ѵ��ڣ���������ǽ�L��С��������
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
//ʵ�ֶ�����Ա���������Ӧ�����ݽṹ���������Ա�Ĳ��ҡ���ӡ��Ƴ��ȹ��ܡ�
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



