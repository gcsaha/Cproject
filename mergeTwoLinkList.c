#include<stdio.h>
#include<stdlib.h>

typedef struct st_tag
{
	int data;
	struct st_tag *next;
}st_type;



st_type *createLinkList(int numberofElement, int *dataArray)
{
	st_type *head=NULL, *temp;
	if(numberofElement <=0)
		return head;
	
	head = (st_type *)malloc(sizeof(st_type));
	head->next = NULL;
	head->data = dataArray[0];
	temp=head;
	
	for(int i=1;i<numberofElement;i++)
	{
		temp->next = (st_type *)malloc(sizeof(st_type));
		temp=temp->next;
		temp->data = dataArray[i];
		temp->next = NULL;
	}
	return head;
}

void displayLinkList(st_type *ptr)
{
	printf("Link is  : ");
	while(ptr)
	{
		printf("%d-->",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
st_type *getHead(st_type **ptr)
{
	st_type *head;
	head = *ptr;
	(*ptr) = (*ptr)->next;
	return head;
}
st_type *mergeLinkList(st_type *h1,st_type *h2)
{
	st_type *head,*temp;
	if(!h1)
		return h2;
	if(!h2)
		return h1;
	
	if(h1->data<= h2->data)
	{
		head = h1;
		h1 = h1->next;
	}
	else
	{
		head = h2;
		h2 = h2->next;
	}
	temp = head;
	
	while(h1 && h2)
	{
		if(h1->data <= h2->data)
		{
			temp->next = h1;
			h1 = h1->next;
			temp = temp->next;
		}
		else
		{
			temp->next = h2;
			h2 = h2->next;
			temp = temp->next;
		}
	}

	if(h1){
		temp->next = h1;
	}else{
		temp->next = h2;
	}

	return head;
}

void main()
{
	int dataArray1[6] = {3,4,5,6,9,15};
	int dataArray2[6] = {1,2,10,14,40,50};
	st_type *linkList1=NULL;
	st_type *linkList2=NULL;
	st_type *mergedLinkList=NULL;
	linkList1 = createLinkList(0,dataArray1);
	linkList2 = createLinkList(0,dataArray2);
	displayLinkList(linkList1);
	displayLinkList(linkList2);
	mergedLinkList = mergeLinkList(linkList1,linkList2);
	displayLinkList(mergedLinkList);
	return;
}