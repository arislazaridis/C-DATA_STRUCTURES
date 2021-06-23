#include <stdio.h>
#include <stdlib.h>

//ylopoihsh stivas lifo me xrisi syndedemenis listas

typedef int elem ;					//typos dedomenwn stoivas

struct node{						//typos komvou listas
	elem data;						//data meros komvou
	struct node *next;				//deiktis next pou deixnei to epomeno stoixeio tis listas
};

typedef struct node LIST_NODE;		//synwnymo komvou listas
typedef struct node *LIST_PTR;		//synwnymo deikti komvou


int ST_init(LIST_PTR *head);		//arxikopoihsh listas
int ST_empty(LIST_PTR head);		//elegxos an einai adeia
void push(LIST_PTR *head,elem x); 	//eisagwgi stoixeiou
void display(LIST_PTR head);		//print ta elements
int ST_pop(LIST_PTR *head,elem *x);	//diagrafi stoixeiou	
void ST_count(LIST_PTR head);		//synolo stoixeiwn(counter)





main(){
	
	int elem,choice;
	LIST_PTR s;						//dilwsi listas
	
	ST_init(&s);					//arxikopoihsh listas
	while(1)
	{
		//dimiourgia menu
		system("cls");
		printf(" \n");
		printf(" | Data  Structure.  \n");
		printf(" | Excercise 5.  \n");
		printf(" | Stack - Linked List \n");
		printf("  \n\n");
			
		printf("      [  MENU  ]  \n\n");
		printf("  [1] Push an Element\n");
		printf("  [2] Pop an Element \n");
		printf("  [3] Print The Stack\n");
		printf("  [4] stack count    \n");
		printf("  [5] Exit           \n");
        do
		{
			printf("\n  Enter choice : ");
        	scanf("%d", &choice);
		}while (choice<1 || choice>5);
        	
        switch(choice) // switch gia tis epiloges toy xristi
		{
			case 1:
				printf("\n  Push an element: ");
				scanf("%d", &elem); 
				push(&s,elem);
				break;
			case 2:
				ST_pop(&s,elem);
				system("pause");			
				break;
			case 3:
				display(s);
				system("pause");
				break;
			case 4:
				ST_count(s);
				system("pause");
				break;
				
			case 5:
				exit(0);				
				
			default:
				printf("\n  pls try again and choose 1-4!!");
				break;
		}
		
	}
	system("pause");	
	
	
}

//arxikopoihsh stoivas
int ST_init(LIST_PTR *head) 				//deiktis se komvo -- by reference -- i allagi tha meinei
{
	return *head==NULL;
}

//elegxos an i stoiva einai keni
int ST_empty(LIST_PTR head)
{
	return head==NULL;					   //epistrefei true/false 1/0
	
}

//eisagwgi neou komvou
//desmeyw mnimi gia ton neo komvo
//vazw ton neo komvo na deixei ekei pou deixnei o head
//o head na deixnei sto newnode
void push(LIST_PTR *head,elem x)
{
	LIST_PTR newnode;
	newnode=(LIST_NODE *)malloc(sizeof(LIST_NODE));
	if (!newnode)
	{
		printf("adynamia desmeysis mnimis");
		return 0;
	}
	newnode->data=x;
	newnode->next=*head;
	*head=newnode;
	return 1;
	
}

//ektypwsi stoivas
//dexete ws orisma tin kefali tis listas kai typwnei to periexomeno twn komvwn
void display(LIST_PTR head)
{
	LIST_PTR current;
	current=head;
	if (current==NULL)
	{
		printf("No elements for display..The stack is empty!!!\n");
	}
	while(current!=NULL)
	{
		printf("[%d]\n",current->data);
		current=current->next;
    }
		
	
}

//diagrafi stoixeiou
//diagrafi ton komvo pou deixnei i kefali tis stoivas
int ST_pop(LIST_PTR *head,elem *x)   //epistrefw ayto pou diagrafike 
{
	LIST_PTR current;
	if (*head == NULL)
	{
		printf("\nThe stack is empty!!!\n");
		return 0;
	}
	else
	{
		current = *head;
		printf("Popped Element is : %d", current->data);
		*head=current->data;
		(*head)=(*head)->next;
		free(current);
		return 1;
		
	}
	
	
}

//Count elements 
void ST_count(LIST_PTR head)
{
	LIST_PTR current;
	int cnt; 
	
	current=head;
	cnt=0; 
	while (current!=NULL)
	{
		cnt++; 
		current=current->next;
	}
	printf("The elements in stack is %d\n",cnt);
	
	
}
