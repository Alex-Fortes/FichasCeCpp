//*
//*		2) Utilizando o exercicio apresentado, crie um programa que permita a
//*		operação com uma fila numa lista ligada.
//*		com as seguintes opções de menu:
//*		
//*		   - Listar fila
//*		   - Inserir elemento
//*		   - Obter primeiro elemento
//*		   - Remover elemento
//*		   - Sair do programa.
// 
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>


//*******************************************************
//* Estrutura de Dados
//*******************************************************
//* Define cada elemento da estrutura
//********************************************************
typedef struct Elemento {
    int valor;
    struct Elemento * proximo;
};

//*********************************************
//* Variáveis globais
//*********************************************
	int isEmpty(Elemento * primeiro);
	int peek(Elemento * primeiro);
	void show(Elemento * primeiro); 
	Elemento * insert(Elemento * primeiro, int dado);
	int remove(Elemento ** primeiro); 

//*********************************************
//* Funções
//*********************************************
// Lista de Funções
//* Função "isEmpty()" 
//*          ->  Verifica se a fila está vazia. 
//* Função "peek()"    
//*          ->  Devolve o elemento na frente da fila.
//* Função "show()"    
//*          ->  Mostra os elementos da fila.
//* Função "remove()"
//*          ->  remove elemento do inicio da fila. 
//* Função "insert()"
//*          ->  insere um elemento no fim na fila.   
//***************************************************


//****************************************************
//* Função "isEmpty()"
//* ->  Verifica se a fila está vazia. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      bool -> true se  a fila está vazia.
//+              false se a fila não está vazia.
//******************************************************
int isEmpty(Elemento* primeiro) {

   if(primeiro == NULL)
      return 1;     // true
   else
      return 0;     // false
}    // Fim da função.
//****************************************************
//* Função "peek()"
//* ->  Devolve o primeiro elemento. 
//*****************************************************
//* Entrada(s): 
//*      top -> ponteiro para o primeiro elemento.
//* Saida(s): 
//*      int -> o primeiro elemento
//******************************************************
	int peek(Elemento * primeiro) {
	   return primeiro->valor;
	}    // Fim da função.

//****************************************************
//* Função "show()"
//* ->  Mostra os elementos da fila. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      não tem.
//******************************************************
	void show(Elemento * primeiro) 
	{
	   Elemento * ptr = NULL;
	   
	   printf("Lista de elementos da fila: ");   
	   if (primeiro != NULL)
	      {
	      ptr = primeiro;	
	      while (ptr != NULL)
	        {
			printf(" %d",ptr->valor);
			ptr = ptr -> proximo;	
	        } // Fim do ciclo "while". 
		  } // Fim do "if".
	   else 
	      {
	      printf("Fila vazia!\n");
	      } // Fim do "else".
	
	   printf("\n");
	}   // Fim da função.


//****************************************************
//* Função "insert()"
//* ->  Insere um elemento no fim da fila. 
//*****************************************************
//* Entrada(s): 
//*      int dado - valor a inserir na fila. 
//* Saida(s): 
//*      não tem.
//******************************************************
Elemento * insert(Elemento * primeiro, int dado) 
{
    Elemento *  novoElemento 
	   =(Elemento*) malloc(sizeof(Elemento));
       	
    Elemento * ultimo = primeiro;
    while (ultimo != NULL && ultimo -> proximo != NULL)
        ultimo = ultimo -> proximo;   	
       	
  	if (novoElemento != NULL)
  	   {
   	    novoElemento->valor = dado;
    	novoElemento->proximo = NULL;
		if (primeiro == NULL) // Se fila está vazia
		   {
		   primeiro = novoElemento;	
		   ultimo = primeiro;	
		   }
		else
		   {
		   ultimo->proximo = novoElemento;
    	   ultimo = novoElemento;
           }
	   }
	else
	   {
	   	printf("Impossivel alocar novo elemento!\n");
	   }
    return primeiro;
} // Fim da função.
       	
       	
		   
//****************************************************
//* Função "remove()"
//* ->  Remove o primeiro elemento fila. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      int -> elemento removido.
//******************************************************
int remove(Elemento ** primeiro) 
{
	Elemento * ptr = NULL;
	int dado = 0;
	
	Elemento * ultimo = *primeiro;
    while (ultimo != NULL && ultimo -> proximo != NULL)
        ultimo = ultimo -> proximo;   
	
	if (*primeiro != NULL)
	    {
	    if(*primeiro == ultimo) // Último elemento da fila 
	      {
	      dado = (*primeiro)->valor;
	      ptr = *primeiro;
	      *primeiro = NULL;
		  ultimo = NULL; 	
	      free(ptr);
		  } 
		else
		  {
		  dado = (*primeiro)->valor;
		  ptr = *primeiro;
		  *primeiro = (*primeiro)->proximo;
          free(ptr);	
		  }		
	   }
	else
	   {
	   	printf("Fila está vazia!\n");
	   	dado = -1;
	   }   
	return dado;
} // Fim da função.	  	
