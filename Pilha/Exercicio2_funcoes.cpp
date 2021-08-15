//*
//*			2) Utilizando o exercicio apresentado, crie um programa que permita a
//*		opera��o com uma pilha numa lista ligada.
//*		com as seguintes op��es de menu:
//*
//*	   - Listar pilha
//*	   - Inserir elemento
//*	   - Obter �ltimo elemento
//*	   - Remover elemento
//*	   - Sair do programa.
//*
//*
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>


//*******************************************************
//* Estrutura de Dados
//*******************************************************
//* Define cada elemento ou n� da estrutura
//********************************************************
typedef struct Elemento {
    int valor;
    struct Elemento * proximo;
};

//*********************************************
//* Vari�veis globais
//*********************************************


//*********************************************
//* Fun��es
//*********************************************
// Lista de Fun��es
//* Fun��o "isEmpty()" 
//*          ->  Verifica se a pilha est� vazia. 
//* Fun��o "peek()"    
//*          ->  Devolve o elemento no topo da pilha.
//* Fun��o "showH()"    
//*          ->  Mostra os elementos da pilha, 
//*              na horizontal.
//* Fun��o "showV()"    
//*          ->  Mostra os elementos da pilha, 
//*              na vertical.
//* Fun��o "pop()"
//*          ->  Remove o elemento de topo da pilha. 
//* Fun��o "push()"
//*          ->  Insere um elemento no topo da pilha. 
//***************************************************
int isEmpty(Elemento *);   
int peek(Elemento *);  
void showH(Elemento *); 
void showV(Elemento *);
Elemento * push(Elemento *, int dado); 
int pop(Elemento **); 


//*****************************************************
//* Fun��es
//****************************************************


//****************************************************
//* Fun��o "isEmpty()"
//* ->  Verifica se a pilha est� vazia. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      bool -> true se  a fila est� vazia.
//+              false se a fila n�o est� vazia.
//******************************************************
int isEmpty(Elemento* base) {

   if(base == NULL)
      return 1;     // true
   else
      return 0;     // false
}    // Fim da fun��o.
   
//****************************************************
//* Fun��o "peek()"
//* ->  Devolve o elemento no topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      top -> ponteiro para o topo da pilha.
//* Saida(s): 
//*      int -> o elemento no topo da pilha.
//******************************************************
int peek(Elemento * base) {
	
   Elemento * topo = base;
   while (topo != NULL && topo -> proximo != NULL)
        topo = topo -> proximo;	
	
   return topo->valor; 
}    // Fim da fun��o.

//****************************************************
//* Fun��o "showH()"
//* ->  Mostra os elementos da pilha na horizontal. 
//*****************************************************
//* Entrada(s): 
//*      base -> ponteiro para a base da pilha.
//* Saida(s): 
//*      n�o tem.
//******************************************************
void showH(Elemento * base) 
	{
   Elemento * ptr = NULL;
   
      
   if (base != NULL)  // Se a pilha n�o est� vazia
      {
      printf("Lista de elementos da pilha - horizontal: ");	
      ptr = base;	
      while (ptr != NULL)
        {
		printf(" %d",ptr->valor);
		ptr = ptr -> proximo;	
        } // Fim do ciclo "while". 
	  } // Fim do "if".
   else 
      {
      printf("Pilha vazia!\n");
      } // Fim do "else".

   printf("\n");
}   // Fim da fun��o.


//****************************************************
//* Fun��o "showV()"
//* ->  Mostra os elementos da pilhana vertical. 
//*****************************************************
//* Entrada(s): 
//*      base -> ponteiro para a base da pilha.
//* Saida(s): 
//*      n�o tem.
//******************************************************
void showV(Elemento * base) 
{
   Elemento *ptr = NULL, *topo = NULL;
   
    topo = base;
	while (topo != NULL && topo -> proximo != NULL)
	   topo = topo -> proximo;
   if (base != NULL)  // Se a pilha n�o est� vazia
      {
      printf("Lista de elementos da pilha - vertical: \n\n");
      printf("-> %3d\n",topo->valor);
      do
        {
        ptr = base;	
        while(ptr->proximo != topo && topo != base)
		     ptr = ptr -> proximo;	
		if (topo != ptr)
		   {
		   printf("-> %3d\n",ptr->valor);
		   topo = ptr;
	       }
        } while (ptr != NULL && topo != base);
	  } // Fim do "if".
   else 
      {
      printf("Pilha vazia!\n");
      } // Fim do "else".

   printf("\n");
}   // Fim da fun��o.

//****************************************************
//* Fun��o "push()"
//* ->  Insere um elemento no topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      base -> ponteiro para a base da pilha.
//*      int dado - valor a inserir no topo da pilha. 
//* Saida(s): 
//*      n�o tem.
//******************************************************
Elemento * push(Elemento * base, int dado) 
{
    Elemento *  novoElemento 
	   =(Elemento*) malloc(sizeof(Elemento));
       	
    Elemento *topo = NULL;
    topo = base;
	while (topo != NULL && topo -> proximo != NULL)
	   topo = topo -> proximo;
  
  	if (novoElemento != NULL)
  	   {
   	    novoElemento->valor = dado;
    	novoElemento->proximo = NULL;
		if (base == NULL) // Se pilha est� vazia
		   {
		   base = novoElemento;	
		   topo = base;	
		   }
		else
		   {
		   topo->proximo = novoElemento;
    	   topo = novoElemento;
           }
	   }
	else
	   {
	   	printf("Imposs�vel alocar novo elemento!\n");
	    printf("Stack overflow!!\n");
	   }
  return base;
} // Fim da fun��o.
  	
 	
//****************************************************
//* Fun��o "pop()"
//* ->  Remove o elemento de topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      base -> ponteiro para a base da pilha.
//* Saida(s): 
//*      int -> elemento de topo da pilha.
//******************************************************
int pop(Elemento ** base) 
{
	Elemento * ptr = NULL;
	int dado = 0;
	
    Elemento *topo = NULL;
    topo = *base;
	while (topo != NULL && topo -> proximo != NULL)
	   topo = topo -> proximo;

	
	if (*base != NULL)   // Se a pilha n�o est� vazia
	    {
	    if(topo == *base) // �ltimo elemento da pilha 
	      {
	      dado = topo->valor;
	      ptr = topo;
	      *base = NULL;
		  topo = NULL; 	
	      free(ptr);
		  } 
		else
		  {
		  dado = topo->valor;
		  ptr = *base;
		  while (ptr->proximo != topo)
		        ptr = ptr-> proximo;
	      topo = ptr;
	      ptr = topo->proximo;
	      topo->proximo = NULL;
          free(ptr);	
		  }		
	   }
	else
	   {
	   	printf("Pilha est� vazia!\n");
	   	printf("Empty stack!!\n");
	   	dado = -1;
	   } 
	return dado;  
} // Fim da fun��o.	   
	

