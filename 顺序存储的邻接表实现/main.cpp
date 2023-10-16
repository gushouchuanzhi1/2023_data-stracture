#include "def.h"

int main() {
    SqList L;
    L.elem = NULL;
    LISTS Lists;
    char myfilename[] = "D:\\unniversity\\visual code\\experiment_1.txt";
    int sign = 1;//操作数字 
    while (sign != 0) {
        system("cls");
        printf("\n\n");
        printf("U202115602 CS2109 谈德昱 制作\n");
        printf("\n");
        printf("                   线性表操作演示菜单\n");
        printf("-----------------------------------------------------------------\n");
        printf("\n");
        printf("0.Exit 退出菜单\n");
        printf("1.InitList线性表初始化               2.DestroyList销毁线性表\n");
        printf("3.ClearList清空线性表                4.ListEmpty线性表判空\n");
        printf("5.ListLength线性表长度               6.GetElem获取元素\n");
        printf("7.LocateElem查找元素                 8.PriorElem获得前驱元素\n");
        printf("9.NextElem获得后继元素               10.ListInsert插入元素\n");
        printf("11.ListDelete删除元素                12.ListTraverse遍历线性表\n");
        printf("13.SaveList线性表存入文件            14.LoadList文件读入线性表\n");
        printf("15.AddList管理添加新的线性表         16.RemoveList管理移除线性表\n");
        printf("17.LocateList查找线性表              18.MaxSubArray求最大子数组和\n");
        printf("19.SubArrayNum和为k的子数组个数      20.sortList_up线性表升序排序\n");
        printf("21.sortList_down线性表降序排序       22.bianli_lists遍历所有的子线性表\n");
        printf("23.initial——lists初始化管理线性表  24.shengxu_lists升序排列子线性表\n");
        printf("25.jiangxu_lists降序排列子线性表     26.delete_sqlist删除对应逻辑位置的元素\n");
        printf("\n");
        printf("-----------------------------------------------------------------\n");
        printf("在完成操作后请按一次回车\n");
        printf("请输入数字（0~26）以进行操作！\n");
        scanf("%d", &sign);
        if (sign < 0 && sign > 26) printf("输入数字错误，请重新输入数字！（0~23）\n");
        else {
            switch (sign) {
            case 0:
                break;
            case 1: {
                printf("即将进行线性表初始化操作\n");
                int flag = InitList(L);
                if (flag == OK) {
                    printf("线性表初始化成功！\n");
                }
                else printf("线性表初始化失败！\n");
                getchar(); getchar();
                break; }
            case 2: {
                printf("即将进行销毁线性表操作\n");
                int flag = DestroyList(L);
                if (flag == 1) printf("销毁成功\n");
                else printf("销毁失败\n");
                getchar(); getchar();
                break; }
            case 3: {
                printf("即将进行清空线性表操作\n");
                int flag = ClearList(L);
                if (flag == 1) printf("清空成功\n");
                else printf("清空失败\n");
                getchar(); getchar();
                break; }
            case 4: {
                printf("即将进行线性表判空操作\n");
                int flag = ListEmpty(L);
                if (flag == 1) printf("线性表为空\n");
                else if (flag == 0)printf("线性表不为空\n");
                else printf("线性表不存在\n");
                getchar(); getchar();
                break; }
            case 5: {
                printf("即将进行求线性表长度操作\n");
                int flag = ListLength(L);
                if (flag == -1)printf("线性表不存在\n");
                else {
                    printf("线性表长度为%d\n", flag);
                }
                getchar(); getchar();
                break; }
            case 6:
            {
                printf("即将进行获取元素操作\n");
                int i;
                printf("请输入要获取的元素的逻辑位置\n");
                scanf("%d", &i);
                ElemType e = 0;
                int flag = GetElem(L, i, e);
                if (flag == 0) printf("序号输入不正确！\n");
                else if(flag == -1) printf("failed\n");
                else printf("第%d位元素是%d\n", i, flag);
                getchar(); getchar();
                break;
            }
            case 7:
            {
                printf("即将进行查找元素操作\n");
                ElemType e;
                printf("请输入需要查找的元素\n");
                scanf("%d", &e);
                int flag = LocateElem(L, e);
                if (flag == -1) printf("线性表不存在\n");
                else if (flag == 0) printf("该元素不存在\n");
                else printf("该元素在线性表位置是%d\n", LocateElem(L, e));
                getchar(); getchar();
                break;
            }
            case 8:
            {
                printf("即将进行获得前驱元素操作\n");
                ElemType pre = 0;
                ElemType e;
                printf("请输入元素\n");
                scanf("%d", &e);
                int flag = PriorElem(L, e, pre);
                if (flag == -1) printf("线性表不存在\n");
                else if (flag == 0) printf("i不符合线性表长度！\n");
                else printf("该元素的前驱是%d\n", pre);
                getchar(); getchar();
                break;
            }
            case 9:
            {
                printf("即将进行获得后继元素操作\n");
                ElemType next;
                ElemType e;
                printf("请输入元素\n");
                scanf("%d", &e);
                int flag = NextElem(L, e, next);
                if (flag == -1) printf("线性表不存在\n");
                else if (flag == 0) printf("i不符合线性表长度！\n");
                else printf("该元素的后继是%d\n", next);
                getchar(); getchar();
                break;
            }
            case 10:
            {
                printf("即将进行插入元素操作\n");
                ElemType e; int i;
                printf("请输入插入的逻辑位置\n");
                scanf("%d", &i);
                printf("请输入插入的元素\n");
                scanf("%d", &e);
                status flag = ListInsert(L, i, e);
                if (flag == -1) printf("线性表不存在");
                else if (flag == 0) printf("i值不符合线性表长度！");
                getchar(); getchar();
                break;
            }
            case 11:
            {
                printf("即将进行删除元素操作\n");
                ElemType e; int i;
                printf("请输入删除的逻辑位置\n");
                scanf("%d", &i);
                int flag = ListDelete(L, i, e);
                if (flag == -1) printf("线性表不存在！\n");
                else if (flag == 0) printf("i值不符合线性表长度！\n");
                else printf("被删除的元素是%d\n", e);
                getchar(); getchar();
                break;
            }
            case 12:
            {
                printf("即将进行遍历线性表操作\n");
                int flag = ListTraverse(L);
                if (flag == INFEASIBLE) printf("failed!\n");
                getchar(); getchar();
                break;
            }
            case 13:
            {
                printf("即将进行线性表存入文件操作\n");
                if (SaveList(L, myfilename) == -1) printf("线性表不存在\n");
                else printf("线性表读写成功 文件保存路径为%s\n", myfilename);
                getchar(); getchar();
                break;
            }
            case 14:
            {
                printf("即将进行文件读入线性表操作\n");
                if (LoadList(L, myfilename) == -1) printf("线性表存在，请更换线性表名称，该操作会自动初始化线性表！\n");
                else printf("文件保存路径为%s\n", myfilename);
                getchar(); getchar();
                break;
            }
            case 15:
            {
                printf("即将进行管理添加新的线性表操作\n");
                printf("请输入要插入新的线性表数量！\n");
                int num, e;
                char name[30];
                Lists.length = 0;
                
                scanf("%d", &num);
                while (num--) {
                    int j = 1;
                    printf("请输入线性表名字\n");
                    scanf("%s", name);
                    AddList(Lists, name);
                   
                    printf("请输入%s线性表中的元素，当输入0时视为输入结束\n", name);
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
                printf("即将进行管理移除线性表操作\n");
                printf("请输入线性表名字\n");
                char ListName[30];
                scanf("%s", ListName);
                if (RemoveList(Lists, ListName) == 0)printf("该名称线性表不存在\n");
                else printf("名称为%s的线性表已删除\n", ListName);
                getchar(); getchar();
                break;
            }
            case 17:
            {
                printf("即将进行查找线性表操作\n");
                printf("请输入线性表名字\n");
                char ListName[30];
                scanf("%s", ListName);
                if (LocateList(Lists, ListName) == 0)printf("该线性表不存在\n");
                else printf("该线性表逻辑序号为%d\n", LocateList(Lists, ListName));
                getchar(); getchar();
                break;
            }
            case 18:
            {
                printf("即将进行求最大子数组和操作\n");
                MaxSubArray(L);
                getchar(); getchar();
                break;
            }
            case 19:
            {
                printf("即将进行查找和为k的子数组个数操作\n");
                int k;
                printf("请输入要查找的子数组和\n");
                scanf("%d", &k);
                SubArrayNum(L, k);
                getchar(); getchar();
                break;
            }
            case 20:
            {
                printf("即将进行线性表升序排序操作\n");
                sortList_up(L);
                printf("操作完成\n");
                getchar(); getchar();
                break;
            }
            case 21:
            {
                printf("即将进行线性表降序排序操作\n");
                sortList_down(L);
                printf("操作完成\n");
                getchar(); getchar();
                break;
            }

            case 22: {
                printf("即将进行遍历管理线性表的操作！\n");
                bianli_lists(Lists);
                getchar(); getchar();
                break;
            }
            case 23: {
                printf("初始化线性表成功！\n");
                initial_lists(Lists);
                getchar(); getchar();
                break;
            }

            case 24: {
                printf("对Lists中线性表升序排列成功^_^!\n");
                shengxu_lists(Lists);
                getchar(); getchar();
                break;
            }

            case 25: {
                printf("对Lists中线性表降序排列成功！\n");
                jiangxu_lists(Lists);
                getchar(); getchar();
                break;
            }

            case 26:{
               int pos = 0;
               printf("请输入需要输出的逻辑位置\n");
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
    printf("感谢使用！\n");
}
