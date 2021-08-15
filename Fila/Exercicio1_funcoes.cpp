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

#define MAX 6


//*********************************************
//* Vari�veis globais
//*********************************************
int fila[MAX];
int front = 0;      // Posi��o do elemento 
                    // da frente da fila
int rear = -1;      // Posi��o do elemento 
                    // na �ltima posi��o da fila
int itemCount = 0;


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
int peek() {
   return fila[front];
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
void show() {
   
   printf("Lista de elementos da fila: ");
   for (int cValor = front; cValor < (front+itemCount); cValor++)
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
bool isEmpty() {
   return itemCount == 0;
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
	int isFull(int top, int MAX) {
	
	   if(top == MAX-1)
	      return 1;        // true
	   else
	      return 0;        // false
	}    // Fim da fun��o.

//****************************************************
//* Fun��o "size()"
//* ->  devolve o  n�mero de elementos da fila. 
//*****************************************************
//* Entrada(s): 
//*      n�o tem. 
//* Saida(s): 
//*      int -> n�mero de elementos da fila.
//******************************************************
int size() {
   return itemCount;
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
void insert(int data) {

   // Se a fila n�o tiver cheia
   if(!isFull()) {
	
      fila[++rear] = data;
      
      itemCount++;
   }
   else
   {
      printf("N�o pode inserir dados: fila est� cheia.\n");
   }
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
int remove() {
	
   front = 0;
	
   int data = fila[0];
	
   itemCount--;	

   // Transporta todos os valores para a frente. 
   for (int cValor = front; cValor < front+ itemCount; cValor++)
       fila[cValor] = fila[cValor+1];
       
   fila[rear] = 0;      
  
   rear--;

   
   return data;  
}
