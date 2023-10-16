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
typedef int ElemType; //����Ԫ�����Ͷ��� 
typedef struct {  //˳���ṹ�Ķ��� 
    ElemType* elem;
    int length;
    int listsize;
}SqList;
typedef struct {  //���Ա�ļ������Ͷ���  
    struct {
        char name[30];
        SqList L;
    } elem[10];
    int length;
}LISTS;
LISTS Lists;      //���Ա��ϵĶ���Lists  
// 1 ��дһ������ʵ�����Ա�ĳ�ʼ�������Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
status InitList(SqList& L) 
{
    if (L.elem==NULL) {//��������� 
        L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));//��elem����ռ� 
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
    }
    else {//���� 
        return INFEASIBLE;
    }
}

// 2 ���Ա�����٣�������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
status DestroyList(SqList& L) {
    if (!L.elem) return INFEASIBLE;
    else {
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
        free(L.elem);//�ͷŸ�����Ԫ�� 
        return OK;
    }
}

// 3 ������Ա�������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
status ClearList(SqList& L) {
    if (L.elem) {//�ж��Ƿ���� 
        L.length = 0;//������Ա� 
        return OK;
    }
    else return INFEASIBLE;
}

// 4 ���Ա��пգ�������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
status ListEmpty(SqList L) {
    if (L.elem) {
        if (L.length == 0) return TRUE;
        else if (L.length) return FALSE;
    }
    else return INFEASIBLE;
}

// 5 ���Ա��ȣ�������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
status ListLength(SqList L) {
    if (L.elem) return L.length;
    else return INFEASIBLE;
}

// 6 ��ȡԪ�أ�������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status GetElem(SqList L, int i, ElemType& e) {
    if (L.elem) {//������� 
        if (i < 1 || i > L.length) return ERROR;//���Ϸ� 
        else {
            e = L.elem[i - 1];
            return OK;
        }
    }
    else return INFEASIBLE;
}

// 7 ����Ԫ�أ�������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
int LocateElem(SqList L, ElemType e) {
    if (L.elem) {
        ElemType* p = L.elem;//pָ����λԪ�� 
        int i = 1;
        while (i <= L.length && *p != e) {//ͬʱ�ж�i�ĺϷ�����elem�Ƿ��e��� 
            i++;
            p++;
        }
        if (i > L.length) return 0;
        else return i;
    }
    else return INFEASIBLE;
}

// 8 ��ȡǰ��Ԫ�أ�������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status PriorElem(SqList L, ElemType e, ElemType& pre) {
    if (L.elem) {
        ElemType* p = L.elem + 1;//�����ж�ǰ�� i�ķ�ΧҪ��������ͬ 
        int i = 2;
        while (i <= L.length && *p != e) {
            i++;
            p++;
        }
        if (i > L.length) return ERROR;
        else {
            pre = *(--p);//ȡ��ǰ�� 
            return OK;
        }
    }
    else return INFEASIBLE;
}

// 9 ��ú��Ԫ�أ�������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status NextElem(SqList L, ElemType e, ElemType& next)
{
    if (L.elem) {
        ElemType* p = L.elem;
        int i = 1;
        while (i < L.length && *p != e) {
            i++;
            p++;
        }
        if (i >= L.length) return ERROR;//����Ҫ�жϺ��Ԫ�� ����i���ܳ���length-1 
        else {
            next = *(++p);//ȡ����̵ĵ�ַ 
            return OK;
        }
    }
    else return INFEASIBLE;
}

// 10 ����Ԫ�أ�������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListInsert(SqList& L, int i, ElemType e)
{
    if(L.elem==NULL){
        return INFEASIBLE;
    }else{
        if(i<1||i>L.length+1){  //i��λ�ò��Ϸ�
            return ERROR;
        }else{
            if(L.length>=L.listsize){       //������Ա������������·�������ռ�
                ElemType * newbase=(ElemType*)realloc(L.elem, sizeof(ElemType)*(LIST_INIT_SIZE+LISTINCREMENT));
                if(newbase==NULL){
                    exit(-1);
                }else{
                    L.elem=newbase;
                    L.listsize=LIST_INIT_SIZE+LISTINCREMENT;
                }
            }
            for(int j=L.length;j>=i;j--){
                L.elem[j]=L.elem[j-1];          //�ƶ�Ԫ�شﵽ����Ŀ��
            }
            L.elem[i-1]=e;              //����
            L.length++;                 //���Ա��ȱ仯
            return OK;
        }
    }
}

// 11 ɾ��Ԫ�أ�������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListDelete(SqList& L, int i, ElemType& e)
{
    if (L.elem) {
        if (i < 1 || i > L.length) return ERROR;//�ж��Ƿ�Ϸ� 
        ElemType* p, * q;
        p = &(L.elem[i - 1]);
        e = *p;
        q = L.elem + L.length - 1;
        for (++p; p <= q; ++p) *(p - 1) = *p;//ɾ���ڵ�֮���ȫ��ǰ�� 
        --L.length;
        return OK;
    }
    else return INFEASIBLE;
}

// 12 �������Ա�������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
status ListTraverse(SqList L)
{
    if (L.elem) {//�жϺϷ��� 
        int i = 0;
        if (L.length == 0) {//�� 
            printf("�����Ա�");
            return 0;
        }
        else {//�ǿ� 
            for (i; i < L.length; i++) {
                printf("%d ", L.elem[i]);
            }
            //printf("%d", L.elem[L.length - 1]);//���һ��ȥ���ո� 
            return OK;
        }
    }
    else return INFEASIBLE;
}

// 13 ���Ա��д�ļ���������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
status  SaveList(SqList L, char FileName[])
{
    if (!L.elem) return INFEASIBLE;
    else {
        FILE* pf = fopen("D:\\unniversity\\visual code\\experiment_1.txt", "w");
        for (int i = 0; i < L.length; i++) {
            fprintf(pf, "%d ", L.elem[i]);//��elem���д���ļ��� 
        }
        fclose(pf);
        return OK;
    }
}

// 14 ���Ա��д�ļ���������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
status  LoadList(SqList& L, char FileName[])
{//����L����������Ҫ���³�ʼ�����Ա�Ҳ������1�Ĳ��֣� 
    if (!L.elem) {
        L.elem = (ElemType*)malloc((LIST_INIT_SIZE) * sizeof(ElemType));
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;

        FILE* fp = fopen("D:\\unniversity\\visual code\\experiment_1.txt", "r");
        int shuju;
        int i = 0;
        for (i; fscanf(fp, "%d", &shuju) == 1; i++) {//��fscanf�Ƿ����������Ϊ�ж�ѭ����׼ 
            L.elem[i] = shuju;
        }
        L.length = i;//����length 
        fclose(fp);
        return OK;
    }
    else return INFEASIBLE;
}

// 15 �����Ա����-�¼�һ�������Ա�ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա�.
status AddList(LISTS& Lists, char ListName[])
{
    if (Lists.length >= 10) {
        printf("����Lists���Դ洢��������");
        return ERROR;
    }
    else {
        Lists.elem[Lists.length].L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        Lists.elem[Lists.length].L.length = 0;
        Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
        int j = 0;
        while (ListName[j] != '\0') {
            Lists.elem[Lists.length].name[j] = ListName[j];
            //�������Ŀ����Ա��������ִ����Ӧ����elem��name��
            j++;
        }
        Lists.elem[Lists.length].name[j] = '\0';
        Lists.length++;
    }
    return OK;
}

// 16 �����Ա����-�Ƴ�һ�����Ա�Lists��ɾ��һ������ΪListName�����Ա�
status RemoveList(LISTS& Lists, char ListName[])
{
    int i = 0;
    for (i = 0; i < Lists.length; i++) {
        if (!strcmp(ListName, Lists.elem[i].name)) {//�Ƚ����� 
            for (i; i < Lists.length; i++) {
                Lists.elem[i] = Lists.elem[i + 1];//ֱ�ӰѺ����ָ�븳��ǰ��
            }
            return OK;
            --Lists.length;
        }
    }
    return ERROR;
}

// 17 �����Ա����-����һ�����Ա���Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
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

// 18 �������������� 
int MaxSubArray(SqList L) {
    //��sum<0ʱ����p֮ǰ��Ԫ�أ���˼������sum��Ϊ0����sum>=0ʱ��sum=sum+p��ǰָ���Ԫ�ص�ֵ
    int add_max = 0;
    int sum = 0;
    int* p = L.elem;
    for (int i = 0; i < L.length; i++) {
        sum = sum + *(p + i);
        if (sum > 0 || sum == 0) {
            //ÿ��ѭ����ʱ����max��sum�Ƚ����sum��max�Ͱ�sum��ֵ����max��
            if (sum > add_max) add_max = sum;
        }
        if (sum < 0) sum = 0;
    }
    printf("��������������Ϊ%d\n", add_max);
    return 0;
}

//  19 ��ΪK�������飺
int SubArrayNum(SqList L, ElemType k) {
    int count = 0;
    int sum[300];

    sum[0] = L.elem[0];
    for (int i = 1; i < L.length; i++) {
        //����iλ��ֵ��iλ�Լ���iλ֮ǰ��Ԫ��֮�� 
        sum[i] = sum[i - 1] + L.elem[i];
    }
    for (int j = 0; j < L.length; j++) {
        for (int k = 0; k <= j; k++) {//����������Ƚ� 
            if (sum[j] - sum[k] == k) count++;
        }

    }
    printf("��ΪK����������%d\n", count);
    return 0;
}


//20 21����˳������������򷽷� 
// 20 ˳������򣺺���������sortList(L)����ʼ���������Ա�L�Ѵ��ڣ���������ǽ�L��С��������
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

// 21 ˳������򣺺���������sortList(L)����ʼ���������Ա�L�Ѵ��ڣ���������ǽ�L�ɴ�С����
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

// 22 �����Ա���������Ա���б���
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

// 23 ��ʼ��lists 
status initial_lists(LISTS& Lists) {
    if (Lists.elem == NULL) {
        
        Lists.length = 0;
        return OK;
    }
}

// 24 ��Lists�е����Ա������������
status shengxu_lists(LISTS& Lists) {
    for (int n = 0; n < Lists.length; n++) {
        sortList_up(Lists.elem[n].L);
    }
    return OK;
}

// 25 ��Lists�е����Ա���н�������
status jiangxu_lists(LISTS& Lists) {
    for (int n = 0; n < Lists.length; n++) {
        sortList_down(Lists.elem[n].L);
    }
    return OK;
}

// 26 �����Ӧ�߼�λ�õ�Ԫ��
status delete_sqlist(SqList& L, int num) {
    if (num < L.length) {
        printf("%d", L.elem[num - 1]);
        return OK;
    }
    else return INFEASIBLE;
}
