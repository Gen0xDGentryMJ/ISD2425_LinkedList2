#include "header.h"

void createEmpty(List *L)
{
	L->first = NULL;
}

bool isEmpty(List L){
	return L.first == NULL;
}

bool isOneElement(List L){
	return !isEmpty(L) && L.first->next == NULL;
}

address alokasi(Infotype X){
	address temp;
	temp = (Nodes*)malloc(sizeof(Nodes));
	temp->X = X;
	temp->next = NULL;
	return temp;
}

void insertFirst(List *L, address newNode)
{
	newNode->next = L->first;
	L->first = newNode;
}

void insertLast(List *L, address newNode)
{
	address temp = L->first;
	if (isEmpty(*L))
	{
		insertFirst(&(*L), newNode);
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void insertAfter(address before, address newNode)
{
	if (before != NULL)
	{
		newNode->next = before->next;
		before->next = newNode;
	}
}

void deleteFirst(List *L)
{
	if (!isEmpty(*L))
	{
		address del = (*L).first;
		(*L).first = (*L).first->next;
		free(del);
	}
}
void deleteAt(List *L, address del)
{
	address P;
	if (!isEmpty(*L))
	{
		if ((*L).first == del)
		{
			deleteFirst(L);
		}
		else
		{
			P = (*L).first;
			while (P->next != del)
			{
				P = P->next;
			}
			P->next = del->next;
			free(del);
		}
	}
}

void deleteLast(List *L)
{
	address P;
	if (!isEmpty(*L))
	{
		if (isOneElement(*L))
		{
			deleteFirst(L);
		}
		else
		{
			for (P = (*L).first; P->next->next != NULL; P = P->next);
			free(P->next);
			P->next = NULL;
		}
	}
}

void printData(List L){
	address temp = L.first;
	while(temp !=NULL){
		printf("[%d]->",temp->X);
		temp = temp->next;
	}
	printf("NULL");
	/*
	alternatif
	for(temp=L.first;temp!=NULL;temp=temp->next){
		printf("[%d]",temp->X);
	}
	*/
}

address findNode(List L, Infotype X)
{
	address bantu = L.first;
	while (bantu != NULL && bantu->X != X)
	{
		bantu = bantu->next;
	}
	return bantu;
}




