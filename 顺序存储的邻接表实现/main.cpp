#include "def.h"

int main() {
    SqList L;
    L.elem = NULL;
    LISTS Lists;
    char myfilename[] = "D:\\unniversity\\visual code\\experiment_1.txt";
    int sign = 1;//�������� 
    while (sign != 0) {
        system("cls");
        printf("\n\n");
        printf("U202115602 CS2109 ̸���� ����\n");
        printf("\n");
        printf("                   ���Ա������ʾ�˵�\n");
        printf("-----------------------------------------------------------------\n");
        printf("\n");
        printf("0.Exit �˳��˵�\n");
        printf("1.InitList���Ա��ʼ��               2.DestroyList�������Ա�\n");
        printf("3.ClearList������Ա�                4.ListEmpty���Ա��п�\n");
        printf("5.ListLength���Ա���               6.GetElem��ȡԪ��\n");
        printf("7.LocateElem����Ԫ��                 8.PriorElem���ǰ��Ԫ��\n");
        printf("9.NextElem��ú��Ԫ��               10.ListInsert����Ԫ��\n");
        printf("11.ListDeleteɾ��Ԫ��                12.ListTraverse�������Ա�\n");
        printf("13.SaveList���Ա�����ļ�            14.LoadList�ļ��������Ա�\n");
        printf("15.AddList��������µ����Ա�         16.RemoveList�����Ƴ����Ա�\n");
        printf("17.LocateList�������Ա�              18.MaxSubArray������������\n");
        printf("19.SubArrayNum��Ϊk�����������      20.sortList_up���Ա���������\n");
        printf("21.sortList_down���Ա�������       22.bianli_lists�������е������Ա�\n");
        printf("23.initial����lists��ʼ���������Ա�  24.shengxu_lists�������������Ա�\n");
        printf("25.jiangxu_lists�������������Ա�     26.delete_sqlistɾ����Ӧ�߼�λ�õ�Ԫ��\n");
        printf("\n");
        printf("-----------------------------------------------------------------\n");
        printf("����ɲ������밴һ�λس�\n");
        printf("���������֣�0~26���Խ��в�����\n");
        scanf("%d", &sign);
        if (sign < 0 && sign > 26) printf("�������ִ����������������֣���0~23��\n");
        else {
            switch (sign) {
            case 0:
                break;
            case 1: {
                printf("�����������Ա��ʼ������\n");
                int flag = InitList(L);
                if (flag == OK) {
                    printf("���Ա��ʼ���ɹ���\n");
                }
                else printf("���Ա��ʼ��ʧ�ܣ�\n");
                getchar(); getchar();
                break; }
            case 2: {
                printf("���������������Ա����\n");
                int flag = DestroyList(L);
                if (flag == 1) printf("���ٳɹ�\n");
                else printf("����ʧ��\n");
                getchar(); getchar();
                break; }
            case 3: {
                printf("��������������Ա����\n");
                int flag = ClearList(L);
                if (flag == 1) printf("��ճɹ�\n");
                else printf("���ʧ��\n");
                getchar(); getchar();
                break; }
            case 4: {
                printf("�����������Ա��пղ���\n");
                int flag = ListEmpty(L);
                if (flag == 1) printf("���Ա�Ϊ��\n");
                else if (flag == 0)printf("���Ա�Ϊ��\n");
                else printf("���Ա�����\n");
                getchar(); getchar();
                break; }
            case 5: {
                printf("�������������Ա��Ȳ���\n");
                int flag = ListLength(L);
                if (flag == -1)printf("���Ա�����\n");
                else {
                    printf("���Ա���Ϊ%d\n", flag);
                }
                getchar(); getchar();
                break; }
            case 6:
            {
                printf("�������л�ȡԪ�ز���\n");
                int i;
                printf("������Ҫ��ȡ��Ԫ�ص��߼�λ��\n");
                scanf("%d", &i);
                ElemType e = 0;
                int flag = GetElem(L, i, e);
                if (flag == 0) printf("������벻��ȷ��\n");
                else if(flag == -1) printf("failed\n");
                else printf("��%dλԪ����%d\n", i, flag);
                getchar(); getchar();
                break;
            }
            case 7:
            {
                printf("�������в���Ԫ�ز���\n");
                ElemType e;
                printf("��������Ҫ���ҵ�Ԫ��\n");
                scanf("%d", &e);
                int flag = LocateElem(L, e);
                if (flag == -1) printf("���Ա�����\n");
                else if (flag == 0) printf("��Ԫ�ز�����\n");
                else printf("��Ԫ�������Ա�λ����%d\n", LocateElem(L, e));
                getchar(); getchar();
                break;
            }
            case 8:
            {
                printf("�������л��ǰ��Ԫ�ز���\n");
                ElemType pre = 0;
                ElemType e;
                printf("������Ԫ��\n");
                scanf("%d", &e);
                int flag = PriorElem(L, e, pre);
                if (flag == -1) printf("���Ա�����\n");
                else if (flag == 0) printf("i���������Ա��ȣ�\n");
                else printf("��Ԫ�ص�ǰ����%d\n", pre);
                getchar(); getchar();
                break;
            }
            case 9:
            {
                printf("�������л�ú��Ԫ�ز���\n");
                ElemType next;
                ElemType e;
                printf("������Ԫ��\n");
                scanf("%d", &e);
                int flag = NextElem(L, e, next);
                if (flag == -1) printf("���Ա�����\n");
                else if (flag == 0) printf("i���������Ա��ȣ�\n");
                else printf("��Ԫ�صĺ����%d\n", next);
                getchar(); getchar();
                break;
            }
            case 10:
            {
                printf("�������в���Ԫ�ز���\n");
                ElemType e; int i;
                printf("�����������߼�λ��\n");
                scanf("%d", &i);
                printf("����������Ԫ��\n");
                scanf("%d", &e);
                status flag = ListInsert(L, i, e);
                if (flag == -1) printf("���Ա�����");
                else if (flag == 0) printf("iֵ���������Ա��ȣ�");
                getchar(); getchar();
                break;
            }
            case 11:
            {
                printf("��������ɾ��Ԫ�ز���\n");
                ElemType e; int i;
                printf("������ɾ�����߼�λ��\n");
                scanf("%d", &i);
                int flag = ListDelete(L, i, e);
                if (flag == -1) printf("���Ա����ڣ�\n");
                else if (flag == 0) printf("iֵ���������Ա��ȣ�\n");
                else printf("��ɾ����Ԫ����%d\n", e);
                getchar(); getchar();
                break;
            }
            case 12:
            {
                printf("�������б������Ա����\n");
                int flag = ListTraverse(L);
                if (flag == INFEASIBLE) printf("failed!\n");
                getchar(); getchar();
                break;
            }
            case 13:
            {
                printf("�����������Ա�����ļ�����\n");
                if (SaveList(L, myfilename) == -1) printf("���Ա�����\n");
                else printf("���Ա��д�ɹ� �ļ�����·��Ϊ%s\n", myfilename);
                getchar(); getchar();
                break;
            }
            case 14:
            {
                printf("���������ļ��������Ա����\n");
                if (LoadList(L, myfilename) == -1) printf("���Ա���ڣ���������Ա����ƣ��ò������Զ���ʼ�����Ա�\n");
                else printf("�ļ�����·��Ϊ%s\n", myfilename);
                getchar(); getchar();
                break;
            }
            case 15:
            {
                printf("�������й�������µ����Ա����\n");
                printf("������Ҫ�����µ����Ա�������\n");
                int num, e;
                char name[30];
                Lists.length = 0;
                
                scanf("%d", &num);
                while (num--) {
                    int j = 1;
                    printf("���������Ա�����\n");
                    scanf("%s", name);
                    AddList(Lists, name);
                   
                    printf("������%s���Ա��е�Ԫ�أ�������0ʱ��Ϊ�������\n", name);
                    scanf("%d", &e);
                    while (e) {
                        ListInsert(Lists.elem[Lists.length-1].L, Lists.elem[Lists.length-1].L.length + 1, e);
                        scanf("%d", &e);
                        
                    }                   
                    //printf("%d", Lists.length);
                    //ListTraverse(Lists.elem[Lists.length-1].L);
                }
                getchar(); getchar();
                break;
            }
            case 16:
            {
                printf("�������й����Ƴ����Ա����\n");
                printf("���������Ա�����\n");
                char ListName[30];
                scanf("%s", ListName);
                if (RemoveList(Lists, ListName) == 0)printf("���������Ա�����\n");
                else printf("����Ϊ%s�����Ա���ɾ��\n", ListName);
                getchar(); getchar();
                break;
            }
            case 17:
            {
                printf("�������в������Ա����\n");
                printf("���������Ա�����\n");
                char ListName[30];
                scanf("%s", ListName);
                if (LocateList(Lists, ListName) == 0)printf("�����Ա�����\n");
                else printf("�����Ա��߼����Ϊ%d\n", LocateList(Lists, ListName));
                getchar(); getchar();
                break;
            }
            case 18:
            {
                printf("�������������������Ͳ���\n");
                MaxSubArray(L);
                getchar(); getchar();
                break;
            }
            case 19:
            {
                printf("�������в��Һ�Ϊk���������������\n");
                int k;
                printf("������Ҫ���ҵ��������\n");
                scanf("%d", &k);
                SubArrayNum(L, k);
                getchar(); getchar();
                break;
            }
            case 20:
            {
                printf("�����������Ա������������\n");
                sortList_up(L);
                printf("�������\n");
                getchar(); getchar();
                break;
            }
            case 21:
            {
                printf("�����������Ա����������\n");
                sortList_down(L);
                printf("�������\n");
                getchar(); getchar();
                break;
            }

            case 22: {
                printf("�������б����������Ա�Ĳ�����\n");
                bianli_lists(Lists);
                getchar(); getchar();
                break;
            }
            case 23: {
                printf("��ʼ�����Ա�ɹ���\n");
                initial_lists(Lists);
                getchar(); getchar();
                break;
            }

            case 24: {
                printf("��Lists�����Ա��������гɹ�^_^!\n");
                shengxu_lists(Lists);
                getchar(); getchar();
                break;
            }

            case 25: {
                printf("��Lists�����Ա������гɹ���\n");
                jiangxu_lists(Lists);
                getchar(); getchar();
                break;
            }

            case 26:{
               int pos = 0;
               printf("��������Ҫ������߼�λ��\n");
               scanf("%d", &pos);
               int flag = delete_sqlist(L, pos);
               if (flag == 1)printf("success!\n");
               else printf("failed!\n");
               getchar(); getchar();
               break;

            }


            }
        }
     
    }
    printf("��лʹ�ã�\n");
}
