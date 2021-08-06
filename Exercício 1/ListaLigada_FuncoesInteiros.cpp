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
 
// função print_List()
 
// Entrada:
	//	node_list * head -> ponteiro para o inicio da lista ligada
	//  Saida (s): não tem.
 
	void print_list(node_list * head) {
	// Declaração de um ponteiro
	// que vai percorrendo a lista
	node_list * current = NULL; 
	current=head;
	
	if(size(head) == 0)
	{
		cout<<"Lista vazia.\n"
	}
	else{
		while(current != NULL){
			printf("%d",current->val);
			current = current->next;
		}
		cout<<endl;
	}//fim da função

	// função sort_list()
	
	void sort_list(node_list * head,bool asc){
		
	// Declaração de um ponteiro que vai percorrendo a lista
	
	node_list * before = head; 
	node_list * after = NULL; 
	int temp = 0;
	bool houveTroca = false;
	
	if (size (head) >=2){
		do
		{
			before = head; 
			houveTroca = false; 
		for(int cElemento=0; cElemento<(size(head)-1); cEIemento++)
		
		{
			if (cElemento>0 && before->next != NULL) 
			before = before->next; 
				if (before->next != NULL) 
				after = before->next;
				
			if (before->val > && asc)
			{
				houveTroca = true ;
				temp = after->val;
				after->val = before->val;
				before->val = temp;
		}
	else if (before->val < after->val && != asc)
	{
		houveTroca = true;
		temp = after->val;
		after->val = before->val;
		before->val = temp;
	}
	}
	} while (houveTroca) 
		print_list(head)
	else
		cout<<"Lista de im só elemento ou lista vazia."<<endl;
}// fim da função

	// função search_by_index()	
	
	int search_by_index(node_list *head, int n) {
	// 1. Dados 
		int i = 0;
		int retval = -1;
		node_list * current = head;
		
	// 2. Algoritmo 
	if (current == NULL){
		cout<<"Lista vazia!"<<endl;
		return -1;
	}
	else if (n == 0)	
		cout<<current->val<<endl;
		return current->val;
	}
	else if (n > size(head))
	{
		cout<<"Posições começam de 0."<<endl;
			cout<<"Estrutura só tem "<<size(head)<<" elementos."<<endl;
		return -1;
	}
	else
	{
		for(i = 0; i < n; i++){
			current = current->next;
		}
		cout<<current->val<<endl;
		return current->val;
	}
}//fim da função
 
	// função search_by_value()	
		int search_by_value(node_list *head, int val) {
	// 1. Dados 
		int pos = 0;
		int retval = -1;
		bool encontrouValor = false;
		node_list * current = head;
		
	// 2. Algoritmo 
	if (current == NULL){
		cout<<"Lista vazia!"<<endl;
		return -1;
	}
	else 
	{
		while(current != NULL)
	}
		if(current->val == val)
			{
				cout<<"Valor encontrado na posição: "<<pos<<"."<<endl;
				encontrouValor = true;
			}
			current = current->next;
			pos++;
			}
			if (encontrouValor)
				return (pos-1);
			else 
			{
				cout<<"Valor não encontrado na estrutura de dados."<<endl;
				return -1;
			}
		}
	}// fim da função

	// função update_by_index()
	int update_by_index(node_list *head , int n, int newVal){
		
	// 1. Dados  
		int i = 0;
		int retval = -1;
		node_list * current = head;
		
	// 2. Algoritmo 
	if (current == NULL){
		cout<<"Lista vazia!"<<endl;
		return -1;
	}
	else if (n == 0)	
		current->val = newVal;
		return n;
	}
	else if (n > size(head))
	{
		cout<<"Posições começam de 0."<<endl;
			cout<<"Estrutura só tem "<<size(head)<<" elementos."<<endl;
		return -1;
	}
	else
	{
		for(i = 0; i < n; i++){
			current = current->next;
		}
		current->val = newVal;
		return n;
	}
}//fim da função	 	 	 	 	 

	// função update_by_value()	
		int update_by_value(node_list *head, int val, int newVal) {
	// 1. Dados 
		int pos = 0;
		int retval = -1;
		bool encontrouValor = false;
		node_list * current = head;
		
	// 2. Algoritmo 
	if (current == NULL){
		cout<<"Lista vazia!"<<endl;
		return -1;
	}
	else 
	{
		while(current != NULL)
	}
		if(current->val == val)
			{
				cout<<"Valor encontrado na posição: "<<pos<<"."<<endl;
				current->val = newVal;
				encontrouValor = true;
			}
			current = current->next;
			pos++;
			}
			if (encontrouValor)
				return (pos-1);
			else 
			{
				cout<<"Valor não encontrado na estrutura de dados."<<endl;
				return -1;
			}
		}
	}// fim da função
	 
	// função remove_last()
	
	int remove_last (node_list * head) { 
	int retval = 0:
		
	/* if there is only one item in the list, remove it */
	if (head->next NULL) {
		retval = head->val;
		free(head);
		return retval;
	}
	/* get to the second to last node in the list */
	node_list * current = head; 
	while (current->next->next != NULL) {
	 current = current->next;
}
	/* now current points to the second to last item of the list, so let's remove current->next */
	retval = current->next->val;
	free(current->next);
	current->next = NULL;
	return retval;
}//fim da função

	// função pop()
	int pop(node_list ** head) {
		
	// Declaração de dados 
	int retval = -1 				// Guarda o valor a devolver 
	node_list * next_node = NULL;  // Ponteiro auxiliar
	
	if (*head == NULL){   // Se a Lista estiver 
	return -1; 			// vazia
	}
	else {	
		next_node = (*head)->next; 	// Define o novo primeiro elemento da lista 
		retval = (*head)->val;		// Obtém o valor a ser retirado
		free ( *head)				// Liberta a posição de memória ocupada pelo primeiro elemento
		*head = next_node;			// Define o novo inicio da lista 
		return reeval; 				// Devolve o valor retirado
	}
}// Fim da função	 
	
	// função remove_by_index()	
	 
	int remove_by_index (node_list ** head, int n) {
		
		// Declaração de dados 
		int i = 0;
		int retval = -1; 
		node_list * current = *head; 
		node_list * temp_node = NULL;
		
		if(n == 0){
			return pop(head);
		}
		for (i = 0; i < n-1;i++){
			if(current->next == NULL){
				return -1;
			}
			current = current->next;
		}
	}// fum da função

		// função remove_by_value()	
	 
	int remove_by_value(node_list ** head, int val) {
		
		// Declaração de dados 
		node_list *previous, *current; // dois ponteiros. um aponta para a posição anterior
									   // e outro para a posição corrente.
	if(*head == NULL) {			// Se a Lista estiver 
	return -1;
	}
	else if((*head)->val == val) {    	// Se for o primeiro
			return pop(head);  			// elemento
		}
		else {
			previous = current = (*head)->next;
			while (current) {			// Enquanto não chegar ao fim da lista "current != NULL"
			  	 
		    if (current->val == val) { 
			previous->next =current->next
			free(current);
			return val;
		}
		previous = current; 
		current = current->next;
		}
	}
	return -1;
}//fim da função


		// função remove_by_valueAll()	
	 
	int remove_by_valueAll(node_list ** head, int val) {
		
		// Declaração de dados 
		node_list *previous, *current; // dois ponteiros. um aponta para a posição anterior
									   // e outro para a posição corrente.
	
		bool encontrouValor =  false;
		
	if(*head == NULL) {			// Se a Lista estiver 
	return -1;
	}
	else if((*head)->val == val) {    	// Se for o primeiro
			return pop(head);  			// elemento
		}
		else {
			previous = *head;
			current = (*head)->next;
			while (current) {			// Enquanto não chegar ao fim da lista "current != NULL"
			  	 
		    if (current->val == val) { 
			previous->next = current->next
			free(current);
		}
		previous = current; 
		current = current->next;
		}
		return val;
	}
	return -1;
}//fim da função

	// função delete_list()
	
	void delete_list(node_list **head){
		
		// delcaração de dados
	node_list *current = *head, 
		// Ponteiro que aponta para o elemento a ser eliminado.
		// É inicializado para a cabeça da lista.
	*next = *head; 
		// Ponteiro que aponta para o próximo elemento.
		// É inicializado para a cabeça da lista.
		
	while (current != NULL) {	// Enquanto não chegar ao fim da lista "current != NULL"
	next  = current->next;  // O ponteiro 'next' aponta para o próximo elemento.
	free(current); // Elimina o elemento corrente.
	current = next;	// O ponteiro corrente passa a apontar para o novo primeiro da lista.
	}
	*head = NULL;
}	// Fim da função .


	
	
