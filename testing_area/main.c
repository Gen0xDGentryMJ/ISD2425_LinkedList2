#include "header.h"

int main(int argc, char *argv[]) {
	List L;
	address temp;
	char menu;
	int bil;
	createEmpty(&L);
	do{
		system("cls");
		if(!isEmpty(L)){
			printData(L);
		}else{
			printf("\n\t Data Masih Kosong");
		}

		printf("\n\n\t Guided Linked List 2 - [XXXXX]\n");// di isi oleh 5 digit npm
		printf("\n\t 1. Insert First");
		printf("\n\t 2. Insert After");
		printf("\n\t 3. Insert Last");
		printf("\n\t 4. Delete First");
		printf("\n\t 5. Delete At");
		printf("\n\t 6. Delete Last");
		printf("\n\t 0. Exit");
		printf("\n\t Input Menu: >>\t"); menu = getch();
		printf("\n\t\n");
		switch(menu){
			case '1':
				printf("\n\t Masukan Angka: "); scanf("%d",&bil);
				printf("\t%d", bil);
				insertFirst(&L,alokasi(bil));
				printf("\n\t Insert First Berhasil");
				break;
			case '2':
				printf("\n\t Masukan Angka Setelah: "); scanf("%d",&bil);
				/*perhatikan findNode di source. fungsi findNode adalah untuk mencari node manakah yang memiliki data yang sesuai dengan inputan diatas.
				
				inputan diatas merupakan tempat node sebelum node data yang ingin dimasukan
				*/
				temp = findNode(L,bil);
				if(temp == NULL){
					printf("\n\t[!] Angka Tidak Ditemukan");
					break;
				}
				printf("\n\t Masukan Angka: "); scanf("%d",&bil);
				printf("%d", bil);
				insertAfter(temp, alokasi(bil));
				printf("\n\t Insert After Berhasil");
				break;
			case '3':
				printf("\n\t Masukan Angka: "); scanf("%d",&bil);
				insertLast(&L,alokasi(bil));
				printf("\n\t Insert Last Berhasil");
				break;
			case '4':
				if(isEmpty(L)){
					printf("\n\t [!] List Masih Kosong");
				}
				deleteFirst(&L);
				printf("\n\t Delete First Berhasil");
				break;
			case '5':
				if(isEmpty(L)){
					printf("\n\t [!] List Masih Kosong");
				}
				printf("\n\t Masukan Angka yang ingin di Delete: "); scanf("%d",&bil);
				temp = findNode(L,bil);
				if(temp == NULL){
					printf("\n\t[!] Angka Tidak Ditemukan");
					break;
				}
				deleteAt(&L, temp);
				printf("\n\t Delete At Berhasil");
				break;
			case '6':
				if(isEmpty(L)){
					printf("\n\t [!] List Masih Kosong");
				}
				deleteLast(&L);
				printf("\n\t Delete Last Berhasil");
				break;
			case '0':
				// Ubah XXXXX jadi 5 digit terakhir NPM
				// Ubah A menjadi Kelas
				// Ubah NAMAPRAKTIKAN menjadi nama kalian
				printf("\n\t Exit [XXXXX - A - NAMAPRAKTIKAN]");
				break;
			default:
				printf("\n\t [!] Menu Tidak Ada");
				break;
		}
		getch();
	}while(menu!='0');
	
	return 0;
}










