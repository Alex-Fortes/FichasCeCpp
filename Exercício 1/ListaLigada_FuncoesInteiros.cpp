// lista ligada

// Que operações se podem efetuar numa lsita ligada?

// - Obter número de elementos de estrutura de dados;
// - Adicionar um elemento no fim da lista
// - Adicionar um elemento no inicio da lista
// - Adicionar um elemento numa determinada posição da lista ligada

// - Atualizar um elemento numa determinada posição da lista ligada
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
	
// Funções de estrutura ligada - "Linked list"
// Lista de funções

	int size(node_list*);
	// função size() -> devolve o número de elementos da lista ligada
	
	void pushfirst(node_list**,int);
	// função pushfirst() -> insere o primeiro elemento da lista ligada
	
	void push (node list* * , int)
	// função push() -> Insere um elemento no fim da lista ligada
		 
	int add_by_index(node_list**, int, int)
	// função add_by_index() -> Insere um elemento numa determinada  posição de uma lista ligada 
	
	void print_list(node_list*);
	// funlão print_List() -> Apresenta os elementos de uma lista ligada
	
	void sort_list(node_list* , bool);
	// função  sort List() -> Ordena os elementos de uma lista ligada

	int search_by_index(node_list* , int);
	// função search_by_index() ->  Pesquisa de um elemento numa determinada posição de uma lista ligada. 
	
	int search_by_value(node_list* , int);
	// função search_by_value() -> Pesquisa de elementos numa lista ligada
		 //	("linked list") pelo valor guardado. Apresenta todas as ocorrências.
	
	int update_by_index(node_list*, int , int);
	// função  update_by_index() -> Atualiza um elemento através da posição da lista ligada.
	
	int update_by_value(node_list*, int, int)
	// função update_by_value() -> Atualiza um elemento de uma lista ligada pelo valor guardado.
	// Atualiza todas as ocorréncias.
	
	int pop(node_list**);
	// função pop() -> Retira o primeiro elemento de uma lista ligada.
	 
	int remove_last(node_list*);
	// função remove_last() -> Retira o último elemento de uma lista ligada .
	 
	int remove_by_index(node_list** , int);
	// função  remove_by_index() -> Retira um elemento de uma lista ligada através da sua posição na lista.
	
	int remove_by_value(node_list**, int);
	// função remove_by_value() -> Retira um elemento de uma lista ligada através do seu valor (primeira ocorrancia).
	
	int remove_by_valueAll(node_list**, int);
	// função remove_by_valueAll
	- > Retira um elemento de uma lista ligada através   do seu valor (todas as ocorrancias)
	void delete list (node  
	// * Fungäo "delete list ( ) "
		// * 	Elimina toda a lista ligada .
	 
	

	
