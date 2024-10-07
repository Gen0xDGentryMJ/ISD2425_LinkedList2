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

address alokasi(string nama, int stok, string ukuran){
	address temp;
	
	temp = (Baju*) malloc(sizeof(Baju));
	
	strcpy(temp->ukuran,ukuran);
	strcpy(temp->namaBaju,nama);
	temp->stok=stok;
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
int nbList(List L){
	int count=0;
	address p = L.first;
	while(p!=NULL){
		count+=1;
		p = p->next;
	}
	return count;
}

address findNodeBaju(List L, string nama){
	address bantu = L.first;
	while (bantu!=NULL)
	{
		if (strcmpi(bantu->namaBaju, nama)==0){
			return bantu;
		}
		bantu=bantu->next;
	}
	return bantu;
}

void printData(List L){
    address P = L.first;

    int i;
    for(i=0;i<=nbList(L);i++){
    	if(i==0||P==NULL||i==nbList(L)+1){
			printf("\n\t[%d]",i);	
		}else{
			printf("\n\t[%d] %s - %s => %d",i,P->namaBaju,P->ukuran,P->stok);
			P=P->next;
		}
	}
}

void kesimpulan(List L){
	address high = L.first;
	address low = L.first;
	address curr = L.first;
		
	while (curr != NULL) {
        if (curr->stok > high->stok) {
            high = curr; 
        }
        if (curr->stok < low->stok) {
            low = curr;
        }
        curr = curr->next;
    }
	
	printf("\n\tBaju dengan Stok Tertinggi: %s dengan Jumlah sebesar Rp %.02d",high->namaBaju, high->stok);
	printf("\n\tBaju dengan Stok Terendah : %s dengan Jumlah sebesar Rp %.02d",low->namaBaju, low->stok);
}
//BONUS
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
        if (curr->stok > highest->stok) {
            highest = curr; 
            prevHighest = prev;
        }
        if (curr->stok < lowest->stok) {
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

