#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//���庯����Ҫ�������
//����״̬ 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//���Ա����ض��� 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef int status;
typedef int ElemType;

typedef struct LNode{//������������������ 
      	ElemType data;
      	struct LNode *next;
    }LNode,*LinkList;
    
typedef struct{  //�����Ա�Ĺ��� 
    struct{	
	 		char name[20];
     		LinkList L;	
        }elem[10];
      
      	int length;//Lists�ĳ��� 
 }LISTS;
 
 status InitList(LinkList &L)
 {
    
    if(L == NULL){//����Ҫ�ж��Ƿ��ǿյ� 
        L = (LinkList)malloc(sizeof(LNode));//���������ռ����ռ� 
        L->next = NULL;//���һ�����ָ���ָ��               
        return OK;     
    }	 
	else return INFEASIBLE;//����Ѿ����ڷ���INFEASIBLE 
 
 }
 
 status DestroyList(LinkList &L)
 // 2 ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
 {
    if(L != NULL){//����Ҫ�ж��Ƿ��ǿյ� 
        LNode *now;
        while(L != NULL){//�ж����������Ƿ�Ϊ�� 
            now = L; 
            L = L->next;
            free(now);//�ͷŵ�ǰָ��Ŀռ䣬�������±��� 
        }                    
        return OK;     
    }
	else return INFEASIBLE;
 
 }
 
 status ClearList(LinkList &L)
 // 3 ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
 {
    if(L != NULL){//����Ҫ�ж������Ƿ��ǿյ� 
	    LNode *now, *Next;
	    now = L->next;
	    while(now){//�ж���������Ƿ�Ϊ�� 
	        Next = now->next;
	        free(now);
	        now = Next;
	    }
	    L->next = NULL;//���ͷ�ͷָ��Ŀռ䱣��ͷָ��       
	    return OK;     
    }
	else return INFEASIBLE;

 }
 
 status ListEmpty(LinkList L)
 // 4 ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
 {
 
    if(L != NULL){//����Ҫ�ж������Ƿ��ǿյ� 
        if(L->next != NULL) return FALSE;//nextָ����Ƿ�Ϊ�� 
        else return TRUE;
    	}
	else return INFEASIBLE;
 }
 
 status ListLength(LinkList L)
 // 5 ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
 
    if(L != NULL){//�ж������Ƿ��ǿյ� 
        int num = 0;
        LNode *p;
        p = L->next;
        while(p != NULL){
            num++;
            p = p->next;//ͨ����ʱָ��Ϊ������ó��� 
        }                   
        return num;     
    }
	else return INFEASIBLE;
}
 
 status GetElem(LinkList L,int i,ElemType &e)
 // 6 ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
 {
 
    if(L != NULL){//�ж������Ƿ��ǿյ� 
        LNode *p;
        int now = 1;
        p = L->next;
        while(p != NULL && now < i){
            p = p->next;
            ++now;
        }//��������Ҹ�Ԫ�� 
        if(!p || now>i){//���i��ֵ�����ϳ��Ȼ���ָ����� 
            return ERROR;
        }
        e = p->data;
        return OK;
    }
	else return INFEASIBLE;
 
 }
 
 status LocateElem(LinkList L,ElemType e)
 // 7 ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
 {
 
    if(L != NULL){//�ж������Ƿ�Ϊ�� 
        LNode *p;
        int pos = 1;//�����߼�λ�� 
        p = L->next;
        while(p && p->data != e){//�����ڣ����ҽ������=e 
            p = p->next;//ָ����һ�� 
            pos++;
        }
        if(p) return pos;
    	else return ERROR;
    }
	else return INFEASIBLE;
}
 
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 8 ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
 
    if(L != NULL){//�ж������Ƿ�Ϊ�� 
        LNode *p;
        int pos = 1;
        p = L;
        while(p->next && p->next->data != e){
            p = p->next;
            pos++;
        }//p->next�Ƿ���� ���Ƿ�λ�úϷ� 
        if(p->next && pos != 1){
            pre = p->data;
            return OK;
        }
		else return ERROR;
    }
	else return INFEASIBLE;
 
 
}
 
status NextElem(LinkList L,ElemType e,ElemType &next)
// 9 ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    
    if(L != NULL){//�ж������Ƿ�Ϊ�� 
        LNode *p,*q;
        p = L;
        while(p->next && p->data != e){
            p = p->next;
        }//�жϺ��Ԫ�غϷ��� 
        q = p->next;
        if(p->next){
            next = q->data;//���ص�next��ָ��ָ��q��������
            return OK;
        }
		else return ERROR;
    }else return INFEASIBLE;
}
 
status ListInsert(LinkList &L,int i,ElemType e)
// 10 ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    if(L != NULL){//�ж������Ƿ�Ϊ�� 
        LNode *p,*s;
        int j = 0;
        p = L;
        while(p && j < i - 1){
            p = p->next;
            j++;
        }
        //�ж��Ƿ�Ϸ� 
        if(!p || j>i-1){
            return ERROR;
        }else{ 
            s = (LinkList)malloc(sizeof(LNode));//���·���ռ� 
            s->data = e;
            s->next = p->next;
            p->next = s;
            return OK;
        }
    }
	else return INFEASIBLE;
}
 
status ListDelete(LinkList &L,int i,ElemType &e)
// 11 ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    if(L != NULL){//�ж������Ƿ�Ϊ�� 
        LNode *p,*q;
        int j = 0;
        p = L;
        while(p->next && j < i - 1){
            p = p->next;
            j++;
        }
		//�ж��Ƿ�Ϸ��� 
        if(!(p->next) || j > i - 1) return ERROR;
        //������������ɾ����Ԫ��ָ�� 
        q = p->next;
        p->next = q->next;
        e = q->data;
        free(q);
        return OK;
    }
	else return INFEASIBLE;
}
 
status ListTraverse(LinkList L)
// 12 ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{

    if(L != NULL){//�ж������Ƿ�Ϊ�� 
        LNode *p;
        p = L->next;
        while(p){
            printf("%d ",p->data);//���� 
            p = p->next;
        }
        return OK;
    }
	else return INFEASIBLE;
}
 
status reverseList(LinkList &L){
// 13 ������L���� 
 	if(L != NULL){//�ж������Ƿ�Ϊ�� 
	 	LNode *p;
 		p = L->next ;
 		int i = ListLength(L);
	 	int j = 0, t = 0, k = 0;
 		int num[i];
 		while(p){
 			num[j] = p->data;
 			++j;
 			p = p->next;
 		}
 		//�����鱣�� 
	 	t = j-1;
	 	LNode *q;
	 	q = L->next;
	 	//�������е����ַ������� 
	 	while(q){
	 		q->data = num[t];
	 		t--;
	 		q = q->next;
	 	}
	 	return OK;
  	} 
 	else return INFEASIBLE;
 }
 
 status RemoveNthFromEnd(LinkList &L,int n)
 {//�Ƴ�������n����� 
 	if(L == NULL){//�ж������Ƿ�Ϊ�� 
 		return INFEASIBLE;
 	}
 	else{
 		LNode *p,*q;
 		p = L;
 		int i = 0;
 		while(p){
 			i++;
 			p = p->next;
 		}
 		//�Ӻ���ǰ�ҵ�������n����� 
 		int leng;
 		leng = i - n + 1;
 		p = L;
 		q = L->next;
 		for(i = 1;i < leng - 1; i++){
 			p = q;
 			q = q->next;
 		}
 		p->next = q->next;//�Ƴ������㣬�������ָ���� 
 		free(q);
 		return OK;
 	}
 }
 
 status sortList(LinkList &L)
 {// 15 ������������ 
 	if(L != NULL){//�ж������Ƿ�Ϊ�� 
 	LNode *p, *q; 
 	p = L->next;
 	int leng = ListLength(L);
 	int j = 0, flag = 0,s = 0;
 	int num[leng];
 	//���������ݵ������� 
 	while(p){
 		num[j] = p->data;
 		++j;
 		p = p->next;
 	}
 	//����ð������ 
 	for(int i = 0; i < leng; i++)	
	{
 		for(int j = i + 1; j < leng; j++)
		{
 			if(num[j] < num[i]){
 				flag = num[i];
 				num[i] = num[j];
 				num[j] = flag;
 			}
 		}
 	}
 	q = L->next;
 	//���µ������� 
 	while(q){
 		q->data = num[s];
 		++s;
 		q = q->next;
 		}
 		return OK;
 	} 
 	else return INFEASIBLE;
}
 
 status SaveList(LinkList L,char FileName[])
 // 16 ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
 {
 
 	if(!L) return INFEASIBLE;
 	else{//�ж������Ƿ�Ϊ�� 
 	    FILE *pf = fopen("FileName","w");//�����ָ����ļ����в��� 
 	    LinkList S;
 	    S = L;
 	    while(S)
 	    {
 	    	//��Ԫ�ط���filname����wд����� 
 	        fprintf(pf, "%d ", S->data);
 	        S = S->next;//����һ������ָ�� 
 	    }
 	    fclose(pf);//�������˹ر��ļ�ָ�� 
 	    return OK;
 	}	    
 }
 
 status LoadList(LinkList &L,char FileName[])
 // 17 ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
 {
 	if(L) return INFEASIBLE;
 	else{//�ж������Ƿ�Ϊ�� 
 	    FILE * pf = fopen("FileName","r");//�����ļ�ָ�� 
 	    LinkList q = NULL, p;
 	    int number;
 	    if(fscanf(pf, "%d", &number) == 1){
 	    	//����û�г�ʼ�� 
 	        q = (LinkList)malloc(sizeof(LNode));
 	        q->data = number;
 	        p = q;
 	        while(fscanf(pf, "%d", &number) == 1){
 	            p = p->next = (LinkList)malloc(sizeof(LNode));//����ռ� 
 	            p->data = number;
 	            //���洢��number�洢��ָ��ָ��������� 
 	        }
 	        p->next = NULL;
 	    }
 	    L = q;
 	    fclose(pf);//���ǵùر��ļ� 
 	    return OK;
 	}
 }
 
status AddList(LISTS &Lists,char ListName[])
{
 	// 17 ��Lists�м���initial 
 	int i = 0;
 	while(ListName[i])
 	{
 	    Lists.elem[Lists.length].name[i] = ListName[i];
 	    i++;
 	}
	//�������Ա���Lists�е����Ա� 
 	Lists.elem[Lists.length].name[i] = '\0';
 	Lists.elem[Lists.length].L=(LinkList)malloc(sizeof(LNode));
 	Lists.elem[Lists.length].L->next = NULL;
 	//�������һ������\0�����ҽ��ָ���ָ�롣 
 	Lists.length++;
 	return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
{
 	// 18 ���������Ƴ� 
 	int i;
 	for(i = 0; i < Lists.length; i++)
 	{
 	if(!strcmp(ListName,Lists.elem[i].name))
 	    {
 	    	//�Ƴ������ͷſռ� 
 	        for(;i < Lists.length-1; i++)
 	            {
 	                Lists.elem[i] = Lists.elem[i+1];
 	            }
 	        Lists.length--;
 	        return OK;
 	    }
 	}
 	return ERROR;
}
 	
status LocateList(LISTS Lists,char ListName[])
{//��Lists�в��Ҷ��õ��߼�λ�� 
	int i;
	for(i = 0; i < Lists.length; i++)
	{
		if(!strcmp(ListName,Lists.elem[i].name))
	    	{
	      	  	return i+1;
	    	}
	}
	return 0;
}
