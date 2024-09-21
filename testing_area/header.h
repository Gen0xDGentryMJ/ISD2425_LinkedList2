#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

typedef char string[64];

typedef struct node *address;

typedef struct node{
	string namaPlanet;
	int jarakDariBumi;
	string material;
	address	next;
}Planet;

typedef struct{
	address first;
}List;

void createEmpty(List *L);
address alokasi(string nama, int jarak, string material);
