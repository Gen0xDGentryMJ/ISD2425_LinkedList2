#include "header.h"

int main(int argc, char *argv[]) {
	List L;
	address temp,before;
	string merk, bahan;
	float harga;
	int bil; int i;
	char menu;
	createEmpty(&L);

	do{
		system("cls");
		printData(L);
		printf("\n\t");
		printf("\n[1] Count Data");
		printf("\n[2] Input Data");
		printf("\n[3] Delete Data");
		printf("\n[4] Kesimpulan");
		printf("\n[0] Exit");
		printf("\n>>>>");menu = getch();
		printf("\n\t\n");
		switch(menu){
			case '1':
				printf("\n Ada %d Data",nbList(L));
				break;
			case '2':
				printf("\n\t Data ingin dimasukan di urutan : ");scanf("%d",&bil);
				
				if(bil<0||bil>nbList(L)+1){
					printf("\nurutan tidak valid");
					break;
				}
				printf("\nMasukan Merk Baju: ");fflush(stdin);gets(merk);
				printf("\nMasukan Bahan Baju: ");fflush(stdin);gets(bahan);
				printf("\nMasukan Harga Baju: ");scanf("%f",&harga);
				temp = alokasi(bahan, merk, harga);
				//0
				//1====
				//2====
				//3===
				//4
				//input bill ->>> 2
				//
				//nbList -> 3
				if(bil==0){
					insertFirst(&L,temp);
				}else if(bil<nbList(L)){
					before = findNode(L, bil);
					insertAfter(before, temp);
				}else{
					insertLast(&L, temp);
				}
				printf("\nData Inserted");
				break;
			case '3':
				printf("\n\tMerk Baju yang ingin dihapus: ");fflush(stdin);gets(merk);
				before = findMerk(L,merk);
				if(before!=NULL){
					strcpy(merk,before->b.merk);
					printf("\n[!] Yakin ingin menghapus Baju %s? [Y/N]",merk);
					printf("\n>>> ");scanf("%c",&menu);
					if(menu == 'y'|| menu == 'Y'){
						if(before == L.first){
							deleteFirst(&L);
						}else if(before->next==NULL){
							deleteLast(&L);
						}else{
							deleteAt(&L,before);
						}
						printf("Baju %s telah di hapus",merk);
					}else{
						printf("\ntidak jadi delete data");
					}
				}else{
					printf("\nMerk baju tidak ditemukan [!]");
				}
				break;
			case '4':
				//bubble sort?
				kesimpulan(&L);
				break;
			case '0':
				printf("\nKeluar dari program...");
				break;
			default:
				printf("\n\t[!] Menu Doesn't Exist");
				break;
		}getch();
	}while(menu!='0');
	return 0;
}


