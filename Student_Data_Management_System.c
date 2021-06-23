#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

void gotoxy();
void menu();
void add();
void modify();
void search();
void view();
void deleteData();

struct StudentRecord{
	char name[20];
	char rollNo[10];
	int phoneNo;
	char course[15];
	char emailAdd[30];
}std;

int main(){
	gotoxy(36, 8);
	printf("## STUDENT MANAGEMENT SYSTEM ##");
	gotoxy(36, 18);
	printf("Press any key to go to the menu.");
	getch();
	menu();
	return 0;
}

void menu(){
	system("cls");
	gotoxy(36, 10);
	printf("--SELECT THE OPTION YOU WANT TO BE PERFORMED--");
	gotoxy(8, 12);
	printf("1. Add record.");
	gotoxy(8, 13);
	printf("2. Modify a student's information'.");
	gotoxy(8, 14);
	printf("3. Search an information about a student.");
	gotoxy(8, 15);
	printf("4. View the data.");
	gotoxy(8, 16);
	printf("5. Delete a record.");
	gotoxy(8, 17);
	printf("6. Exit.");
	
	int option;
	gotoxy(8, 19);
	printf("Choose your option number: ");
	scanf("%d", &option);
	switch(option){
		case 1: add();
		break;
		case 2: modify(); 
		break;
		case 3: search();
		break;
		case 4: view();
		break;
		case 5: deleteData();
		break;
		default: gotoxy(8, 20);
		printf("You excited!!");
		break;
	}
}

void add(){
	system("cls");
	FILE *fp;
	fp= fopen("record.txt", "ab+");
	if(fp==NULL){
		gotoxy(36, 10);
		printf("Error opening the file!!");
		exit(1);
	}
	
	char another;
	 fflush(stdin);
	do{
	gotoxy(36, 10);
	printf("--ADD INFORMATION--");	
        gotoxy(8, 12);
		printf("Enter Name: ");
		gets(std.name);
		gotoxy(8, 13);
		printf("Enter Roll Number: ");
		gets(std.rollNo);
		gotoxy(8, 14);
		printf("Enter Phone Number: ");
		scanf("%d", &std.phoneNo);
		gotoxy(8, 15);
		fflush(stdin);
		printf("Enter Course: ");
		gets(std.course);
		gotoxy(8, 16);
		printf("Enter Email Address: ");
		gets(std.emailAdd);
		gotoxy(8, 17);
		
		fwrite(&std, sizeof(std), 1, fp);
		
		gotoxy(8, 19);
		printf("Do you want to add information of another student? 'y'or'n'");
		fflush(stdin);
		another= getch();
		system("cls"); 
	}while(another=='y');
	
	fclose(fp);
	
	if(another=='n'){
		menu();
	}
}

void modify(){
	system("cls");
	FILE *fp;
	char sName[20];
	
	gotoxy(36, 7);
	printf("--MODIFY INFORMATION--");	
	gotoxy(8, 9);
	
		printf("Enter Name Of The Student Whose Information Needs To Be Verified: ");
		fflush(stdin);
		gets(sName);
		fp= fopen("record.txt", "rb+");
	if(fp==NULL){
		gotoxy(36, 10);
		printf("Error opening the file!!");
		exit(1);
	}
	
    fflush(stdin);
	while(fread(&std, sizeof(std), 1, fp)==1){
		if(strcmp(sName, std.name)==0){
		gotoxy(8, 12);
		fflush(stdin);
		printf("Enter Name: ");
		gets(std.name);
		gotoxy(8, 13);
		printf("Enter Roll Number: ");
		gets(std.rollNo);
		gotoxy(8, 14);
		printf("Enter Phone Number: ");
		scanf("%d", &std.phoneNo);
		gotoxy(8, 15);
		fflush(stdin);
		printf("Enter Course: ");
		gets(std.course);
		gotoxy(8, 16);
		printf("Enter Email Address: ");
		gets(std.emailAdd);
		
		fseek(fp, -sizeof(std), SEEK_CUR);
		fwrite(&std, sizeof(std), 1, fp);	
		break;
		}
	}
	fclose(fp);
	gotoxy(8, 18);
	printf("Press any key to continue.");
	getch();
	menu();	
}

void search(){
	system("cls");
    FILE *fp;
	fp= fopen("record.txt", "rb");
	if(fp==NULL){
		gotoxy(36, 10);
		printf("Error opening the file!!");
		exit(1);
	}
	char sName[20];
	
	gotoxy(36, 10);
	printf("--SEARCH INFORMATION--");	
	gotoxy(8, 12);
	fflush(stdin);
		printf("Enter Name Of The Student Whose Information You Need To Know: ");
		gets(sName);
	system("cls");
	while(fread(&std, sizeof(std), 1, fp)==1){
		if(strcmp(sName, std.name)==0){
		gotoxy(8, 12);
		printf("Name: %s", std.name);
		gotoxy(8, 13);
		printf("Roll Number: %s", std.rollNo);
		gotoxy(8, 14);
		printf("Phone Number: %d", std.phoneNo);
		gotoxy(8, 15);
		printf("Course: %s", std.course);
		gotoxy(8, 16);
		printf("Email Address: %s", std.emailAdd);
		break;
		}
	}
	fclose(fp);
	gotoxy(8, 18);
	printf("Press any key to continue.");
	getch();
	menu();		
}

void view(){
	system("cls");
	int i=1;
	gotoxy(36, 10);
	printf("--VIEW INFORMATION--");
	gotoxy(8, 14);
	printf("S. NO.");
	gotoxy(18, 14);
	printf("NAME");
	gotoxy(32, 14);
	printf("ROLL NUMBER");
	gotoxy(50, 14);
	printf("PHONE NUMBER");
	gotoxy(74, 14);
	printf("COURSE");
	gotoxy(87, 14);
	printf("EMAIL ADDRESS");
	gotoxy(8, 15);	
	printf("----------------------------------------------------------------------------------------------------------------------");
	
	FILE *fp;
	fp= fopen("record.txt", "rb+");
	if(fp==NULL){
		gotoxy(36, 8);
		printf("Error opening the file!!");
		exit(1);
	}
	int j= 16;
	while(fread(&std, sizeof(std), 1, fp)==1){
		
	gotoxy(8, j);
	printf("%d", i);
	gotoxy(18, j);
	printf("%s", std.name);
	gotoxy(32, j);
	printf("%s", std.rollNo);
	gotoxy(50, j);
	printf("%d", std.phoneNo);
	gotoxy(74, j);
	printf("%s", std.course);
	gotoxy(87, j);
	printf("%s", std.emailAdd);
	i++;
	j++;
	}
	fclose(fp);
	gotoxy(8, j+3);
	printf("Press any key to continue.");
	getch();
	menu();
}

void deleteData(){
	system("cls");
	FILE *ft;
	FILE *fp;
	char sName[20];
	
	gotoxy(36, 10);
	printf("--DELETE INFORMATION--");
	gotoxy(12, 13);
	
	printf("Enter Name Of The Student Whose Information You Need To Delete: ");
	fflush(stdin);
	gets(sName);
	
	fp= fopen("record.txt", "rb+");
	if(fp==NULL){
		gotoxy(36, 10);
		printf("Error opening the file!!");
		exit(1);
	}
	
	ft= fopen("temp.txt", "wb+");
	if(ft==NULL){
		gotoxy(36, 14);
		printf("Error opening the file!!");
		exit(1);
	}
	while(fread(&std, sizeof(std), 1, fp)==1){
	if(strcmp(sName, std.name)!=0){
		fwrite(&std, sizeof(std), 1, ft);
	}	
	}
	fclose(fp);
	fclose(ft);
	remove("record.txt");
	rename("temp.txt", "record.txt");
	
	gotoxy(8, 16);
	printf("Press any key to continue.");
	getch();
	menu();
}

void gotoxy(int x, int y){
	COORD c;
	c.X= x;
	c.Y= y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
