//*
//*		1) Utilizando o exercicio apresentado, crie um programa que permita a
//*		opera��o com uma pilha num vetor est�tico
//*		com as seguintes op��es de menu:
//*		
//*		   - Listar pilha
//*		   - Inserir elemento
//*		   - Obter �ltimo elemento
//*		   - Remover elemento
//*		   - Sair do programa.
//*
//*
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>

//*********************************************************************
//* Vari�veis globais
//*********************************************************************
	int isEmpty(int);   
	int isFull(int, int);
	int peek(int[], int); 
	void showH(int[], int); 
	void showV(int[], int);
	int push(int[], int dado, int topo, int); 
	int pop(int[], int topo); 
	
	//* Fun��es
//***********************************************
//* Lista de Fun��es da Pilha:
//***********************************************
//* Fun��o "isEmpty()" 
//*          ->  Verifica se a pilha est� vazia. 
//* Fun��o "isFull()"
//*          ->  Verifica se a pilha est� cheia.
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
//**************************************************************
//* Fun��es
//**************************************************************
//****************************************************
//* Fun��o "isEmpty()"
//* ->  Verifica se a pilha est� vazia. 
//*****************************************************
//* Entrada(s): 
//*      top - �ndice do topo. 
//* Saida(s): 
//*      bool -> true se  a fila est� vazia.
//+              false se a fila n�o est� vazia.
//******************************************************
	int isEmpty(int top) {
	
	   if(top == -1)
	      return 1;  // true
	   else
	      return 0;  // false
	}    // Fim da fun��o.
	   
   
//****************************************************
//* Fun��o "isFull()"
//* ->  Verifica se a pilha est� cheia. 
//*****************************************************
//* Entrada(s): 
//*      top - �ndice do topo.
//*      MAXSIZE - N�mero m�ximo de elementos da pilha. 
//* Saida(s): 
//*      bool -> true se  a pilha est� cheia.
//+              false se a pilha n�o est� cheia.
//******************************************************   
	int isFull(int top, int MAXSIZE) {
	
	   if(top == MAXSIZE-1)
	      return 1;        // true
	   else
	      return 0;        // false
	}    // Fim da fun��o.

//****************************************************
//* Fun��o "peek()"
//* ->  Devolve o elemento no topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      stack[] - pilha.
//*      top - �ndice do topo. 
//* Saida(s): 
//*      int -> o elemento no topo da pilha.
//******************************************************
	int peek(int stack[], int top) {
	   return stack[top];
	}    // Fim da fun��o.

//****************************************************
//* Fun��o "showH()"
//* ->  Mostra os elementos da pilha na horizontal. 
//*****************************************************
//* Entrada(s): 
//*      stack[] - pilha.
//*      top - �ndice do topo.
//* Saida(s): 
//*      n�o tem.
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
	}    // Fim da fun��o.




//****************************************************
//* Fun��o "showV()"
//* ->  Mostra os elementos da pilha na vertical. 
//*****************************************************
//* Entrada(s): 
//*      stack[] - pilha. 
//*      top - �ndice do topo.
//* Saida(s): 
//*      n�o tem.
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
	}    // Fim da fun��o.

//****************************************************
//* Fun��o "push()"
//* ->  Insere um elemento no topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      int data - valor a inserir no topo da pilha.
//*      stack[] - pilha.
//*      top - �ndice do topo.
//*      MAXSIZE - N�mero m�ximo de elementos da pilha. 
//* Saida(s): 
//*      top - �ndice do topo. 
//******************************************************
	int push(int stack[], int dado, int top, int MAXSIZE) {
	
	   if(!isFull(top,MAXSIZE)) // Se a pilha n�o est� cheia
	   {      
	      top = top + 1;   
	      stack[top] = dado;
	   } 
	   else 
	   {
	      printf("N�o pode inserir dados: pilha est� cheia.\n");
	      printf("Stack overflow!!\n");
	   }
	   return top;
	}   // Fim da fun��o.


//****************************************************
//* Fun��o "pop()"
//* ->  Remove o elemento de topo da pilha. 
//*****************************************************
//* Entrada(s): 
//*      stack[] - pilha.
//*      top - �ndice do topo.
//* Saida(s): 
//*      top - �ndice do topo. 
//******************************************************
int pop(int stack[], int top) 
{
   int dado = 0;
	
   if(!isEmpty(top))   // Se a pilha n�o est� vazia
   {    
      dado = stack[top];
      stack[top] = 0;  // Limpa a posi��o
	  top = top - 1;   
   } 
   else 
   {
      printf("N�o encontrou dados: pilha est� vazia.\n");
      printf("Empty stack!!\n");
   }
   return top;
}    // Fim da fun��o.
