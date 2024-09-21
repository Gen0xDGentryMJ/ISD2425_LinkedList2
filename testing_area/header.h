#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

typedef char string[64];

typedef struct node *address;

typedef struct{
	string namaPlanet;
	int jarakDariBumi;
	string material;	
}Data;
typedef struct node{
	Data data;
	address	next;
}Planet;

typedef struct{
	address first;
}List;

void createEmpty(List *L);
bool isEmpty(List L);
address alokasi(string nama, int jarak, string material);
void insertFirst(List *L, address newNode);
void insertLast(List *L, address newNode);
void insertAfter(address before, address newNode);
void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);
int nbList(List L);
void printData(List L);
