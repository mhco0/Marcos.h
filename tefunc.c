#include "marcos.h"

int main(void){

	int vetor[10]={5,6,7,3,2,1,9,0,4,8};
	int i;

	for(i=0;i<10;i++){
		printf("%d\n",vetor[i] );
	}


	quick_sort(vetor,0,9);
	//merge_sort(vetor,0,9);


	printf("\n");
	for(i=0;i<10;i++){
		printf("%d\n",vetor[i] );
	}

}

