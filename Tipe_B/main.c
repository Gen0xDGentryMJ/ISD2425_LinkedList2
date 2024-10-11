#include "header.h"

int main(int argc, char *argv[]) {
	List L, history;
	char menu;
	string nama;
	string ukuran;
	address before;
	string temp;
	
	int stok, bil;
	
	createEmpty(&L);
	createEmpty(&history);
	do{
		system("cls");
		printData(L);
		printf("\n\n\t[Menu Belanja Mall Atma]\n");
		printf("\n\t[1]. Input Baju");
		printf("\n\t[2]. Hitung Data");
		printf("\n\t[3]. Hapus Baju");
		printf("\n\t[4]. Kesimpulan");
		printf("\n\t[5]. History Baju");
		printf("\n\t------------------------------");
		printf("\n\t[6]. Reverse List [Bonus]");
		printf("\n\t[7]. Swap Dari stok [Tugas]");
		
		printf("\n\t[0]. Keluar");
		printf("\n\t>>> ");menu = getche();

		switch(menu){
			case '1':
				//input berdasarkan stok
				system("cls");
				printData(L);
				printf("\n\n\tData ingin dimasukan di urutan : ");scanf("%d",&bil);//inputan berdasarkan urutan
				
				if(bil<0||bil>nbList(L)+1){
					printf("\n\tUrutan Tidak Valid");
					break;
				}

				do{
					//nama
					printf("\n\tMasukan Nama Baju: ");fflush(stdin);gets(nama);
					if(strcmpi(nama,"-")!=0 && strlen(nama)!=0){
						//kondisi nama benar
						break;
					}else{
						//kondisi nama salah
						printf("\n\t[!] Invalid, Nama tidak boleh Kosong atau - [!]");
					}
				}while(1);
				do{
					//stok
					printf("\n\tMasukan Stok Baju: ");scanf("%d",&stok);
					if(stok>0){
						//kondisi stok benar
						break;
					}else{
						//kondisi stok salah
						printf("\n\t[!] Invalid, Stok Baju Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);
				do{
					//ukuran
					printf("\n\tMasukan Ukuran Baju [ S | M | L | XL | XXL ]: ");fflush(stdin);gets(ukuran);
					if(strcmpi(ukuran,"s")==0||strcmpi(ukuran,"m")==0||strcmpi(ukuran,"l")==0||strcmpi(ukuran,"xl")==0||strcmpi(ukuran,"xxl")==0){
						//kondisi ukuran benar
						break;
					}else{
						//kondisi ukuran salah
						printf("\n\t[!] Invalid, ukuran hanya bisa [S], [M], [L], [XL], atau [XXL] [!]");
					}
				}while(1);
				
				if(bil==0){
					insertFirst(&L,alokasi(nama, stok, ukuran));
				}else if(!isEmpty(L)&&nbList(L)>1&&bil<nbList(L)){
					printf("\n\tNama Baju yang ingin disisipkan: "); fflush(stdin); gets(temp);
					address before = findNodeBaju(L, temp);
					if(strlen(temp)==0||before==NULL){
						printf("\n\tInvalid Insert");
						break;
					}else{
						insertAfter(before, alokasi(nama, stok, ukuran));
					}
				}else{
					insertLast(&L, alokasi(nama, stok, ukuran));
				}
				printf("\n\tData Inserted");
				
				break;
			case '2':
				//menghitung data planet beserta biaya pergi
				printf("\n\tAda %d Data",nbList(L));
				break;
			case '3':
				//hanya bisa di akses ketika ada planet
				if(nbList(L)>=1){
					printf("\n\tNama Baju yang ingin dihapus: ");fflush(stdin);gets(nama);
					before = findNodeBaju(L, nama);
					
					if(before==NULL){
						printf("\n\t[!] Nama Baju tidak ditemukan [!]");
						break;
					}
					
					printf("\n\t[!] Yakin ingin menghapus Baju %s? [Y/N]",before->namaBaju);
					printf("\n\t>>> ");scanf("%c",&menu);
					
					if(menu == 'y'|| menu == 'Y'){
						printf("\n\t[!] Baju %s telah di hapus [!]",before->namaBaju);
						insertLast(&history,alokasi(before->namaBaju,before->stok,before->ukuran));
						if(before == L.first){
							deleteFirst(&L);
						}else if(before->next==NULL){
							deleteLast(&L);
						}else{
							deleteAt(&L,before);
						}
					}else{
						printf("\n\t[!] Tidak Jadi Delete Data Baju [!]");
					}
				}else{
					printf("\n\t[!] Data Masih Kosong [!]");
				}
				break;
			case '4':
				if(!isEmpty(L)){
					kesimpulan(L);
				}else{
					printf("\n\t[!] Masukan Data Telebih Dahulu [!]");
				}
				break;
			case '5':
				if(!isEmpty(history)){
					printHistoryData(history);
				}else{
					printf("\n\t[!] Masukan Data Telebih Dahulu [!]");
				}
				break;
			case '6':
				if(isEmpty(L)){
					printf("\n\t[!] Masukan Data Telebih Dahulu [!]");
				}else if(isOneElement(L)){
					printf("\n\t[!] Tidak Bisa Melakukan Reverse List [!]");
				}else{
					L.first = ReverseList(L);
					printf("\n\tBerhasil Reverse");
				}
				break;
			case '7':
				if(isEmpty(L)){
					printf("\n\t[!] Masukan Data Telebih Dahulu [!]");
				}else if(isOneElement(L)){
					printf("\n\t[!] Tidak Bisa Menukar Karena Data Hanya Satu [!]");
				}else{
					swapping1(&L);
					printf("\n\tBerhasil Menukar");
				}
				break;
			case '0':
				printf("\n\n\t Connection Lost User [NAMA PRAKTIKAN] - [NPM]");//Gentry Marvelo Jusuf - 220711878
				break;
			default:
				printf("\n[!] Menu tidak Ditemukan [!]");
				break;

		}
		if(menu!='0') getch();
	}while(menu!='0');
	return 0;
}

