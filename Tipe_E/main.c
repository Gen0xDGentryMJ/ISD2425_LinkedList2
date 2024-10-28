#include "header.h"

int main(int argc, char *argv[]) {
	List L, history;
	string nama, tipe, temp;
	int berat,bil;
	float harga;
	char menu;

	address before;
	Data display = alokasiData("-","-",0,0.0);
	createEmpty(&L);
	createEmpty(&history);
	do{
		system("cls");
		printData(L, display);

		// printf("\n\n\t [Current Data: ]");
		// printf("\n\t Nama Belanjaan: %s", display.namaBelanjaan);
		// printf("\n\t Tipe Belanjaan: %s", display.tipeBelanjaan);
		// printf("\n\t Harga Belanjaan: Rp %.2f ", display.hargaBelanjaan);
		// printf("\n\t Berat Belanjaan: %0.2dkg",display.beratBelanjaan);

		printf("\n\n\t [Menu Supermarket AtmaMaret]\n");
		printf("\n\t [1]. Input Belanjaan");
		printf("\n\t [2]. Hapus Belanjaan");
		printf("\n\t [3]. Edit Data");
		printf("\n\t [4]. Next");
		printf("\n\t [5]. History Belanjaan");
		printf("\n\t ------------------------------");
		printf("\n\t [6]. Delete Semua Duplikat [Bonus]");//delete duplicate
		printf("\n\t [7]. Swap Dari Berat [Tugas]");//Swap Berat tertinggi dengan Berat terendah
		
		printf("\n\t [0]. Keluar");
		printf("\n\t >>> ");menu = getche();
		switch(menu){
			case '1':
				//input berdasarkan jarak
				system("cls");
				printData(L, display);
				printf("\n\n\t Data ingin dimasukan di urutan : ");scanf("%d",&bil);//inputan berdasarkan urutan
				
				if(bil<0||bil>nbList(L)+1){
					printf("\n\tUrutan Tidak Valid");
					break;
				}

				do{
					//nama
					printf("\n\t Masukan Nama Belanjaan: ");fflush(stdin);gets(nama);
					if(strcmpi(nama,"-")!=0 && strlen(nama)!=0){
						//kondisi nama benar
						break;
					}else{
						//kondisi nama salah
						printf("\n\t [!] Invalid, Nama tidak boleh kosong atau - [!]");
					}
				}while(1);
				do{
					//tipe
					printf("\n\t Masukan Tipe Belanjaan[Sayur|Daging|Bumbu]: ");fflush(stdin);gets(tipe);
					if(strcmpi(tipe,"Sayur")==0||strcmpi(tipe,"Daging")==0||strcmpi(tipe,"Bumbu")==0){
						//kondisi tipe benar
						break;
					}else{
						//kondisi tipe salah
						printf("\n\t [!] Invalid, Tipe hanya bisa Sayur, Daging, atau Bumbu [!]\n");
					}
				}while(1);
				do{
					//berat
					printf("\n\t Masukan Berat Belanjaan: ");scanf("%d",&berat);
					if(berat>=0){
						//kondisi berat benar
						break;
					}else{
						//kondisi berat salah
						printf("\n\t [!] Invalid, Berat Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);
				do{
					//harga
					printf("\n\t Masukan Harga Belanjaan: ");scanf("%f",&harga);
					if(harga>=1){
						//kondisi harga benar
						break;
					}else{
						//kondisi harga salah
						printf("\n\t [!] Invalid, Harga Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);

				display = alokasiData(nama,tipe,berat,harga);
				

				//autosorted linked list
				if(bil==0){
					insertFirst(&L,alokasi(alokasiData(nama, tipe, berat, harga)));
				}else if(!isEmpty(L)&&nbList(L)>1&&bil<nbList(L)){
					printf("\n\t Nama Belanjaan yang ingin disisipkan: "); fflush(stdin); gets(temp);
					address before = findNode(L, temp);
					if(strlen(temp)==0||before==NULL){
						printf("\n\t [!] Invalid Penambahan data [!]");
					}
					insertAfter(before, alokasi(alokasiData(nama, tipe, berat, harga)));
				}else{
					insertLast(&L, alokasi(alokasiData(nama, tipe, berat, harga)));
				}
				printf("\n\t Data Inserted");
				break;

			case '2':
				//hanya bisa di akses ketika ada data
				if(!isEmpty(L)){
					printf("\n\t Nama Belanjaan yang ingin dihapus: %s ",display.namaBelanjaan);
					before = findNode(L, display.namaBelanjaan);
					
					if(before==NULL){
						printf("\n\t [!] Nama Belanjaan tidak ditemukan [!]");
						break;
					}
					
					printf("\n\t[!] Yakin ingin Menghapus Belanjaan %s? [Y/N]",before->k.namaBelanjaan);
					printf("\n\t>>> ");menu = getche();
					
					if(menu != 'y'&& menu != 'Y'){
						printf("\n\t[!] Tidak Jadi Bayar Data Belanjaan [!]");
						break;
					}else{
						printf("\n\t [!] Belanjaan %s telah dihapus [!]",before->k.namaBelanjaan);
						insertLast(&history, alokasi(before->k));//memasukan kedalam history 
						if(before == L.first){
							deleteFirst(&L);
						}else if(before->next==NULL){
							deleteLast(&L);
						}else{
							deleteAt(&L,before);
						}

						if(!isEmpty(L)){
							display = alokasiData(L.first->k.namaBelanjaan,L.first->k.tipeBelanjaan, L.first->k.beratBelanjaan, L.first->k.hargaBelanjaan);
						}else{
							display = alokasiData("-","-",0,0.0);
						}
					}
				}else{
					printf("\n\t [!] Data Masih Kosong [!]");
				}
				break;
			case '3':
				
				//menghitung data planet
				if(isEmpty(L)){
					printf("\n\t [!] Data Masih Kosong [!]");
				}else{
					printf("\n\t Masukan Nama Belanjaan yang ingin diedit: ");fflush(stdin);gets(nama);
					before = findNode(L,nama);
					if(before==NULL){
						printf("\n\t [!] Data tidak ditemukan [!] ");
						break;
					}
					do{
						//nama
						printf("\n\t Masukan Nama Belanjaan: ");fflush(stdin);gets(nama);
						if(strcmpi(nama,"-")!=0 && strlen(nama)!=0){
							//kondisi nama benar
							break;
						}else{
							//kondisi nama salah
							printf("\n\t [!] Invalid, Nama tidak boleh kosong atau - [!]");
						}
					}while(1);
					do{
						//tipe
						printf("\n\t Masukan Tipe Belanjaan[Sayur|Daging|Bumbu]: ");fflush(stdin);gets(tipe);
						if(strcmpi(tipe,"Sayur")==0||strcmpi(tipe,"Daging")==0||strcmpi(tipe,"Bumbu")==0){
							//kondisi tipe benar
							break;
						}else{
							//kondisi tipe salah
							printf("\n\t [!] Invalid, Tipe hanya bisa Sayur, Daging, atau Bumbu [!]\n");
						}
					}while(1);
					do{
						//berat
						printf("\n\t Masukan Berat Belanjaan: ");scanf("%d",&berat);
						if(berat>=0){
							//kondisi berat benar
							break;
						}else{
							//kondisi berat salah
							printf("\n\t [!] Invalid, Berat Tidak Boleh Lebih Kecil dari 1 [!]");
						}
					}while(1);
					do{
						//harga
						printf("\n\t Masukan Harga Belanjaan: ");scanf("%f",&harga);
						if(harga>=1){
							//kondisi harga benar
							break;
						}else{
							//kondisi harga salah
							printf("\n\t [!] Invalid, Harga Tidak Boleh Lebih Kecil dari 1 [!]");
						}
					}while(1);
					display = alokasiData(nama,tipe,berat,harga);
					//print current data
					EditData(&L,display,before);
					printf("\n\t Berhasil Edit\n");
				}
				break;
			case '4':
				if(isEmpty(L)){
					printf("\n\t [!] Data Kosong, Masukan Data Telebih Dahulu [!]");
					break;
				}
				if(isOneElement(L)){
					printf("\n\t [!] Tidak Bisa Menggeser Karena Data Hanya 1 [!]");
					break;
				}	
				display = geser(L, display);
				printf("\n\t Berhasil geser");
				break;
			case '5':
				if(!isEmpty(history)){
					printHistoryData(history);
				}else{
					printf("\n\t [!] Masukan Data Telebih Dahulu [!]");
				}
				break;
			case '6':
				if(isEmpty(L)){
					printf("\n\t [!] Masukan Data Telebih Dahulu [!]");
				}else if(isOneElement(L)){
					printf("\n\t [!] Tidak Bisa Melakukan Delete Duplikat [!]");
				}else{
					deleteDupliAll(&L);
					printf("\n\t Berhasil Melakukan Delete Duplikat");
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
				printf("\n\n\t Sukses terus Mahasiswa [NAMA PRAKTIKAN] - [NPM]");//Gentry Marvelo Jusuf - 220711878
				break;
			default:
				printf("\n[!] Menu tidak Ditemukan [!]");
				break;

		}
		if(menu!='0') getch();
	}while(menu!='0');
	return 0;
}


