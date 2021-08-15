//*
//*		2) Utilizando o exercicio apresentado, crie um programa que permita a
//*		opera��o com uma fila numa lista ligada.
//*		com as seguintes op��es de menu:
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
//* Vari�veis globais
//*********************************************
// Ponteiro para o inicio da fila
struct Elemento *primeiro = NULL;
// Ponteiro para o fim da fila
struct Elemento *ultimo = NULL;

//*********************************************
//* Fun��es
//*********************************************
// Lista de Fun��es
//* Fun��o "isEmpty()" 
//*          ->  Verifica se a fila est� vazia. 
//* Fun��o "peek()"    
//*          ->  Devolve o elemento na frente da fila.
//* Fun��o "show()"    
//*          ->  Mostra os elementos da fila.
//* Fun��o "remove()"
//*          ->  remove elemento do inicio da fila. 
//* Fun��o "insert()"
//*          ->  insere um elemento no fim na fila.   
//***************************************************


//****************************************************
//* Fun��o "isEmpty()"
//* ->  Verifica se a fila est� vazia. 
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
//* ->  Devolve o primeiro elemento. 
//*****************************************************
//* Entrada(s): 
//*      top -> ponteiro para o primeiro elemento.
//* Saida(s): 
//*      int -> o primeiro elemento
//******************************************************
int peek(Elemento * base) {
	
   Elemento * topo = base;
   while (topo != NULL && topo -> proximo != NULL)
        topo = topo -> proximo;	
	
   return topo->valor; 
}    // Fim da fun��o.

//****************************************************
//* Fun��o "peek()"
//* ->  Devolve o elemento na frente da fila. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      int -> o elemento na frente da fila.
//******************************************************
int peek() {
   return primeiro->valor;
}    // Fim da fun��o.

//****************************************************
//* Fun��o "show()"
//* ->  Mostra os elementos da fila. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      n�o tem.
//******************************************************
void show() 
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
}   // Fim da fun��o.


//****************************************************
//* Fun��o "insert()"
//* ->  Insere um elemento no fim da fila. 
//*****************************************************
//* Entrada(s): 
//*      int dado - valor a inserir na fila. 
//* Saida(s): 
//*      n�o tem.
//******************************************************
void insert(int dado) 
{
    Elemento *  novoElemento 
	   =(Elemento*) malloc(sizeof(Elemento));
       	
  	if (novoElemento != NULL)  // Foi possivel alocar o elemento
  	   {
   	    novoElemento->valor = dado;
    	novoElemento->proximo = NULL;
		if (primeiro == NULL) // Se fila est� vazia
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
} // Fim da fun��o.
       	
       	



//****************************************************
//* Fun��o "remove()"
//* ->  Remove o primeiro elemento fila. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      int -> elemento removido.
//******************************************************
int remove() 
{
	Elemento * ptr = NULL;
	int dado = 0;
	
	if (primeiro != NULL)      // Se a fila n�o est� vazia
	    {
	    if(primeiro == ultimo) // �ltimo elemento da fila 
	      {
	      dado = primeiro->valor;
	      ptr = primeiro;
	      primeiro = NULL;
		  ultimo = NULL; 	
	      free(ptr);
		  } 
		else
		  {
		  dado = primeiro->valor;
		  ptr = primeiro;
		  primeiro = primeiro->proximo;
		  ptr->proximo = NULL;
          free(ptr);	
		  }		
	   }
	else
	   {
	   	printf("Fila est� vazia!\n");
	   	dado = -1;
	   }   
	return dado;
} // Fim da fun��o.	   
	
