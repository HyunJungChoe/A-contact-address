#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>  //�۾��� �ֱ�,â ��ȯ



void main()
{
	int b=0;  //�ʱ�ȭ
	char select = 0;  //�ʱ�ȭ
	system("mode con cols=65 lines=50");
	//cols = ĭ/�� (����)  lines = ��/�� (����)  :: â�� �����մϴ�.

	while (b != 3)
	{
		banner(); //��� �Լ�  �α��� ȸ������ �޴��� ���´�.
		printf("	 �޴��� �����ϼ��� : ");
		b = getche();
		getchar();
	
		switch (b)
		{
		case '1': _login();  //1. �α��� �Լ�
			
			break;
			

		case '2': User_Register_get();     //2. ��� �Լ�
			
			continue;

		case '3': return 0;   //3. ����
			break;

		default: 
			printf(" \n �ٽ� �Է��� �ּ���.  \n");
			system("pause");

		}

	}

}


