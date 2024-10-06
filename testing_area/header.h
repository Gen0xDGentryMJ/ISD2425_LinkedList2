#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

typedef char string[64];

typedef struct node *address;

typedef struct node{
	string namaPlanet;// contoh: bumi, mars, jupiter
	//nama tidak boleh kosong atau -
	int jarakDariBumi;// dihitung /km, contoh: input 1 => tampilan 1 km
	//jarak tidak boleh lebih kecil dari 1 (input minimal 1)
	string status;//status ada 3(aman, berbahaya, mematikan)
	address	next;
}Planet;

typedef struct{
	address first;
}List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);
address alokasi(string nama, int jarak, string status);

void insertFirst(List *L, address newNode);
void insertAfter(address before, address newNode);
void insertLast(List *L, address newNode);

void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);

int nbList(List L);
address findNodePlanet(List L, string nama);
void printData(List L);
void kesimpulan(List L);
//BONUS
address ReverseList(List L);

//Tugas
void swapping1(List *L);
