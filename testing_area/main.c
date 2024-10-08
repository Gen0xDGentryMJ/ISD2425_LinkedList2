#include "header.h"

typedef int Infotype;


int main(int argc, char *argv[]) {
	List L;
	createEmpty(&L);
	address before;
	int temp;
	
	insertFirst(&L,alokasi(1));
	insertFirst(&L,alokasi(2));
	insertLast(&L,alokasi(3));
	before = findNode(L, 1);
	insertAfter(before, alokasi(7));
	insertFirst(&L,alokasi(8));
	before = findNode(L, 2);
	insertAfter(before, alokasi(5));
	deleteAt(&L,before);
	
	//85173
	
	return 0;
}










