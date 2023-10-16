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
	//��myfilename����·����������ļ���ȡ���� 
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
		printf("    	  22. ListDelete    23. ListTrabverse���ڼ����� �߼�λ�� Ԫ�أ�\n");
		printf("    	  24. sortlist\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~24]:");
		scanf("%d",&x);
		
	switch(x){
	   	case 1://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	if(InitList(L) == OK) printf("�������ɹ���\n");
		 	else printf("������ʧ�ܣ�\n");
		 	
		 	getchar();getchar();
		 	break;
	   
	   	case 2://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	flag = DestroyList(L);
		 	if(flag == OK) printf("����ݻٳɹ���\n");
		 	else if(flag == INFEASIBLE) printf("����ݻ�ʧ�ܣ�\n");
		 	
		 	getchar();getchar();
		 	break;
	   	
		case 3://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			if(ClearList(L) == OK) printf("��������գ�\n");
			else printf("�������ڣ�\n");   
			getchar();getchar();
			break;
			
	   	case 4://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
	   		if(ListEmpty(L) == INFEASIBLE) printf("�������ڣ�\n");
			else if(ListEmpty(L) == TRUE) printf("����Ϊ�գ�\n");
			else if(ListEmpty(L) == FALSE) printf("����Ϊ�գ�\n");
		 	
			getchar();getchar();
		 	break;
		 	
	   	case 5://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	if(ListLength(L)==INFEASIBLE) printf("�������ڣ�\n");
			else printf("����ĳ���Ϊ%d��\n",ListLength(L));    
		 	getchar();getchar();
		 	break;
		 	
	   	case 6://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
	   		printf("�������ȡԪ�ص�λ��\n");
	   		scanf("%d",&i);
			if(GetElem(L,i,e)==INFEASIBLE) printf("�������ڣ�\n");
			else if(GetElem(L,i,e)==OK) printf("�ѳɹ�������e�У�Ԫ��Ϊ%d��\n",e);
			else if(GetElem(L,i,e)==ERROR) printf("��ȡλ�÷Ƿ���\n");
			
		 	getchar();getchar();
		 	break;
		 	
	   	case 7://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
	   		printf("���������Ԫ��\n");
	   		scanf("%d",&e); 
	   		if(LocateElem(L,e)==INFEASIBLE) printf("�������ڣ�\n");
			else if(LocateElem(L,e)==0) printf("Ԫ�ز��������У�\n");
			else printf("������Ԫ�ص�λ��Ϊ%d��\n",LocateElem(L,e));
		 	getchar();getchar();
		 	break;
		 	
	   	case 8://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
	   		printf("�������ȡǰ����Ԫ��\n");
	   		scanf("%d",&e);
		 	if(PriorElem(L,e,pre)==INFEASIBLE) printf("�������ڣ�\n");
			else if(PriorElem(L,e,pre)==OK) printf("ǰ���ѳɹ�������pre�У�ǰ��Ϊ%d��\n",pre);
			else if(PriorElem(L,e,pre)==ERROR) printf("ǰ�������ڣ�\n");  
		 	getchar();getchar();
		 	break;
	   	case 9://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	printf("�������ȡ��̵�Ԫ��\n");
	   		scanf("%d",&e);
		 	if(NextElem(L,e,next)==INFEASIBLE) printf("�������ڣ�\n");
			else if(NextElem(L,e,next)==OK) printf("����ѳɹ�������next�У����Ϊ%d��\n",next);
			else if(NextElem(L,e,next)==ERROR) printf("��̲����ڣ�\n");     
		 	getchar();getchar();
		 	break;
		 	
	   	case 10://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			printf("�������������λ�úͲ���Ԫ��\n");
	   		scanf("%d %d",&i,&e);
	   		flag=ListInsert(L,i,e);
		 	if(flag==INFEASIBLE) printf("�������ڣ�\n");
			else if(flag==OK) printf("Ԫ�ز���ɹ���\n");
			else if(flag==ERROR) printf("����λ�÷Ƿ���\n");     
		 	getchar();getchar();
		 	break;
		 	
	   	case 11://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	printf("������ɾ��λ��\n");
	   		scanf("%d",&i);
	    	flag=ListDelete(L,i,e);
		 	if(flag==INFEASIBLE) printf("�������ڣ�\n");
			else if(flag==OK) printf("Ԫ��ɾ���ɹ�����Ԫ��Ϊ%d��\n",e);
			else if(flag==ERROR) printf("ɾ��λ�÷Ƿ���\n");      
		 	getchar();getchar();
		 	break;
		 	
	   	case 12://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к�������      
		 	if(ListTraverse(L)==INFEASIBLE) printf("�������ڣ�\n");
			getchar();getchar();
		 	break;
		 	
		case 13://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			if(reverseList(L)==INFEASIBLE) printf("�����ǿձ�\n");
			else printf("����ת�ɹ�\n");
			getchar();getchar();
		 	break;
		 	
		case 14://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	printf("������ɾ������ĵ�����n�����\n");
			 scanf("%d",&n); 
			if(RemoveNthFromEnd(L,n)==INFEASIBLE) printf("�������ڣ�\n");
			else printf("Ԫ��ɾ���ɹ�\n");
			getchar();getchar();
		 	break;
		 	
		case 15://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			if(sortList(L)==INFEASIBLE) printf("�������ڣ�\n");
			else if(sortList(L)==OK) printf("��������С��������");
			getchar();getchar();
		 	break;
		 	
		case 16://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	flag=SaveList(L, myfilename);
			if(flag==INFEASIBLE) printf("�������ڣ�\n");
			else if(flag==OK) printf("�����Ѵ洢�ڲ����ļ��У�");
			getchar();getchar();
		 	break;
		 	
		case 17://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			flag=LoadList(L,myfilename);
			if(flag==INFEASIBLE) printf("�����Ѵ��ڣ�\n");
			else if(flag==OK) printf("�����ļ������Ѷ��������У�");
			getchar();getchar();
		 	break;
		 	
		case 18://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	printf("��������ӵ�������");
		 	scanf("%s",Name);
		 	flag=AddList(Lists,Name);
			if(flag==OK) printf("����%s�������Lists�У�\n",Name);
			getchar();getchar();
		 	break;
		 	
		case 19://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
		 	printf("������ɾ����������");
		 	scanf("%s",Name);
		 	flag=RemoveList(Lists,Name);
			if(flag==OK) printf("����%s��Lists��ɾ����\n",Name);
			else printf("ɾ��ʧ��"); 
			getchar();getchar();
			break;
		
		case 20://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			printf("����������");
		 	scanf("%s",Name);
		 	flag=LocateList(Lists,Name);
			if(flag) printf("����%s��Lists�е�λ����%d��\n",Name,flag);
			else printf("δ�ҵ���Ӧ����"); 
			getchar();getchar();
		 	break;
		 	
		case 21://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			printf("����������ѡ��ı���,����λ�úͲ���Ԫ��\n");
		   	scanf("%d %d %d",&num,&i,&e);
		   	flag=ListInsert(Lists.elem[num-1].L,i,e);
			if(flag==INFEASIBLE) printf("�������ڣ�\n");
			else if(flag==OK) printf("Ԫ�ز���ɹ���\n");
			else if(flag==ERROR) printf("����λ�÷Ƿ���\n");     
			getchar();getchar();
			break;
			
		case 22://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			printf("������ѡ��ı���,ɾ��λ��\n");
		   	scanf("%d %d",&num,&i);
		    flag=ListDelete(Lists.elem[num-1].L,i,e);
			if(flag==INFEASIBLE) printf("�������ڣ�\n");
			else if(flag==OK) printf("Ԫ��ɾ���ɹ�����Ԫ��Ϊ%d��\n",e);
			else if(flag==ERROR) printf("ɾ��λ�÷Ƿ���\n");      
			getchar();getchar();
			break;
	   	
		case 23://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			int i;
			if(!Lists.length)
			{
				printf("��������!\n");
			}
			for(i=0;i<Lists.length;i++)
			{
				printf("%s ",Lists.elem[i].name);
				ListTraverse(Lists.elem[i].L);
				printf("\n");
			}
			getchar();getchar();
			break; 
			
		case 24://����ͨ��flag==status�����в����ɹ�ʧ���жϣ��Է���ν��к������� 
			int j;
			for(i=0;i<Lists.length;i++)
		 	{
		 		sortList(Lists.elem[i].L);
		 	}
		 	printf("������ɹ�!");
			getchar();getchar();
			break;
		case 0:
         	break;
		}
  	}
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}
