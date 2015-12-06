#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL, *tail = NULL, *temp = NULL, *temp1 = NULL, *temp2 = NULL, *temp3 = NULL, *temp4 = NULL, *temp5 = NULL;
void create();
void sort();
void traverse();
int flag = 0, size = 0;
void main()
{
	create();
	printf("\n before sorting two misplaced elements \n");
	traverse();
	sort();
	printf("\n after sorting two misplaced elements \n");
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
	temp3 = head;
	while ((temp3->next) != tail)
	{
		temp3 = temp3->next;
	}
	if ((head->data)>((head->next)->data))
	{
		int i = 1;
		temp1 = head;
		temp = temp->next;
		while (temp != NULL)
		{
			if (((temp1->data) > (temp->data)) && ((temp1->data) > ((temp->next)->data)) && ((temp1->data) < (((temp->next)->next)->data)) || i == size - 2)
			{
				//temp=temp->next;
				temp4->next = temp1->next;
				temp1->next = (temp->next)->next;
				temp2 = temp->next;
				temp->next = temp1;
				temp2->next = temp4->next;
				head = temp2;
				break;

			}
			temp = temp->next;
			i++;
		}
	}
	else if ((tail->data)<(temp3->data))
	{
		temp1 = tail;
		temp = head;
		while (temp != temp3)
		{
			if (((temp1->data) > (temp->data)) && ((temp1->data) < ((temp->next)->data)) && ((temp1->data) <= (((temp->next)->next)->data)))
			{
				temp2->next = (temp->next);
				temp->next = temp1;
				temp1->next = (temp2->next)->next;
				temp3->next = temp2->next;
				temp2 = temp3->next;
				temp2->next = NULL;
				tail = temp2;
			}
			temp = temp->next;
		}
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			if ((temp->data) > ((temp->next)->data))
			{
				temp1 = temp->next;
				temp2 = temp;
				break;
			}
			temp = temp->next;
		}
		temp = head;
		while (temp->next != NULL)
		{
			if (((temp1->data) >= (temp->data)) && ((temp1->data) > ((temp->next)->data)) && ((temp1->data) < (((temp->next)->next)->data)))
			{
				temp5->next = temp->next;
				temp3->next = temp1->next;
				temp4->next = (temp->next)->next;
				temp->next = temp2->next;
				temp2->next = temp5->next;
				(temp2->next)->next = temp3->next;
				temp1->next = temp4->next;
			}
			temp = temp->next;
		}
	}
}
