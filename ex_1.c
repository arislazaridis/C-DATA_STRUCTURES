#include<stdio.h>
#include <stdlib.h>					//vivliothikes gia tin rand
#include<time.h>   

#define SIZE 10 					// pinakes me deikti size 1..10

// dhmiourgia 4 synartisewn 
void retrieve();                 	// gemisma 2 pinakwn me tyxeous arithmous
void update();						// dhmiourgia pinaka c opou prosthetei ta stoixeia ton pinakwn a,b
void display_arrays_with_random_elements();
void display_sum();						

float a[SIZE],b[SIZE],c[SIZE];         // dhlosi pinakwn me stathero megethos SIZE kai typo stoixeiwn pragmatikous arithmous

int i;

void main()
{
 
int choice;    // dilosi metavlitis epilogis gia to menu
	

	// dhmiourgia MENU 
	while(1)
	{
		system("cls"); 		//katharizei to screen
	
		printf("      [  MENU  ]  \n\n");
		
			
		printf("  [1] Fill the arrays with random elements \n");
		printf("  [2] Print the arrays with random elements\n");	
		printf("  [3] Sum the elements of the arrays\n");
		printf("  [4] Print the sum of all the elements of the arrays \n");
		
		printf("  [5] Exit\n\n");
	
	// Periorismos sthn eisodo toy xristi prokeimenou na epileksei tis epiloges toy MENU
	do
	{
		printf(" Enter your choice: ");
		scanf("%d",&choice);
	}while (choice<1 || choice>5);
			
		
	
	switch(choice)                                         // switch gia tis epiloges toy xristi
		{
			case 1:
					retrieve();
					printf("\n[the arrays are successfully filled with random elements]\n");
					break;
			case 2:
					display_arrays_with_random_elements();
					break;
			case 3:
					update();
					printf("\n[The array A is successfully filled]\n");
					break;
					
			case 4:
					display_sum();
					break;
					
				
			case 5:
					printf("thank you, see you later!");
					exit(0);
					
			default:
					printf(" pls try again and choose 1-5!!"); 
		}
		
		printf("\n");
		system("pause");    // paramenei to terminal anoixto 
	}
	
	



}




//gemisma dyo pinakwn B kai C
void retrieve(){
 
 srand (time(NULL));                                // synartisi poy gemizei toys pinakes B, C apo 0 ews 100 (vasi tou xronou time(null)
 
 //symplirvsh pikana b me tyxaious arithmous
 
 for(i=0; i<SIZE; i++)
 {
	b[i]=rand()%100;                                  // me rand gemizei kathe stoixeio toy pinaka apo 0 ews 100
 }

 
  //symplirvsh pinaka c me tyxaious arithmous
 
 for(i=0; i<SIZE; i++)
 {
	c[i]=rand()%100;                                   //  // me rand gemizei kathe stoixeio toy pinaka apo 0 ews 100 (paragwgi arithmou apto 1-100)
 }
 
}

void update(){
 
 //prosthesi twn 2 pianakvn se enan pinaka A
 
 for(i=0; i<SIZE; i++)
 {
	a[i] = b[i] + c[i];
 }
 
}


void display_arrays_with_random_elements()
{
	
	//ektypwsi pinaka b
	printf("[ARRAY B]: \n");
	printf("[");
	for (i=0; i<SIZE-1; i++)
		printf("%.2f, ",b[i]);
	printf("%.2f]",b[SIZE-1]);
	
	//ektypvsh pinaka c 
	printf("\n\n[ARRAY C]: ");
	printf("\n[");
	for (i=0; i<SIZE-1; i++)
		printf("%.2f, ",c[i]);
	printf("%.2f]",c[SIZE-1]);
		
}


void display_sum()
{
				
 	printf("\n");
 	printf("\n4: Elements of the table A := B + C :\n\n");
 	
 	printf("[");
	for (i=0; i<SIZE-1; i++)
		printf("%.2f, ",a[i]);
	printf("%.2f]",a[SIZE-1]);
 	
}

