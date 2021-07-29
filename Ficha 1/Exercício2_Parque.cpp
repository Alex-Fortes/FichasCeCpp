/*
	Parque
	Fazer um programa que gere um parque de estacionamento com sete posições.
	 O programa deve apresentar um menu com as seguintes op?ões: 
	 - Listar lugares; - Marcar lugar; - Libertar lugar; - Sair do progroma.  
*/

// Inclusão de Bibliotecas: C
#include <stdio.h>  // Funções: "scanf()", "printf()"
#include <stdlib.h> // Funções: "system()".
#include <locale.h> // "setlocale()"
#include <math.h>   // "pow()", "sqrt()"
#include <conio.h>  // "getch()"

// Inclusão de Bibliotecas: C++

#include <iostream> // Contém o "cin" e o "cout"
#include <iomanip>  // Contém "setprecision()"
using namespace std; // Selecionar o "std" como espaço de nomes
                     // predefinido.

//* 2. Dados Globais
	const char LIVRE = 'L', OCUPADO = 'O' ;
	void inicializaParque(char[], int); void mostraMenu();
	char obtemEscolha(char );
	bool processaEscolha(char, char[],
	int, bool) ; void listarLugares(char[], int); 
	void marcarLugar(char[], int);
	void libertarLugar(char[], int); bool sairDoPrograma(bool);
	void escolhaInvalida(char); void despedida();

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	  const int NUMLUGARES = 7; 
	  char lugares[NUMLUGARES]; 
	  char escolha = '\0' ;
	  bool queroSair = false;    
 	inicializaParque(lugares, NUMLUGARES);
	do{
		
	mostraMenu();
	escolha = obtemEscolha(escolha); queroSair =
	processaEscolha(escolha,lugares,
	NUMLUGARES, queroSair);
	}while(!queroSair); 
	despedida();
return 0;
}
 //* Função "inicializaParque()"


	void inicializaParque(char lugares[], int numElementos)
	{
	for(int cLugar= 0; cLugar < numElementos;
	cLugar++) lugares[cLugar] = LIVRE;
} // Fim da função.

 //* Função "mostraMenu()"


	void mostraMenu()
	{
	
	system("cls"); system("color A");
	cout<<"**********************************"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*       Parque Guest             *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*         A. Listar              *"<<endl;	
	cout<<"*         B. Marcar lugar.       *"<<endl;
	cout<<"*         C. Libertar lugar.     *"<<endl;
	cout<<"*         D. Sair do programa.   *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"**********************************"<<endl;
cout<<endl;
} // Fim da função.

	//* Função "obtemEscolha()"


	char obtemEscolha(char escolha)
	{
	cout<<"Qual a sua escolha (A-D)? "; cin>>escolha;
return escolha;
}

//* Função "processaEscolha()"

 bool processaEscolha(char escolha, char lugares[], int numLugares, bool queroSair)
{
	switch(escolha)
	{
	case 'a': case 'A': 
	listarLugares(lugares, numLugares); break;
	case 'b': case 'B': 
	marcarLugar(lugares, numLugares); break;
	case 'c': case 'C':
	libertarLugar(lugares, numLugares); break;
	case 'd': case 'D':
	queroSair = sairDoPrograma(queroSair); break;
	default: escolhaInvalida(escolha);
}
return queroSair;
}	// Fim da função.

//* Função "listarLugares()"

	void listarLugares(char lugares[],
	int numLugares)
	{
	cout<<"Listagem de lugares: "<<endl;
	for (int cLugar=0; cLugar < numLugares;cLugar++)
	{
	cout<<"Lugar "<<(cLugar+1)<<": "; if (lugares[cLugar] == LIVRE)
	cout<<"livre."<<endl; 
	else
	cout<<"ocupado."<<endl;
}
system("pause");
}	// Fim da função.

//* Função "marcarLugar()"

	void marcarLugar(char lugares[], int numLugares)
{
	int numLugar = 0; 
	do {
	cout<<"Qua1 o lugar a ocupar (1-"; cout<<numLugares<<")? "; cin>>numLugar;

	if (numLugar >= 1 && numLugar <= numLugares)
	{
		if (lugares[numLugar-1] == LIVRE)
		{
		cout<<"Lugar ocupado com sucesso!"<<endl;
	}
else
	{
	cout<<"O lugar escolhido, já está";
	cout<<" ocupado!"<<endl;
	}
}
else
	{
		cout<<"Os lugares devem estar entre 1"; 
		cout<<" e "<<numLugares<<"!"<<endl;
	}
} while(numLugar < 1 || numLugar > numLugares || lugares[numLugar-1]== OCUPADO);
lugares[numLugar-1] = OCUPADO; 
system("pause");
}	// Fim da função.


//* Função "libertarLugar()"

		void libertarLugar(char lugares[], int numLugares)
	{
		int numLugar = 0;
	do{
		cout<<"Qua1 o lugar a libertar (1-"; cout<<numLugares<<")? "; 
		cin>>numLugar;
	if (numLugar >= 1 && numLugar <= numLugares)
		{
		 if (lugares[numLugar-1] == OCUPADO)
			{
			 lugares[numLugar-1] = LIVRE;
				cout<<"Lugar libertado com sucesso!"<<endl;
	}
	else
		{
		cout<<"O lugar escolhido, já está"; 
		cout<<" livre!"<<endl;
	}
}
else
	{
	cout<<"Os lugares devem estar entre 1"; 
	cout<<" e "<<numLugares<<"!"<<endl;
	}
} while(numLugar <1 || numLugar > numLugares); 
system("pause");
} // Fim da função.

//* Função "sairDoPrograma()"
	
	bool sairDoPrograma(bool queroSair)
	{
		cout<<"Tem a certeza que quer sair (S/N)? ";
		char resposta = '\0';
		fflush(stdin); cin>>resposta; fflush(stdin); 
		if (resposta == 's' || resposta == 'S')
		return true;
		else
		return false;
} //fim da função
	//* Funçao "escolhalnvalida()"

	void escolhaInvalida(char escolha)
		{
		cout<<"\""<<escolha<<"\"";
		cout<<" é uma escolha inválida!\n";
	system("pause") ;
}  // Fim da função.

//* Função "despedida()"

	void despedida()
		{
		cout<<"Obrigado por ter usado o programa."; 
		cout<<endl;
system("pause");
}

