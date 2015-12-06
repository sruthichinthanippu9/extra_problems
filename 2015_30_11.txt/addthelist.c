#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*head1 = NULL, *tail1 = NULL, *temp1 = NULL, *head2 = NULL, *tail2 = NULL, *temp2 = NULL;
void create(int n);
void traverse();
void add();
int size1 = 0, size2 = 0;
void main()
{
	create(1);
	create(2);
	add();
	traverse();
}
void create(int n)
{
	int val;
	char ans;
	do
	{
		printf("\n enter the data");
		scanf("%d", &val);
		temp1 = (struct node *)malloc(sizeof(struct node));
		if (temp1 == NULL)
			printf("unable to allocate memory");
		temp1->data = val;
		temp1->next = NULL;
		if (n == 1)
		{
			if (head1 == NULL)
			{
				head1 = tail1 = temp1;
				size1++;
			}
			else
			{
				tail1->next = temp1;
				tail1 = temp1;
				size1++;
			}
		}
		else if (n == 2)
		{
			if (head2 == NULL)
			{
				head2 = tail2 = temp1;
				size2++;
			}
			else
			{
				tail2->next = temp1;
				tail2 = temp1;
				size2++;
			}
		}
		printf("do u want to insert more nodes(y/n):");
		ans = getch();
	} while (ans == 'y' || ans == 'Y');
}
void traverse()
{
	temp1 = head1;
	if (temp1 == NULL)
		printf("list is empty ");
	else
	{
		while (temp1 != NULL)
		{
			printf("%d   ", temp1->data);
			temp1 = temp1->next;
		}
	}
}
void add()
{
	if (size2 > size1)
	{
		temp2 = head1;
		head1 = head2;
		head2 = temp2;
	}
	temp1 = head1;
	temp2 = head2;
	while (temp2 != NULL)
	{
		temp1->data += temp2->data;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}