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

//Data input(string nama, int jarak, string material){
//	Data d;
//	d.jarakDariBumi = jarak;
//	strcpy(d.namaPlanet, nama);
//	strcpy(d.material, material);
//	return d;
//}
address alokasi(string nama, int jarak, string material){
	address temp;
	printf("\ncrashed");
	temp = (Planet*) malloc(sizeof(Planet));
//	temp->data = input(nama, jarak, material);
	strcpy(temp->material,material);
	strcpy(temp->namaPlanet,nama);
	temp->jarakDariBumi=jarak;
	temp->next=NULL;
	printf("\ncrashed");
	return temp;
}

void insertFirst(List *L, address newNode){
	printf("\ncrashed2");
	newNode->next = L->first;
	L->first = newNode;
	printf("\ncrashed3");
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
 
void printData(List L){
    address P = L.first;

    int i;
    for(i=0;i<=nbList(L);i++){
    	if(i==0||P==NULL||i==nbList(L)+1){
			printf("\n\t[%d]",i);	
		}else{
			printf("\n\t[%d] %d - %s => %s",i,P->jarakDariBumi,P->namaPlanet,P->material);
			P=P->next;
		}
	}
}
