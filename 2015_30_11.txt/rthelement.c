#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*head1 = NULL, *tail1 = NULL, *temp1 = NULL, *head2 = NULL, *tail2 = NULL, *temp2 = NULL;
void create(int n);
void traverse();
void sort();
void rele(int);
int size1 = 0, size2 = 0;
void main()
{
	int r;
	printf("enter rth element:");
	scanf("%d", &r);
	printf("\n");
	create(1);
	create(2);
	traverse();
	printf("\n");
	sort();
	rele(r);
}
void create(int n)
{
	int val;
	char ans;
	do
	{
		printf("enter the data");
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
void sort()
{
	if (size2 > size1)
	{
		temp2 = head1;
		head1 = head2;
		head2 = temp2;
	}
	traverse();
	printf("\n");
	temp1 = head1;
	while (head2->next != NULL)
	{
		if (temp1 == head1)
		{
			if ((temp1->data) < (head2->data))
			{
				temp2 = head2;
				head2 = head2->next;
				temp2->next = temp1->next;
				temp1->next = temp2;
				temp1 = temp1->next;
			}
			else
			{
				temp2 = head2;
				head2 = head2->next;
				temp2->next = temp1;
				head1 = temp2;
				temp1 = temp1->next;
			}
		}
		else
		{
			temp1 = head1;
			while (((temp1->data)<(head2->data)) && (((temp1->next)->data)<(head2->data)))
			{
				temp1 = temp1->next;
			}
			if (temp1->next != NULL)
			{
				temp2 = head2;
				head2 = head2->next;
				temp2->next = temp1->next;
				temp1->next = temp2;
			}
			else
			{
				temp2 = head2;
				head2 = head2->next;
				temp1->next = temp2;
				temp2->next = NULL;
			}
		}
	}
	if (head2->next == NULL)
	{
		temp1 = head1;
		while (((temp1->data)<(head2->data)) && (((temp1->next)->data)<(head2->data)) && (temp1->next != NULL))
		{
			temp1 = temp1->next;
		}
		if (temp1 == head1)
		{
			temp2 = head2;
			temp2->next = temp1;
			head1 = temp2;
			temp1 = temp1->next;
		}
		else if (temp1->next != NULL)
		{
			temp2 = head2;
			temp2->next = temp1->next;
			temp1->next = temp2;
		}
		else if (temp1->next == NULL)
		{
			temp2 = head2;
			temp1->next = temp2;
		}
	}
}
void rele(int r)
{
	int i = 0;
	temp1 = head1;
	while (temp1 != NULL)
	{
		i++;
		if ((temp1->data) == (temp1->next)->data)
			i--;
		if (i == r)
		{
			printf("%d th element is %d", r, temp1->data);
			break;
		}
		temp1 = temp1->next;
	}
}
