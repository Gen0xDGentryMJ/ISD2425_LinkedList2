//varian 2
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

typedef char string[50];
typedef struct node *address;

typedef struct{
	string namaBelanjaan;
	string tipeBelanjaan;
	float hargaBelanjaan;
	int beratBelanjaan;//dalam kg
}Data;

typedef struct node{
	Data k;
	address next;
}Belanja;

typedef struct{
    address first;
}List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);

address alokasi(Data data);
Data alokasiData(string nama, string tipe, int berat, float harga);
void insertFirst(List *L, address newNode);
void insertAfter(address before, address newNode);
void insertLast(List *L,address newNode);

void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);

int nbList(List L);
void printData(List L, Data d);
address findNode(List L, string nama);

void EditData(List *L, Data k, address before);
void printHistoryData(List L);
Data geser(List L, Data d);

//BONUS
void deleteDupliAll(List *L);
//TUGAS
void swapping1(List *L);

	

