#include <stdio.h>
#include <stdlib.h>

#define SIZE 55 							//55 students
#define K 100 								//desmeuw parapanw theseis se periptwsh lathwn


struct student{								//kataskevi tou struct me ta stoixeia
	char am[SIZE];
	char name[SIZE];
	char last_name[SIZE];
	char fathers_name[SIZE];
	char adress[SIZE];
	char phone_number[SIZE];
	char mobile_number[SIZE];
	int lesson;
};

typedef struct student RECORD;										//Orismos sinonimou sto struct, me onoma RECORD
RECORD students[K];													//dilosi pinaka typou struct student, wste na desmeysoyme 55 theseis

int N;																//arithmos foititwn pou epilegei o xristis
void read_record();													//Sinartiri pou diavazi apo to xristi ta stixia
int print_record();													//Sinartiri pou ektiponi ston xristi ta stixia


void main()
{
	int choice;


	while(1)
    {
		system("cls");

		
		printf("  \n\n");	
		printf("      ||  OPTIONS  ||  \n\n");
			
		printf("  [1] Student Registration\n");
		printf("  [2] Display Student\n");
		printf("  [3] Exit\n\n");

		do
		{
			printf("\n  >>  Make a choice: ");
        	scanf("%d", &choice);
        	if (choice<1 || choice>3){
        		printf("<< You must choose 1-3 >>\n");
			}
		}while (choice<1 || choice>3);

		switch(choice)
		{
			case 1:
				do
				{
					printf("\n  >> How many Student would you like to add?:");
					scanf("%d",&N);
					if (N<1 || N>55){
						printf("\n<< The total number of registrations must be been 55 >>\n");
						
					}
				}
				while(N<1 || N>55);
				read_record();
				break;
			case 2:
				print_record();
				break;
			case 3:
				exit(0);

			default:
				printf("\n  >> ...not a valid answer! The number of registrations is between 1-55\n");
				break;
		}
			system("pause");
	}
}
void read_record()
{
	int i;
	printf("\n  [Students Informations]:\n ");
	for(i=0;i<N;i++)
	{
	printf("\n[%d]Student\n",i+1);	
	printf("\n>> Give the AM: ");
	scanf("%s",students[i].am);

	printf("\n>> Give the Name: ");
	scanf("%s",students[i].name);

	printf("\n>> Give the Last Name: ");
	scanf("%s",students[i].last_name);

	printf("\n>> Give the Fathers Name: ");
	scanf("%s",students[i].fathers_name);

	printf("\n>> Give the Adress: ");
	scanf("%s",students[i].adress);

	printf("\n>> Give the Phone Number: ");
	scanf("%s",students[i].phone_number);

	printf("\n>> Give the Mobile Number: ");
	scanf("%s",students[i].mobile_number);

	do{ //for question 3c

		printf("\n  [0] Maths\n  [1] Python\n  [2] C Introduction \n  [3] Data Structures \n");
		printf("\n  Choose a Lesson: ");
		scanf("%d",&students[i].lesson);
	}
	while (students[i].lesson<0 || students[i].lesson>3);

	}

}

int print_record()
{

	int i;
	if (N==0){
		printf("\n|| No registration's yet ||\n");
	}
	for (i=0; i<N; i++)
	printf("\n  1.  AM: %s\n  2.  Name:  %s\n  3.  Last Name:  %s\n  4.  Father's Name:  %s\n  5.  Address:  %s\n  6.  Phone Number:  %s\n  7.  Mobile Number:  %s\n  8.  Lesson:  %d\n\n",students[i].am, students[i].name, students[i].last_name,students[i].fathers_name,students[i].adress,students[i].phone_number,students[i].mobile_number,students[i].lesson);
}

