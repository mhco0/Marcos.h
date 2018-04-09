//Bibliotecas:
#include <stdio.h>	
#include <stdlib.h>
#include <math.h> //-lm
#include <time.h>


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


typedef struct Tree{
	int val;
	struct Tree * left;
	struct Tree * right;
}TREE;

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


//Funções de arvore:
//-----------------New-Node---------------------
TREE * new_node(int val){
	TREE * node =(TREE * ) malloc(sizeof(TREE));
	if(node==NULL){
		puts("Erro ao alocar o node");
		exit(0);
	}

	node->val=val;

	node->left=NULL;

	node->right=NULL;

	return node ;
}
//----------------------------------------------

//----------------Insert-Node------------------
TREE * insert_node(TREE * root , int val){
	if(root==NULL){
		return new_node(val);
	}else if(val>root->val){
		root->right=insert_node(root->right,val);
		return root;
	}else{
		root->left=insert_node(root->left,val);
		return root;
	}
}
//---------------------------------------------

//-----------------Show-Tree-------------------
void show_tree(TREE * root){

	if(root==NULL){
		return ;
	}else{
		show_tree(root->left);
		printf("%d\n",root->val);
		show_tree(root->right);
	}
}
//----------------------------------------------
//----------------Search-Tree-------------------

TREE * search_tree(TREE * root,int val){

	if(root==NULL){
		return NULL;
	}

	if(root->val==val){
		return root;
	}else if(root->val<val){
		return search_tree(root->right,val);
	}else{
		return search_tree(root->left,val);
	}


}

//---------------------------------------------
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
void merge(int * vector, int left , int right , int * aux){
	int i,j,k;
	int mid;

	for(i=left;i<=right;i++){
		aux[i]=vector[i];
	}

	mid=floor((left+right)/2);

	i=left;
	j=mid+1;

	for(k=left;k<=right;k++){
		if(j>right){
			vector[k]=aux[i];
			i++;
		}else if(i>mid){
			vector[k]=aux[j];
			j++;
		}else if(aux[i]<aux[j]){
			vector[k]=aux[i];
			i++;
		}else{
			vector[k]=aux[j];
			j++;
		}
	}
}

void msort(int * vector , int left , int right,int *aux){

	if(left!=right){
		int mid;

		mid=floor((left+right)/2);

		msort(vector,left,mid,aux);
		msort(vector,mid+1,right,aux);
		merge(vector,left,right,aux);
			
	}
}

void merge_sort(int *vector,int left , int right){
	int * aux=NULL;

	aux=(int * )malloc((right+1)*sizeof(int));

	msort(vector,left,right,aux);

	free(aux);
}
//------------------------------------------
//---------------Quick-Sort-----------------
int particion(int * vector, int left , int right){
	int i,j;
	int aux;

	i=left;
	j=right;

	while(i<j){
		while (i<=right && vector[i]<=vector[left]){
			i++;
		}
		while(vector[j]>vector[left]){
			j--;
		}

		if(i<j){
			aux=vector[i];
			vector[i]=vector[j];
			vector[j]=aux;
		}

	}	
	
	aux=vector[left];
	vector[left]=vector[j];
	vector[j]=aux;
	
	return j;

}

void q_sort(int * vector , int left,int right){
	int mid;

	if(left<right){
		mid=particion(vector,left,right);
		q_sort(vector,left,mid-1);
		q_sort(vector,mid+1,right);
	}
}

void quick_sort(int * vector, int left, int right){
	int aux,pivo;
	srand(time(NULL));

	pivo=rand()%right;

	aux=vector[pivo];
	vector[pivo]=vector[left];
	vector[left]=aux;
	
	q_sort(vector,left,right);
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
