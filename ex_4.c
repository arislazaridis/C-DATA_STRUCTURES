#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10	 						//megethos pinaka stoivas(statikos pinakas)
	
typedef int elem; 								//typos dedomenwn stoivas 

struct stack{
	elem array[STACK_SIZE];  					//pinakas stoixeiwn stoivas
	int top; 									//koryfi stoivas
}; 

typedef struct stack STACK; 					//synwnymo stoivas

//prwtotypa synartisewn

void ST_init(STACK *s);							//arxikopoihsh stoivas
int ST_empty(STACK s);							//elegxei an h stoiva einai adeia
int ST_full(STACK s);							//elegxei an h stoiva einai gemati
int ST_push(STACK *s,elem x);					//push element
int ST_pop(STACK *s,elem *x);					//pop element

main()
{
	int choice,elem,i;							//dilwsi metavlitwn
	STACK st;									//stigmiotypo tou struct STACK
	
	ST_init(&st);								//arxikopoihsh stoivas 
	
	while(1)
	{
		//dimiourgia menu xristi
		system("cls");
		printf("       [ MENU ]  \n\n");
		printf("  [1]  Push an Element\n");
		printf("  [2]  Pop an Element\n");
		printf("  [3]  Print The Stack\n");
		printf("  [4]  Exit\n\n");
		
		//Periorismos choice metaksy 1-4
		do
		{										 
			printf("\n  ~Stack:Enter choice: ");
			scanf("%d",&choice);
		} while (choice<1 || choice>4);
		
		//switch gia tis epiloges tou xristi
		switch(choice)
		{
			case 1:
				printf("\nPush an element: ");
				scanf("%d",&elem);												//diavazei to element pou edwse o xristis kai to  apothikeyei stin metavliti elem	
				if (ST_push(&st,elem))											//an to push einai True/False typwnei to antistoixo minima 
					printf("Push is Done!!");
				else
					printf("Push is not completed , the stack is Full!");
				break;
			case 2:
				if (ST_pop(&st,&elem))											
					printf("Pop element : %d is done !!!", elem);
				else
					printf("The stuck is empty ..Pop is failed!");
				break;
			case 3:
				printf("\n\nThe stack has %d elements: \n", st.top+1);			
				for (i=0; i<=st.top; i++)
				{
					printf("[%3d]\n",st.array[i]);								//print ta stoixeia tis stoivas
				}
				break;
			case 4:
				printf("Bye Bye!!");
				exit(0);
			default:
				printf("\n  ~Stack: pls try again and choose 1-4!!");
				
		}
		printf("\n\n");
		system("pause");
	}

	
}


// ST_init(): arxikopoiei ti lista 

void ST_init(STACK *s)
{
	s->top=-1;
}

/* ST_empty(): epistrefei TRUE/FALSE
   analoga me to an i stoiva einai adeia */
   
int ST_empty(STACK s)
{
	return s.top==-1;
}

/* ST_full(): epistrefei TRUE/FALSE
   analoga me to an i stoiva einai gemati */
int ST_full(STACK s)
{
	return s.top==STACK_SIZE-1;
}

/* ST_push(): Eisagei to x sti stoiva s
   epistrefei TRUE(1)  : se periptwsi epitixias
              FALSE(0) : se periptwsi apotixias */
int ST_push(STACK *s,elem x)
{
	if (ST_full(*s))
		return 0;
	else
	{
		s->top++;
		s->array[s->top]=x;
		return 1;
	}
}


/*  ST_pop(): Kanei eksagwgi poy einai stin korifi tis listas
	epistrefei TRUE(1)  : se periptwsi epitixias
 		       FALSE(0) : se periptwsi apotixias */
int ST_pop(STACK *s,elem *x)
{
	if (ST_empty(*s))
		return 0;
	else
	{
		*x=s->array[s->top];
		s->top--;
		return 1;
	}
}
