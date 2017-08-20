#include<stdio.h>
#include<stdlib.h>
void insert_beg();
void display();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();

struct node
{
	int data;
	struct node *next;
	struct node *pre;
};
struct node *start=NULL;
void main()
{
	int c=0,n;
	while(c==0)
		{
			c==1;
			printf("Choose from the following options :\n1.Insert at beggining\n2.Insert at last\n3.Insert at any position \n4.Delete from beggining\n5.Delete from last\n6.Delete from any position");
	        scanf("%d",&n);
            switch(n)
            {
            	case 1:
            		insert_beg();
            		break;
            	case 2:
            		insert_end();
            		break;
            	case 3:
            		insert_pos();
            		break;
            	case 4:
            		delete_beg();
            		break;
            	case 5:
            		delete_end();
            		break;
            	case 6:
            		delete_pos();
            		break;
            	case 7:
            		display();
            		break;


            }
            printf("\n\nPress 1 to exit and 0 for more.\n");
	        scanf("%d",&c);
		}
}		
void insert_beg()
{
	struct node *ne;
	ne=(struct node *)malloc(sizeof(struct node));
	printf("Enter the number to insert.....\n\n");
	scanf("%d",&ne->data);
	ne->next=NULL;
	ne->pre=NULL;
	if(start==NULL)
	{
		start=ne;
	}
	else
	{
		ne->next=start;
		start->pre=ne;
		start=ne;

	}
}
void display()
{
	struct node *head;
	head=start;
	if(start==NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		while(head!=NULL)
		{
			printf("%d\t",head->data);
			head=head->next;
		}
		
}
}
void insert_end()
{
	struct node *ne;
	ne=(struct node *)malloc(sizeof(struct node));
	printf("Enter the number to be inserted...\n\n");
	scanf("%d",&ne->data);
	ne->pre=NULL;
	ne->next=NULL;
	if(start==NULL)
	{
		start=ne;
	}
	else
	{
		struct node *head;
		head=start;
		while(head->next!=NULL)
		{
			head=head->next;
		}
		ne->pre=head->next;
		head->next=ne;

	}

}
void insert_pos()
{
	int i=0,x;
	struct node *ne;
	struct node *head;
	struct node *temp;
    head=start;
	ne=(struct node *)malloc(sizeof(struct node));
	printf("Enter the number to be inserted...\n");
	scanf("%d",&ne->data);
	ne->next=NULL;
	ne->pre=NULL;
	if(start==NULL)
	{
		start=ne;
	}
	else
	{
		
		printf("Enter the position...\n\n");
		scanf("%d",&x);
		x--;
		while(i<x-1)
		{
			i++;
			head=head->next;
		}
		temp=head;
		temp=temp->next;
		 ne->next=head->next;
		 ne->pre=head;
		 head->next=ne;
         temp->pre=ne;
	}
}
void delete_beg()
{
	if(start==NULL)
	{
		printf("The list is empty");

	}
	else
	{
		start=start->next;
		start->pre=NULL;
	}
}
void delete_end()
{
	struct node *head;
	head=start;
	if(start==NULL)
	{
		printf("The list is empty..\n");
	}
	else
	{
		while(head->next->next!=NULL)
		{
			head=head->next;
		}
		head->next=NULL;
	}
}
void delete_pos()
{
	int i=0,x;
	struct node *head,*temp;
	head=start;
	if(start==NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		printf("Enter the position from where you want to delete...\n");
		scanf("%d",&x);
		x--;
		while(i<x-1)
		{
			i++;
			head=head->next;
		}
		temp=head->next;
		temp->pre=head->next;
		head->next=head->next->next;

	}
}