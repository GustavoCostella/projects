#include <stdio.h>
#include <stdlib.h>

struct SList {
  int value;
  struct SList *next;
  struct SList *previous;
  	
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
TList *insertValue(TList *h,int vl)
{
    TList *new, *aux;
    new=(TList *)malloc(sizeof(TList));
    new->value=vl;
    new->next=NULL;
    new->previous=NULL;
    if (h==NULL) // lista vazia
    {
		return new;
    }
    aux=h; // aux recebe o endereço da cabeça da lista (primeiro)
    while (aux->next!=NULL) 
		aux=aux->next;
	aux->next=new;
	new->previous=aux;
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


void updateList(TList *h, int vo, int vn)
{
	TList *aux=findValue(h,vo);
	if (aux==NULL)
	{
		printf("Valor %d não existe!\n",vo);
		return;
	}
	aux->value=vn;
}

TList *deleteValue(TList *h, int vl)
{
	TList *previous=NULL,*current=h;
	if (h==NULL) return NULL; // lista vazia
	while (current->next!=NULL)
	{
		if (current->value==vl)
		{
			if (current==h)
			{
				h=current->next;
				free(current);
				return h;
			}
			previous->next=current->next;
			free(current);
			return h;
	    }
		previous=current;
		current=current->next;
    }
    if (current==h)
    {
		free(current);
		return NULL;
	}
	previous->next=NULL;
	free(current);
	return h;
}

void reverse(TList *p){
	if(p==NULL) return;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	while(p!=NULL){
		printf("%d\n",p->value);
		p=p->previous;
	}
}

int main()
{
    TList *mylist=NULL, *head=NULL;
    int op=1, vl,vold,vnew;
    while (op!=0)
    {
		printf("\n1 - Insere\n2 - Procura\n3 - Lista Todos\n4 - Limpa Lista\n5 - Atualiza\n6 - Exclui Elemento\n7 - Imprime ao contrario\n0 - Sai: ");
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
			continue;
		}
		if (op==5)
		{
			printf("Valor antigo: "); scanf("%d",&vold);
			printf("Valor   novo: "); scanf("%d",&vnew);
			updateList(head,vold,vnew);
			continue;
		}
		if (op==6)
		{
			printf("Valor a ser excluído: "); scanf("%d",&vl);
			head=deleteValue(head,vl);
			continue;
		}
		if(op==7)
		{
			reverse(head);
			continue;
		}
    }
    return 0;
}