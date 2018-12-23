#include<stdio.h>
#include<string.h>
#include<windows.h>  //글씨색 넣기,창 전환


/*
도움 준 사람 : 성서학과 강성원 , 컴소 김정현
*/

#define MAX_NUM 100



//연락처를 저장하는 구조체
typedef struct {
	char name[30];
	char number[30];
	char group[30];
}User;


//함수 선언
int saveFile(User* ptr, int* num);
int openFile(User* ptr, int* num);
void insert(User* ptr, int* num);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void printAll(User* ptr, int* num);


//로그인 성공시 이동하는 메인 주소록
int mainjuso(void) 
{
	system("cls"); //창 전환

	int input;
	User user[MAX_NUM]; //연락처를  저장할 구조체 배열
	int person = 0; //저장된 user수



	openFile(user, &person);//저장된 연락처를 불러오는 함수



							//메뉴 선택
	while (1) {
		
		print_menu();

		scanf("%d", &input);



		if (input == 1) {
			printf("\n	*** 연락처 추가 ***   \n");
			insert(user, &person);
		}
		else if (input == 2) {
			printf("\n	*** 연락처  삭제 *** \n");
			deleted(user, &person);
		}
		else if (input == 3) {
			printf("\n	 *** 연락처  검색 *** \n");
			search(user, &person);
		}
		else if (input == 4) {
			printf("\n	*** 연락처  보기 ***  \n");
			printAll(user, &person);
		}
		else if (input == 5) {
			saveFile(user, &person);
			return 0;
		}
		else
			printf("	잘못 입력 하셨습니다 ! ");
		system("pause");
	}

	return 0;

}



//연락처를 파일에 저장하는 함수
int saveFile(User* ptr, int* num) {

	if (*num > 0) {
		int i, state;
		FILE* fp = fopen("UserInfo.txt", "wt");



		
		if (fp == NULL) {  //오류 발생시 예외 처리 합니다. 
			
			return 1;
		}



		//구조체 배열에 저장된 연락처를 파일에 저장
	
		for (i = 0; i < *num; i++) {
			fprintf(fp, "%s %s %s", ptr[i].name, ptr[i].number, ptr[i].group);
			fputc('\n', fp);
		}



		/* fclose함수는 종료시 오류가 발생하면
		0이 아닌 다른값을 리턴하므로 비정상 종료로 판단되면
		안내후 프로그램을 종료 */ 
		state = fclose(fp);
		if (state != 0) {
			printf("File Close Error!\n");
			return 1;
		}
		printf("\n  저장 완료 \n");
		system("pause");
		return 0;
	}

	else {
		printf("\n  Exit \n");
		system("pause");
		return 0;
	}
}



//파일로부터 연락처를 불러오는 함수
int openFile(User* ptr, int* num) {
	int state;
	char temp;
	FILE* fp = fopen("UserInfo.txt", "rt");



	if (fp == NULL) {
		printf("File Open Error!\n");
		return 1;
	}



	//파일에 저장된 연락처를 구조체 배열에 저장
	while (1) {
		fscanf(fp, "%s %s %s", ptr[*num].name, ptr[*num].number, ptr[*num].group);
		if (feof(fp) != 0)
			break;
		(*num)++;
	}



	/* fclose함수는 종료시 오류가 발생하면
	0이 아닌 다른값을 리턴하므로 비정상 종료로 판단되면
	안내후 프로그램을 종료 */
	state = fclose(fp);
	if (state != 0) {
		printf("File Close Error!\n");
		return 1;
	}

	return 0;
}



//연락처를  삽입하는 함수
void insert(User* ptr, int* num) {

	//유저정보가 꽉 차지 않으면
	if (*num < MAX_NUM) {
		printf("	이름을 입력 : ");
		scanf("%s", ptr[*num].name);
		printf("	번호를 입력 : ");
		scanf("%s", ptr[*num].number);
		printf("	그룹을 입력 : ");
		scanf("%s", ptr[*num].group);
		


		(*num)++;
		printf("	** 저장 완료 ** \n\n");
		system("pause");
	}
	//연락처가 꽉 차면
	else
		printf("	** 더이상 저장 공간이 없습니다.** \n\n");
		system("pause");
}



//연락처를  삭제하는 함수
int deleted(User* ptr, int* num) {
	char name[30];
	int i, j;



	//정보가 한개라도 남아있으면
	if (*num > 0) {
		printf("	이름을 입력: ");
		scanf("%s", name);



		for (i = 0; i < MAX_NUM; i++) {
			//문자열이므로 비교하기위해 strcmp사용
			if (strcmp(name, ptr[i].name) == 0) {

				(*num)--;
				printf("	** 삭제 완료 ** \n\n");
				system("pause");

				//데이터가 가득 차지 않았다면
				if (i != MAX_NUM - 1) {
					for (j = i; j < MAX_NUM; j++) {
						//문자열이므로 strcpy를 사용하여 데이터 복사
						strcpy(ptr[j].name, ptr[j + 1].name);
						strcpy(ptr[j].number, ptr[j + 1].number);
						strcpy(ptr[j].group, ptr[j + 1].group);
					}
					//구조체 배열의 마지막을 NULL로 바꿈
					*ptr[MAX_NUM - 1].name = NULL;
					*ptr[MAX_NUM - 1].number = NULL;
					*ptr[MAX_NUM - 1].group = NULL;
				}
				

				//데이터가 가득 찼다면
				else {
					//구조체 배열의 마지막을 NULL로 바꿈
					*ptr[MAX_NUM - 1].name = NULL;
					*ptr[MAX_NUM - 1].number = NULL;
					*ptr[MAX_NUM - 1].group = NULL;
				}
				return 0;
			}
		}
		printf("	** 연락처를 찾지 못했습니다. ** \n\n");
		system("pause");
		return 0;
	}


	//저장된  정보가 없다면
	else {
		printf("	** 연락처가 없습니다. ** \n\n");
		system("pause");
		return 0;
	}
}



//연락처를  검색하는 함수
int search(User* ptr, int* num)
{
	char name[30];	//검색할 이름
	char group[30];	//검색할 그룹
	int i, select;
	


	//저장된 정보가 있다면
	if (*num > 0)
	{

		printf("	이름 으로 검색 --> 1 \n");
		printf("	그룹 으로 검색 --> 2 \n");
		scanf("%d", &select);

		//이름으로 검색
		if (select == 1)
		{
			printf("	검색할 이름을 입력하세요 : ");
			scanf("%s", name);
			printf("\n\n");
			for (i = 0; i < *num; i++)//저장된 연락처 만큼 반복 
			{
				if (strcmp(name, ptr[i].name) == 0)//strcmp는 동일할 때 0(거짓)출력, 연락처 정보와 받은 이름과 같은것이 있다면 출력합니다.
				{
				 

					printf("	=================\n");
					printf("	이름 : %s\n", ptr[i].name);
					printf("	번호 : %s\n", ptr[i].number);
					printf("	그룹 : %s\n", ptr[i].group);

				}
				

			}
			
			printf("\n\n\n");

			

		}
		//그룹으로 검색
		else if (select == 2)
		{
			printf("	검색할 그룹을 입력하세요 : ");
			scanf("%s", group);
			printf("\n\n");
			for (i = 0; i < *num; i++)//저장된 연락처 수만큼 반복 
			{
				if (strcmp(group, ptr[i].group) == 0)//strcmp는 동일할 때 0(거짓)출력, 연락처 정보와 받은 그룹과 같은것이 있다면 출력합니다.
				{
				 

					printf("	=================\n");
					printf("	이름 : %s\n", ptr[i].name);
					printf("	번호 : %s\n", ptr[i].number);
					printf("	그룹 : %s\n", ptr[i].group);

				}

				
			}
			
			printf("\n\n\n");

			
		}
		else
		printf("	** 잘못 입력하셨습니다..1 또는 2를 입력해 주세요 **  \n\n");
		
		return 0;
		system("pause");
	}
	else 
	{
		printf("	** 정보가 없습니다. ** \n\n");
		return 0;
		system("pause");
	}
	
	
}




//저장된 모든 이름과 전화번호 정보를 출력하는 함수
void printAll(User* ptr, int* num) 
{
	int i = 0;

	if (*num > 0) 
	{
		for (i = 0; i < *num; i++)
		{
			printf("	=================\n");
			printf("	이름 : %s\n", ptr[i].name);
			printf("	번호 : %s\n", ptr[i].number);
			printf("	그룹  : %s\n", ptr[i].group);
			
		}
		
	}
	else
		printf("	** 정보가 없습니다. **  \n\n");
	system("pause");
}



