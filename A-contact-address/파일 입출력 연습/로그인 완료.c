#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>  //글씨색 넣기,창 전환


typedef struct UserInformation {
	char id[16];
	char password[16];

} UI;



#define MAX_USER_DATA  100

UI g_user_data[MAX_USER_DATA];

int user_suer_count;

void LoadUserData()  //불러오기
{
	int index = 0;
	FILE *p_file = fopen("user.txt", "rb");   // 파일 읽기
	if (p_file != NULL) {
		fread(&user_suer_count, sizeof(int), 1, p_file);
		for (index = 0; index < user_suer_count; index++) {
			fread(g_user_data + index, sizeof(UI), 1, p_file);
		}
		fclose(p_file);
	}
}

void SaveUserData()  //저장하기
{
	int index = 0;
	FILE *p_file = fopen("user.txt", "wb");  //파일 쓰기,  회원은  하나밖에 저장이 안된ㄷ다. wb이기때문에.. a로 하면 오류가 난다.
	if (p_file != NULL) {
		fwrite(&user_suer_count, sizeof(int), 1, p_file);
		for (index = 0; index < user_suer_count; index++) {
			fwrite(g_user_data + index, sizeof(UI), 1, p_file);
		}
		fclose(p_file);
	}
}

void GetPassword(char parm_password[])   //패스워드 암호화
{
	int input = 0, index = 0;
	while (input != 13) {
		input = getch();
		if (input == 13) parm_password[index] = 0;
		else {
			printf("*");
			parm_password[index++] = input;
		}
	}
	printf("\n");
}

void User_Register_get()  //회원 등록 함수

{

	
	system("cls");//새창 전환
	
	int i; //아이디 for 문을 위해 
	

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("	,-.                .            \n");
	printf("	|  )         o     |            \n");
	printf("	|-<  ,-. ,-: . ,-. |-  ,-. ;-.  \n");
	printf("	|  \\ |-' | | | `-. |   |-' |    \n");
	printf("	'  ' `-' `-| ' `-' `-' `-' '    \n");
	printf("	         `-'                    \n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf("	회원 등록하시려면 다음 정보를 입력하셔야 합니다.\n\n");


	printf("1.  ID를 입력해 주세요: ");
	gets(g_user_data[user_suer_count].id);  //아이디 받기 

	for (i = 0; i < user_suer_count; i++)//아이디 중복체크를 위해
	{
		if (strcmp(g_user_data[i].id, g_user_data[user_suer_count].id) == 0)         //이미 회원가입이 되어져 있는 상태면 다시 입력
		{
			printf("   이미 등록된 ID입니다!!\n");
			printf("   다시 입력해주세요");
			system("pause");
			system("cls");
			User_Register_get();//처음으로 돌아가기
		}
	}

	printf("\n");
	printf("2.  Password 입력해 주세요: ");
	gets(g_user_data[user_suer_count].password);   //비밀번호 받기
	printf("\n");

	user_suer_count++;

	printf("회원이 되신걸 축하드립니다.. \n\n");


	SaveUserData(); //저장 
	system("pause");


}

void _login()  //로그인 
{
	system("cls");  //새창 전환

	int index = 0, input = 0;
	char id[16], password[16], success_login = 0;

	//FILE *p_file = fopen("user.txt", "rb");
	
	LoadUserData();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);  //색 변경

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");

	printf("		,                              \n");
	printf("	|            o                 \n");
	printf("	|    ,-. ,-: . ;-.             \n");
	printf("	|    | | | | | | |             \n");
	printf("	`--' `-' `-| ' ' '             \n");
	printf("	        `-'          \n");
	printf("\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //색 변경

	printf("		로그인을 해주세요 \n\n");

	printf("\n\n");
	printf("\n\n		아이디를 입력 : ");
	gets(id);
	printf("\n\n		비밀번호를 입력 : ");
	GetPassword(password);

	

		for (index = 0; index < user_suer_count; index++) 
		{
			if (!strcmp(g_user_data[index].id, id)) //아이디가 맞다면 
			{


				if (!strcmp(g_user_data[index].password, password))  //비밀번호가 맞다면 
				{
					
					printf("\n\n	** 성공적으로 로그인 했습니다. ** \n\n");
					
					system("pause");

					mainjuso();
				}

				else
				{
					printf("\n\n	** 암호가 틀렸습니다. ** \n\n");   //아이디는 맞는데 비밀번호가 틀리다면 
					success_login = 1;
					system("pause");
					break;
					
				}
			
				
					
			}
			else
				printf("\n\n	** 아이디가 존재하지 않습니다. ** \n\n");
				system("pause");
				break;
			
		}
		

	
}
