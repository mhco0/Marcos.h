//Bibliotecas:
#include <stdio.h>	
#include <stdlib.h>
#include <math.h> //-lm


//Listas:
//------------------Estrutura---------------------
typedef struct Lista{

	 //Valores; 

	struct Lista *next;

} LISTA;

typedef struct Playlist{

	//Valores;

	LISTA *album;
	struct Playlist *next;

} PLAYLIST;


typedef struct Fila{
	
	//Valores;

	struct Fila * next;
}FILA;

//---------------------Debug----------------------
void ver_playlist(PLAYLIST *meus_albuns){

	PLAYLIST *cur = NULL;

	cur = meus_albuns->next;

	while (cur != NULL){
		LISTA *cur2 = NULL;

		cur2 = cur->album;

		cur2 = cur2->next;
		while (cur2 != NULL){
			//Valores que voce deseja mostrar
			cur2 = cur2->next;
		}
		cur = cur->next;
	}
}

void ver_fila(FILA *front){
	FILA *cur = NULL;

	cur = front->next;

	while (cur != NULL){
		//Valores que voce deseja mostrar
		cur = cur->next;
	}
}


// Funções de Lista:
//-----------------Insert-List--------------------
LISTA * insert_list(LISTA * head){
	LISTA * cur=head;
	LISTA * new = NULL;

	new=(LISTA*)malloc(sizeof(LISTA));
	if(new==NULL){
		puts("Tivemos um problema ao alocar a memoria");
		exit(0);
	}

	new->next=NULL;

	if(cur->next==NULL){
		cur->next=new;
	}else{
		while(cur->next!=NULL){
			cur=cur->next;
		}
		cur->next=new;
	}

	return head;

}
//------------------------------------------------

//-----------------Remove-List--------------------
LISTA *remove_list(LISTA *head){
	LISTA *old = NULL;
	LISTA *last_old = NULL;
	int rola = 0;

	last_old = head;
	old = head->next;

	while (old != NULL && !rola){
		if (1){//comparação para achar
			rola = 1;
		}else{
			last_old = old;
			old = old->next;
		}
	}

	if (old != NULL){
		last_old->next = old->next;
		free(old);
	}

	return head;
}
//--------------------------------------------

//Funções de Fila:
//------------------Enqueue-------------------
FILA *enqueue(FILA *rear, FILA *front){
	FILA *new = NULL;

	new = (FILA *)malloc(sizeof(FILA));
	if (new == NULL){
		puts("Tivemos problema ao adicionar um elemento na fila");
		exit(1);
	}

	new->next = NULL;

	rear->next = new;

	return new;
}

//--------------------------------------------

//------------Enqueue-Front-------------------
FILA *enqueue_front(FILA *rear){

	FILA *new = NULL;
	FILA *cur = NULL;

	cur = rear;

	new = (FILA *)malloc(sizeof(FILA));
	if (new == NULL){
		puts("Tivemos problema ao adicionar um elemento na fila");
		exit(1);
	}

	new->next = NULL;

	cur->next = new;

	return new;
}
//--------------------------------------------

//------------Empty-Queue-------------------
FILA *empty_queue(FILA *front, FILA **rear){
	FILA *old = NULL;
	FILA *last_old = NULL;

	last_old = front;
	old = front->next;

	while (old != NULL){
		last_old = old;
		old = old->next;
		free(last_old);
	}

	front->next = NULL;

	(*(rear)) = front;

	return front;
}
//-------------------------------------------

//Ordenação:
//----------------Insertion---------------------
void insertion_sort(int * vet , int tam){
	int var;
	int i,j;

	for(i=1;i<tam;i++){
		var=vet[i];
		j=i-1;

		while(j>=0 && vet[j]>=var){
			vet[j+1]=vet[j];
			j--;
		}

		vet[j+1]=var;

	}


}
//----------------------------------------------

//-----------------Merge------------------------
void merge(int * array,int inicio,int meio,int fim){
	int * esquerda=NULL;
	int * direita=NULL;

	int tam_esq=(meio-inicio+1);
	int tam_dir=(fim-meio);

	int i,j,k,l;
	int maior=0;

	for(l=inicio;l<=fim;l++){
		if(l==0){
			maior=array[l];
		}

		if(array[l]>maior){
			maior=array[l];
		}
	}

	esquerda=(int*)malloc((tam_esq+1)*sizeof(int));
	if(esquerda==NULL){

		puts("tivemos um erro ao alocar espaco na memoria");
		exit(0);

	}

	direita=(int*)malloc((tam_dir+1)*sizeof(int));
	if(direita==NULL){

		free(esquerda);

		puts("tivemos um erro ao alocar espaco na memoria");
		exit(0);

	}

	for(i=0;i<tam_esq;i++){
		esquerda[i]=array[inicio+i];
	}

	for(j=0;j<tam_dir;j++){
		direita[j]=array[meio+j+1];
	}


	esquerda[tam_esq]=maior;
	direita[tam_dir]=maior;

	i=0;
	j=0;

	for(k=inicio;k<=fim;k++){
		if(esquerda[i]<=direita[j]){
			array[k]=esquerda[i];
			i++;
		}else{
			array[k]=direita[j];
			j++;
		}
	}

	free(esquerda);
	free(direita);

}


void merge_sort(int * array ,int inicio, int parada){//indice dos elementos

	int meio;

	if(inicio < parada){
		meio=floor(((inicio+parada)/2));

		merge_sort(array,inicio,meio);
		merge_sort(array,meio+1,parada);
		merge(array,inicio,meio,parada);

	}


}
//------------------------------------------
//--------------Bubble-Sort-----------------

void bubble_sort(int * vetor,int tam ){
	int i,j;

	do{
	 	j=0;

		for(i=0;i<tam-2;i++){

			if(vetor[i]>vetor[i+1]){
				int aux;
				aux=vetor[i];
				vetor[i]=vetor[i+1];
				vetor[i+1]=aux;

				j=1;
			}

		}

	}while(j);


}

//------------------------------------------

//Busca:
//--------------Binary-Search---------------
int binary_search(int * vector,int key, int tam){
	int inicio=0;
	int fim=tam-1;
	int meio;

	do{
		meio=floor((fim+inicio)/2);

		if(vector[meio]==key){
			return meio;
		}else if(vector[meio]<key){
			inicio=meio+1;
		}else{
			fim=meio-1;
		}

	}while(inicio<=fim);

	return -1;

}
//------------------------------------------
