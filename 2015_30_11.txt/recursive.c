#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL, *tail = NULL, *temp = NULL, *temp2;
void create();
void traverse();
struct node *recursive(struct node *head);
int flag = 0, size = 0;
void main()
{
	
	create();
	traverse();
	recursive(head);
	printf("\n");
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
struct node *recursive(struct node *temp2)
{
	struct node *temp1;
	if (temp2->next == NULL)
	{
		return temp2;
	}
	temp1 = temp2->next;
	if (temp2 == head)
		temp2->next = NULL;
	recursive(temp1)->next = temp2;
	return temp2;
}
