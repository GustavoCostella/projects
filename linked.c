#include <stdio.h>
#include <stdlib.h>

struct SList {
  int value;
  struct SList *next;
};

typedef struct SList TList;
//
// Incluindo valor usando a técnica de passar o endereço do ponteiro
// Conhecida como ponteiro de ponteiro (por isso os dois asteriscos)
// Esta função não vai ser utilizada na main
TList *insertValuePP(TList **p, int vl)
{
    TList *new, *aux;
    new=(TList *)malloc(sizeof(TList));
    new->value=vl;
    new->next=NULL;
    if (*p==NULL)
    {
		*p=new;
		return new;
    }	
    aux=*p;
    while (aux->next!=NULL)
		aux=aux->next;
	aux->next=new;
	return new;
}
// Inserção do valor sem utilizar ponteiro de ponteiro
TList *insertValue(TList *h, int vl)
{
    TList *new, *aux;
    new=(TList *)malloc(sizeof(TList));
    new->value=vl;
    new->next=NULL;
    if (h==NULL) // lista vazia
    {
		return new;
    }
    aux=h; // aux recebe o endereço da cabeça da lista (primeiro)
    while (aux->next!=NULL) 
		aux=aux->next;
	aux->next=new;
	return new;
}
//
void deleteList(TList *p)
{
	TList *aux;
	while (p!=NULL)
	{
	   aux=p->next;
	   free(p);
	   p=aux;
    }
}

void showAll(TList *p)
{
	TList *aux;
	while (p!=NULL)
	{
	   aux=p->next;
       printf("%d\n",p->value);
	   p=aux;
    }
}

TList *findValue(TList *p,int vl)
{
	TList *aux;
	//if (p==NULL) return;
	while (p!=NULL)
	{
	   aux=p->next;
	   if (p->value==vl) return p; 
	   p=aux;
    }
	return NULL;
}

void update(TList *p, int Vold, int Vnew){
	TList *aux = findValue(p,Vold);
	if(aux == NULL){
		printf("Valor %d não existe\n",Vold);
		return;
	}
	aux -> value = Vnew;
}
TList *deleteValue(TList *h, int vl){
	TList *previous = NULL, *current = h;
	if(h == NULL) return NULL;
	while(current->next != NULL){
		if(current -> value == vl){
			if (current == h){
				free(current);
				return h;
			}
			previous = current;
			current=current->next;
		}
	}
}

int main()
{
    TList *mylist=NULL, *head=NULL;
    int op=1, vl,nv;
    while (op!=0)
    {
		printf(" 1 - Insere\n 2 - Procura\n 3 - Lista Todos\n 4 - Limpa Lista\n 5 - Atualiza um valor\n 6 - exclui um valor\n 0 - Sai: ");
		scanf("%d",&op);
		if (op==1)
		{
			printf("Valor: ");
			scanf("%d",&vl);
			mylist=insertValue(head,vl);
			if (head==NULL) head=mylist;
			continue;
		}
		if (op==2)
		{
			printf("Valor: ");
			scanf("%d",&vl);
			if (findValue(head,vl)!=NULL)
			   printf("Valor presente na lista!\n");
			else
			   printf("Valor não encontrado na lista!\n");
			continue;
	    }
		if (op==3)
		{
		  showAll(head);
		  continue;
		}
		if (op==4)
		{
			deleteList(head);
			head=NULL; // não esquecer de setar a lista para vazia
		}
		if(op == 5){
			printf("Informe o valor antigo:\n");
			scanf("%d",&vl);
			printf("Informe o valor novo:\n");
			scanf("%d",&nv);
			update(head,vl,nv);
			continue;
		if (op == 6){
			printf("Informe o valor a ser excluido\n");
			scanf("%d",&vl);
			deleteValue(head,vl);	
		}
		}
    }
    return 0;
}