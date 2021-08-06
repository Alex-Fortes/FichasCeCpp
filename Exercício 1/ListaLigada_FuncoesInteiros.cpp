// lista ligada

// Que opera��es se podem efetuar numa lsita ligada?

// - Obter n�mero de elementos de estrutura de dados;
// - Adicionar um elemento no fim da lista
// - Adicionar um elemento no inicio da lista
// - Adicionar um elemento numa determinada posi��o da lista ligada

// - Atualizar um elemento numa determinada posi��o da lista ligada
// - Pesquisar um elemento numa determinada

// Bibliotecas de C
#include <cstudio>
#include <cstdlib>
#include <clocale>

// Bibliotecas de C++
#include <iostream>
using namespace std;

// Estrutura de Dados

	typedef struct node {
		int val;
		struct node*next;
	}; node_list;  // novo tipo de dados
	
// Fun��es de estrutura ligada - "Linked list"
// Lista de fun��es

	int size(node_list*);
	// fun��o size() -> devolve o n�mero de elementos da lista ligada
	
	void pushfirst(node_list**,int);
	// fun��o pushfirst() -> insere o primeiro elemento da lista ligada
	
	void push (node list* * , int)
	// fun��o push() -> Insere um elemento no fim da lista ligada
		 
	int add_by_index(node_list**, int, int)
	// fun��o add_by_index() -> Insere um elemento numa determinada  posi��o de uma lista ligada 
	
	void print_list(node_list*);
	// funl�o print_List() -> Apresenta os elementos de uma lista ligada
	
	void sort_list(node_list* , bool);
	// fun��o  sort List() -> Ordena os elementos de uma lista ligada

	int search_by_index(node_list* , int);
	// fun��o search_by_index() ->  Pesquisa de um elemento numa determinada posi��o de uma lista ligada. 
	
	int search_by_value(node_list* , int);
	// fun��o search_by_value() -> Pesquisa de elementos numa lista ligada
		 //	("linked list") pelo valor guardado. Apresenta todas as ocorr�ncias.
	
	int update_by_index(node_list*, int , int);
	// fun��o  update_by_index() -> Atualiza um elemento atrav�s da posi��o da lista ligada.
	
	int update_by_value(node_list*, int, int)
	// fun��o update_by_value() -> Atualiza um elemento de uma lista ligada pelo valor guardado.
	// Atualiza todas as ocorr�ncias.
	
	int pop(node_list**);
	// fun��o pop() -> Retira o primeiro elemento de uma lista ligada.
	 
	int remove_last(node_list*);
	// fun��o remove_last() -> Retira o �ltimo elemento de uma lista ligada .
	 
	int remove_by_index(node_list** , int);
	// fun��o  remove_by_index() -> Retira um elemento de uma lista ligada atrav�s da sua posi��o na lista.
	
	int remove_by_value(node_list**, int);
	// fun��o remove_by_value() -> Retira um elemento de uma lista ligada atrav�s do seu valor (primeira ocorrancia).
	
	int remove_by_valueAll(node_list**, int);
	// fun��o remove_by_valueAll
	- > Retira um elemento de uma lista ligada atrav�s   do seu valor (todas as ocorrancias)
	void delete list (node  
	// * Fung�o "delete list ( ) "
		// * 	Elimina toda a lista ligada .
	 
	

	
