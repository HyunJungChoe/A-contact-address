#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>  //글씨색 넣기

void banner() 

{
	system("cls");
	int a=0;

	printf("\n");
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	printf("       ┌─────────────────────────────────────────────────┐ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("       │                                                 │ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("       │ m    m   mmm        mmmmm   mmmm   mmmm  m    m │ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("       │ #    #     #        #    # m\"  \"m m\"  \"m #  m\"  │ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("       │ #mmmm#     #        #mmmm\" #    # #    # #m#    │ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("       │ #    #     #        #    # #    # #    # #  #m  │ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	printf("       │ #    # \"mmm\"        #mmmm\"  #mm#   #mm#  #    \"m│ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("       │                                                 │ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("       │                                                 │ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("       └─────────────────────────────────────────────────┘ \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n");
	printf("\n");


	printf("	안녕하세요! 연락처를 관리하는 HJ BOOK 입니다. \n");
	printf("	원하시는 메뉴를 선택해 주세요 \n\n");
	printf("	1. 로그인 \n\n");
	printf("	2. 회원가입 \n\n");
	printf("	3. 종료 \n\n");

	
		


}

void print_menu()
{
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("\n\n\n");
	printf("              #    # ###### #    # #    # \n");
	printf("              ##  ## #      ##   # #    # \n");
	printf("              # ## # #####  # #  # #    # \n");
	printf("              #    # #      #  # # #    # \n");
	printf("              #    # #      #   ## #    # \n");
	printf("              #    # ###### #    #  #### \n\n\n\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf("		1. 연락처  등록 \n\n");
	printf("		2. 연락처  삭제 \n\n");
	printf("		3. 연락처  검색 \n\n");
	printf("		4. 연락처  보기 \n\n");
	printf("		5. 저장 및 끝내기\n\n");
	

	printf("	원하시는 메뉴를 선택하세요 : ");
	;


}
                               


