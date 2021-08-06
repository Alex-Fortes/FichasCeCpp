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
	// função remove_by_value() -> Retira um elemento de uma lista ligada através do seu valor (primeira ocorrencia).
	
	int remove_by_valueAll(node_list**, int);
	// função remove_by_valueAll -> Retira um elemento de uma lista ligada através do seu valor (todas as ocorrencias)
	
	void delete_list(node_list**);  
	// função delete_list() -> Elimina toda a lista ligada.
	
// função size() -> devolve o número de elementos da lista ligada	

	// Entrada:
//	node_list*head -> ponteiro para o início da lista ligada

	// Saida
// número da estutura de dados ou zero se a lesta não existir.

	int size(node_list*head){
		node_list *aux = NULL;
	
	if (head == NULL)	// Lista vazia.
	return 0;
	else
	{
	int numE=0; aux = head; 
	while (aux . = NULL){
		numE ++ ; aux = aux->next; 
	}
	return numE;
} // Fim do else.
} // Fim da função size()
	 
	void pushfirst (node_list ** head, int val) {
	
		node_list * new_node; 
		new_node = (node_list*)malloc(sizeof(node_list));
		
		new_node->val = val;
		new_node->next = *head;
		*head = new_node; 
	}// Fim da função
	
	void push(node_list ** head, int val) {
	// Dados 
	node_list * current = *head;
	// Ponteiro que aponta para a última posição da lista ligada.
	// É inicializado para o inicio da lista .
	
	// Algoritmo
	// 1. lista vazia
	if (size(*head)==0)
	{
		pushfirst(head,val);
	}
	// 2. Obtém o último elemento da lista
	while (current->next != NULL) {
	current = current->next;
}
	// 3. Insere um novo elemento na última posição 
	current->next = (node_list*)malloc(sizeof(node_list));
	current->next->val  = val;
	current->next->next = NULL;
}
	
	// função add_by_index () -> Insere um elemento numa determinada posição de uma lista ligada
	 
	// Entrada(s): 
	//	node_list ** head	-> ponteiro para ponteiro para o inicio da lista ligada.
	//						-> posição.
	//						-> valor a inserir
	
	//  Saida(s): devolve valor inserido ou -1 em caso de erro.
	 
	int add_by_index(node_list * *head, int n, int val) {
	// 1. Dados
		int i=0;
		int retval = -1;
		node_list * before = *head;
		node_list * after = NULL;
		
	// 2. Algoritmo
	if (*head == NULL)
	{
		cout<<"Lista vazia!"<<endl;
		return -1;
	}
	else
	if(n == 0){
		pushtirst(head, val);
		cout<<"Elemento inserido na primeira posição."<<endl;
		return val;
	}
	else if (n > size(*head))
	{
		cout<<"Posições começam de 0."<<endl;
		cout<<"Estrutura só tem "<<size(*head)<<"elementos."<<endl;
		return -1;
	}
	else if(n == size(*head))
	{
		push(head,val);
		return val;
	}
	else{
		for (i = 0; i < n; i++){
			if (i>=1)
			before = before->next;
			
				if (before->next != NULL)
					after = before->next;
		}
	// Definição do novo elemento 
	node_list * new_node;
	new_node = (node_list*) malloc(sizeof(node_list));
	new_node->val = val; 
	new_node->next = NULL;
	
	// Inserção do novo elemento entre "before" e "after" 
	before->next = new_node;
	new_node->next = after; 
	return retval;
}
} // fim da função
 
// * Fungäo "print List ( ) "
	// * 	Apresenta os elementos de uma lista ligada
( linked list")
 
// * Entrada (s) .
node list * head - > ponteiro para o inicio da lista
ligada .
// * Saida (s) : näo tem.
 
void print list (node list  *  head) { // Declaraqäo de um ponteiro
/ / que vai percorrendo a 1 is ta node list * current = NULL ; curren t=head ;



	 
	

	
