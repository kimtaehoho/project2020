#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct pet{
	char name[50];
	char snack[50];
	int number;
	int date;
	struct pet* next;
}pet_t;

void open(pet_t* list_head);
pet_t* search(pet_t* list_head,char* name);
pet_t* add(pet_t* list_head,pet_t*(*func)(pet_t*,char*));
void search_pet(pet_t* list_head,pet_t*(*func)(pet_t*,char*));
void show_all(pet_t* list_head);
void delete(pet_t** list_head,pet_t*(*func)(pet_t*,char*));
void delete_all();
void save_all(pet_t* list_head);

void main()
{
	int key;
	pet_t* list_head=NULL;
	while(key!=7)
	{
		printf("==============================\n");
		printf("반려견 관리 프로그램\n");
		printf("1. 반려견 맡기기(이름,비밀번호,맡길 기간,좋아하는 간식 순서로)\n");
		printf("2. 자신의 반려견 검색\n");//자신의 반려견 검색
		printf("3. 반려견 이름 삭제 후 찾아가기\n");//반려견 이름 삭제
		printf("4. 모든 정보 출력\n");
		printf("5. 모든 정보 삭제\n");
		printf("6. 모든 정보 저장\n");
		printf("7. 실행 종료\n");
		printf("==============================\n");
		printf("번호를 선택하시오:");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				list_head = add(list_head, search);;
				break;
	
			case 2:
				search_pet(list_head,search);
				break;
			case 3:
				delete(&list_head,search);
				break;
			case 4:
				show_all(list_head);
				break;
			case 5:
				delete_all();
				break;
			case 6:
				save_all(list_head);
				break;
			default:
				printf("잘못된 입력입니다.\n");
				break;
		}
	if(key==7)
		printf("프로그램을 종료합니다.");
	}
}

pet_t* add(pet_t* list_head,pet_t*(*func)(pet_t*, char*))
{
	pet_t* tmp_node;
	pet_t* new_node;
	char pet_name[50];
	char pet_snack[50];
	int pet_number;
	int pet_date;
	
	printf("반려견 이름:");
	scanf("%s",pet_name);
	tmp_node=func(list_head,pet_name);

	if(tmp_node!=NULL)
	{
		printf("이미 이 반려견은 존재합니다.\n");
		return list_head;
	}
	else
	{	
		printf("비밀번호:");
		scanf("%d",&pet_number);
	
		printf("맡길 기간(예시:1,2,3...):");
		scanf("%d",&pet_date);

		printf("좋아하는 간식 입력:");
		scanf("%s",pet_snack);
	}
	
	new_node=(pet_t*)malloc(sizeof(pet_t));
	strcpy(new_node->name,pet_name);
	new_node->number=pet_number;
	new_node->date=pet_date;
	strcpy(new_node->snack,pet_snack);

	new_node->next=list_head;//new_node값을 다음줄로 이동시켜라.
	list_head=new_node;//new_node를 list_head값에 넣음.
	return list_head;
}


void open(pet_t* list_head)
{
	pet_t* new_node;
	FILE* fp=fopen("pet.txt","r+");
	if(fp==NULL)
	{
		printf("파일을 열지 못합니다.\n");
		return;		
	}
	while(1)
	{
		new_node=(pet_t*)malloc(sizeof(pet_t));
		if(feof(fp)!=0)
		{
			break;
		}
		fscanf(fp,"%s %d %d %s\n",new_node->name,&new_node->number,&new_node->date,new_node->snack);
		new_node->next=list_head;
		list_head=new_node;
	}
	fclose(fp);
	printf("파일을 불러옴.\n");
}


pet_t* search(pet_t* list_head,char* pet_name)
{
	pet_t* tmp=list_head;
	while(tmp)
	{
		if(!strcmp(tmp->name,pet_name))//한칸씩 이동하면서 name값을 찾음
		{
			return tmp;
		}
		tmp=tmp->next;
	}
	return tmp;
}


void search_pet(pet_t* list_head,pet_t*(*func)(pet_t*,char*))
{
	pet_t* tmp_node;
	char pet_name[50];//tmp_node 정보를 불러옴
	printf("찾아갈 반려견을 입력하시오:");
	scanf("%s",pet_name);

	tmp_node=func(list_head,pet_name);
	
	if(tmp_node==NULL)
		printf("입력한 반려견은 없는 반려견입니다.\n");
	else
	{
		printf("반려견 이름:%s\n",tmp_node->name);
		printf("비밀번호:%d\n",tmp_node->number);
		printf("맡긴 기간:%d\n",tmp_node->date);
		printf("좋아하는 간식:%s\n",tmp_node->snack);
	}
}

void delete(pet_t** list_head,pet_t*(func)(pet_t*,char*))
{
   pet_t* tmp_node;
   pet_t* prev=NULL;
   pet_t* seek=*list_head;

   char pet_name[50];

   printf("찾아갈 반려견 이름:");
   scanf("%s",pet_name);

   tmp_node=func(*list_head,pet_name);

   if(tmp_node==NULL)
   {
      printf("존재하지 않는 반려견입니다.\n");
      return;
   }
	if(strcmp((*list_head)->name,pet_name)==0)
	{
        tmp_node=*list_head;
        (*list_head)=(*list_head)->next;
        free(tmp_node);
		printf("반려견과 좋은시간 되세요~!\n");
		return;
    }
	else
    {
    	while(tmp_node==NULL)
    	{
        	if (strcmp(tmp_node->name,pet_name)==0)
        	{
            	prev->next=tmp_node->next;
            	free(tmp_node);
				printf("반려견과 좋은시간 되세요~!\n");
            	return;
        	}
        	prev=tmp_node;
        	tmp_node=tmp_node->next;
    	}
    }
}



void show_all(pet_t* list_head)
{
	pet_t* tmp_node=list_head;
	if(list_head=NULL)
	{
		printf("어떠한 정보도 없습니다.\n");
	}
	while(tmp_node!=NULL)
	{
		printf("반려견 이름:%s\n",tmp_node->name);
		printf("비밀번호:%d\n",tmp_node->number);
		printf("맡긴 기간:%d\n",tmp_node->date);
		printf("좋아하는 간식:%s\n",tmp_node->snack);
		tmp_node=tmp_node->next;
	}
}
		

void delete_all()
{
	pet_t* prev;
	pet_t* tmp_node;
	pet_t* new_node;
	pet_t* list_head;

	tmp_node=list_head;
	while(tmp_node!=NULL)
	{
		prev=tmp_node;
		tmp_node=tmp_node->next;
		free(prev);
	}
	new_node=NULL;
	tmp_node=NULL;
	list_head=NULL;
	prev=NULL;
	printf("모든 정보가 삭제되었습니다.\n");
}				


void save_all(pet_t* list_head)
{
	pet_t* tmp_node;
	FILE* fp=fopen("pet.txt","w+");
	if(fp==NULL)
	{
		printf("파일을 열지 못했습니다.\n");
		return;
	}
	while(list_head)
	{
		tmp_node=list_head;
		fprintf(fp,"%s %d %d %s\n",tmp_node->name,tmp_node->number,tmp_node->date,tmp_node->snack);
		list_head=list_head->next;
		free(tmp_node);
	}
	fclose(fp);
	printf("모든 정보가 저장되었습니다.\n");
}



















