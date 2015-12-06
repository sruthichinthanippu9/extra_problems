#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL, *tail = NULL, *temp = NULL, *temp1 = NULL, *temp2 = NULL, *temp3 = NULL;
void create();
void sort();
void traverse();
int flag = 0, size = 0;
void main()
{
	create();
	traverse();
	printf("\n");
	sort();
	traverse();
}
void create()
{
	int val;
	char ans;
	do
	{
		printf("enter the data");
		scanf("%d", &val);
		temp = (struct node *)malloc(sizeof(struct node));
		if (temp == NULL)
			printf("unable to allocate memory");
		temp->data = val;
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
}
void traverse()
{
	temp = head;
	if (temp == NULL)
		printf("list is empty ");
	else
	{
		while (temp != NULL)
		{
			printf("%d   ", temp->data);
			temp = temp->next;
		}
	}
}
void sort()
{
	temp = head;
	while (temp->next != NULL)
	{
		if ((temp->data) < ((temp->next)->data) && (((temp->next)->data) > (((temp->next)->next)->data)))
		{
			temp1 = temp->next;
			break;
		}
		temp = temp->next;
	}
	while (temp1 != NULL)
	{
		temp3 = temp2;
		temp2 = temp1;
		temp1 = temp1->next;
		temp2->next = temp3;
	}
	temp->next = temp2;
}