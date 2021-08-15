//*
//*		1) Utilizando o exercicio apresentado, crie um programa que permita a
//*		operação com uma pilha num vetor estático
//*		com as seguintes opções de menu:
//*		
//*		   - Listar pilha
//*		   - Inserir elemento
//*		   - Obter último elemento
//*		   - Remover elemento
//*		   - Sair do programa.
//*
//*
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>

//*********************************************************************
//* Variáveis globais
//*********************************************************************
	int isEmpty(int);   
	int isFull(int, int);
	int peek(int[], int); 
	void showH(int[], int); 
	void showV(int[], int);
	int push(int[], int dado, int topo, int); 
	int pop(int[], int topo); 
	
	//* Funções
//***********************************************
//* Lista de Funções da Pilha:
//***********************************************
//* Função "isEmpty()" 
//*          ->  Verifica se a pilha está vazia. 
//* Função "isFull()"
//*          ->  Verifica se a pilha está cheia.
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
//**************************************************************
//* Funções
//**************************************************************
//****************************************************
//* Função "isEmpty()"
//* ->  Verifica se a pilha está vazia. 
//*****************************************************
//* Entrada(s): 
//*      top - índice do topo. 
//* Saida(s): 
//*      bool -> true se  a fila está vazia.
//+              false se a fila não está vazia.
//******************************************************
	int isEmpty(int top) {
	
	   if(top == -1)
	      return 1;  // true
	   else
	      return 0;  // false
	}    // Fim da função.
	   
   
//****************************************************
//* Função "isFull()"
//* ->  Verifica se a pilha está cheia. 
//*****************************************************
//* Entrada(s): 
//*      top - índice do topo.
//*      MAXSIZE - Número máximo de elementos da pilha. 
//* Saida(s): 
//*      bool -> true se  a pilha está cheia.
//+              false se a pilha não está cheia.
//******************************************************   
	int isFull(int top, int MAXSIZE) {
	
	   if(top == MAXSIZE-1)
	      return 1;        // true
	   else
	      return 0;        // false
	}    // Fim da função.

//****************************************************
//* Função "peek()"
//* ->  Devolve o elemento no topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      stack[] - pilha.
//*      top - índice do topo. 
//* Saida(s): 
//*      int -> o elemento no topo da pilha.
//******************************************************
	int peek(int stack[], int top) {
	   return stack[top];
	}    // Fim da função.

//****************************************************
//* Função "showH()"
//* ->  Mostra os elementos da pilha na horizontal. 
//*****************************************************
//* Entrada(s): 
//*      stack[] - pilha.
//*      top - índice do topo.
//* Saida(s): 
//*      não tem.
//******************************************************
	void showH(int stack[], int top) {
	   
	    if (!isEmpty(top))
	      {
		  printf("Lista de elementos da pilha-horizontal: ");
	      for (int cValor =0; cValor <= top; cValor++)
	          printf(" %d",stack[cValor]);
	      }
	    else
	     {
	     printf("Pilha vazia!!");	
		 }
	  
	   printf("\n");
	}    // Fim da função.




//****************************************************
//* Função "showV()"
//* ->  Mostra os elementos da pilha na vertical. 
//*****************************************************
//* Entrada(s): 
//*      stack[] - pilha. 
//*      top - índice do topo.
//* Saida(s): 
//*      não tem.
//******************************************************
	void showV(int stack[], int top) {
	
	       
	    if (!isEmpty(top))
	       {
	       printf("Lista de elementos da pilha-vertical: \n\n");
	       for (int cValor =top; cValor >= 0; cValor--)
	          printf("-> %3d\n",stack[cValor]);
	      }
	    else
	     {
	     printf("Pilha vazia!!");	
		 }
	  
	   printf("\n");
	}    // Fim da função.

//****************************************************
//* Função "push()"
//* ->  Insere um elemento no topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      int data - valor a inserir no topo da pilha.
//*      stack[] - pilha.
//*      top - índice do topo.
//*      MAXSIZE - Número máximo de elementos da pilha. 
//* Saida(s): 
//*      top - índice do topo. 
//******************************************************
	int push(int stack[], int dado, int top, int MAXSIZE) {
	
	   if(!isFull(top,MAXSIZE)) // Se a pilha não está cheia
	   {      
	      top = top + 1;   
	      stack[top] = dado;
	   } 
	   else 
	   {
	      printf("Não pode inserir dados: pilha está cheia.\n");
	      printf("Stack overflow!!\n");
	   }
	   return top;
	}   // Fim da função.


//****************************************************
//* Função "pop()"
//* ->  Remove o elemento de topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      stack[] - pilha.
//*      top - índice do topo.
//* Saida(s): 
//*      top - índice do topo. 
//******************************************************
int pop(int stack[], int top) 
{
   int dado = 0;
	
   if(!isEmpty(top))   // Se a pilha não está vazia
   {    
      dado = stack[top];
      stack[top] = 0;  // Limpa a posição
	  top = top - 1;   
   } 
   else 
   {
      printf("Não encontrou dados: pilha está vazia.\n");
      printf("Empty stack!!\n");
   }
   return top;
}    // Fim da função.
