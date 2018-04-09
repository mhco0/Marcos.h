#include "marcos.h"

int main(void){

	TREE * root=NULL;
	TREE * temp=NULL;
	int i;


	for(i=0;i<10;i++){
		root=insert_node(root,i);
	}


	show_tree(root);


	temp=search_tree(root , 10);
	if(temp==NULL){
		puts("nao ta na arvore");
	}else{
		printf("%d\n",temp->val );
	}


}

