#include "header.h"

void createEmpty(List *L){
    (*L).first = NULL;
}
bool isEmpty(List L){
    return L.first == NULL;
}
bool isOneElement(List L){
    return !isEmpty(L)&&L.first->next==NULL;
}
address alokasi(string bahan, string merk, float harga){
    address p;
    p = (node*)malloc(sizeof(node));
    strcpy(p->b.bahan,bahan);
    strcpy(p->b.merk,merk);
    p->b.harga = harga;
    p->next = NULL;
    return p;
}
void insertFirst(List *L, address newNode){
    newNode->next = (*L).first;
    (*L).first = newNode;
}
void insertAfter(address before, address newNode){
    if(before!=NULL){
        newNode->next = before->next;
        before->next = newNode;
    }
}
void insertLast(List *L,address newNode){
    address P;
    if(isEmpty(*L)){
        insertFirst(L,newNode);
    }else{
        for(P=(*L).first;P->next!=NULL;P=P->next);
        P->next = newNode;
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
void printData(List L){
    address P = L.first;
    int i;
    for(i=0;i<=nbList(L)+1;i++){
    	if(i==0||P==NULL||i==nbList(L)+1){
			printf("\n\t[%d]",i);	
		}else{
			printf("\n\t[%d] %s - %s => Rp. %.0f",i,P->b.merk,P->b.bahan,P->b.harga);
			P=P->next;
		}
	}
}

address findNode(List L, int bil){
    address cari=L.first;
    int i;
    for(i=1;i<bil;i++){
    	cari=cari->next;
	}
    return cari;
}
address findMerk(List L, string merk){
    address cari;
    int i;
    cari=L.first;
    for(i=0;i<nbList(L);i++){
    	if(strcmpi(cari->b.merk,merk)==0){
    		break;
		}
    	cari=cari->next;
	}
    return cari;
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
//////////////////////////
address findHighestData(List L){
	address temp=L.first;
	address high;
	float tempharga;
	tempharga = temp->b.harga;
	while(temp->next!=NULL){
		if(tempharga <= temp->next->b.harga){
			tempharga = temp->next->b.harga;
			high = temp->next;
		}
		temp = temp->next;
	}
	return high;
}

address findLowestData(List L){
	address temp=L.first;
	address low=temp;
	
	while(temp->next!=NULL){
		if(temp->b.harga >= temp->next->b.harga){
			low = temp->next;
		}
		temp = temp->next;
	}
	return low;
}
void kesimpulan(List *L){
	address temp, high, low;
	
	temp = (*L).first;
	high = findHighestData((*L));
	low = findLowestData((*L));
	
	
	printf("\n\tBaju dengan harga tertinggi adalah dengan merk : %s",high->b.merk);
//	printf("\n\tBaju dengan harga terendah adalah dengan merk : %s",low->b.merk);
	printf("\n\tMerk baju tersebut sekarang diubah menjadi %s",low->b.merk);
	printf("\n");
	
	if(isOneElement((*L))){
		printf("\n[+] Baju termahal dan termurah, keren banget [+]");
	}else{
		if(low == (*L).first){
			(*L).first = low->next;
		}else{
			while(temp->next!=low){
				temp = temp->next;
			}temp->next=low->next;
		}
		low->next = high->next;
		high->next = low;	
		printf("\n[+] Baju dengan harga terendah sudah dipindah!");
	}
}

//bubble sort
/*
	bajutemp = temp->b;
	temp->b = temp->next->b;
	temp->next->b = bajutemp;
*/



