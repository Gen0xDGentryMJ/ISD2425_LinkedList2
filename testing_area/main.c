#include "header.h"

int main(int argc, char *argv[]) {
	List L, history;
	char menu,submenu;
	string nama, material;
	int jarak;
	
	createEmpty(&L);
	createEmpty(&history);
	do{
		system("cls");
		printData(L);
		printf("\n\n\tMenu ");
		printf("\n\t[1]. Input Planet");
		printf("\n\t[2]. Hitung Data");
		printf("\n\t[3]. Hapus Planet");
		printf("\n\t[0]. Keluar");
		printf("\n\t>>> ");menu = getche();

		switch(menu){
			case '1':
				do{
					system("cls");
					printf("\n\t[1]. First");
					printf("\n\t[2]. After");
					printf("\n\t[3]. Last");
					switch(submenu){
						case '1':
							insertFirst(&L, alokasi(nama, jarak, material));
							break;
						case '2':
							break;
						case '3':
							insertLast(&L, alokasi(nama, jarak, material));
							break;	
						case '-':
							printf("Kembali ke menu utama");
							break;
					}
					
				}while(submenu!='-');
				printf("\n\tMasukan Nama ");fflush(stdin);gets(nama);
				printf("\tMasukan Jarak ");scanf("%d", &jarak);
				printf("\tMasukan Material ");fflush(stdin);gets(material);
				break;
			case '2':
			
				break;
			case '3':
			
				break;
			case '0':
			
				break;
			default:
			
				break;

		}
		if(menu!='0') getch();
	}while(menu!='0');
	return 0;
}
