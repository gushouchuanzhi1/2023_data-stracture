#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define TRUE 1  
#define FALSE 0  
#define OK 1  
#define ERROR 0  
#define INFEASIBLE -1  
#define OVERFLOW -2  
#define LIST_INIT_SIZE 100  
#define LISTINCREMENT  10  
typedef int status;
typedef int ElemType; //数据元素类型定义 
typedef struct {  //顺序表结构的定义 
    ElemType* elem;
    int length;
    int listsize;
}SqList;
typedef struct {  //线性表的集合类型定义  
    struct {
        char name[30];
        SqList L;
    } elem[10];
    int length;
}LISTS;
LISTS Lists;      //线性表集合的定义Lists  
// 1 编写一个函数实现线性表的初始化。线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
status InitList(SqList& L) 
{
    if (L.elem==NULL) {//如果不存在 
        L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));//给elem分配空间 
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
    }
    else {//存在 
        return INFEASIBLE;
    }
}

// 2 线性表的销毁：如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
status DestroyList(SqList& L) {
    if (!L.elem) return INFEASIBLE;
    else {
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
        free(L.elem);//释放该数据元素 
        return OK;
    }
}

// 3 清空线性表：如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
status ClearList(SqList& L) {
    if (L.elem) {//判断是否存在 
        L.length = 0;//清空线性表 
        return OK;
    }
    else return INFEASIBLE;
}

// 4 线性表判空：如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
status ListEmpty(SqList L) {
    if (L.elem) {
        if (L.length == 0) return TRUE;
        else if (L.length) return FALSE;
    }
    else return INFEASIBLE;
}

// 5 线性表长度：如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
status ListLength(SqList L) {
    if (L.elem) return L.length;
    else return INFEASIBLE;
}

// 6 获取元素：如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status GetElem(SqList L, int i, ElemType& e) {
    if (L.elem) {//如果存在 
        if (i < 1 || i > L.length) return ERROR;//不合法 
        else {
            e = L.elem[i - 1];
            return OK;
        }
    }
    else return INFEASIBLE;
}

// 7 查找元素：如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
int LocateElem(SqList L, ElemType e) {
    if (L.elem) {
        ElemType* p = L.elem;//p指向首位元素 
        int i = 1;
        while (i <= L.length && *p != e) {//同时判断i的合法性与elem是否和e相等 
            i++;
            p++;
        }
        if (i > L.length) return 0;
        else return i;
    }
    else return INFEASIBLE;
}

// 8 获取前驱元素：如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status PriorElem(SqList L, ElemType e, ElemType& pre) {
    if (L.elem) {
        ElemType* p = L.elem + 1;//由于判断前驱 i的范围要求有所不同 
        int i = 2;
        while (i <= L.length && *p != e) {
            i++;
            p++;
        }
        if (i > L.length) return ERROR;
        else {
            pre = *(--p);//取出前驱 
            return OK;
        }
    }
    else return INFEASIBLE;
}

// 9 获得后继元素：如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status NextElem(SqList L, ElemType e, ElemType& next)
{
    if (L.elem) {
        ElemType* p = L.elem;
        int i = 1;
        while (i < L.length && *p != e) {
            i++;
            p++;
        }
        if (i >= L.length) return ERROR;//由于要判断后继元素 所以i不能超过length-1 
        else {
            next = *(++p);//取出后继的地址 
            return OK;
        }
    }
    else return INFEASIBLE;
}

// 10 插入元素：如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListInsert(SqList& L, int i, ElemType e)
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        if(i<1||i>L.length+1){  //i的位置不合法
            return ERROR;
        }else{
            if(L.length>=L.listsize){       //如果线性表已满，则重新分配扩大空间
                ElemType * newbase=(ElemType*)realloc(L.elem, sizeof(ElemType)*(LIST_INIT_SIZE+LISTINCREMENT));
                if(newbase==NULL){
                    exit(-1);
                }else{
                    L.elem=newbase;
                    L.listsize=LIST_INIT_SIZE+LISTINCREMENT;
                }
            }
            for(int j=L.length;j>=i;j--){
                L.elem[j]=L.elem[j-1];          //移动元素达到插入目的
            }
            L.elem[i-1]=e;              //插入
            L.length++;                 //线性表长度变化
            return OK;
        }
    }
}

// 11 删除元素：如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListDelete(SqList& L, int i, ElemType& e)
{
    if (L.elem) {
        if (i < 1 || i > L.length) return ERROR;//判断是否合法 
        ElemType* p, * q;
        p = &(L.elem[i - 1]);
        e = *p;
        q = L.elem + L.length - 1;
        for (++p; p <= q; ++p) *(p - 1) = *p;//删除节点之后的全部前移 
        --L.length;
        return OK;
    }
    else return INFEASIBLE;
}

// 12 遍历线性表：如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
status ListTraverse(SqList L)
{
    if (L.elem) {//判断合法性 
        int i = 0;
        if (L.length == 0) {//空 
            printf("空线性表");
            return 0;
        }
        else {//非空 
            for (i; i < L.length; i++) {
                printf("%d ", L.elem[i]);
            }
            //printf("%d", L.elem[L.length - 1]);//最后一个去除空格 
            return OK;
        }
    }
    else return INFEASIBLE;
}

// 13 线性表读写文件：如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
status  SaveList(SqList L, char FileName[])
{
    if (!L.elem) return INFEASIBLE;
    else {
        FILE* pf = fopen("D:\\unniversity\\visual code\\experiment_1.txt", "w");
        for (int i = 0; i < L.length; i++) {
            fprintf(pf, "%d ", L.elem[i]);//将elem逐个写入文件中 
        }
        fclose(pf);
        return OK;
    }
}

// 14 线性表读写文件：如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
status  LoadList(SqList& L, char FileName[])
{//由于L不存在所以要重新初始化线性表，也即函数1的部分； 
    if (!L.elem) {
        L.elem = (ElemType*)malloc((LIST_INIT_SIZE) * sizeof(ElemType));
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;

        FILE* fp = fopen("D:\\unniversity\\visual code\\experiment_1.txt", "r");
        int shuju;
        int i = 0;
        for (i; fscanf(fp, "%d", &shuju) == 1; i++) {//将fscanf是否读到数据作为判断循环标准 
            L.elem[i] = shuju;
        }
        L.length = i;//更新length 
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
}

// 15 多线性表管理-新加一个新线性表：只需要在Lists中增加一个名称为ListName的空线性表.
status AddList(LISTS& Lists, char ListName[])
{
    if (Lists.length >= 10) {
        printf("超过Lists可以存储的数量！");
        return ERROR;
    }
    else {
        Lists.elem[Lists.length].L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        Lists.elem[Lists.length].L.length = 0;
        Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
        int j = 0;
        while (ListName[j] != '\0') {
            Lists.elem[Lists.length].name[j] = ListName[j];
            //将新增的空线性表名字逐字存入对应长度elem的name中
            j++;
        }
        Lists.elem[Lists.length].name[j] = '\0';
        Lists.length++;
    }
    return OK;
}

// 16 多线性表管理-移除一个线性表：Lists中删除一个名称为ListName的线性表
status RemoveList(LISTS& Lists, char ListName[])
{
    int i = 0;
    for (i = 0; i < Lists.length; i++) {
        if (!strcmp(ListName, Lists.elem[i].name)) {//比较名字 
            for (i; i < Lists.length; i++) {
                Lists.elem[i] = Lists.elem[i + 1];//直接把后面的指针赋给前面
            }
            return OK;
            --Lists.length;
        }
    }
    return ERROR;
}

// 17 多线性表管理-查找一个线性表：在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
int LocateList(LISTS Lists, char ListName[])
{
    int i = 0;
    for (i; i < Lists.length; i++) {
        if (!strcmp(ListName, Lists.elem[i].name)) {
            return i + 1;
        }
    }
    return 0;
}

// 18 最大连续子数组和 
int MaxSubArray(SqList L) {
    //当sum<0时舍弃p之前的元素，意思就是让sum变为0，当sum>=0时让sum=sum+p当前指向的元素的值
    int add_max = 0;
    int sum = 0;
    int* p = L.elem;
    for (int i = 0; i < L.length; i++) {
        sum = sum + *(p + i);
        if (sum > 0 || sum == 0) {
            //每次循环的时候让max和sum比较如果sum＞max就把sum的值赋给max。
            if (sum > add_max) add_max = sum;
        }
        if (sum < 0) sum = 0;
    }
    printf("最大连续子数组和为%d\n", add_max);
    return 0;
}

//  19 和为K的子数组：
int SubArrayNum(SqList L, ElemType k) {
    int count = 0;
    int sum[300];

    sum[0] = L.elem[0];
    for (int i = 1; i < L.length; i++) {
        //将第i位赋值第i位以及第i位之前的元素之和 
        sum[i] = sum[i - 1] + L.elem[i];
    }
    for (int j = 0; j < L.length; j++) {
        for (int k = 0; k <= j; k++) {//逐个做差作比较 
            if (sum[j] - sum[k] == k) count++;
        }

    }
    printf("和为K的子数组有%d\n", count);
    return 0;
}


//20 21考虑顺序表有两种排序方法 
// 20 顺序表排序：函数名称是sortList(L)；初始条件是线性表L已存在；操作结果是将L由小到大排序
status sortList_up(SqList L) {
    int trans;
    for (int i = 0; i < L.length - 1; i++) {
        for (int j = 0; j < L.length - i - 1; j++) {
            if (L.elem[j] > L.elem[j + 1]) {
                trans = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = trans;
            }
        }
    }
    return OK;
}

// 21 顺序表排序：函数名称是sortList(L)；初始条件是线性表L已存在；操作结果是将L由大到小排序
status sortList_down(SqList L) {
    int trans;
    for (int i = 0; i < L.length - 1; i++) {
        for (int j = 0; j < L.length - i - 1; j++) {
            if (L.elem[j] < L.elem[j + 1]) {
                trans = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = trans;
            }
        }
    }
    return OK;
}

// 22 在线性表管理中线性表进行遍历
status bianli_lists(LISTS Lists) {
    int n = 0;
    for (n = 0; n < Lists.length; n++)
    {
        printf("%s ", Lists.elem[n].name);
        ListTraverse(Lists.elem[n].L);
        putchar('\n');
    }
    return 0;
}

// 23 初始化lists 
status initial_lists(LISTS& Lists) {
    if (Lists.elem == NULL) {
        
        Lists.length = 0;
        return OK;
    }
}

// 24 对Lists中的线性表进行升序排列
status shengxu_lists(LISTS& Lists) {
    for (int n = 0; n < Lists.length; n++) {
        sortList_up(Lists.elem[n].L);
    }
    return OK;
}

// 25 对Lists中的线性表进行降序排列
status jiangxu_lists(LISTS& Lists) {
    for (int n = 0; n < Lists.length; n++) {
        sortList_down(Lists.elem[n].L);
    }
    return OK;
}

// 26 输出对应逻辑位置的元素
status delete_sqlist(SqList& L, int num) {
    if (num < L.length) {
        printf("%d", L.elem[num - 1]);
        return OK;
    }
    else return INFEASIBLE;
}
