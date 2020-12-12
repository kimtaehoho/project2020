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


void main()
{
	int key;
	pet_t* list_head=NULL;
	while(key!=8)
	{
	printf("==============================\n");
	printf("반려견 관리 프로그램\n");
	printf("1. 반려견 맡기기(이름,비밀번호,맡길 기간,좋아하는 간식 순서로)\n");
	printf("2. 자신의 반려견 검색\n");//자신의 반려견 검색
	printf("3. 반려견 이름 변경\n");
	printf("4. 반려견 이름 삭제 후 찾아가기\n");//반려견 이름 삭제
	printf("5. 모든 정보 출력\n");
	printf("6. 모든 정보 삭제\n");
	printf("7. 모든 정보 저장\n");
	printf("8. 실행 종료\n");
	printf("==============================\n");
	printf("번호를 선택하시오:");
	scanf("%d",&key);
	switch(key)
	{
		case 1:
			add(list_head,search);
			break;
	
		case 2:
			search_pet(list_head,search);
			break;
	}
	}
}
/*
		case 3:
			change();
			break;
		case 4:
			delete();
			break;
		case 5:
			show_all();
			break;
		case 6:
			delete_all();
			break;
		case 7:
			save();
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
	}
	if(key==8)
		printf("프로그램을 종료합니다.");
*/
pet_t* add(pet_t* list_head,pet_t*(*func)(pet_t*, char*))
{
	pet_t* tmp_node;
	pet_t* new_node;
	char pet_name[50];
	char pet_snack[50];
	int pet_number;
	int pet_date;
	
	new_node=(pet_t*)malloc(sizeof(pet_t));
	
	printf("반려견 이름:");
	scanf("%s",pet_name);

	if(tmp_node=NULL)
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

	strcpy(new_node->name,pet_name);
	new_node->number=pet_number;
	new_node->date=pet_date;
	strcpy(new_node->snack,pet_snack);

	new_node->next=list_head;//new_node값을 다음줄로 이동시켜라.
	list_head=new_node;//new_node를 list_head값에 넣음.
	return list_head;
}

/*
void show();
{
	pet* tmp_node;
	char name[30];
	printf("찾고싶은 반려견:");
	scanf("%s",name);
	tmp_node=func(list_head,name);
	if(tmp_node)
	{
		printf("반려견 이름:%s\n",tmp_node->name);
		printf("비밀번호:%d\n",tmp_node->number);
		printf("맡긴 기간:%d\n",tmp_node->date);
		printf("좋아하는 간식:%s\n",tmp_node->snack);
		func
*/

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
	return;
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
		printf("비밀번호:%ls\n",&tmp_node->number);
		printf("맡긴 기간:%ls\n",&tmp_node->date);
		printf("좋아하는 간식:%s\n",tmp_node->snack);
	}
}

	































			