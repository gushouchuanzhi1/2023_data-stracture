#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//定义函数需要的相关数
//函数状态 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//线性表的相关定义 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef int status;
typedef int ElemType;

typedef struct LNode{//定义链表结点的相关性质 
      	ElemType data;
      	struct LNode *next;
    }LNode,*LinkList;
    
typedef struct{  //多线性表的管理 
    struct{	
	 		char name[20];
     		LinkList L;	
        }elem[10];
      
      	int length;//Lists的长度 
 }LISTS;
 
 status InitList(LinkList &L)
 {
    
    if(L == NULL){//首先要判断是否是空的 
        L = (LinkList)malloc(sizeof(LNode));//给链表分配空间分配空间 
        L->next = NULL;//最后一个结点指向空指针               
        return OK;     
    }	 
	else return INFEASIBLE;//如果已经存在返回INFEASIBLE 
 
 }
 
 status DestroyList(LinkList &L)
 // 2 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
 {
    if(L != NULL){//首先要判断是否是空的 
        LNode *now;
        while(L != NULL){//判断现在链表是否为空 
            now = L; 
            L = L->next;
            free(now);//释放当前指针的空间，接着往下遍历 
        }                    
        return OK;     
    }
	else return INFEASIBLE;
 
 }
 
 status ClearList(LinkList &L)
 // 3 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
 {
    if(L != NULL){//首先要判断链表是否是空的 
	    LNode *now, *Next;
	    now = L->next;
	    while(now){//判断现在这个是否为空 
	        Next = now->next;
	        free(now);
	        now = Next;
	    }
	    L->next = NULL;//不释放头指针的空间保留头指针       
	    return OK;     
    }
	else return INFEASIBLE;

 }
 
 status ListEmpty(LinkList L)
 // 4 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
 {
 
    if(L != NULL){//首先要判断链表是否是空的 
        if(L->next != NULL) return FALSE;//next指向的是否为空 
        else return TRUE;
    	}
	else return INFEASIBLE;
 }
 
 status ListLength(LinkList L)
 // 5 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
 
    if(L != NULL){//判断链表是否是空的 
        int num = 0;
        LNode *p;
        p = L->next;
        while(p != NULL){
            num++;
            p = p->next;//通过何时指针为空来获得长度 
        }                   
        return num;     
    }
	else return INFEASIBLE;
}
 
 status GetElem(LinkList L,int i,ElemType &e)
 // 6 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
 {
 
    if(L != NULL){//判断链表是否是空的 
        LNode *p;
        int now = 1;
        p = L->next;
        while(p != NULL && now < i){
            p = p->next;
            ++now;
        }//往后遍历找该元素 
        if(!p || now>i){//如果i的值不符合长度或者指针错误 
            return ERROR;
        }
        e = p->data;
        return OK;
    }
	else return INFEASIBLE;
 
 }
 
 status LocateElem(LinkList L,ElemType e)
 // 7 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
 {
 
    if(L != NULL){//判断链表是否为空 
        LNode *p;
        int pos = 1;//定义逻辑位置 
        p = L->next;
        while(p && p->data != e){//当存在，并且结点数据=e 
            p = p->next;//指向下一个 
            pos++;
        }
        if(p) return pos;
    	else return ERROR;
    }
	else return INFEASIBLE;
}
 
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 8 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
 
    if(L != NULL){//判断链表是否为空 
        LNode *p;
        int pos = 1;
        p = L;
        while(p->next && p->next->data != e){
            p = p->next;
            pos++;
        }//p->next是否存在 且是否位置合法 
        if(p->next && pos != 1){
            pre = p->data;
            return OK;
        }
		else return ERROR;
    }
	else return INFEASIBLE;
 
 
}
 
status NextElem(LinkList L,ElemType e,ElemType &next)
// 9 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    
    if(L != NULL){//判断链表是否为空 
        LNode *p,*q;
        p = L;
        while(p->next && p->data != e){
            p = p->next;
        }//判断后继元素合法？ 
        q = p->next;
        if(p->next){
            next = q->data;//返回的next是指针指向q的数据域
            return OK;
        }
		else return ERROR;
    }else return INFEASIBLE;
}
 
status ListInsert(LinkList &L,int i,ElemType e)
// 10 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{

    if(L != NULL){//判断链表是否为空 
        LNode *p,*s;
        int j = 0;
        p = L;
        while(p && j < i - 1){
            p = p->next;
            j++;
        }
        //判断是否合法 
        if(!p || j>i-1){
            return ERROR;
        }else{ 
            s = (LinkList)malloc(sizeof(LNode));//重新分配空间 
            s->data = e;
            s->next = p->next;
            p->next = s;
            return OK;
        }
    }
	else return INFEASIBLE;
}
 
status ListDelete(LinkList &L,int i,ElemType &e)
// 11 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{

    if(L != NULL){//判断链表是否为空 
        LNode *p,*q;
        int j = 0;
        p = L;
        while(p->next && j < i - 1){
            p = p->next;
            j++;
        }
		//判断是否合法？ 
        if(!(p->next) || j > i - 1) return ERROR;
        //调整下跳过被删除的元素指针 
        q = p->next;
        p->next = q->next;
        e = q->data;
        free(q);
        return OK;
    }
	else return INFEASIBLE;
}
 
status ListTraverse(LinkList L)
// 12 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{

    if(L != NULL){//判断链表是否为空 
        LNode *p;
        p = L->next;
        while(p){
            printf("%d ",p->data);//遍历 
            p = p->next;
        }
        return OK;
    }
	else return INFEASIBLE;
}
 
status reverseList(LinkList &L){
// 13 将链表L倒序 
 	if(L != NULL){//判断链表是否为空 
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
 		//用数组保存 
	 	t = j-1;
	 	LNode *q;
	 	q = L->next;
	 	//将数组中的重现返回数组 
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
 {//移除倒数第n个结点 
 	if(L == NULL){//判断链表是否为空 
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
 		//从后往前找到倒数第n个结点 
 		int leng;
 		leng = i - n + 1;
 		p = L;
 		q = L->next;
 		for(i = 1;i < leng - 1; i++){
 			p = q;
 			q = q->next;
 		}
 		p->next = q->next;//移除这个结点，调整结点指针域 
 		free(q);
 		return OK;
 	}
 }
 
 status sortList(LinkList &L)
 {// 15 升序排列链表 
 	if(L != NULL){//判断链表是否为空 
 	LNode *p, *q; 
 	p = L->next;
 	int leng = ListLength(L);
 	int j = 0, flag = 0,s = 0;
 	int num[leng];
 	//将链表数据导入数组 
 	while(p){
 		num[j] = p->data;
 		++j;
 		p = p->next;
 	}
 	//暴力冒泡排序法 
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
 	//重新导入链表 
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
 // 16 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
 {
 
 	if(!L) return INFEASIBLE;
 	else{//判断链表是否为空 
 	    FILE *pf = fopen("FileName","w");//定义出指针对文件进行操作 
 	    LinkList S;
 	    S = L;
 	    while(S)
 	    {
 	    	//将元素放入filname进行w写入操作 
 	        fprintf(pf, "%d ", S->data);
 	        S = S->next;//向下一个继续指针 
 	    }
 	    fclose(pf);//最后别忘了关闭文件指针 
 	    return OK;
 	}	    
 }
 
 status LoadList(LinkList &L,char FileName[])
 // 17 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
 {
 	if(L) return INFEASIBLE;
 	else{//判断链表是否为空 
 	    FILE * pf = fopen("FileName","r");//定义文件指针 
 	    LinkList q = NULL, p;
 	    int number;
 	    if(fscanf(pf, "%d", &number) == 1){
 	    	//链表没有初始化 
 	        q = (LinkList)malloc(sizeof(LNode));
 	        q->data = number;
 	        p = q;
 	        while(fscanf(pf, "%d", &number) == 1){
 	            p = p->next = (LinkList)malloc(sizeof(LNode));//分配空间 
 	            p->data = number;
 	            //将存储的number存储给指针指向的数据域 
 	        }
 	        p->next = NULL;
 	    }
 	    L = q;
 	    fclose(pf);//最后记得关闭文件 
 	    return OK;
 	}
 }
 
status AddList(LISTS &Lists,char ListName[])
{
 	// 17 在Lists中加入initial 
 	int i = 0;
 	while(ListName[i])
 	{
 	    Lists.elem[Lists.length].name[i] = ListName[i];
 	    i++;
 	}
	//跟据线性表定义Lists中的线性表 
 	Lists.elem[Lists.length].name[i] = '\0';
 	Lists.elem[Lists.length].L=(LinkList)malloc(sizeof(LNode));
 	Lists.elem[Lists.length].L->next = NULL;
 	//名字最后一个加入\0，并且结点指向空指针。 
 	Lists.length++;
 	return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
{
 	// 18 在链表里移除 
 	int i;
 	for(i = 0; i < Lists.length; i++)
 	{
 	if(!strcmp(ListName,Lists.elem[i].name))
 	    {
 	    	//移除并且释放空间 
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
{//在Lists中查找对用的逻辑位置 
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
