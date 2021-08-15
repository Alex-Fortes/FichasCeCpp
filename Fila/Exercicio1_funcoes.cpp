//*
//*		1) Utilizando o exercicio apresentado, crie um programa que permita a
//*		operação com uma fila num vetor estático
//*		com as seguintes opções de menu:
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
//* Variáveis globais
//*********************************************
int fila[MAX];
int front = 0;      // Posição do elemento 
                    // da frente da fila
int rear = -1;      // Posição do elemento 
                    // na última posição da fila
int itemCount = 0;


//*********************************************
//* Funções
//*********************************************
// Lista de Funções
//* Função "isEmpty()" 
//*          ->  Verifica se a fila está vazia. 
//* Função "isFull()"
//*          ->  Verifica se a fila está cheia.
//* Função "peek()"    
//*          ->  Devolve o elemento na frente da fila.
//* Função "show()"    
//*          ->  Mostra os elementos da fila.
//* Função "size()"
//*          ->  devolve o  número de elementos da fila. 
//* Função "remove()"
//*          ->  remove  elemento da fila. 
//* Função "insert()"
//*          ->  insere um elemento na fila.  
//***************************************************


//****************************************************
//* Função "peek()"
//* ->  devolve o elemento na frente da fila. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      int -> o elemento na frente da fila.
//******************************************************
int peek() {
   return fila[front];
}

//****************************************************
//* Função "show()"
//* ->  Mostra os elementos da fila. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
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
//* Função "isEmpty()"
//* ->  verifica se a fila está vazia. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      bool -> true se  a fila está vazia.
//+              false se a fila não está vazia.
//******************************************************
bool isEmpty() {
   return itemCount == 0;
}



//****************************************************
//* Função "isFull()"
//* ->  verifica se a fila está cheia. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      bool -> true se  a fila está cheia.
//+              false se a fila não está cheia.
//******************************************************
	int isFull(int top, int MAX) {
	
	   if(top == MAX-1)
	      return 1;        // true
	   else
	      return 0;        // false
	}    // Fim da função.

//****************************************************
//* Função "size()"
//* ->  devolve o  número de elementos da fila. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      int -> número de elementos da fila.
//******************************************************
int size() {
   return itemCount;
}  



//****************************************************
//* Função "insert()"
//* ->  insere um elemento na fila. 
//*****************************************************
//* Entrada(s): 
//*      int data - valor a inserir na fila. 
//* Saida(s): 
//*      não tem.
//******************************************************
void insert(int data) {

   // Se a fila não tiver cheia
   if(!isFull()) {
	
      fila[++rear] = data;
      
      itemCount++;
   }
   else
   {
      printf("Não pode inserir dados: fila está cheia.\n");
   }
}  // Fim da função "insert()".




//****************************************************
//* Função "remove()"
//* ->  remove  elemento da fila. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
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
