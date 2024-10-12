#include "header.h"

int main(int argc, char *argv[]) {
	List L, history;
	Data display;
	string nama, kode;
	int berat;
	float harga;

	address before;
	string temp;
	
	
	int bil;
	char menu;
	display = alokasiData("-","-",0,0.0);
	createEmpty(&L);
	createEmpty(&history);
	do{
		system("cls");
		printData(L);
		// printf("\n\n\t [Current Data: ]");
		
		// if(display.berat != 0){
		// 	printf("\n\t Nama Senyawa: %s", display.namaSenyawa);//string nama
		// 	printf("\n\t Kode Senyawa: %s", display.kodeSenyawa);//string -> padat/cair/gas
		// 	printf("\n\t Harga Senyawa: Rp %.2f ", display.hargaSenyawa);//float harga
		// 	printf("\n\t Berat Senyawa: %0.2dg",display.berat);//int berat per gram
		// }else{
		// 	printf("\n\t [!] Belum ada data [!]");
		// }

		printf("\n\n\t [Menu Lab Kimia Atmarium]\n");
		printf("\n\t [1]. Input Senyawa");
		printf("\n\t [2]. Hapus Senyawa");
		printf("\n\t [3]. Edit data");
		printf("\n\t [4]. Next");
		printf("\n\t [5]. History Senyawa");
		printf("\n\t ------------------------------");
		printf("\n\t [6]. Delete Semua Duplikat [Bonus]");//delete duplicate 
		printf("\n\t [7]. Swap Dari Berat [Tugas]");//Swap Berat tertinggi dengan Berat terendah
		
		printf("\n\t [0]. Keluar");
		printf("\n\t >>> ");menu = getche();
		switch(menu){
			case '1':
				//input berdasarkan jarak
				system("cls");
				printData(L);
				printf("\n\n\tData ingin dimasukan di urutan : ");scanf("%d",&bil);//inputan berdasarkan urutan
				
				if(bil<0||bil>nbList(L)+1){
					printf("\n\tUrutan Tidak Valid");
					break;
				}

				do{
					//nama
					printf("\n\t Masukan Nama Senyawa: ");fflush(stdin);gets(nama);
					if(strcmpi(nama,"-")!=0 && strlen(nama)!=0){
						//kondisi nama benar
						break;
					}else{
						//kondisi nama salah
						printf("\n\t [!] Invalid, Nama tidak boleh kosong atau - [!]");
					}
				}while(1);
				do{
					//kode
					printf("\n\t Masukan Kode Senyawa: ");fflush(stdin);gets(kode);
					if(strcmpi(kode,"padat")==0||strcmpi(kode,"cair")==0||strcmpi(kode,"gas")==0){
						//kondisi kode benar
						break;
					}else{
						//kondisi kode salah
						printf("\n\t [!] Invalid, Kode hanya bisa Padat, Cair, atau Gas [!]\n");
					}
				}while(1);
				do{
					//berat
					printf("\n\t Masukan Berat Senyawa: ");scanf("%d",&berat);
					if(berat>0){
						//kondisi berat benar
						break;
					}else{
						//kondisi berat salah
						printf("\n\t [!] Invalid, Berat Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);
				do{
					//harga
					printf("\n\t Masukan Harga Senyawa: ");scanf("%f",&harga);
					if(harga>=1){
						//kondisi harga benar
						break;
					}else{
						//kondisi harga salah
						printf("\n\t [!] Invalid, Harga Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);

				display = alokasiData(nama,kode,berat,harga);
				

				//autosorted linked list
				if(bil==0){
					insertFirst(&L,alokasi(alokasiData(nama, kode, berat, harga)));
				}else if(!isEmpty(L)&&nbList(L)>1&&bil<nbList(L)){
					printf("\n\t Nama Senyawa yang ingin disisipkan: "); fflush(stdin); gets(temp);
					address before = findNode(L, temp);
					if(strlen(temp)==0||before==NULL){
						printf("\n\t Invalid Insert");
						break;
					}else{
						insertAfter(before, alokasi(alokasiData(nama, kode, berat, harga)));
						printf("\n\t Data Inserted");
					}
				}else if(bil == 2){
					insertLast(&L, alokasi(alokasiData(nama, kode, berat, harga)));
				}
				printf("\n\t Data Inserted");
				break;

			case '2':
				//hanya bisa di akses ketika ada data
				if(!isEmpty(L)){
					printf("\n\t Nama Senyawa yang ingin dihapus: ");fflush(stdin);gets(nama);
					before = findNode(L, nama);
					
					if(before==NULL){
						printf("\n\t [!] Nama Senyawa tidak ditemukan [!]");
						break;
					}
					
					printf("\n\t [!] Yakin ingin menghapus Senyawa %s? [Y/N]",before->k.namaSenyawa);
					printf("\n\t >>> ");menu = getche();
					
					if(menu == 'y'|| menu == 'Y'){
						printf("\n\t [!] Senyawa %s telah di hapus [!]",before->k.namaSenyawa);
						insertLast(&history, alokasi(before->k));//memasukan kedalam history 
						if(before == L.first){
							deleteFirst(&L);
						}else if(before->next==NULL){
							deleteLast(&L);
						}else{
							deleteAt(&L,before);
						}
						if(isEmpty(L)){
							display = alokasiData("-","-",0,0.0);
						}else{
							display = alokasiData(L.first->k.namaSenyawa,L.first->k.kodeSenyawa, L.first->k.berat, L.first->k.hargaSenyawa);
						}
					}else{
						printf("\n\t [!] Tidak Jadi Delete Data Senyawa [!]");
					}
				}else{
					printf("\n\t [!] Data Masih Kosong [!]");
				}
				break;
			case '3'://done
				//hanya bisa di akses minimal 1 data
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
						printf("\n\t Masukan Nama Senyawa: ");fflush(stdin);gets(nama);
						if(strcmpi(nama,"-")!=0 && strlen(nama)!=0){
							//kondisi nama benar
							break;
						}else{
							//kondisi nama salah
							printf("\n\t [!] Invalid, Nama tidak boleh kosong atau - [!]");
						}
					}while(1);
					do{
						//kode
						printf("\n\t Masukan Kode Senyawa: ");fflush(stdin);gets(kode);
						if(strcmpi(kode,"padat")==0||strcmpi(kode,"cair")==0||strcmpi(kode,"gas")==0){
							//kondisi kode benar
							break;
						}else{
							//kondisi kode salah
							printf("\n\t [!] Invalid, Kode hanya bisa Padat, Cair, atau Gas [!]\n");
						}
					}while(1);
					do{
						//berat
						printf("\n\t Masukan Berat Senyawa: ");scanf("%d",&berat);
						if(berat>0){
							//kondisi berat benar
							break;
						}else{
							//kondisi berat salah
							printf("\n\t [!] Invalid, Berat Tidak Boleh Lebih Kecil dari 1 [!]");
						}
					}while(1);
					do{
						//harga
						printf("\n\t Masukan Harga Senyawa: ");scanf("%f",&harga);
						if(harga>=1){
							//kondisi harga benar
							break;
						}else{
							//kondisi harga salah
							printf("\n\t [!] Invalid, Harga Tidak Boleh Lebih Kecil dari 1 [!]");
						}
					}while(1);
					display = alokasiData(nama,kode,berat,harga);
					//print current data
					EditData(&L,display,before);
					printf("\n\t Berhasil Edit\n");	
				}
				break;
			case '4':
				//hanya bisa di akses minimal 1 data
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

