#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pet{
	char name[50];//맡기고 찾을 반려견 이름
	char snack[50]//좋아하는 간식
	int number;//맡기고 찾을 비밀번호
	int date;//맡길 기간
}PET;
int main(void)
{
	SelectMenu();
	return 0;
}
int SelectMenu()
{
	int key =0;
	printf("반려견 관리 프로그램 0:종료\n");
	printf("1:반려견 맡기기\n2:맡길때 비밀번호\n3:반려견 맡길 기간\n4:반려견 찾기\n5:찾을때 비밀번호\n6:반려견이 좋아하는 간식 유무")
	scanf("%d",&key);
	return key;
}
