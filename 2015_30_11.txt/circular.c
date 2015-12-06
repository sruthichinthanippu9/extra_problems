#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL, *tail = NULL, *temp = NULL, *temp1 = NULL;
void create();
void insert(int);
void print();
int f = 0, size = 0;
void main()
{
	int n;
    create();
	printf("enter  the position where u wanted to insert the node");
	scanf("%d", &n);
	insert(n);
	print();
}
void print()
{
	temp = head;
	if (temp == NULL)
		printf("empty list ");
	else
	{
		while (temp != tail)
		{
			printf("%d   ", temp->data);
			temp = temp->next;
		}
		printf("%d  ", tail->data);
	}
}
void create()
{
	int new;
	char ans;
	do
	{
		printf("enter the data");
		scanf("%d", &new);
		temp = (struct node *)malloc(sizeof(struct node));
		if (temp == NULL)
			printf("unable to allocate memory");
		temp->data = new;
		temp->next = NULL;
		if (head == NULL)
		{
			head = tail = temp;
			size++;
		}
		else
		{
			tail->next = temp;
			tail = temp;
			size++;
		}
		printf("do u want to insert more nodes(y/n):");
		ans = getch();
	} while (ans == 'y' || ans == 'Y');
	tail->next = head;
}
void insert(int n)
{
	int new;
	printf("enter the data");
	scanf("%d", &new);
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
		printf("unable to allocate memory");
	temp->data = new;
	temp->next = NULL;
	if (n == 1)
	{
		temp->next = head;
		tail->next = temp;
		head = temp;
	}
	else if (n>size)
	{
		tail->next = temp;
		temp->next = head;
		tail = temp;
	}
	else
	{
		temp1 = head;
		while (f != n - 2)
		{
			temp1 = temp1->next;
			f++;
		}
		temp->next = temp1->next;
		temp1->next = temp;
	}
}