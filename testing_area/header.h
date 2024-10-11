#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

/*tipe data yang akan diterima oleh linked list adalah infotype*/ 
typedef int Infotype;// pendeklarasian bahwa infotype adalah int

/*address digunakan untuk menyimpan alamat pointer dari node*/
typedef struct node *address;
/*nodes akan menyimpan data dan juga menunjuk ke alamat Nodes selanjutnya*/ 
typedef struct node{ // disini node bekerja sebagai sebuat tag sehingga bisa langsung dipanggil sebelum dideklarasi
	Infotype X;
	address	next;
}Nodes;

/*list menunjuk ke data pertama yakni first*/
typedef struct{
	address first;
}List;

void createEmpty(List *L);							//menginitkan / membuat list kosong
bool isEmpty(List L);								//mengecek apakah list itu kosong
bool isOneElement(List L);							//mengecek apakah list hanya memiliki 1 data saja
address alokasi(Infotype X);						//mengalokasikan data ke sebuah address beserta membuat node baru

void insertFirst(List *L, address newNode);			//memasukan data ke awal data linked list
void insertAfter(address before, address newNode);	//memasukan data ke linked list setelah node tertentu
void insertLast(List *L, address newNode);			//memasukan data ke akhir data linked list

void deleteFirst(List *L);							//menghapus data node pertama
void deleteAt(List *L, address del);				//menghapus data node tertentu
void deleteLast(List *L);							//menghapus data node terakhir

void printData(List L);								//menampilkan data dalam linked list

address findNode(List L, Infotype X);				//mencari data pada linked list menggunakan tipe data tertentu

















