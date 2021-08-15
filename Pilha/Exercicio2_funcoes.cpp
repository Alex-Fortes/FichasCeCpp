//*
//*			2) Utilizando o exercicio apresentado, crie um programa que permita a
//*		operação com uma pilha numa lista ligada.
//*		com as seguintes opções de menu:
//*
//*	   - Listar pilha
//*	   - Inserir elemento
//*	   - Obter último elemento
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
//* Define cada elemento ou nó da estrutura
//********************************************************
typedef struct Elemento {
    int valor;
    struct Elemento * proximo;
};

//*********************************************
//* Variáveis globais
//*********************************************


//*********************************************
//* Funções
//*********************************************
// Lista de Funções
//* Função "isEmpty()" 
//*          ->  Verifica se a pilha está vazia. 
//* Função "peek()"    
//*          ->  Devolve o elemento no topo da pilha.
//* Função "showH()"    
//*          ->  Mostra os elementos da pilha, 
//*              na horizontal.
//* Função "showV()"    
//*          ->  Mostra os elementos da pilha, 
//*              na vertical.
//* Função "pop()"
//*          ->  Remove o elemento de topo da pilha. 
//* Função "push()"
//*          ->  Insere um elemento no topo da pilha. 
//***************************************************
int isEmpty(Elemento *);   
int peek(Elemento *);  
void showH(Elemento *); 
void showV(Elemento *);
Elemento * push(Elemento *, int dado); 
int pop(Elemento **); 


//*****************************************************
//* Funções
//****************************************************


//****************************************************
//* Função "isEmpty()"
//* ->  Verifica se a pilha está vazia. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      bool -> true se  a fila está vazia.
//+              false se a fila não está vazia.
//******************************************************
int isEmpty(Elemento* base) {

   if(base == NULL)
      return 1;     // true
   else
      return 0;     // false
}    // Fim da função.
   
//****************************************************
//* Função "peek()"
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
}    // Fim da função.

//****************************************************
//* Função "showH()"
//* ->  Mostra os elementos da pilha na horizontal. 
//*****************************************************
//* Entrada(s): 
//*      base -> ponteiro para a base da pilha.
//* Saida(s): 
//*      não tem.
//******************************************************
void showH(Elemento * base) 
	{
   Elemento * ptr = NULL;
   
      
   if (base != NULL)  // Se a pilha não está vazia
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
}   // Fim da função.


//****************************************************
//* Função "showV()"
//* ->  Mostra os elementos da pilhana vertical. 
//*****************************************************
//* Entrada(s): 
//*      base -> ponteiro para a base da pilha.
//* Saida(s): 
//*      não tem.
//******************************************************
void showV(Elemento * base) 
{
   Elemento *ptr = NULL, *topo = NULL;
   
    topo = base;
	while (topo != NULL && topo -> proximo != NULL)
	   topo = topo -> proximo;
   if (base != NULL)  // Se a pilha não está vazia
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
}   // Fim da função.

//****************************************************
//* Função "push()"
//* ->  Insere um elemento no topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      base -> ponteiro para a base da pilha.
//*      int dado - valor a inserir no topo da pilha. 
//* Saida(s): 
//*      não tem.
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
		if (base == NULL) // Se pilha está vazia
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
	   	printf("Impossível alocar novo elemento!\n");
	    printf("Stack overflow!!\n");
	   }
  return base;
} // Fim da função.
  	
 	
//****************************************************
//* Função "pop()"
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

	
	if (*base != NULL)   // Se a pilha não está vazia
	    {
	    if(topo == *base) // Último elemento da pilha 
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
	   	printf("Pilha está vazia!\n");
	   	printf("Empty stack!!\n");
	   	dado = -1;
	   } 
	return dado;  
} // Fim da função.	   
	

