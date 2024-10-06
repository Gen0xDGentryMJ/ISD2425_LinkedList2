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

address alokasi(string nama, int jarak, string status){
	address temp;
	
	temp = (Planet*) malloc(sizeof(Planet));
	
	strcpy(temp->status,status);
	strcpy(temp->namaPlanet,nama);
	temp->jarakDariBumi=jarak;
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

address findNodePlanet(List L, string nama){
	address bantu = L.first;
	while (bantu!=NULL)
	{
		if (strcmpi(bantu->namaPlanet, nama)==0){
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
			printf("\n\t[%d] %d km - %s => %s",i,P->jarakDariBumi,P->namaPlanet,P->status);
			P=P->next;
		}
	}
}

void kesimpulan(List L){
	address high = L.first;
	address low = L.first;
	address curr = L.first;
		
	while (curr != NULL) {
        if (curr->jarakDariBumi > high->jarakDariBumi) {
            high = curr; 
        }
        if (curr->jarakDariBumi < low->jarakDariBumi) {
            low = curr;
        }
        curr = curr->next;
    }
	
	printf("\n\t Planet dengan jarak terjauh dari bumi: %s dengan biaya peluncuran sebesar Rp %.02d",high->namaPlanet, (high->jarakDariBumi * 15));
	printf("\n\t Planet dengan jarak pendek dari bumi %s dengan biaya peluncuran sebesar Rp %.02d",low->namaPlanet, (low->jarakDariBumi * 15));
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
        if (curr->jarakDariBumi > highest->jarakDariBumi) {
            highest = curr; 
            prevHighest = prev;
        }
        if (curr->jarakDariBumi < lowest->jarakDariBumi) {
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


