//Bibliotecas:
#include <stdio.h>	
#include <stdlib.h>
#include <math.h> //-lm


//Listas:
//------------------Estrutura---------------------
typedef struct Lista{

	 //Valores ; 

	struct Lista *next;

} LISTA;

typedef struct Playlist{

	//Valores ;

	LISTA *album;
	struct Playlist *next;

} PLAYLIST;

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

//-----------------Insert-List--------------------



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