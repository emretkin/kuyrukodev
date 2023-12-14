#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node {
  int data;
  struct node* next;
};
static int boyut=0;
struct node* front=NULL;
struct node* temp=NULL;
struct node* rear=NULL;

void ekle(int id){
	struct node* new=(struct node*)malloc(sizeof(struct node));

	new->data=id;
	new->next=NULL;
	switch(id){
		
	case 1:
	if(front==NULL){
	front=new;
	rear=new;
    boyut++;
    }
	else{
	rear->next=new;
	rear=new;	
	boyut++;
	}
    break;
	
    case 2:
  	if(front==NULL){
	front=new;
	rear=new;
    boyut++;
	}
	else if(boyut==1||boyut==2){
	rear->next=new;
	rear=new;	
	boyut++;
	}
	else{
		temp=front->next->next;
		front->next->next=new;
		new->next=temp;
		boyut++;
	}
	break;
	
	case 3:
	if(front==NULL){
	front=new;
	rear=new;
    boyut++;
    }
  	else{
		temp=front;
		new->next=temp;
		front=new;
		boyut++;
	}  
	break;
		
    
}	
}

void cikar(){
	if (front == NULL) {
        printf("S�ra bo�, i�lem yapacak kimse yok.\n");
    }
    else{
    temp=front;
    front=temp->next;
    free(temp);
    boyut--;
    }
}

void yazdir(){
	if (front == NULL) {
    }
    else{
	temp=front;
	while(temp->next!=NULL){
		printf("ID%d=>",temp->data);
		temp=temp->next;
	}
	printf("ID%d\n",temp->data);
		}
}

void main(){
	setlocale(LC_ALL, "Turkish");
	int secim,id;
	while(1){
	printf("Hangi i�lem olsun ?\n\n");
	printf("1.Kuyru�a Girme ��lemi\n");
	printf("2.Kuyruktakini ��leme Alma\n");
	printf("3.Kuyru�u G�r�nt�leme ��lemi\n");
	scanf("%d",&secim);
	
	switch(secim){
	case 1:
	      printf("ID Numaran�z� girin:");
	      scanf("%d",&id);
	      ekle(id);
	      yazdir();
	      break;
	
	case 2:
		 cikar();
		yazdir();
	 
		 break;
		 
	case 3:
	     yazdir();
		 break;
		 	 
	default:
            printf("Hatal� bir se�im yap�ld�.\n");
	}
	}
		}
	
