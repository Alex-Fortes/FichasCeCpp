//*
//*		1) Utilizando o exercicio apresentado, crie um programa que permita a
//*		opera��o com uma fila num vetor est�tico
//*		com as seguintes op��es de menu:
//*		
//*		   - Listar fila
//*		   - Inserir elemento
//*		   - Obter primeiro elemento
//*		   - Remover elemento
//*		   - Sair do programa.
//*
// Bibliotecas de C
//******************************************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <clocale>

//*********************************************
//* Vari�veis globais
//*********************************************

	int peek(int fila[], int primeiro);
	void show(int fila[],int primeiro, int ultimo);
	bool isEmpty(int primeiro); 
	bool isFull(int ultimo, int MAX);
	int size(int ultimo, int primeiro);
	int insert(int fila[], int ultimo,   int MAX,    int data);
	int remove(int fila[], int primeiro, int ultimo);

//*********************************************
//* Fun��es
//*********************************************
// Lista de Fun��es
//* Fun��o "isEmpty()" 
//*          ->  Verifica se a fila est� vazia. 
//* Fun��o "isFull()"
//*          ->  Verifica se a fila est� cheia.
//* Fun��o "peek()"    
//*          ->  Devolve o elemento na frente da fila.
//* Fun��o "show()"    
//*          ->  Mostra os elementos da fila.
//* Fun��o "size()"
//*          ->  devolve o  n�mero de elementos da fila. 
//* Fun��o "remove()"
//*          ->  remove  elemento da fila. 
//* Fun��o "insert()"
//*          ->  insere um elemento na fila.  
//***************************************************


//****************************************************
//* Fun��o "peek()"
//* ->  devolve o elemento na frente da fila. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      int -> o elemento na frente da fila.
//******************************************************
	int peek(int fila[], int primeiro) {
	   return fila[primeiro];
	}

//****************************************************
//* Fun��o "show()"
//* ->  Mostra os elementos da fila. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      int -> o elemento no topo da fila.
//******************************************************
	void show(int fila[],int primeiro, int ultimo) {
	   
	   printf("Lista de elementos da fila: ");
	   for (int cValor = primeiro; cValor <= ultimo; cValor++)
	       printf(" %d",fila[cValor]);
	   printf("\n");
	}

//****************************************************
//* Fun��o "isEmpty()"
//* ->  verifica se a fila est� vazia. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      bool -> true se  a fila est� vazia.
//+              false se a fila n�o est� vazia.
//******************************************************
	bool isEmpty(int ultimo) {
	   return ultimo == -1;
	}

//****************************************************
//* Fun��o "isFull()"
//* ->  verifica se a fila est� cheia. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      bool -> true se  a fila est� cheia.
//+              false se a fila n�o est� cheia.
//******************************************************

	bool isFull(int ultimo, int MAX) {
	   return ultimo == (MAX-1);
	}
	
//****************************************************
//* Fun��o "size()"
//* ->  devolve o  n�mero de elementos da fila. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      int -> n�mero de elementos da fila.
//******************************************************
	int size(int ultimo, int primeiro) {
	   return (ultimo-primeiro+1);
	} 

//****************************************************
//* Fun��o "insert()"
//* ->  insere um elemento na fila. 
//*****************************************************
//* Entrada(s): 
//*      int data - valor a inserir na fila. 
//* Saida(s): 
//*      n�o tem.
//******************************************************
	int insert(int fila[], int ultimo, int MAX, int data) {
	
	   // Se a fila n�o tiver cheia
	   if(!isFull(ultimo,MAX)) 
	   {
	   	  ultimo++;
		  fila[ultimo] = data;
	   }
	   else
	   {
	      printf("N�o pode inserir dados: fila est� cheia.\n");
	   }
	  return ultimo; 
	}  // Fim da fun��o "insert()".


//****************************************************
//* Fun��o "remove()"
//* ->  remove  elemento da fila. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      int -> primeiro elemento da fila.
//******************************************************
	int remove(int fila[], int primeiro, int ultimo) 
	   {
		
	   if (!isEmpty(ultimo))   // Fila n�o est� vazia
	      {
		  int data = fila[primeiro];
		  //itemCount--;	
		  
	      // Transporta todos os valores para a frente. 
	      for (int cValor = primeiro; cValor < ultimo; cValor++)
	          fila[cValor] = fila[cValor+1];
	       
	      fila[ultimo] = 0;      
	      ultimo--;
	   }
	   else
	   {
	      printf("N�o pode remover dados: fila est� vazia.\n");
	   }
	return ultimo;
	}

