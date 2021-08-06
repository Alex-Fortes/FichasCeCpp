//****************************************************
//*  0785 - Estruturas de Dados
//****************************************************
//* Capítulo 07 - Estruturas de dados de lista ligada
//****************************************************
//* 01. Introdução
//*
//* 01.01 O que são estruturas de dados? 
//* 
//*   Data Structures are the programmatic
//*    way of storing data so that data 
//*    can be used efficiently.
//*
//*
//* 01.02 Que estruturas de dados existem?
//*
//* Data Definition
//* Data Definition defines a particular data
//*    with the following characteristics.
//*
//*  Atomic - Definition should define a single concept.
//* 
//*  Traceable - Definition should be able to be mapped
//*     to some data element.
//*
//*  Accurate - Definition should be unambiguous.
//*
//*  Clear and Concise - Definition should be understandable.
//* 
//* Data Object
//*  Data Object represents an object having a data.
//* 
//*  Data Type
//*  Data type is a way to classify various types of data
//*  such as integer, string, etc. which determines the values 
//*  that can be used with the corresponding type of data, 
//*  the type of operations that can be performed on the 
//*  corresponding type of data. There are two data types -
//* 
//*  Built-in Data Type
//*  Derived Data Type
//*  Built-in Data Type
//*
//* Those data types for which a language has built-in support
//*  are known as Built-in Data types. 
//*  For example, most of the languages provide the following 
//*  built-in data types.
//*
//* Integers
//* Boolean (true, false)
//* Floating (Decimal numbers)
//* Character and Strings
//* Derived Data Type
//*
//* Those data types which are implementation independent 
//* as they can be implemented in one or the other way are
//* known as derived data types. 
//* These data types are normally built by the combination
//* of primary or built-in data types and associated operations 
//* on them. For example -
//*
//* List
//* Array
//* Stack
//* Queue
//*
//*
//* 01.03 Que termos se utilizam para caracterizar 
//*       uma estrutura de dados? 
//*
//*  Basic Terminology
//*   Data - Data are values or set of values.
//*   Data Item - Data item refers to single unit of values.
//*   Group Items - Data items that are divided into 
//*                   sub items are called as Group Items.
//*   Elementary Items - Data items that cannot be divided
//*             are called as Elementary Items.
//*   Attribute and Entity - An entity is that which contains
//*        certain attributes or properties, which may 
//*        be assigned values.
//*   Entity Set - Entities of similar attributes form 
//*        an entity set.
//*   Field - Field is a single elementary unit of 
//*         information representing an attribute of an entity.
//*   Record - Record is a collection of field values 
//*         of a given entity.
//*   File - File is a collection of records of the 
//*         entities in a given entity set.
//*
//*
//* 01.04 Que operações se podem efetuar sobre uma
//*       estrutura de dados?
//*
//*   Basic Operations
//*   The data in the data structures are processed 
//*   by certain operations. 
//*   The particular data structure chosen largely 
//*   depends on the frequency of the operation that 
//*   needs to be performed on the data structure.
//* 
//*   Traversing
//*   Searching
//*   Insertion
//*   Deletion
//*   Sorting
//*   Merging
//*
//*
//* 01.05 O papel dos algoritmos
//*
//*
//* Algorithm is a step-by-step procedure, 
//* which defines a set of instructions to be executed 
//* in a certain order to get the desired output. 
//* Algorithms are generally created independent 
//* of underlying languages, i.e. an algorithm can be
//* implemented in more than one programming language.
//*
//* From the data structure point of view, 
//* following are some important categories of algorithms -
//*
//* Search - Algorithm to search an item in a data structure.
//*
//* Sort - Algorithm to sort items in a certain order.
//* 
//* Insert - Algorithm to insert item in a data structure.
//*
//* Update - Algorithm to update an existing item in a 
//* data structure.
//* 
//* Delete - Algorithm to delete an existing item 
//*  from a data structure.
//*
//* Characteristics of an Algorithm
//* Not all procedures can be called an algorithm. 
//* An algorithm should have the following characteristics -
//* 
//* Unambiguous - Algorithm should be clear and unambiguous.
//*   Each of its steps (or phases), and their inputs/outputs
//*   should be clear and must lead to only one meaning.
//*
//* Input - An algorithm should have 0 or more 
//*      well-defined inputs.
//* 
//* Output - An algorithm should have 1 or more 
//*          well-defined outputs,
//*          and should match the desired output.
//*
//* Finiteness - Algorithms must terminate after a 
//*   finite number of steps.
//*
//* Feasibility - Should be feasible with the available 
//*    resources.
//*
//* Independent - An algorithm should have 
//*   step-by-step 
//*   directions, 
//*   which should be independent of any 
//*   programming code.
//*
//****************************************************
//* 02. Lista ligada ("Linked List")
//*
//* 02.01 Estrutura de uma lista ligada 
//*
//*  Uma lista ligada é constituída por um conjunto 
//*  de elementos ("records") ligados através  
//*  de ponteiros.
//*
//*  Existem os seguintes tipos de listas ligadas
//*  ("linked lists"):
//*    
//*  Types of Linked List
//*  Following are the various types of linked list.
//* 
//*    Simple Linked List - Item navigation is forward only.
//*
//*    Doubly Linked List - Items can be navigated forward and backward.
//* 
//*    Circular Linked List - Last item contains link of the first element 
//*          as next and the first element has a
//*          link to the last element as previous.
//*
//*
//* 02.02 Que operações se podem efetuar numa lista ligada? 
//*
//*
//* Basic Operations
//* Following are the basic operations supported by a list.
//*
//*  Insertion - Adds an element at the beginning of the list.
//*
//*  Deletion - Deletes an element at the beginning of the list.
//* 
//*  Display - Displays the complete list.
//*
//*  Search - Searches an element using the given key.
//* 
//*  Delete - Deletes an element using the given key.
//*
//*
//*  -> Obter o número de elementos ("records") de 
//*     uma lista ligada ("length()" ou "size()").
//*  -> Inserção de elementos numa lista ligada.
//*  -> Listagem dos elementos de uma lista ligada.
//*  -> Ordenação dos elementos de uma lista ligada.
//*  -> Ordenar os elementos de uma lista ligada.
//*  -> Pesquisa de elementos.
//*  -> Atualização de elementos.
//*  -> Remoção de elementos.
//*
//*  Outras operações: 
//*    - Transposição de elementos (troca de elementos);
//*    - Junção de duas listas ligadas.
//*
//*
//* 02.03 Descrição pormenorizada das operações
//* 
//*  -> Obter o número de elementos ("records") de 
//*     uma lista ligada.
//*
//*  -> Inserção de elementos:
//*     - Adicionar um elemento no fim da lista 
//*     - Adicionar um elemento no inicio da lista 
//*     - Adicionar um elemento numa determinada posição da 
//*       lista ligada.
//*
//*  -> Apresentar os elementos de uma lista ligada.
//*
//* -> Ordenar os elementos de uma lista ligada:
//*    - Ordem ascendente. 
//*    - Ordem descendente.
//*
//* -> Pesquisa de elementos:
//*    - Pesquisar um elemento numa determinada posição da 
//*      lista ligada.
//*    - Pesquisar um elemento por valor numa lista ligada.
//*
//*
//* -> Atualização de elementos:
//*    - Atualizar um elemento numa determinada posição da 
//*      lista ligada.
//*    - Atualizar um elemento por valor numa lista ligada
//*      (primeira ocorrência ou todas as ocorrências).  
//*
//*
//* -> Remoção de elementos:
//*    - Remover um elemento no fim da lista 
//*    - Remover um elemento no inicio da lista 
//*    - Remover um elemento numa determinada posição da 
//*      lista ligada.
//*    - Remover todos os elementos de uma lista ligada
//*************************************************************
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
// Biblioteca de C++
#include <iostream>
#include "ListaLigada_FuncoesInteiros.cpp"
using namespace std;



//*****************************************************
// Protótipos das funções
// Declaração das funções - Cabeçalhos das funções
//******************************************************
		void mostraMenu();
		char obtemEscolha(char, int );
		bool processaEscolha(char, node_list**, bool );
		void despedida();
		
		
		void insereElemento(node_list**);
		void mostraElementos(node_list*);
		void pesquisaElemento(node_list*);
		void atualizaElemento(node_list*);
		void removeElemento(node_list**);
		
		
		bool sairDoPrograma(bool );
		void escolhaInvalida();
		void pausa();

//*********************************************************
//* Função principal
//*********************************************************
	int main(void) {
		
	// 1. Dados
	char escolha = '\0';
	node_list * lista = NULL;
	bool queroSair = false;
	setlocale(LC_ALL, "Portuguese");	
		
	// 2. Algoritmo
	do {
		  mostraMenu();	
		  escolha = obtemEscolha(escolha,6);	
		  queroSair = processaEscolha(escolha,&lista,queroSair); 	
		} while (!queroSair);	
		despedida();
	return EXIT_SUCCESS;
}   // Fim da função "main()".



//******************************************************
//* Função "mostra_menu()"
//* -> Apresenta um menu de opções. 
//******************************************************
//* Entrada(s): não tem. 
//* Saida(s): não tem.
//******************************************************
	void mostraMenu() {
	system("cls");	system("color A");	
	cout<<"***************************************"<<endl;
	cout<<"*                                     *"<<endl;
	cout<<"*   Lista Ligada - \"Linked List\"    *"<<endl;
	cout<<"*                                     *"<<endl;
	cout<<"*   A. Insere elemento na estrutura.  *"<<endl;
	cout<<"*   B. Mostra estrutura de dados.     *"<<endl;
	cout<<"*   C. Pesquisa por elemento.         *"<<endl;
	cout<<"*   D. Atualiza elemento.             *"<<endl;
	cout<<"*   E. Remove elemento na estrutura.  *"<<endl;
	cout<<"*   F. Sair do programa.              *"<<endl;
	cout<<"*                                     *"<<endl;
	cout<<"***************************************"<<endl;
	cout<<endl;
} // Fim da função "mostra_menu()".



//******************************************************
//* Função "obtem_escolha()"
//* -> obtém escolha do utilizador num menu de opções. 
//******************************************************
//* Entrada(s): char escolha - escolha anterior. 
//* Saida(s): char escolha   - escolha atual.
//******************************************************
	char obtemEscolha(char escolha, int limiteSup) {
	
	char ultimaOp = (char)(limiteSup+64); // "A" - ASCII 65	
	cout<<"Qual a sua escolha (A-"<<ultimaOp<<")? ";
	cin>>escolha;cin.ignore();
return escolha;
} // Fim da função "obtem_escolha()".


//******************************************************
//* Função "processa_escolha()"
//* -> processa a  escolha do utilizador 
//*                                 num menu de opções. 
//******************************************************
//* Entrada(s): 
//*            char escolha     - escolha.
//*            node_list *lista - ponteiro para o início
//*                               da lista.
//*            bool queroSair   - controla saída do 
//*                               programa.
//* 
//* Saida(s): bool queroSair   - controla saída do 
//*                              programa - valor atualizado. 
//***********************************************************
	bool processaEscolha(char escolha,node_list **head_lista, bool queroSair) {
	
	switch(escolha)
		{
		case  'A': case 'a': // Insere elemento na estrutura.
		     insereElemento(head_lista); break;
		
		case  'B': case 'b':  // Mostra estrutura de dados.
		     mostraElementos(*head_lista); break;
		
		case  'C': case 'c':  // Pesquisa por elemento.
		     pesquisaElemento(*head_lista); break;
		
		case  'D': case 'd':  // Atualiza elemento.
		     atualizaElemento(*head_lista); break;
		
		case  'E': case 'e':  // Remove elemento na estrutura.
		     removeElemento(head_lista); break;
		
		case  'F': case 'f':  // Sair do programa. 	
			 queroSair = sairDoPrograma(queroSair); break;
	default:
	     escolhaInvalida();	
	} // Fim do "switch".
	return queroSair;
} // Fim da função "obtem_escolha()".


//******************************************************
//* Função "insereElemento()"
//* -> insere um elemento na lista ligada ("linked list"). 
//******************************************************
//* Entrada(s): 
//*            node_list *lista - ponteiro para o início
//*                               da lista.
//* Saida(s): não tem. 
//***********************************************************
	void insereElemento(node_list **lista) {
		
	// 1. Dados
	char escolha = '\0';
	bool queroSair = false;
	
	
	// 2. Algoritmo
	do {
	system("cls");	system("color A");		
	cout<<"**************************************************************"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"* A. Adicionar um elemento no inicio da lista.               *"<<endl;
	cout<<"* B. Adicionar um elemento no fim da lista.                  *"<<endl;
	cout<<"* C. Adicionar um elemento numa determinada posição da lista.*"<<endl;
	cout<<"* D. Voltar ao menu anterior.                                *"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"**************************************************************"<<endl;	
	escolha = obtemEscolha(escolha,4);

	switch(escolha)
	{
	case  'A': case 'a':  // Adicionar um elemento no inicio da lista.
		 {
		 int valor = 0;	
		 cout<<"Qual o valor a inserir? "; cin>>valor;	
		 pushfirst(lista, valor);	
		 print_list(*lista);
		 cout<<"Valor inserido com sucesso!";
		 pausa(); break;
		 }
	case  'B': case 'b':  // Adicionar um elemento no fim da lista.
		 {
		 int valor = 0;	
		 cout<<"Qual o valor a inserir? "; cin>>valor;
		 if (size(*lista) == 0)
		    pushfirst(lista, valor);
		 else		
		    push(lista, valor);
		 print_list(*lista);	
		 cout<<"Valor inserido com sucesso!"; pausa();break;
		 }
	case  'C': case 'c':  // Adicionar um elemento numa 
	                      //           determinada posição da lista.
		 {
		 int valor = 0, pos = 0;
		 cout<<"Qual o valor a inserir? "; cin>>valor;
		 if (size(*lista) == 0)
		    {
		    cout<<"A lista está vazia. Só pode inserir na posição 0."<<endl;	
		    pos=0;	
			} 
		 else 
		    {
	       do {
		    cout<<"Qual o valor da posição (0-"<<size(*lista);
		    cout<<")? "; cin>>pos;	
		    if (pos <0 || pos > size(*lista))	
		      cout<<"Posição inválida!! Tente de novo!!";
		    } while(pos <0 || pos > size(*lista));
		   }
		 add_by_index(lista, pos, valor);
		 print_list(*lista);	
		 cout<<"Valor inserido com sucesso!"; pausa();break;
		   }
	case  'D': case 'd':  //  Voltar ao menu anterior.
	      queroSair = sairDoPrograma(queroSair); break;
		 
	default:
	     escolhaInvalida();		
	}	
}while(!queroSair);
} // Fim da função "insereElemento()".


//******************************************************
//* Função "mostraElementos()"
//* -> mostra os elemento da lista ligada ("linked list"). 
//******************************************************
//* Entrada(s): 
//*            node_list *lista - ponteiro para o início
//*                               da lista.
//* Saida(s):  não tem. 
//***********************************************************
void mostraElementos(node_list *lista) {
	
// 1. Dados
char escolha = '\0';
bool queroSair = false;


// 2. Algoritmo
	do {
	system("cls");	system("color A");		
	cout<<"**************************************************************"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"* A. Apresenta os elementos da estrutura de dados.           *"<<endl;
	cout<<"* B. Ordena elementos de forma ascendente.                   *"<<endl;
	cout<<"* C. Ordena elementos de forma descendente.                  *"<<endl;
	cout<<"* D. Voltar ao menu anterior.                                *"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"**************************************************************"<<endl;	
	escolha = obtemEscolha(escolha,4);

	switch(escolha)
	{
	case  'A': case 'a':  // Apresenta os elementos da estrutura de dados.
		 {
		 print_list(lista);pausa();break;
		 }
	case  'B': case 'b':  // Ordena elementos de forma ascendente.
		 {
	     sort_list(lista, true);pausa();break;
		 }
	case  'C': case 'c':  // Ordena elementos de forma descendente. 
		 {
	     sort_list(lista, false);pausa();break;
		 }
	case  'D': case 'd':  //  Voltar ao menu anterior.
	      queroSair = sairDoPrograma(queroSair); break;
		 
	default:
	     escolhaInvalida();		
	}	
	}while(!queroSair);
	
} // Fim da função "mostraElemento()".


//******************************************************
//* Função "pesquisaElemento()"
//* -> pesquisa por um ou mais elementos na lista ligada
//*                                     ("linked list"). 
//******************************************************
//* Entrada(s): 
//*            node_list *lista - ponteiro para o início
//*                               da lista.
//* Saida(s): não tem. 
//***********************************************************
	void pesquisaElemento(node_list *lista) {
		
	// 1. Dados
	char escolha = '\0';
	bool queroSair = false;
	
	
	// 2. Algoritmo
	do {
	system("cls");	system("color A");	
	cout<<"**************************************************************"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"* A. Pesquisa por posição na estrutura de dados.             *"<<endl;
	cout<<"* B. Pesquisa por valor na estrutura de dados.               *"<<endl;
	cout<<"* C. Voltar ao menu anterior.                                *"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"**************************************************************"<<endl;	
	escolha = obtemEscolha(escolha,3);

	switch(escolha)
		{
		case  'A': case 'a':  // Pesquisa por posição na estrutura de dados.
			 {
			 int pos = 0;	
			 cout<<"Qual a posição a pesquisar (0-"<<size(lista);
			 cout<<")? "; cin>>pos;
			 search_by_index(lista, pos);
			 pausa();break;
			 }
		case  'B': case 'b':  // Pesquisa por valor na estrutura de dados.
			 {
			 int valor = 0;	
			 cout<<"Qual o valor a pesquisar? "; cin>>valor;	
			 search_by_value(lista, valor);
			 pausa();break;
			 }
		case  'C': case 'c':  // Voltar ao menu anterior. 
		      queroSair = sairDoPrograma(queroSair); break;
	default:
	     escolhaInvalida();		
	}	
}while(!queroSair);
	
} // Fim da função "pesquisaElemento()".



//******************************************************
//* Função "atualizaElemento()"
//* -> atualiza ou ou mais elementos na lista ligada
//*                                     ("linked list"). 
//******************************************************
//* Entrada(s): 
//*            node_list *lista - ponteiro para o início
//*                               da lista.
//* Saida(s): não tem. 
//***********************************************************
	void atualizaElemento(node_list *lista) {
		
	// 1. Dados
	char escolha = '\0';
	bool queroSair = false;
	
	
	// 2. Algoritmo
	do {
	system("cls");	system("color A");	
	cout<<"**************************************************************"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"* A. Atualiza por posição na estrutura de dados.             *"<<endl;
	cout<<"* B. Atualiza por valor na estrutura de dados.               *"<<endl;
	cout<<"* C. Voltar ao menu anterior.                                *"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"**************************************************************"<<endl;	
	escolha = obtemEscolha(escolha,3);

	switch(escolha)
		{
		case  'A': case 'a':  // Pesquisa por posição na estrutura de dados.
			 {
			 int pos = 0;	
			 cout<<"Qual a posição a atualizar? "; cin>>pos;
			 int novoValor = 0;	
			 cout<<"Qual o novo valor a inserir? "; cin>>novoValor;	 	
			 update_by_index(lista, pos,novoValor);
			 cout<<"Valor atualizado com sucesso!";
			 pausa();break;
			 }
		case  'B': case 'b':  // Pesquisa por valor na estrutura de dados.
			 {
			 int valor = 0;	
			 cout<<"Qual o valor a atualizar? "; cin>>valor;
			 int novoValor = 0;	
			 cout<<"Qual o novo valor a inserir? "; cin>>novoValor;	 	
			 update_by_value(lista, valor,novoValor);
			 cout<<"Valor(es) atualizado(s) com sucesso!";
			 pausa();break;
			 }
		case  'C': case 'c':  // Voltar ao menu anterior. 
		      queroSair = sairDoPrograma(queroSair); break;
		 
	default:
	     escolhaInvalida();		
	}	
}while(!queroSair);
	
} // Fim da função "atualizaElemento()".



//******************************************************
//* Função "removeElemento()"
//* -> remove um ou mais elementos 
//*                  na lista ligada ("linked list"). 
//******************************************************
//* Entrada(s): 
//*            node_list *lista - ponteiro para o início
//*                               da lista.
//* Saida(s): não tem. 
//***********************************************************
	void removeElemento(node_list **lista) {
		
	// 1. Dados
	char escolha = '\0';
	bool queroSair = false;
	
	
	// 2. Algoritmo
	do {
	
	system("cls");system("color A");		
	cout<<"**************************************************************"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"* A. Remover um elemento no inicio da lista.                 *"<<endl;
	cout<<"* B. Remover um elemento no fim da lista.                    *"<<endl;
	cout<<"* C. Remover um elemento numa determinada posição da lista.  *"<<endl;
	cout<<"* D. Remover elemento por valor na lista (primeiro).         *"<<endl;
	cout<<"* E. Remover todos os elementos por valor na lista.          *"<<endl;
	cout<<"* F. Remover toda a estrutura.                               *"<<endl;
	cout<<"* G. Voltar ao menu anterior.                                *"<<endl;
	cout<<"*                                                            *"<<endl;
	cout<<"**************************************************************"<<endl;	
	print_list(*lista);
	escolha = obtemEscolha(escolha,7);

	switch(escolha)
		{
		case  'A': case 'a':  // Remover um elemento no inicio da lista..
			 {
			 if (size(*lista) == 0)
			    {
			    cout<<"A lista está vazia."<<endl;	
				} 
			 else 
			    {
			    pop(lista); print_list(*lista); 
				cout<<"Elemento removido com sucesso!";
			    }
		     pausa();break;
			 }
		case  'B': case 'b':  // Remover um elemento no fim da lista.
			 {
			 if (size(*lista) == 0)
			    {
			    cout<<"A lista está vazia."<<endl;	
				} 
			 else 
			   {
			    remove_last(*lista); print_list(*lista);	 
				cout<<"Elemento removido com sucesso!";
			   }
		     pausa();break;
			 }
		case  'C': case 'c':  // Remover um elemento numa 
		                      //           determinada posição da lista.
			 {
			 if (size(*lista) == 0)
			    {
			    cout<<"A lista está vazia."<<endl;	
				} 
			 else 
			    {
			   int pos = 0;
		       do {
			    cout<<"Qual o valor da posição (0-"<<size(*lista)-1;
			    cout<<")? "; cin>>pos;	
			    if (pos < 0 || pos >= size(*lista))	
			        cout<<"Posição inválida!! Tente de novo!!";
			    } while(pos < 0 || pos >= size(*lista));
			    if (remove_by_index(lista, pos) != -1)	
			       cout<<"Valor removido com sucesso!";
			    print_list(*lista);   
			   }
			  pausa();break;
			   }
		case  'D': case 'd':  // Remover elemento por valor na lista (primeiro). 
		                      
			 {
			 if (size(*lista) == 0)
			    {
			    cout<<"A lista está vazia."<<endl;	
				} 
			 else 
			    {
			    int valor = 0;
			    cout<<"Qual o valor a remover? "; cin>>valor;	
			    if (remove_by_value(lista, valor) != -1)	
			       cout<<"Valor removido com sucesso!"; 
			    print_list(*lista);
			    }
		        pausa();break;
			    }
		case  'E': case 'e':  // Remover todos os elementos 
		                      // por valor na lista. 
			 {
			 if (size(*lista) == 0)
			    {
			    cout<<"A lista está vazia."<<endl;	
				} 
			 else 
			    {
			    int valor = 0;
			    cout<<"Qual o valor a remover? "; cin>>valor;	
			    if (remove_by_valueAll(lista, valor) != -1)	
			    cout<<"Valor(es) removido(s) com sucesso!"; 
			    print_list(*lista);
			    }
		        pausa();break;
			    }    
		case  'F': case 'f':  // Remover todos os elementos..
			 {
			 if (size(*lista) == 0)
			    {
			    cout<<"A lista está vazia."<<endl;	
				} 
			 else 
			   {
			    delete_list(lista); 
				cout<<"Elemento(s) removido(s) com sucesso!";
				print_list(*lista);
			   }
		     pausa();break;
			 }  
		case  'G': case 'g':  //  Voltar ao menu anterior.
		      queroSair = sairDoPrograma(queroSair); break;
			 
	default:
	     escolhaInvalida();		
	}	
}while(!queroSair);
	
} // Fim da função "removeElemento()".




//*************************************************
//*  Função "sairDoPrograma()"
//*   Entrada(s): queroSair (bool) 
//*   Saida(s): queroSair (bool)
//*************************************************
	bool sairDoPrograma(bool queroSair)
		{
		char resposta = '\0';
			fflush(stdin);
			cout<<"Tem a certeza (S/N)? ";
		    cin>>resposta;
			// cin.ignore();	
			if (resposta == 'S'  ||  resposta == 's')
			   queroSair = true;	
	return queroSair;	
} // Fim da função "sairDoPrograma()".


//**************************************************
//* Função "escolhaInvalida()"
//*  Entrada(s): não tem.
//*  Saida(s): não tem.
//**************************************************
	void escolhaInvalida()
	{
	  cout<<"Escolha inválida!\n"; system("pause");	
	} // Fim da função "escolhaInvalida()".


//***************************************************
//*  Função "despedida()"
//*   Entrada(s): não tem.
//*   Saida(s): não tem.
//***************************************************
	void despedida()
	{
	cout<<"Obrigado por ter utilizado o nosso \"software\"!\n";
	pausa();
	} // Fim da função "despedida()".	


//***************************************************
//*  Função "pausa()"
//*   Entrada(s): não tem.
//*   Saida(s): não tem.
//***************************************************
	void pausa()
	{
	fflush(stdin);	
	cout<< "\nPrima qualquer tecla para continuar ... ";
	cin.get();
	} // Fim da função "pausa()".




