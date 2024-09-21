#include "header.h"

int main(int argc, char *argv[]) {
	List L, history;
	char menu;
	createEmpty(&L);
	createEmpty(&history);
	do{
		printData(L);
		system("cls");
		printf("\n\tMenu ");
		printf("\n\t[1]. Hitung Data");
		printf("\n\t[2]. Input Planet");
		printf("\n\t[3]. Hapus Planet");
		printf("\n\t[0]. Keluar");
		print("\n>>>");menu = getche();

		switch(menu){
			case 1:

				break;
			case 2:
			
				break;
			case 3:
			
				break;
			case 0:
			
				break;
			default:
			
				break;

		}
		if(menu!='0') getch();
	}while(menu!='0');
	return 0;
}
