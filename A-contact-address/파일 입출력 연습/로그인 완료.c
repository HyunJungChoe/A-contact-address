#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>  //�۾��� �ֱ�,â ��ȯ


typedef struct UserInformation {
	char id[16];
	char password[16];

} UI;



#define MAX_USER_DATA  100

UI g_user_data[MAX_USER_DATA];

int user_suer_count;

void LoadUserData()  //�ҷ�����
{
	int index = 0;
	FILE *p_file = fopen("user.txt", "rb");   // ���� �б�
	if (p_file != NULL) {
		fread(&user_suer_count, sizeof(int), 1, p_file);
		for (index = 0; index < user_suer_count; index++) {
			fread(g_user_data + index, sizeof(UI), 1, p_file);
		}
		fclose(p_file);
	}
}

void SaveUserData()  //�����ϱ�
{
	int index = 0;
	FILE *p_file = fopen("user.txt", "wb");  //���� ����,  ȸ����  �ϳ��ۿ� ������ �ȵȤ���. wb�̱⶧����.. a�� �ϸ� ������ ����.
	if (p_file != NULL) {
		fwrite(&user_suer_count, sizeof(int), 1, p_file);
		for (index = 0; index < user_suer_count; index++) {
			fwrite(g_user_data + index, sizeof(UI), 1, p_file);
		}
		fclose(p_file);
	}
}

void GetPassword(char parm_password[])   //�н����� ��ȣȭ
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

void User_Register_get()  //ȸ�� ��� �Լ�

{

	
	system("cls");//��â ��ȯ
	
	int i; //���̵� for ���� ���� 
	

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

	printf("	ȸ�� ����Ͻ÷��� ���� ������ �Է��ϼž� �մϴ�.\n\n");


	printf("1.  ID�� �Է��� �ּ���: ");
	gets(g_user_data[user_suer_count].id);  //���̵� �ޱ� 

	for (i = 0; i < user_suer_count; i++)//���̵� �ߺ�üũ�� ����
	{
		if (strcmp(g_user_data[i].id, g_user_data[user_suer_count].id) == 0)         //�̹� ȸ�������� �Ǿ��� �ִ� ���¸� �ٽ� �Է�
		{
			printf("   �̹� ��ϵ� ID�Դϴ�!!\n");
			printf("   �ٽ� �Է����ּ���");
			system("pause");
			system("cls");
			User_Register_get();//ó������ ���ư���
		}
	}

	printf("\n");
	printf("2.  Password �Է��� �ּ���: ");
	gets(g_user_data[user_suer_count].password);   //��й�ȣ �ޱ�
	printf("\n");

	user_suer_count++;

	printf("ȸ���� �ǽŰ� ���ϵ帳�ϴ�.. \n\n");


	SaveUserData(); //���� 
	system("pause");


}

void _login()  //�α��� 
{
	system("cls");  //��â ��ȯ

	int index = 0, input = 0;
	char id[16], password[16], success_login = 0;

	//FILE *p_file = fopen("user.txt", "rb");
	
	LoadUserData();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);  //�� ����

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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //�� ����

	printf("		�α����� ���ּ��� \n\n");

	printf("\n\n");
	printf("\n\n		���̵� �Է� : ");
	gets(id);
	printf("\n\n		��й�ȣ�� �Է� : ");
	GetPassword(password);

	

		for (index = 0; index < user_suer_count; index++) 
		{
			if (!strcmp(g_user_data[index].id, id)) //���̵� �´ٸ� 
			{


				if (!strcmp(g_user_data[index].password, password))  //��й�ȣ�� �´ٸ� 
				{
					
					printf("\n\n	** ���������� �α��� �߽��ϴ�. ** \n\n");
					
					system("pause");

					mainjuso();
				}

				else
				{
					printf("\n\n	** ��ȣ�� Ʋ�Ƚ��ϴ�. ** \n\n");   //���̵�� �´µ� ��й�ȣ�� Ʋ���ٸ� 
					success_login = 1;
					system("pause");
					break;
					
				}
			
				
					
			}
			else
				printf("\n\n	** ���̵� �������� �ʽ��ϴ�. ** \n\n");
				system("pause");
				break;
			
		}
		

	
}
