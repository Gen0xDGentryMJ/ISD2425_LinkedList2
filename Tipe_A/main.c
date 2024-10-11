#include "header.h"

int main(int argc, char *argv[]) {
	List L, history;
	char menu;
	string nama, status, temp;
	int jarak, bil;
	address before;

	createEmpty(&L);
	createEmpty(&history);

	do{
		system("cls");
		printData(L);
		printf("\n\n\t[Menu Angkasa AtmaCorp]\n");
		printf("\n\t[1]. Input Planet");
		printf("\n\t[2]. Hitung Data");
		printf("\n\t[3]. Hapus Planet");
		printf("\n\t[4]. Kesimpulan");
		printf("\n\t[5]. History Planet");
		printf("\n\t------------------------------");
		printf("\n\t[6]. Reverse List [Bonus]");//reverse list, mengreverse list yang telah dibuat
		printf("\n\t[7]. Swap Dari Jarak [Tugas]");//Swap jarak terpendek dengan jarak terpanjang
		
		printf("\n\t[0]. Keluar");
		printf("\n\t>>> ");menu = getche();

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
					printf("\n\tMasukan Nama Planet: ");fflush(stdin);gets(nama);
					if(strcmpi(nama,"-")!=0 && strlen(nama)!=0){
						//kondisi nama benar
						break;
					}else{
						//kondisi nama salah
						printf("\n\t[!] Invalid, Nama tidak boleh Kosong atau - [!]");
					}
				}while(1);
				do{
					//jarak
					printf("\n\tMasukan Jarak Planet Dari Bumi: ");scanf("%d",&jarak);
					if(jarak>0){
						//kondisi jarak benar
						break;
					}else{
						//kondisi jarak salah
						printf("\n\t[!] Invalid, Jarak Tidak Boleh Lebih Kecil dari 1 [!]");
					}
				}while(1);
				do{
					//status
					printf("\n\tMasukan Status Planet[Aman|Bahaya|Mematikan]: ");fflush(stdin);gets(status);
					if(strcmpi(status,"aman")==0||strcmpi(status,"bahaya")==0||strcmpi(status,"mematikan")==0){
						//kondisi status benar
						break;
					}else{
						//kondisi status salah
						printf("\n\t[!] Invalid, Status hanya bisa [Aman], [Bahaya], atau [Mematikan] [!]");
					}
				}while(1);
				
				if(bil==0){
					insertFirst(&L,alokasi(nama, jarak, status));
					printf("\n\tData Inserted");
				}else if(!isEmpty(L)&&nbList(L)>1&&bil<nbList(L)){
					printf("\n\tNama Planet yang ingin disisipkan: "); fflush(stdin); gets(temp);
					address before = findNodePlanet(L, temp);
					if(strlen(temp)==0||before==NULL){
						printf("\n\tInvalid Insert");
						break;
					}else{
						insertAfter(before, alokasi(nama, jarak, status));
						printf("\n\tData Inserted");
					}
				}else{
					insertLast(&L, alokasi(nama, jarak, status));
					printf("\n\tData Inserted");
				}
				break;
			case '2':
				//menghitung data planet beserta biaya pergi
				printf("\n\tAda %d Data",nbList(L));
				break;
			case '3':
				//hanya bisa di akses ketika ada planet
				if(!isEmpty(L)){
					printf("\n\tNama Planet yang ingin dihapus: ");fflush(stdin);gets(nama);
					before = findNodePlanet(L, nama);
					
					if(before==NULL){
						printf("\n\t[!] Nama Planet tidak ditemukan [!]");
						break;
					}
					
					printf("\n\t[!] Yakin ingin menghapus Planet %s? [Y/N]",before->namaPlanet);
					printf("\n\t>>> ");scanf("%c",&menu);
					
					if(menu == 'y'|| menu == 'Y'){
						printf("\n\t[!] Planet %s telah di hapus [!]",before->namaPlanet);
						insertLast(&history,alokasi(before->namaPlanet,before->jarakDariBumi,before->status));
						// printf("\nada error data");

						if(before == L.first){
							deleteFirst(&L);
							// printf("\nada error data1");
						}else if(before->next==NULL){
							deleteLast(&L);
							// printf("\nada error data3");
						}else{
							deleteAt(&L,before);
							// printf("\nada error data2");
						}
					}else{
						printf("\n\t[!] Tidak Jadi Delete Data Planet [!]");
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
				printf("\n\n\tConnection Lost User [NAMA PRAKTIKAN] - [NPM]");//Gentry Marvelo Jusuf - 220711878
				break;
			default:
				printf("\n\t[!] Menu tidak Ditemukan [!]");
				break;

		}getch();
	}while(menu!='0');
	return 0;
}

