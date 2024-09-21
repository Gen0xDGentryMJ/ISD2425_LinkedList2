#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

typedef char string[50];

typedef struct{
	string nama;
	//baju int stok
	//kimia str berbahaya
	//makanan str tipeSize
	//mobil tipe mesin
	//buku int halaman buku 
}X;
typedef struct{
	string bahan;//katun wol nilon 
	string tipe[5];
	float harga;
}Baju;
//
//typedef struct{
//	string Ph_level;// asam, basa, netral
//	string senyawa[5];  
//	float harga;
//}Kimia;
//
//typedef struct{
//	string film;//dilan, conjuring, avengers
//	string makanan[5];
//	float hargaTiket;
//}Bioskop;
//
//typedef struct{
//	string tipe_mobil;convertible, sedan, minivan
//	string merk[5];
//	float harga;
//}Mobil;
//
//typedef struct{
//	string tipe_buku;novel, komik, majalah
//	string genre[5];
//	float harga;
//}Buku;

typedef struct node *address;

typedef struct node{
	Baju b;
    address next;
}node;

typedef struct{
    address first;
}List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);
address alokasi(string bahan, string merk, float harga);
void insertFirst(List *L, address newNode);
void insertAfter(address before, address newNode);
void insertLast(List *L,address newNode);
void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);
void printData(List L);
address findNode(List L, int bil);
address findMerk(List L, string merk);
int nbList(List L);
//////////
address findHighestData(List L);
address findLowestData(List L);
void kesimpulan(List *L);


