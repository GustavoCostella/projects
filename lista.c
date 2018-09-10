#include <stdio.h>
#include <stdlib.h>

struct tlist{
	int value;
	struct tlist *next;
};

int main(){
	struct tlist *mylist, *first;
	int s;
	do{
	printf("1 -- Adicionar valor --\n");
	printf("2 -- Parar -- \n");
	printf("3 -- Imprimir valores -- \n");
	printf("0 -- Sair --\n");
	switch(s){
		case 1:
		mylist = (struct tlist *)malloc(sizeof(struct tlist));
		printf("Informe o numero: \n");
		scanf("%d",&mylist-> value);
		case 2:	
		mylist->next = NULL;
		printf("VALORES ALOCADOS\n");
		case 3:
		


		
	}


		
	}while(s != 0);
	return 0;
}