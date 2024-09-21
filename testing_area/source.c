#include "header.h"

void createEmpty(List *L){
	L->first = NULL;
}

address alokasi(string nama, int jarak, string material){
	address temp;
	strcpy(temp->namaPlanet, nama);
	temp->jarakDariBumi = jarak;
	strcpy(temp->material, material);
	return temp;
}
