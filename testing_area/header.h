#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

typedef struct node *address;
typedef int Infotype;
typedef struct node{
	Infotype X;
	address	next;
}Nodes;

typedef struct{
	address first;
}List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);
address alokasi(Infotype X);

void insertFirst(List *L, address newNode);
void insertAfter(address before, address newNode);
void insertLast(List *L, address newNode);

void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);

address findNode(List L, Infotype X);
