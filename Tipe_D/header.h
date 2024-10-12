#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <time.h>

typedef char string[64];

typedef struct node *address;

typedef struct node{
	int nomorGerbong;
	string tipeGerbong; 
	float hargaTiket;
	int kapasitas;
	address	next;
}Gerbong;

typedef struct{
	address first;
}List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);

address alokasi(int nomor, string tipe, float harga, int kapasitas);

void insertFirst(List *L, address newNode);
void insertAfter(address before, address newNode);
void insertLast(List *L, address newNode);

void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);

int nbList(List L);

address findNode(List L, string tipe, int nomor);
void printData(List L);
void EditData(List *L, address before, string tipe, int nomor, float harga, int kapasitas );
void printHistoryData(List L);
//BONUS
address ReverseList(List L);
//Tugas
void swapping1(List *L);


