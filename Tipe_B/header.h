#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

typedef char string[64];

typedef struct node *address;

typedef struct node{
	string namaBaju;
	int stok;
	string ukuran;
	address	next;
}Baju;

typedef struct{
	address first;
}List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);
address alokasi(string nama, int stok, string ukuran);

void insertFirst(List *L, address newNode);
void insertAfter(address before, address newNode);
void insertLast(List *L, address newNode);

void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);

int nbList(List L);
address findNodeBaju(List L, string nama);
void printData(List L);
void printHistoryData(List L);
void kesimpulan(List L);
//BONUS
address ReverseList(List L);

//Tugas
void swapping1(List *L);
