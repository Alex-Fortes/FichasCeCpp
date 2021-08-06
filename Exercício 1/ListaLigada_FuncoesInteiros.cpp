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
	// fun��o remove_by_value() -> Retira um elemento de uma lista ligada atrav�s do seu valor (primeira ocorrencia).
	
	int remove_by_valueAll(node_list**, int);
	// fun��o remove_by_valueAll -> Retira um elemento de uma lista ligada atrav�s do seu valor (todas as ocorrencias)
	
	void delete_list(node_list**);  
	// fun��o delete_list() -> Elimina toda a lista ligada.
	
// fun��o size() -> devolve o n�mero de elementos da lista ligada	

	// Entrada:
//	node_list*head -> ponteiro para o in�cio da lista ligada

	// Saida
// n�mero da estutura de dados ou zero se a lesta n�o existir.

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
} // Fim da fun��o size()
	 
	void pushfirst (node_list ** head, int val) {
	
		node_list * new_node; 
		new_node = (node_list*)malloc(sizeof(node_list));
		
		new_node->val = val;
		new_node->next = *head;
		*head = new_node; 
	}// Fim da fun��o
	
	void push(node_list ** head, int val) {
	// Dados 
	node_list * current = *head;
	// Ponteiro que aponta para a �ltima posi��o da lista ligada.
	// � inicializado para o inicio da lista .
	
	// Algoritmo
	// 1. lista vazia
	if (size(*head)==0)
	{
		pushfirst(head,val);
	}
	// 2. Obt�m o �ltimo elemento da lista
	while (current->next != NULL) {
	current = current->next;
}
	// 3. Insere um novo elemento na �ltima posi��o 
	current->next = (node_list*)malloc(sizeof(node_list));
	current->next->val  = val;
	current->next->next = NULL;
}
	
	// fun��o add_by_index () -> Insere um elemento numa determinada posi��o de uma lista ligada
	 
	// Entrada(s): 
	//	node_list ** head	-> ponteiro para ponteiro para o inicio da lista ligada.
	//						-> posi��o.
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
		cout<<"Elemento inserido na primeira posi��o."<<endl;
		return val;
	}
	else if (n > size(*head))
	{
		cout<<"Posi��es come�am de 0."<<endl;
		cout<<"Estrutura s� tem "<<size(*head)<<"elementos."<<endl;
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
	// Defini��o do novo elemento 
	node_list * new_node;
	new_node = (node_list*) malloc(sizeof(node_list));
	new_node->val = val; 
	new_node->next = NULL;
	
	// Inser��o do novo elemento entre "before" e "after" 
	before->next = new_node;
	new_node->next = after; 
	return retval;
}
} // fim da fun��o
 
// fun��o print_List()
 
// Entrada:
	//	node_list * head -> ponteiro para o inicio da lista ligada
	//  Saida (s): n�o tem.
 
	void print_list(node_list * head) {
	// Declara��o de um ponteiro
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
	}//fim da fun��o

	// fun��o sort_list()
	
	void sort_list(node_list * head,bool asc){
		
	// Declara��o de um ponteiro que vai percorrendo a lista
	
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
		cout<<"Lista de im s� elemento ou lista vazia."<<endl;
}// fim da fun��o

	// fun��o search_by_index()	
	
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
		cout<<"Posi��es come�am de 0."<<endl;
			cout<<"Estrutura s� tem "<<size(head)<<" elementos."<<endl;
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
}//fim da fun��o
 
	// fun��o search_by_value()	
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
				cout<<"Valor encontrado na posi��o: "<<pos<<"."<<endl;
				encontrouValor = true;
			}
			current = current->next;
			pos++;
			}
			if (encontrouValor)
				return (pos-1);
			else 
			{
				cout<<"Valor n�o encontrado na estrutura de dados."<<endl;
				return -1;
			}
		}
	}// fim da fun��o

	// fun��o update_by_index()
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
		cout<<"Posi��es come�am de 0."<<endl;
			cout<<"Estrutura s� tem "<<size(head)<<" elementos."<<endl;
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
}//fim da fun��o	 	 	 	 	 

	// fun��o update_by_value()	
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
				cout<<"Valor encontrado na posi��o: "<<pos<<"."<<endl;
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
				cout<<"Valor n�o encontrado na estrutura de dados."<<endl;
				return -1;
			}
		}
	}// fim da fun��o
	 
	// fun��o remove_last()
	
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
}//fim da fun��o

	// fun��o pop()
	int pop(node_list ** head) {
		
	// Declara��o de dados 
	int retval = -1 				// Guarda o valor a devolver 
	node_list * next_node = NULL;  // Ponteiro auxiliar
	
	if (*head == NULL){   // Se a Lista estiver 
	return -1; 			// vazia
	}
	else {	
		next_node = (*head)->next; 	// Define o novo primeiro elemento da lista 
		retval = (*head)->val;		// Obt�m o valor a ser retirado
		free ( *head)				// Liberta a posi��o de mem�ria ocupada pelo primeiro elemento
		*head = next_node;			// Define o novo inicio da lista 
		return reeval; 				// Devolve o valor retirado
	}
}// Fim da fun��o	 
	
	// fun��o remove_by_index()	
	 
	int remove_by_index (node_list ** head, int n) {
		
		// Declara��o de dados 
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
	}// fum da fun��o

		// fun��o remove_by_value()	
	 
	int remove_by_value(node_list ** head, int val) {
		
		// Declara��o de dados 
		node_list *previous, *current; // dois ponteiros. um aponta para a posi��o anterior
									   // e outro para a posi��o corrente.
	if(*head == NULL) {			// Se a Lista estiver 
	return -1;
	}
	else if((*head)->val == val) {    	// Se for o primeiro
			return pop(head);  			// elemento
		}
		else {
			previous = current = (*head)->next;
			while (current) {			// Enquanto n�o chegar ao fim da lista "current != NULL"
			  	 
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
}//fim da fun��o


		// fun��o remove_by_valueAll()	
	 
	int remove_by_valueAll(node_list ** head, int val) {
		
		// Declara��o de dados 
		node_list *previous, *current; // dois ponteiros. um aponta para a posi��o anterior
									   // e outro para a posi��o corrente.
	
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
			while (current) {			// Enquanto n�o chegar ao fim da lista "current != NULL"
			  	 
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
}//fim da fun��o

	// fun��o delete_list()
	
	void delete_list(node_list **head){
		
		// delcara��o de dados
	node_list *current = *head, 
		// Ponteiro que aponta para o elemento a ser eliminado.
		// � inicializado para a cabe�a da lista.
	*next = *head; 
		// Ponteiro que aponta para o pr�ximo elemento.
		// � inicializado para a cabe�a da lista.
		
	while (current != NULL) {	// Enquanto n�o chegar ao fim da lista "current != NULL"
	next  = current->next;  // O ponteiro 'next' aponta para o pr�ximo elemento.
	free(current); // Elimina o elemento corrente.
	current = next;	// O ponteiro corrente passa a apontar para o novo primeiro da lista.
	}
	*head = NULL;
}	// Fim da fun��o .


	
	
