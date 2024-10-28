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


address alokasi(int nomor, string tipe, float harga, int kapasitas){
	address temp;
	temp = (Gerbong*) malloc(sizeof(Gerbong));
	
	temp->nomorGerbong = nomor;
	strcpy(temp->tipeGerbong,tipe);
	temp->hargaTiket = harga;
	temp->kapasitas = kapasitas;
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
address findNode(List L, string tipe, int nomor){
	address temp;
	for(temp = L.first; temp!=NULL; temp=temp->next){
		if(strcmpi(temp->tipeGerbong, tipe)==0 && temp->nomorGerbong == nomor){
			return temp;
		}
	}
	return temp;
	
}

int nbList(List L){
	int count=0;
	address p = L.first;
	while(p!=NULL){
		count+=1;
		p = p->next;
	}
	return count;
}
void EditData(List *L, address before, string tipe, int nomor, float harga, int kapasitas ){//done
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
		temp->hargaTiket = harga;
		temp->nomorGerbong = nomor;
		temp->kapasitas = kapasitas;
		strcpy(temp->tipeGerbong, tipe);
	}
}
void printHistoryData(List L){//done
	address temp = L.first;
	if(isEmpty(L)){
		printf("\n\t[!]Data Masih Kosong[!]");
	}else{
		int i=1;
		printf("\n\t[List] ");
		for(temp = L.first;temp!=NULL;i++){
			if(i%5==0){
				printf("\n\t");
			}
			printf("[%s - %d - %0.2d - Rp. %0.2f]->", temp->tipeGerbong,temp->nomorGerbong,temp->kapasitas,temp->hargaTiket);
			temp = temp->next;
		}
		printf("[NULL]");
		
	}
}

void printData(List L){//done
    address temp = L.first;

    int i;
    for(i=0;i<=nbList(L);i++){
    	if(i==0||temp==NULL||i==nbList(L)+1){
			printf("\n\t[%d]",i);	
		}else{
			printf("\n\t[%d] %s - %d - %.2d => Rp. %0.2f",i,temp->tipeGerbong,temp->nomorGerbong,temp->kapasitas,temp->hargaTiket);
			
			temp=temp->next;
		}
	}
}

//BONUS
// void deleteDupliAll(List *L){//done
// 	address temp = L->first;
// 	address nextTemp = NULL;
// 	for(temp = L->first;temp!=NULL;temp = temp->next){
// 		for(nextTemp = temp->next; nextTemp!=NULL; nextTemp=nextTemp->next){
// 			if(strcmpi(temp->tipeGerbong,nextTemp->tipeGerbong)==0&&
// 			temp->hargaTiket == nextTemp->hargaTiket&&
// 			temp->kapasitas ==
// 			 nextTemp->kapasitas&&
// 			temp->nomorGerbong == nextTemp->nomorGerbong){
// 				deleteAt(L, nextTemp);
// 			}
// 		}
// 	}
// }
address ReverseList(List L){
	address prev = NULL;
	address next = NULL;
	address curr = L.first;
	
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
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
        if (curr->kapasitas > highest->kapasitas) {
            highest = curr; 
            prevHighest = prev;
        }
        if (curr->kapasitas < lowest->kapasitas) {
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
