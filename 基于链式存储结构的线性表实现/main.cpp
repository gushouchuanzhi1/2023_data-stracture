#include "def.h"


int main(void){
	LinkList L;  
	int x = 1, flag = 0, i = 0, j, n, e = 0;
	int pre = 0, next = 0, sum = 0, num = 0;
	L = NULL;
	char Name[20];
	char FileName[30];
	LISTS Lists;
	Lists.length=0;
	
	char myfilename[]="1.txt";
	//用myfilename定义路径方便后续文件读取操作 
	while(x != 0){
		system("cls");	
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList       9. NextElem\n");
		printf("    	  2. DestroyList    10. ListInsert\n");
		printf("    	  3. ClearList      11. ListDelete\n");
		printf("    	  4. ListEmpty      12. ListTrabverse\n");
		printf("    	  5. ListLength     13. reverseList\n");
		printf("    	  6. GetElem        14.RemoveNthFromEnd\n");
		printf("    	  7. LocateElem		15.sortList\n");
		printf("    	  8. PriorElem		\n");
		printf("    	  16. SaveList      17. LoadList\n");
		printf("    	  18. AddList       19. RemoveList\n");
		printf("    	  20. LocateList    21. ListInsert\n");
		printf("    	  22. ListDelete    23. ListTrabverse（第几个表 逻辑位置 元素）\n");
		printf("    	  24. sortlist\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~24]:");
		scanf("%d",&x);
		
	switch(x){
	   	case 1://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	if(InitList(L) == OK) printf("链表创建成功！\n");
		 	else printf("链表创建失败！\n");
		 	
		 	getchar();getchar();
		 	break;
	   
	   	case 2://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	flag = DestroyList(L);
		 	if(flag == OK) printf("链表摧毁成功！\n");
		 	else if(flag == INFEASIBLE) printf("链表摧毁失败！\n");
		 	
		 	getchar();getchar();
		 	break;
	   	
		case 3://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			if(ClearList(L) == OK) printf("链表已清空！\n");
			else printf("链表不存在！\n");   
			getchar();getchar();
			break;
			
	   	case 4://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
	   		if(ListEmpty(L) == INFEASIBLE) printf("链表不存在！\n");
			else if(ListEmpty(L) == TRUE) printf("链表为空！\n");
			else if(ListEmpty(L) == FALSE) printf("链表不为空！\n");
		 	
			getchar();getchar();
		 	break;
		 	
	   	case 5://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	if(ListLength(L)==INFEASIBLE) printf("链表不存在！\n");
			else printf("链表的长度为%d！\n",ListLength(L));    
		 	getchar();getchar();
		 	break;
		 	
	   	case 6://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
	   		printf("请输入获取元素的位置\n");
	   		scanf("%d",&i);
			if(GetElem(L,i,e)==INFEASIBLE) printf("链表不存在！\n");
			else if(GetElem(L,i,e)==OK) printf("已成功保存在e中，元素为%d！\n",e);
			else if(GetElem(L,i,e)==ERROR) printf("获取位置非法！\n");
			
		 	getchar();getchar();
		 	break;
		 	
	   	case 7://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
	   		printf("请输入查找元素\n");
	   		scanf("%d",&e); 
	   		if(LocateElem(L,e)==INFEASIBLE) printf("链表不存在！\n");
			else if(LocateElem(L,e)==0) printf("元素不在链表中！\n");
			else printf("链表中元素的位置为%d！\n",LocateElem(L,e));
		 	getchar();getchar();
		 	break;
		 	
	   	case 8://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
	   		printf("请输入获取前驱的元素\n");
	   		scanf("%d",&e);
		 	if(PriorElem(L,e,pre)==INFEASIBLE) printf("链表不存在！\n");
			else if(PriorElem(L,e,pre)==OK) printf("前驱已成功保存在pre中，前驱为%d！\n",pre);
			else if(PriorElem(L,e,pre)==ERROR) printf("前驱不存在！\n");  
		 	getchar();getchar();
		 	break;
	   	case 9://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	printf("请输入获取后继的元素\n");
	   		scanf("%d",&e);
		 	if(NextElem(L,e,next)==INFEASIBLE) printf("链表不存在！\n");
			else if(NextElem(L,e,next)==OK) printf("后继已成功保存在next中，后继为%d！\n",next);
			else if(NextElem(L,e,next)==ERROR) printf("后继不存在！\n");     
		 	getchar();getchar();
		 	break;
		 	
	   	case 10://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			printf("请依次输入插入位置和插入元素\n");
	   		scanf("%d %d",&i,&e);
	   		flag=ListInsert(L,i,e);
		 	if(flag==INFEASIBLE) printf("链表不存在！\n");
			else if(flag==OK) printf("元素插入成功！\n");
			else if(flag==ERROR) printf("插入位置非法！\n");     
		 	getchar();getchar();
		 	break;
		 	
	   	case 11://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	printf("请输入删除位置\n");
	   		scanf("%d",&i);
	    	flag=ListDelete(L,i,e);
		 	if(flag==INFEASIBLE) printf("链表不存在！\n");
			else if(flag==OK) printf("元素删除成功，该元素为%d！\n",e);
			else if(flag==ERROR) printf("删除位置非法！\n");      
		 	getchar();getchar();
		 	break;
		 	
	   	case 12://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作      
		 	if(ListTraverse(L)==INFEASIBLE) printf("链表不存在！\n");
			getchar();getchar();
		 	break;
		 	
		case 13://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			if(reverseList(L)==INFEASIBLE) printf("链表是空表！\n");
			else printf("链表翻转成功\n");
			getchar();getchar();
		 	break;
		 	
		case 14://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	printf("请输入删除链表的倒数第n个结点\n");
			 scanf("%d",&n); 
			if(RemoveNthFromEnd(L,n)==INFEASIBLE) printf("链表不存在！\n");
			else printf("元素删除成功\n");
			getchar();getchar();
		 	break;
		 	
		case 15://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			if(sortList(L)==INFEASIBLE) printf("链表不存在！\n");
			else if(sortList(L)==OK) printf("链表已由小到大排序！");
			getchar();getchar();
		 	break;
		 	
		case 16://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	flag=SaveList(L, myfilename);
			if(flag==INFEASIBLE) printf("链表不存在！\n");
			else if(flag==OK) printf("链表已存储在测试文件中！");
			getchar();getchar();
		 	break;
		 	
		case 17://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			flag=LoadList(L,myfilename);
			if(flag==INFEASIBLE) printf("链表已存在！\n");
			else if(flag==OK) printf("测试文件数据已读入链表中！");
			getchar();getchar();
		 	break;
		 	
		case 18://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	printf("请输入添加的链表名");
		 	scanf("%s",Name);
		 	flag=AddList(Lists,Name);
			if(flag==OK) printf("链表%s已添加至Lists中！\n",Name);
			getchar();getchar();
		 	break;
		 	
		case 19://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
		 	printf("请输入删除的链表名");
		 	scanf("%s",Name);
		 	flag=RemoveList(Lists,Name);
			if(flag==OK) printf("链表%s从Lists中删除！\n",Name);
			else printf("删除失败"); 
			getchar();getchar();
			break;
		
		case 20://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			printf("输入链表名");
		 	scanf("%s",Name);
		 	flag=LocateList(Lists,Name);
			if(flag) printf("链表%s在Lists中的位置是%d！\n",Name,flag);
			else printf("未找到对应链表"); 
			getchar();getchar();
		 	break;
		 	
		case 21://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			printf("请依次输入选择的表序,插入位置和插入元素\n");
		   	scanf("%d %d %d",&num,&i,&e);
		   	flag=ListInsert(Lists.elem[num-1].L,i,e);
			if(flag==INFEASIBLE) printf("链表不存在！\n");
			else if(flag==OK) printf("元素插入成功！\n");
			else if(flag==ERROR) printf("插入位置非法！\n");     
			getchar();getchar();
			break;
			
		case 22://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			printf("请输入选择的表序,删除位置\n");
		   	scanf("%d %d",&num,&i);
		    flag=ListDelete(Lists.elem[num-1].L,i,e);
			if(flag==INFEASIBLE) printf("链表不存在！\n");
			else if(flag==OK) printf("元素删除成功，该元素为%d！\n",e);
			else if(flag==ERROR) printf("删除位置非法！\n");      
			getchar();getchar();
			break;
	   	
		case 23://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			int i;
			if(!Lists.length)
			{
				printf("链表不存在!\n");
			}
			for(i=0;i<Lists.length;i++)
			{
				printf("%s ",Lists.elem[i].name);
				ListTraverse(Lists.elem[i].L);
				printf("\n");
			}
			getchar();getchar();
			break; 
			
		case 24://尽量通过flag==status来进行操作成功失败判断，以防多次进行函数操作 
			int j;
			for(i=0;i<Lists.length;i++)
		 	{
		 		sortList(Lists.elem[i].L);
		 	}
		 	printf("已排序成功!");
			getchar();getchar();
			break;
		case 0:
         	break;
		}
  	}
	printf("欢迎下次再使用本系统！\n");
}
