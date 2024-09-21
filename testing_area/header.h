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
	string SDA;
	address	next;
}Planet;

typedef struct{
	address first;
}List;
