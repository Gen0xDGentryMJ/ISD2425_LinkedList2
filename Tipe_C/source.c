#include "header.h"

void createEmpty(List *L){
	L->first = NULL;
}
bool isEmpty(List L){
	return L.first == NULL;
}
bool isOneElement(List L){
    return !isEmpty(L)&&L.first->next==NULL;
}
Data alokasiData(string nama, string kode, int berat, float harga){
	Data data;
	strcpy(data.namaSenyawa,nama);
	strcpy(data.kodeSenyawa,kode);
	data.berat=berat;
	data.hargaSenyawa=harga;
	return data;
}

address alokasi(Data data){
	address temp;
	temp = (BahanKimia*) malloc(sizeof(BahanKimia));
	temp->k= data;
	temp->next=NULL;
	
	return temp;
}

void insertFirst(List *L, address newNode){
	newNode->next = L->first;
	L->first = newNode;
}
void insertLast(List *L, address newNode){
	address temp = L->first;
	if(isEmpty(*L)){
		insertFirst(&(*L), newNode);
	}else{
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
void insertAfter(address before, address newNode){
    if(before!=NULL){
        newNode->next = before->next;
        before->next = newNode;
    }
}
void deleteFirst(List *L){
    if(!isEmpty(*L)){
        address del = (*L).first;
        (*L).first = (*L).first->next;
        free(del);
    }

}
void deleteAt(List *L, address del){
    address P;
    if(!isEmpty(*L)){
        if((*L).first==del){
            deleteFirst(L);
        }else{
            P=(*L).first;
            while(P->next!=del){
                P = P->next;
            }
            P->next = del->next;
            free(del);
        }
    }
}
void deleteLast(List *L){
    address P;
    if(!isEmpty(*L)){
        if(isOneElement(*L)){
            deleteFirst(L);
        }else{
            for(P=(*L).first;P->next->next!=NULL;P=P->next);
            free(P->next);
            P->next = NULL;
        }
    }
}

// int nbList(List L){
// 	int count=0;
// 	address p = L.first;
// 	while(p!=NULL){
// 		count+=1;
// 		p = p->next;
// 	}
// 	return count;
// }
int findInsert(List L, Data data){
	address temp = L.first;
	//1-> data paling kecil 
	if(temp->k.berat>data.berat&&temp == L.first){
		return 0;
	}

	while(temp->next!=NULL){	
		temp = temp->next;
	}
	
	if(temp->k.berat<data.berat){
		return 2;
	}else{
		return 1;
	}
}

address findNode(List L, string nama){
	address bantu = L.first;
	while (bantu!=NULL)
	{
		if (strcmpi(bantu->k.namaSenyawa, nama)==0){
			return bantu;
		}
		bantu=bantu->next;
	}
	return bantu;
}

void printData(List L){
    address P = L.first;
	printf("\n\t[First]->");
	int i=0;
    while(P!=NULL){
    	if(i%5==0&&i!=0){
    		printf("\n\t");
		}
		printf("[%s]-> ",P->k.kodeSenyawa);
    	P=P->next;
    	i++;
	}
	printf("NULL");
	
}
Data geser(List L, Data d){
	address temp = L.first;
	while (temp!=NULL){
		if(strcmpi(temp->k.namaSenyawa, d.namaSenyawa)==0){
			if (temp->next!=NULL){
				/*
				misal data
				1
				2 -> current temp.k.namasenyawa == d.namaSenyawa
				3 
				*/
				temp = temp->next;
				/*
				misal data
				1
				2 d.namaSenyawa
				3 -> current temp
				*/
				strcpy(d.namaSenyawa, temp->k.namaSenyawa);
				strcpy(d.kodeSenyawa, temp->k.kodeSenyawa);
				d.berat = temp->k.berat;
				d.hargaSenyawa = temp->k.hargaSenyawa;
				/*
				misal data
				1
				2 
				3 -> current temp.k.namasenyawa == d.namaSenyawa
				*/
			}else{
				strcpy(d.namaSenyawa, L.first->k.namaSenyawa);
				strcpy(d.kodeSenyawa, L.first->k.kodeSenyawa);
				d.berat = L.first->k.berat;
				d.hargaSenyawa = L.first->k.hargaSenyawa;
			}
		}
		temp = temp->next;
	}
	return d;
}
void printCurrData(List L, Data k){
	address temp = L.first;
	if(isEmpty(L)){
		printf("\n\t[!]Data Masih Kosong[!]");
	}else{
		printf("\n\tNama Senyawa: %s", k.namaSenyawa);
		printf("\n\tKode Senyawa: %s", k.kodeSenyawa);
		printf("\n\tHarga Senyawa: Rp %.2f ", k.hargaSenyawa);
		printf("\n\tBerat Senyawa: %0.2dg",k.berat);
		while (temp!=NULL){
			if(strcmpi(temp->k.namaSenyawa, k.namaSenyawa)!=0){
				printf("\n\tNama Senyawa: %s", temp->k.namaSenyawa);
				printf("\n\tKode Senyawa: %s", temp->k.kodeSenyawa);
				printf("\n\tHarga Senyawa: Rp %.2f ", temp->k.hargaSenyawa);
				printf("\n\tBerat Senyawa: %0.2d g",temp->k.berat);
			}
			temp = temp->next;
		}
		
	}
}
void printHistoryData(List L){
	address temp = L.first;
	if(isEmpty(L)){
		printf("\n\t[!]Data Masih Kosong[!]");
	}else{
		int i=1;
		printf("\n\t[List]->");
		for(temp = L.first;temp!=NULL;i++){
			if(i%5==0){
				printf("\n\t->");
			}
			printf("[%s-%s-%0.2dg-Rp %.2f]->", temp->k.namaSenyawa,temp->k.kodeSenyawa,temp->k.berat,temp->k.hargaSenyawa);
			temp = temp->next;
		}
		printf("[NULL]");
		
	}
}

//BONUS
void deleteDupliAll(List *L){
	address temp = L->first;
	while(temp!=NULL){
		if(strcmpi(temp->k.kodeSenyawa,temp->next->k.kodeSenyawa)==0&&strcmpi(temp->k.namaSenyawa,temp->next->k.namaSenyawa)==0){
			
			address toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete); 
		}else{
			temp=temp->next;
		}
	}
}

//TUGAS
void swapping1(List *L){
	address prevHighest = NULL;
	address prevLowest = NULL;
	
    address highest = L->first;
	address lowest = L->first;
    
	address curr = L->first;
	address prev = NULL;
	
	while (curr != NULL) {
        if (curr->k.berat > highest->k.berat) {
            highest = curr; 
            prevHighest = prev;
        }
        if (curr->k.berat < lowest->k.berat) {
            lowest = curr;
            prevLowest = prev;
        }
        prev = curr; 
        curr = curr->next;
    }
   
	
	if (highest == L->first) {
        L->first = lowest;
    } else if (lowest == L->first) {
        L->first = highest;
    }
	
	if(prevHighest == lowest){
		//berarti lowest bersebelahan sebelum highest
		address temp = highest->next;
	    highest->next = lowest->next;
	    lowest->next = temp;
		highest->next = lowest;
		if (prevLowest != NULL) {
        	prevLowest->next = highest;
    	}
	}else if(prevLowest == highest){
		//berarti lowest bersebelahan sebelum highest
		address temp = highest->next;
	    highest->next = lowest->next;
	    lowest->next = temp;
		lowest->next = highest;
		if (prevHighest != NULL) {
        	prevHighest->next = lowest;
    	}
	}else{
		// menukar pointer
	    address temp = highest->next;
	    highest->next = lowest->next;
	    lowest->next = temp;
		
	    if (prevHighest != NULL) prevHighest->next = lowest;
	    if (prevLowest != NULL) prevLowest->next = highest;
    	
	}
	
    
}

