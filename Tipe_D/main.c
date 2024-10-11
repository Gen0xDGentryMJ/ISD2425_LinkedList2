#include "header.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));

	List L;
	char menu;
	
	int nomor;
	string tipe;
	int kapasitas;
	float harga;
	
	string temp;
	int bil;
	int randomizer;
	address before;
	
	createEmpty(&L);
	do{
		system("cls");
		printData(L);
		printf("\n\n\t[Menu Stasiun Atma]\n");
		printf("\n\t[1]. Input Gerbong");//create random insert
		printf("\n\t[2]. Tampilkan Gerbong ");//read
		/* menampilkannya seperti model kereta seperti [0] -> [tipeGerbong-nomorGerbong] -> [||||] */
		printf("\n\t[3]. Servis Gerbong");//
		printf("\n\t[4]. Update Gerbong");//update data 
		printf("\n\t[5]. Hapus Gerbong");//delete //submenu 0->DeleteFirst, 1->DeleteAt, 2->DeleteLast
		printf("\n\t------------------------------");
		printf("\n\t[6]. Delete Duplikat [Bonus]");//delete duplicate kalau tipe gerbong dan id/nomorGerbong yang sama
		printf("\n\t[7]. Swap High & Low [Tugas]");//Swap jarak terpendek dengan jarak terpanjang
		
		printf("\n\t[0]. Keluar");
		printf("\n\t>>> ");menu = getche();

		switch(menu){
			case '1':
				/*
					int nomorGerbong;
					string tipeGerbong; 
					float hargaTiket;
					int kapasitas;
					address	next;
				*/
				system("cls");
				printData(L);
				
				do{
					//tipe Gerbong
					printf("\n\tMasukan Tipe Gerbong: ");fflush(stdin);gets(tipe);
					if(strcmpi(tipe,"-")!=0 && strlen(tipe)!=0){
						//kondisi tipe benar
						if(strcmpi(tipe,"Ekonomi")==0 || strcmpi(tipe,"Bisnis")==0 || strcmpi(tipe,"Eksekutif")==0){
							break;
						}else{
							printf("\n\t[!] Invalid Tipe Gerbong hanya bisa Ekonomi, Bisnis, Atau Eksekutif [!]");
						}
					}else{
						//kondisi tipe salah
						printf("\n\t[!] Invalid, Jarak Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);
				do{
					//nomor
					printf("\n\tMasukan Nomor Gerbong: ");scanf("%d",&nomor);
					if(nomor>0){
						//kondisi nomor benar
						break;
					}else{
						//kondisi nomor salah
						printf("\n\t[!] Invalid, Nomor Gerbong Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);
				do{
					//kapasitas
					printf("\n\tMasukan Kapasitas Gerbong: ");scanf("%d",&kapasitas);
					if(kapasitas>0){
						//kondisi kapasitas benar
						break;
					}else{
						//kondisi kapasitas salah
						printf("\n\t[!] Invalid, Kapasitas Gerbong Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);

				if(strcmpi(tipe,"Ekonomi")==0){
					harga = 150000 + (kapasitas * 10000);
				}else if(strcmpi(tipe,"Eksekutif")==0){
					harga = 225000 + (kapasitas * 15000);
				}else{
					harga = 300000 + (kapasitas * 20000);
				}

				randomizer=rand()%(2-0+1)+0;
				if(randomizer==0){
					insertFirst(&L, alokasi(nomor,tipe,harga,kapasitas));
					printf("\n\tData Inserted");
				}else if(randomizer==1&&!isOneElement(L)){
					randomizer = rand()%((nbList(L)-1)-1+1)+1;
					address before = findNodeRandomizer(L, randomizer);
					if(strlen(temp)==0||before==NULL){
						printf("\n\tInvalid Insert");
						break;
					}else{
						insertAfter(before, alokasi(nomor,tipe,harga,kapasitas));
						printf("\n\tData Inserted");
					}
				}else{
					insertLast(&L, alokasi(nomor,tipe,harga,kapasitas));
					printf("\n\tData Inserted");
				}
				break;
			case '2':
				//menghitung data planet beserta biaya pergi
				printf("\n\tAda %d Data",nbList(L));
				break;
			case '3':
				//hanya bisa di akses ketika ada planet
				// if(!isEmpty(L)){
				// 	printf("\n\tNama Planet yang ingin dihapus: ");fflush(stdin);gets(nama);
				// 	before = findNodePlanet(L, nama);
					
				// 	if(before==NULL){
				// 		printf("\n\t[!] Nama Planet tidak ditemukan [!]");
				// 		break;
				// 	}
					
				// 	printf("\n\t[!] Yakin ingin menghapus Planet %s? [Y/N]",before->namaPlanet);
				// 	printf("\n\t>>> ");scanf("%c",&menu);
					
				// 	if(menu == 'y'|| menu == 'Y'){
				// 		printf("\n\t[!] Planet %s telah di hapus [!]",before->namaPlanet);
				// 		if(before == L.first){
				// 			deleteFirst(&L);
				// 		}else if(before->next==NULL){
				// 			deleteLast(&L);
				// 		}else{
				// 			deleteAt(&L,before);
				// 		}
				// 	}else{
				// 		printf("\n\t[!] Tidak Jadi Delete Data Planet [!]");
				// 	}
				// }else{
				// 	printf("\n\t[!] Data Masih Kosong [!]");
				// }
				break;
			case '4':
				if(isEmpty(L)){
					printf("\n\t[!] Masukan Data Telebih Dahulu [!]");
				}else{
					before =findNode(L, tipe, nomor);
					deleteAt(&L, )
					//masukin ke temp data
				}
				break;
			case '5':
				if(!isEmpty(L)){
					kesimpulan(L);
				}else{
					printf("\n\t[!] Masukan Data Telebih Dahulu [!]");
				}
				break;
			case '6':
				if(isEmpty(L)){
					printf("\n\t[!] Masukan Data Telebih Dahulu [!]");
				}else if(isOneElement(L)){
					printf("\n\t[!] Tidak Bisa Menukar Karena Data Hanya Satu [!]");
				}else{
					//mengdelete data gerbong
				}
				break;
			case '7':
				if(isEmpty(L)){
					printf("\n\t[!] Masukan Data Telebih Dahulu [!]");
				}else if(isOneElement(L)){
					printf("\n\t[!] Tidak Bisa Menukar Karena Data Hanya Satu [!]");
				}else{
					//menukar Kapasitas terbanyak dengan kapasitas terdikit
				}
				break;
			case '0':
				printf("\n\n\tSukses terus Penjelajah [NAMA PRAKTIKAN] - [NPM]");//Gentry Marvelo Jusuf - 220711878
				break;
			default:
				printf("\n[!] Menu tidak Ditemukan [!]");
				break;

		}
		if(menu!='0') getch();
	}while(menu!='0');
	return 0;
}


