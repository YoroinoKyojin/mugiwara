#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *newnode,*tail;
void createlist();
void display();
void insertatbegin();
void insertend();
void insertatpos();
void deleteatbeg();
void deleteatend();
void main()
{
	while(1)
	{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("The following options are available");
	printf("\n");
	printf("1.Create your list\n");
	printf("2.Display your list\n");
	printf("3.Insert at beginning\n");
	printf("4.Insert at end\n");
	printf("5.Insert anywhere\n");
	printf("6.Delete at begin\n");
	printf("7.Delete at end\n");
	printf("8.Delete anywhere\n");
	printf("9.Find length of linked list\n");
	printf("10.Reversal of linked list\n");
	printf("11.Exit");
	printf("\n");
	int f;
	int c=1;
	printf("Enter an option");
	scanf("%d",&f);
	printf("\n");
	switch(f)
	{
		case 1:
			createlist();
			break;
		case 2:
			display();
			break;
		case 3:
			insertatbegin();
			break;
		case 4:
			insertend();
			break;
		case 5:
			insertatpos();
			break;
		case 6:
			deleteatbeg();
			break;
		case 7:
			deleteatend();
			break;
		case 11:
			break;
		default:
			printf("Invalid input");	
	}
	if (f==11)
	{
		break;
	}
	}
}
void createlist()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	printf("\n");
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		tail->next=newnode;
	}
		tail=newnode;
}	

void display()
{
	if (head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		struct node *p=head;
		while(p!=NULL)
		{
			printf("%d",p->data);
			printf("\n");
			p=p->next;
		}
	}
}

void insertatbegin()
{
	if (head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		struct node *newvar;
		newvar=(struct node*)malloc(sizeof(struct node));
		printf("Enter new data : ");
		scanf("%d",&newvar->data);
		newvar->next=NULL;
		newvar->next=head;
		head=newvar;
	}
}

void insertend()
{
	if (head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		struct node *newvar1;
		newvar1=(struct node*)malloc(sizeof(struct node));
		printf("Enter new data : ");
		scanf("%d",&newvar1->data);
		newvar1->next=NULL;
		struct node *travel;
		travel=head;
		while(travel->next!=NULL)
		{
			travel=travel->next;
		}
		travel->next=newvar1;
	}
}

void insertatpos()
{
	if (head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		int i=1, pos;
		int c=0;
		struct node *count;
		count = head;
		while(count!=NULL)
		{
			c++;
			count=count->next;
		}
		printf("Enter the position : ");
		scanf("%d",&pos);
		if (pos<1 || pos>c)
		{
			printf("Invalid position");
		}
		else
		{
			struct node *traverse;
			struct node *temp;
			traverse=(struct node*)malloc(sizeof(struct node));
			traverse->next=NULL;
			printf("Enter the data : ");
			scanf("%d",&traverse);
			temp=head;
			while(i<pos-1)
			{
				temp=temp->next;
				i++;
			}
			traverse->next=temp->next;
			temp->next=traverse;
		}
	}
}

void deleteatbeg()
{
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		struct node *leon;
		leon=head;
		head=head->next;
		leon->next=NULL;
		free(leon);
	}
}

void deleteatend()
{
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		struct node *temp,*prevnode;
		temp=head;
		while(temp->next!=NULL)
		{
			prevnode=temp;
			temp=temp->next;
		}
		if(temp==head)
		{
			head=NULL;
		}
		else
		{
			prevnode->next=NULL;
		}
		free(temp);
	}
}
	

