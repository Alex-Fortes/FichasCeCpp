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

//*********************************************
//* Variáveis globais
//*********************************************

	int peek(int fila[], int primeiro);
	void show(int fila[],int primeiro, int ultimo);
	bool isEmpty(int primeiro); 
	bool isFull(int ultimo, int MAX);
	int size(int ultimo, int primeiro);
	int insert(int fila[], int ultimo,   int MAX,    int data);
	int remove(int fila[], int primeiro, int ultimo);

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
	int peek(int fila[], int primeiro) {
	   return fila[primeiro];
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
	void show(int fila[],int primeiro, int ultimo) {
	   
	   printf("Lista de elementos da fila: ");
	   for (int cValor = primeiro; cValor <= ultimo; cValor++)
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
	bool isEmpty(int ultimo) {
	   return ultimo == -1;
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

	bool isFull(int ultimo, int MAX) {
	   return ultimo == (MAX-1);
	}
	
//****************************************************
//* Função "size()"
//* ->  devolve o  número de elementos da fila. 
//*****************************************************
//* Entrada(s): 
//*      não tem. 
//* Saida(s): 
//*      int -> número de elementos da fila.
//******************************************************
	int size(int ultimo, int primeiro) {
	   return (ultimo-primeiro+1);
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
	int insert(int fila[], int ultimo, int MAX, int data) {
	
	   // Se a fila não tiver cheia
	   if(!isFull(ultimo,MAX)) 
	   {
	   	  ultimo++;
		  fila[ultimo] = data;
	   }
	   else
	   {
	      printf("Não pode inserir dados: fila está cheia.\n");
	   }
	  return ultimo; 
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
	int remove(int fila[], int primeiro, int ultimo) 
	   {
		
	   if (!isEmpty(ultimo))   // Fila não está vazia
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
	      printf("Não pode remover dados: fila está vazia.\n");
	   }
	return ultimo;
	}

