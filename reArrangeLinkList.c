/**
 * @defgroup   REARRANGELINKLIST re Arrange Link List
 *
 * @brief      This file implements re Arrange Link List.
 * 
 * Source: https://www.careercup.com/question?id=5721888672710656
 * 
 * Input:  a->x->b->y->c->z
 * 
 * Output: a->b->c->z->y->x
 *
 * @author     Gour Chandra Saha
 * @date       17-Dec-2019
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct st_tag
{
	char data;
	struct st_tag *next;
}st_type;

st_type *createLinkList(int numberofElement, char *dataArray)
{
	st_type *head = NULL,*temp;
	if(numberofElement<=0)
		return head;
	head = (st_type *)malloc(sizeof(st_type));
	head->next = NULL;
	head->data = dataArray[0];
	temp = head;

	for(int i=1;i<numberofElement;i++)
	{
		temp->next = (st_type *)malloc(sizeof(st_type));
		temp = temp->next;
		temp->data = dataArray[i];
		temp->next = NULL;
	}
	return head;
}
void displayLinkList(st_type *ptr)
{
	printf("Link list :  ");
	while(ptr)
	{
		printf("%c-->",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void reArrangeLinkList(st_type **head)
{
	st_type *cur,*save,*prev;
	if(!(*head) || !(*head)->next || !(*head)->next->next)
		return;

	prev = (*head)->next;
	cur = prev->next;
	(*head)->next = cur;
	prev->next = NULL;

	while(cur->next && cur->next->next)
	{
		save = cur->next;
		cur->next = save->next;
		cur = cur->next;
		save->next = prev;
		prev = save;

	}
	if(!cur->next)
	{
		cur->next = prev;
	}
	else
	{
		cur->next->next = prev;
	}
}
void main()
{
	st_type *head = NULL;
	char dataArray1[12] = {'a','u','b','v','c','w','d','x','e','y','f','z'};
	head = createLinkList(12,dataArray1);
	displayLinkList(head);
	reArrangeLinkList(&head);
	displayLinkList(head);
	return;
}