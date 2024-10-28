#include "header.h"

int main(int argc, char *argv[]) {
	List L, servis;
	char menu;
	
	int nomor;
	string tipe;
	int kapasitas;
	float harga;
	
	string temp;
	int bil;
	address before;
	
	createEmpty(&L);
	createEmpty(&servis);
	do{
		system("cls");
		printData(L);
		printf("\n\n\t [Menu Stasiun Atma]\n");
		printf("\n\t [1]. Input Gerbong");//create random insert
		printf("\n\t [2]. Hitung Gerbong ");//read
		/* menampilkannya seperti model kereta seperti [0] -> [tipeGerbong-nomorGerbong] -> [||||] */
		printf("\n\t [3]. Servis Gerbong");// history servis
		printf("\n\t [4]. Update Gerbong");//update data 
		printf("\n\t [5]. Hapus Gerbong");//delete //submenu 0->DeleteFirst, 1->DeleteAt, 2->DeleteLast
		printf("\n\t ------------------------------");
		printf("\n\t [6]. Reverse List [Bonus]");//reverse List
		printf("\n\t [7]. Swap High & Low [Tugas]");//Swap kapasitas terkecil dengan kapasitas terbesar
		
		printf("\n\t [0]. Keluar");
		printf("\n\t >>> ");menu = getche();

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
				printf("\n\n\t Data ingin dimasukan di urutan : ");scanf("%d",&bil);//inputan berdasarkan urutan
				
				if(bil<0||bil>nbList(L)+1){
					printf("\n\t Urutan Tidak Valid");
					break;
				}
				do{
					//nomor
					printf("\n\t Masukan Nomor Gerbong: ");scanf("%d",&nomor);
					if(nomor>0){
						//kondisi nomor benar
						break;
					}else{
						//kondisi nomor salah
						printf("\n\t [!] Invalid, Nomor Gerbong Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);
				do{
					//tipe Gerbong
					printf("\n\t Masukan Tipe Gerbong[Ekonomi|Bisnis|Eksekutif]: ");fflush(stdin);gets(tipe);
					if(strcmpi(tipe,"-")==0 || strlen(tipe)==0){
						//kondisi tipe salah
						printf("\n\t [!] Invalid, Tipe tidak boleh kosong [!]");
					}else{
						if(strcmpi(tipe,"Ekonomi")==0 || strcmpi(tipe,"Bisnis")==0 || strcmpi(tipe,"Eksekutif")==0){
							break;
						}else{
							printf("\n\t [!] Invalid Tipe Gerbong hanya bisa Ekonomi, Bisnis, Atau Eksekutif [!]");
						}
					}
				}while(1);
				do{
					//kapasitas
					printf("\n\t Masukan Kapasitas Gerbong: ");scanf("%d",&kapasitas);
					if(kapasitas>0){
						//kondisi kapasitas benar
						break;
					}else{
						//kondisi kapasitas salah
						printf("\n\t [!] Invalid, Kapasitas Gerbong Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);

				if(strcmpi(tipe,"Ekonomi")==0){
					harga = 150000 + (kapasitas * 10000);
				}else if(strcmpi(tipe,"Eksekutif")==0){
					harga = 225000 + (kapasitas * 15000);
				}else{
					harga = 300000 + (kapasitas * 20000);
				}

				if(bil==0){
					insertFirst(&L, alokasi(nomor,tipe,harga,kapasitas));
					printf("\n\t Data Inserted");
				}else if(!isEmpty(L)&&nbList(L)>1&&bil<nbList(L)){
					address before = findNode(L,tipe,nomor);
					if(strlen(temp)==0||before==NULL){
						printf("\n\t Invalid Insert");
						break;
					}else{
						insertAfter(before, alokasi(nomor,tipe,harga,kapasitas));
						printf("\n\t Data Inserted");
					}
				}else{
					insertLast(&L, alokasi(nomor,tipe,harga,kapasitas));
					printf("\n\t Data Inserted");
				}
				break;
			case '2':
				//menghitung data planet beserta biaya pergi
				printf("\n\t Ada %d Data",nbList(L));
				break;
			case '3':
				if(!isEmpty(servis)){
					printHistoryData(servis);
				}else{
					printf("\n\t [!] Masukan Data Telebih Dahulu [!]");
				}
				break;
			case '4':
				if(isEmpty(L)){
					printf("\n\t [!] Data Masih Kosong [!]");
				}else{
					printf("\n\t Tipe Gerbong yang ingin dihapus: ");fflush(stdin);gets(tipe);
					printf("\n\t Nomor Gerbong yang ingin dihapus: ");scanf("%d",&nomor);
					before = findNode(L,tipe, nomor);
					
					if(before==NULL){
						printf("\n\t [!] Gerbong tidak ditemukan [!]");
						break;
					}
					do{
						//nomor
						printf("\n\t Masukan Nomor Gerbong: ");scanf("%d",&nomor);
						if(nomor>0){
							//kondisi nomor benar
							break;
						}else{
							//kondisi nomor salah
							printf("\n\t [!] Invalid, Nomor Gerbong Tidak Boleh Lebih Kecil dari 1 [!]");
						}
					}while(1);
					do{
						//tipe Gerbong
						printf("\n\t Masukan Tipe Gerbong: ");fflush(stdin);gets(tipe);
						if(strcmpi(tipe,"-")==0 || strlen(tipe)==0){
							//kondisi tipe salah
							printf("\n\t [!] Invalid, Tipe tidak boleh kosong [!]");
						}else{
							if(strcmpi(tipe,"Ekonomi")==0 || strcmpi(tipe,"Bisnis")==0 || strcmpi(tipe,"Eksekutif")==0){
								break;
							}else{
								printf("\n\t [!] Invalid Tipe Gerbong hanya bisa Ekonomi, Bisnis, Atau Eksekutif [!]");
							}
						}
					}while(1);
					do{
						//kapasitas
						printf("\n\t Masukan Kapasitas Gerbong: ");scanf("%d",&kapasitas);
						if(kapasitas>0){
							//kondisi kapasitas benar
							break;
						}else{
							//kondisi kapasitas salah
							printf("\n\t [!] Invalid, Kapasitas Gerbong Tidak Boleh Lebih Kecil dari 1 [!]");
						}
					}while(1);
					if(strcmpi(tipe,"Ekonomi")==0){
						harga = 150000 + (kapasitas * 10000);
					}else if(strcmpi(tipe,"Eksekutif")==0){
						harga = 225000 + (kapasitas * 15000);
					}else{
						harga = 300000 + (kapasitas * 20000);
					}
					
					//print current data
					EditData(&L,before,tipe,nomor,harga,kapasitas);
					printf("\n\t Berhasil Edit\n");	
				}
				break;
			case '5':
				if(!isEmpty(L)){
					printf("\n\t Tipe Gerbong yang ingin dihapus: ");fflush(stdin);gets(tipe);
					printf("\n\t Nomor Gerbong yang ingin dihapus: ");scanf("%d",&nomor);
					before = findNode(L,tipe, nomor);
					
					if(before==NULL){
						printf("\n\t [!] Gerbong tidak ditemukan [!]");
						break;
					}
					
					printf("\n\t [!] Yakin ingin menghapus Gerbong %s-%d ?[Y/N]",before->tipeGerbong,before->nomorGerbong);
					printf("\n\t >>> ");menu = getche();
					
					if(menu == 'y'|| menu == 'Y'){
						printf("\n\t [!] Gerbong %s-%d telah di hapus [!]",before->tipeGerbong,before->nomorGerbong);
						insertLast(&servis,alokasi(before->nomorGerbong,before->tipeGerbong,before->hargaTiket,before->kapasitas));

						if(before == L.first){
							deleteFirst(&L);
						}else if(before->next==NULL){
							deleteLast(&L);
						}else{
							deleteAt(&L,before);
						}
					}else{
						printf("\n\t [!] Tidak Jadi Delete Data Planet [!]");
					}
				}else{
					printf("\n\t [!] Data Masih Kosong [!]");
				}
				break;
			case '6':
				if(isEmpty(L)){
					printf("\n\t [!] Masukan Data Telebih Dahulu [!]");
				}else if(isOneElement(L)){
					printf("\n\t [!] Tidak Bisa Menukar Karena Data Hanya Satu [!]");
				}else{
					L.first = ReverseList(L);
					printf("\n\t Berhasil Reverse List");
				}
				break;
			case '7':
				if(isEmpty(L)){
					printf("\n\t [!] Masukan Data Telebih Dahulu [!]");
				}else if(isOneElement(L)){
					printf("\n\t [!] Tidak Bisa Menukar Karena Data Hanya Satu [!]");
				}else{
					swapping1(&L);
					printf("\n\t Berhasil Menukar");
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


