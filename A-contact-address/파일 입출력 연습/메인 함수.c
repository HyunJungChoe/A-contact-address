#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>  //글씨색 넣기,창 전환



void main()
{
	int b=0;  //초기화
	char select = 0;  //초기화
	system("mode con cols=65 lines=50");
	//cols = 칸/행 (가로)  lines = 줄/열 (세로)  :: 창을 고정합니다.

	while (b != 3)
	{
		banner(); //배너 함수  로그인 회원가입 메뉴가 나온다.
		printf("	 메뉴를 선택하세요 : ");
		b = getche();
		getchar();
	
		switch (b)
		{
		case '1': _login();  //1. 로그인 함수
			
			break;
			

		case '2': User_Register_get();     //2. 등록 함수
			
			continue;

		case '3': return 0;   //3. 종료
			break;

		default: 
			printf(" \n 다시 입력해 주세요.  \n");
			system("pause");

		}

	}

}


