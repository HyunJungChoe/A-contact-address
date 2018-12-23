#include<stdio.h>
#include<string.h>
#include<windows.h>  //�۾��� �ֱ�,â ��ȯ


/*
���� �� ��� : �����а� ������ , �ļ� ������
*/

#define MAX_NUM 100



//����ó�� �����ϴ� ����ü
typedef struct {
	char name[30];
	char number[30];
	char group[30];
}User;


//�Լ� ����
int saveFile(User* ptr, int* num);
int openFile(User* ptr, int* num);
void insert(User* ptr, int* num);
int deleted(User* ptr, int* num);
int search(User* ptr, int* num);
void printAll(User* ptr, int* num);


//�α��� ������ �̵��ϴ� ���� �ּҷ�
int mainjuso(void) 
{
	system("cls"); //â ��ȯ

	int input;
	User user[MAX_NUM]; //����ó��  ������ ����ü �迭
	int person = 0; //����� user��



	openFile(user, &person);//����� ����ó�� �ҷ����� �Լ�



							//�޴� ����
	while (1) {
		
		print_menu();

		scanf("%d", &input);



		if (input == 1) {
			printf("\n	*** ����ó �߰� ***   \n");
			insert(user, &person);
		}
		else if (input == 2) {
			printf("\n	*** ����ó  ���� *** \n");
			deleted(user, &person);
		}
		else if (input == 3) {
			printf("\n	 *** ����ó  �˻� *** \n");
			search(user, &person);
		}
		else if (input == 4) {
			printf("\n	*** ����ó  ���� ***  \n");
			printAll(user, &person);
		}
		else if (input == 5) {
			saveFile(user, &person);
			return 0;
		}
		else
			printf("	�߸� �Է� �ϼ̽��ϴ� ! ");
		system("pause");
	}

	return 0;

}



//����ó�� ���Ͽ� �����ϴ� �Լ�
int saveFile(User* ptr, int* num) {

	if (*num > 0) {
		int i, state;
		FILE* fp = fopen("UserInfo.txt", "wt");



		
		if (fp == NULL) {  //���� �߻��� ���� ó�� �մϴ�. 
			
			return 1;
		}



		//����ü �迭�� ����� ����ó�� ���Ͽ� ����
	
		for (i = 0; i < *num; i++) {
			fprintf(fp, "%s %s %s", ptr[i].name, ptr[i].number, ptr[i].group);
			fputc('\n', fp);
		}



		/* fclose�Լ��� ����� ������ �߻��ϸ�
		0�� �ƴ� �ٸ����� �����ϹǷ� ������ ����� �ǴܵǸ�
		�ȳ��� ���α׷��� ���� */ 
		state = fclose(fp);
		if (state != 0) {
			printf("File Close Error!\n");
			return 1;
		}
		printf("\n  ���� �Ϸ� \n");
		system("pause");
		return 0;
	}

	else {
		printf("\n  Exit \n");
		system("pause");
		return 0;
	}
}



//���Ϸκ��� ����ó�� �ҷ����� �Լ�
int openFile(User* ptr, int* num) {
	int state;
	char temp;
	FILE* fp = fopen("UserInfo.txt", "rt");



	if (fp == NULL) {
		printf("File Open Error!\n");
		return 1;
	}



	//���Ͽ� ����� ����ó�� ����ü �迭�� ����
	while (1) {
		fscanf(fp, "%s %s %s", ptr[*num].name, ptr[*num].number, ptr[*num].group);
		if (feof(fp) != 0)
			break;
		(*num)++;
	}



	/* fclose�Լ��� ����� ������ �߻��ϸ�
	0�� �ƴ� �ٸ����� �����ϹǷ� ������ ����� �ǴܵǸ�
	�ȳ��� ���α׷��� ���� */
	state = fclose(fp);
	if (state != 0) {
		printf("File Close Error!\n");
		return 1;
	}

	return 0;
}



//����ó��  �����ϴ� �Լ�
void insert(User* ptr, int* num) {

	//���������� �� ���� ������
	if (*num < MAX_NUM) {
		printf("	�̸��� �Է� : ");
		scanf("%s", ptr[*num].name);
		printf("	��ȣ�� �Է� : ");
		scanf("%s", ptr[*num].number);
		printf("	�׷��� �Է� : ");
		scanf("%s", ptr[*num].group);
		


		(*num)++;
		printf("	** ���� �Ϸ� ** \n\n");
		system("pause");
	}
	//����ó�� �� ����
	else
		printf("	** ���̻� ���� ������ �����ϴ�.** \n\n");
		system("pause");
}



//����ó��  �����ϴ� �Լ�
int deleted(User* ptr, int* num) {
	char name[30];
	int i, j;



	//������ �Ѱ��� ����������
	if (*num > 0) {
		printf("	�̸��� �Է�: ");
		scanf("%s", name);



		for (i = 0; i < MAX_NUM; i++) {
			//���ڿ��̹Ƿ� ���ϱ����� strcmp���
			if (strcmp(name, ptr[i].name) == 0) {

				(*num)--;
				printf("	** ���� �Ϸ� ** \n\n");
				system("pause");

				//�����Ͱ� ���� ���� �ʾҴٸ�
				if (i != MAX_NUM - 1) {
					for (j = i; j < MAX_NUM; j++) {
						//���ڿ��̹Ƿ� strcpy�� ����Ͽ� ������ ����
						strcpy(ptr[j].name, ptr[j + 1].name);
						strcpy(ptr[j].number, ptr[j + 1].number);
						strcpy(ptr[j].group, ptr[j + 1].group);
					}
					//����ü �迭�� �������� NULL�� �ٲ�
					*ptr[MAX_NUM - 1].name = NULL;
					*ptr[MAX_NUM - 1].number = NULL;
					*ptr[MAX_NUM - 1].group = NULL;
				}
				

				//�����Ͱ� ���� á�ٸ�
				else {
					//����ü �迭�� �������� NULL�� �ٲ�
					*ptr[MAX_NUM - 1].name = NULL;
					*ptr[MAX_NUM - 1].number = NULL;
					*ptr[MAX_NUM - 1].group = NULL;
				}
				return 0;
			}
		}
		printf("	** ����ó�� ã�� ���߽��ϴ�. ** \n\n");
		system("pause");
		return 0;
	}


	//�����  ������ ���ٸ�
	else {
		printf("	** ����ó�� �����ϴ�. ** \n\n");
		system("pause");
		return 0;
	}
}



//����ó��  �˻��ϴ� �Լ�
int search(User* ptr, int* num)
{
	char name[30];	//�˻��� �̸�
	char group[30];	//�˻��� �׷�
	int i, select;
	


	//����� ������ �ִٸ�
	if (*num > 0)
	{

		printf("	�̸� ���� �˻� --> 1 \n");
		printf("	�׷� ���� �˻� --> 2 \n");
		scanf("%d", &select);

		//�̸����� �˻�
		if (select == 1)
		{
			printf("	�˻��� �̸��� �Է��ϼ��� : ");
			scanf("%s", name);
			printf("\n\n");
			for (i = 0; i < *num; i++)//����� ����ó ��ŭ �ݺ� 
			{
				if (strcmp(name, ptr[i].name) == 0)//strcmp�� ������ �� 0(����)���, ����ó ������ ���� �̸��� �������� �ִٸ� ����մϴ�.
				{
				 

					printf("	=================\n");
					printf("	�̸� : %s\n", ptr[i].name);
					printf("	��ȣ : %s\n", ptr[i].number);
					printf("	�׷� : %s\n", ptr[i].group);

				}
				

			}
			
			printf("\n\n\n");

			

		}
		//�׷����� �˻�
		else if (select == 2)
		{
			printf("	�˻��� �׷��� �Է��ϼ��� : ");
			scanf("%s", group);
			printf("\n\n");
			for (i = 0; i < *num; i++)//����� ����ó ����ŭ �ݺ� 
			{
				if (strcmp(group, ptr[i].group) == 0)//strcmp�� ������ �� 0(����)���, ����ó ������ ���� �׷�� �������� �ִٸ� ����մϴ�.
				{
				 

					printf("	=================\n");
					printf("	�̸� : %s\n", ptr[i].name);
					printf("	��ȣ : %s\n", ptr[i].number);
					printf("	�׷� : %s\n", ptr[i].group);

				}

				
			}
			
			printf("\n\n\n");

			
		}
		else
		printf("	** �߸� �Է��ϼ̽��ϴ�..1 �Ǵ� 2�� �Է��� �ּ��� **  \n\n");
		
		return 0;
		system("pause");
	}
	else 
	{
		printf("	** ������ �����ϴ�. ** \n\n");
		return 0;
		system("pause");
	}
	
	
}




//����� ��� �̸��� ��ȭ��ȣ ������ ����ϴ� �Լ�
void printAll(User* ptr, int* num) 
{
	int i = 0;

	if (*num > 0) 
	{
		for (i = 0; i < *num; i++)
		{
			printf("	=================\n");
			printf("	�̸� : %s\n", ptr[i].name);
			printf("	��ȣ : %s\n", ptr[i].number);
			printf("	�׷�  : %s\n", ptr[i].group);
			
		}
		
	}
	else
		printf("	** ������ �����ϴ�. **  \n\n");
	system("pause");
}



