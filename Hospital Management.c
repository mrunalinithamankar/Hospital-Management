//HEADER FILES
#include<stdio.h>//Use for standard I/O Operation
#include<windows.h>
#include<conio.h>//Use for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>

char ans=0;
int ok;
int b, valid=0;
//FUNCTION DECLERATION
void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
//void func_list();
//void Search_rec(void);
//void Edit_rec(void);
//void Dlt_rec(void);
//void ex_it(void);
//Defines gotoxy()
//void gotoxy(short x, short y) {
//COORD pos = {x, y};//sets co-ordinates in (x,y).
//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}

struct patient//list of global variable
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char Problem[20];
};

struct patient  p,temp_c;



void main()
{

    WelcomeScreen();//Use to call WelcomeScreen function
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function




}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void) //function for welcome screen
{

	printf("\n\n\n\n\n\n\n\t\t\t\t*****************--------*****************");
	printf("\n\t\t\t\t**\t\t WELCOME TO\t\t**");
	printf("\n\t\t\t\t*   NEWLIFE HOSPITAL MANAGEMENT SYSTEM   *");
	printf("\n\t\t\t\t*****************--------*****************");
	printf("\n\n\n\n\n Press any key to continue......\n");
	getch();//Use to holds screen for some seconds
	system("cls");

}
/* ************************************************* Title Screen ********************************************* */
void Title(void)
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t       NEWLIFE HOSPITAL         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
/* ************************************************* Main Menu ********************************************* */
void MainMenu(void)
{
	system("cls");
	int choose;
	Title();
	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);

	switch(choose)
	{

	case 1:
	Add_rec();//Add_rec function is called
    	break;
    /*case 2:
    	func_list();
    	break;
	case 3:
	Search_rec();//View_rec function is call
    	break;
	case 4:
		Edit_rec();//Edit_rec function is call
		break;
	case 5:
		Dlt_rec();//Dlt_rec function is call
		break;
	case 6:
		ex_it();//ex_it function is call
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}*/

}
/* ************************************************* Exit Screen ********************************************* */
void ex_it(void)//function to exit
{
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();

}
/* ************************************************* Login Screen ********************************************* */
void LoginScreen(void)//function for login screen
{
//list of variables
int e=0	;
char Username[15];
char Password[15];
char original_Username[25]="system";
char original_Password[15]="newlife$1";

do
{
	printf("\n\n\n\n\t\t\t\tEnter your Username and Password :)");
	printf("\n\n\n\t\t\t\t\tUSERNAME:");
	scanf("%s",&Username);

	printf("\n\n\t\t\t\t\tPASSWORD:");
	scanf("%s",&Password);

	if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
	{
		printf("\n\n\n\t\t\t\t\tLogin Successful...");
        getch();
		MainMenu();
		break;
	}
	else
	{
		printf("\n\t\t\tEither Username or Password is incorrect. Try Again!");
		e++;
		getch();
	}

}
while(e<=2);
	if(e>2)
	{
	printf("You have cross the limit. You cannot login. ");
	getch();
    ex_it();
	}

system("cls");
}



/* **************************************ADD RECORD*******************************************/

void Add_rec(void)
{
	system("cls");
	Title();// call Title function

	char ans;
	FILE*ek;//file pointer
	ek=fopen("Record2.dat","a");//open file in write mode
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");

	/* **************************First Name*********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>30)
	{
		printf("\n\t Invalid \t The name is too long");
		goto A;
	}
	else if(strlen(p.First_Name)<3)
    {
        printf("\n\t Invalid \t The name is too short");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.First_Name);b++)
		{
			if (isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contains invalid character.Enter again :");
			goto A;
		}
	}

	/* ********************************************** Last name ************************************************ */
	B:
	printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
	if(strlen(p.Last_Name)>30)
	{
		printf("\n\t Invalid \t The name is too long");
		goto B;
	}
	else if(strlen(p.Last_Name)<2)
    {
        printf("\n\t Invalid \t The name is too short");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Last_Name);b++)
		{
			if (isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contains invalid character. Enter again :");
			goto B;
		}
	}
/* ******************************************* Gender ************************************************************** */
	do
	{
	    printf("\n\t\t\tGender[F/M/O(Others)]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F'|| toupper(p.Gender)=='O')
		{
			ok =1;
		}
		else
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Invalid. Try again: ");
    	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */
    printf("\n\t\t\tAge:");
    scanf(" %d",&p.age);
/* **************************************** Address ******************************************************************* */
    do
    {
    C:
    printf("\n\t\t\tAddress: ");
    scanf("%s",p.Address);
    p.Address[0]=toupper(p.Address[0]);
    if(strlen(p.Address)>20||strlen(p.Address)<4)
	{
		printf("\n\t Invalid :( \t Try again:");
		goto C;
	}

}while(!valid);
/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",p.Contact_no);
    if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(p.Contact_no);b++)
		{
			if (!isalpha(p.Contact_no[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contains invalid characters.  Enter again :");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",p.Email);
    if (strlen(p.Email)>30||strlen(p.Email)<8)
    {
       printf("\n\t Invalid \t The max range for email is 30 and min range is 8 :)");
	}
}while(strlen(p.Email)>30||strlen(p.Email)<8);
/* ********************************************************* Problem *********************************************** */
    E:
    printf("\n\t\t\tProblem: ");
    scanf("%s",p.Problem);
    p.Problem[0]=toupper(p.Problem[0]);
    if(strlen(p.Problem)>30||strlen(p.Problem)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.Problem);b++)
		{
			if (isalpha(p.Problem[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Problem contain Invalid character :(  Enter again :)");
			goto E;
		}
	}
/* ********************************************** Prescribed Doctor **************************************** */
	F:
    printf("\n\t\t\tPrescribed Doctor:");
    scanf("%s",p.Doctor);
    p.Doctor[0]=toupper(p.Doctor[0]);
    if(strlen(p.Doctor)>30||strlen(p.Doctor)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(p.Doctor);b++)
		{
			if (isalpha(p.Doctor[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Doctor name contain Invalid character :(  Enter again :)");
			goto F;
		}
	}

    fprintf(ek," %s %s %c %d %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_rec();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you.");
    	getch();
    	MainMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
