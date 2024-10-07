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
void printData(List L){
	
}

