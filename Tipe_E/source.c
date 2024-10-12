#include "header.h"

void createEmpty(List *L){//done
	L->first = NULL;
}
bool isEmpty(List L){//done
	return L.first == NULL;
}
bool isOneElement(List L){//done
    return !isEmpty(L)&&L.first->next==NULL;
}
Data alokasiData(string nama, string tipe, int berat, float harga){//done
	Data data;
	strcpy(data.namaBelanjaan,nama);
	strcpy(data.tipeBelanjaan,tipe);
	data.beratBelanjaan=berat;
	data.hargaBelanjaan=harga;
	return data;
}

address alokasi(Data data){//done
	address temp;
	temp = (Belanja*) malloc(sizeof(Belanja));
	temp->k= data;
	temp->next=NULL;
	
	return temp;
}

void insertFirst(List *L, address newNode){//done
	newNode->next = L->first;
	L->first = newNode;
}
void insertLast(List *L, address newNode){//done
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
void insertAfter(address before, address newNode){//done
    if(before!=NULL){
        newNode->next = before->next;
        before->next = newNode;
    }
}
void deleteFirst(List *L){//done
    if(!isEmpty(*L)){
        address del = (*L).first;
        (*L).first = (*L).first->next;
        free(del);
    }

}
void deleteAt(List *L, address del){//done
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
void deleteLast(List *L){//done
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



address findNode(List L, string nama){//done
	address bantu = L.first;
	while (bantu!=NULL)
	{
		if (strcmpi(bantu->k.namaBelanjaan, nama)==0){
			return bantu;
		}
		bantu=bantu->next;
	}
	return bantu;
}

void printData(List L, Data d){//done
    address P = L.first;

    int i;
    for(i=0;i<=nbList(L);i++){
    	if(i==0||P==NULL||i==nbList(L)+1){
			printf("\n\t[%d]",i);	
		}else{
			printf("\n\t[%d] %s - %s - %.2dkg => Rp. %0.2f",i,P->k.namaBelanjaan,P->k.tipeBelanjaan,P->k.beratBelanjaan,P->k.hargaBelanjaan);
			if(strcmpi(P->k.namaBelanjaan, d.namaBelanjaan)==0){
				printf("  -= Current Data =- ");
			}
			P=P->next;
		}
	}
}

void printHistoryData(List L){//done
	address temp = L.first;
	if(isEmpty(L)){
		printf("\n\t[!]Data Masih Kosong[!]");
	}else{
		int i=1;
		printf("\n\t[List]");
		for(temp = L.first;temp!=NULL;i++){
			if(i%5==0){
				printf("\n\t");
			}
			printf("[%s - %s - %0.2d - %0.2f]->", temp->k.namaBelanjaan,temp->k.tipeBelanjaan,temp->k.beratBelanjaan,temp->k.hargaBelanjaan);
			temp = temp->next;
		}
		printf("[NULL]");
		
	}
}

Data geser(List L, Data d){
	address temp = findNode(L,d.namaBelanjaan);
	
	if (temp->next!=NULL){
		temp = temp->next;
		strcpy(d.namaBelanjaan, temp->k.namaBelanjaan);
		strcpy(d.tipeBelanjaan, temp->k.tipeBelanjaan);
		d.beratBelanjaan = temp->k.beratBelanjaan;
		d.hargaBelanjaan = temp->k.hargaBelanjaan;
	}else{
		strcpy(d.namaBelanjaan, L.first->k.namaBelanjaan);
		strcpy(d.tipeBelanjaan, L.first->k.tipeBelanjaan);
		d.beratBelanjaan = L.first->k.beratBelanjaan;
		d.hargaBelanjaan = L.first->k.hargaBelanjaan;
	}
	return d;
}
void EditData(List *L, Data k, address before){//done
	address temp = L->first;
	if(isEmpty(*L)){
		printf("\n\t[!]Data Masih Kosong[!]");
	}else{
		while(temp!=NULL){
			if(temp == before){
				break;
			}
			temp = temp->next;
		}
		temp->k = k;
	}
}
int nbList(List L){//done
	int count=0;
	address p = L.first;
	while(p!=NULL){
		count+=1;
		p = p->next;
	}
	return count;
}

//BONUS
void deleteDupliAll(List *L){//done
	address temp = L->first;
	address nextTemp = NULL;
	for(temp = L->first;temp!=NULL;temp = temp->next){
		for(nextTemp = temp->next; nextTemp!=NULL; nextTemp=nextTemp->next){
			if(strcmpi(temp->k.tipeBelanjaan,nextTemp->k.tipeBelanjaan)==0&&strcmpi(temp->k.namaBelanjaan,nextTemp->k.namaBelanjaan)==0&&
			temp->k.beratBelanjaan == nextTemp->k.beratBelanjaan&&temp->k.hargaBelanjaan == nextTemp->k.hargaBelanjaan){
				deleteAt(L,nextTemp);
			}
		}
	}
}

//TUGAS
void swapping1(List *L){//done
	address prevHighest = NULL;
	address prevLowest = NULL;
	
    address highest = L->first;
	address lowest = L->first;
    
	address curr = L->first;
	address prev = NULL;
	
	while (curr != NULL) {
        if (curr->k.beratBelanjaan > highest->k.beratBelanjaan) {
            highest = curr; 
            prevHighest = prev;
        }
        if (curr->k.beratBelanjaan < lowest->k.beratBelanjaan) {
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


