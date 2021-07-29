/*
	Restaurante
	Fazer um programa que gere 10 mesas de um restaurante. 
	O programa deve apresentar um menu com as seguintes opções: 
	- Listar mesas; - Reservar mesa; - Ocupar mesa; - Desocupar mesa; 
	- Sair do programa.  
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
	const char LIVRE = 'L', RESERVADA = 'R'
	, OCUPADA = 'O' ;

	void inicializaMesas(char[], int); 
	void mostraMenu();
	char obtemEscolha(char );
	bool processaEscolha(char, char[], int, bool); 
	void listarMesas(char[], int); 
	void reservarMesa(char[], int); 
	void marcarMesa(char[], int); 
	void libertarMesa(char[], int); 
	bool sairDoPrograma(bool);
	void escolhaInvalida(char); 
	void despedida();

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	const int NUMMESAS = 7; 
	char mesas[NUMMESAS]; 
	char escolha = '\0'; 
	bool queroSair = false;
	
	inicializaMesas(mesas, NUMMESAS); 
		do {
			mostraMenu();
			escolha = obtemEscolha(escolha); queroSair =
			processaEscolha (escolha ,mesas ,
								NUMMESAS, queroSair);
}while(!queroSair); 
despedida();
return 0;
}

	void inicializaMesas(char mesas[],
	int numElementos)
	{
	for(int cMesa= 0; cMesa < numElementos;
	cMesa++) mesas[cMesa] = LIVRE;
}

 //* Função "mostraMenu()"

	void mostraMenu()
	{
	system("cls"); system("color A");
	cout<<"**********************************"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*       Restaurante Guest        *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*         A. Listar mesas        *"<<endl;	
	cout<<"*         B. Reservar mesa       *"<<endl;
	cout<<"*         C. Ocupar mesa         *"<<endl;
	cout<<"*         D. Libertar mesa       *"<<endl;
	cout<<"*         E. Sair do programa.   *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"**********************************"<<endl;
cout<<endl;
} // Fim da função.

	//* Função "obtemEscolha()"

	char obtemEscolha(char escolha)
	{
	cout<<"Qual a sua escolha (A-E)? "; cin>>escolha;
return escolha;
}

//* Função "processaEscolha()"

 	bool processaEscolha(char escolha, 
 		char mesas[], int numMesas, 
		 bool queroSair)
	{
	switch(escolha)
	{
	case 'a': case 'A': 
	listarMesas(mesas, numMesas); break;
	case 'b': case 'B': 
	reservarMesa(mesas, numMesas); break;
	case 'c': case 'C': 
	marcarMesa(mesas, numMesas); break;
	case 'd': case 'D': 
	libertarMesa(mesas, numMesas); break;
	case 'e': case 'E':
	queroSair = sairDoPrograma(queroSair); break;
	default: 
	escolhaInvalida(escolha);
}
return queroSair;
}	// Fim da função.

//* Função "listarMesas"

	void listarMesas(char mesas[],
			int numMesas)
	{
	cout<<"Listagem de mesas: "<<endl;
	for (int cMesa=0; cMesa < numMesas;
	cMesa++)
	{
	cout<<"Mesa "<<(cMesa+1)<<": "; 
	if (mesas[cMesa] == LIVRE)
		cout<<"livre."<<endl;
	else if (mesas[cMesa] == RESERVADA) 
		cout<<"reservada."<<endl;
	else
		cout<<"ocupada."<<endl;
	}
system("pause");
}	// Fim da função.

//* Função "marcarMesa()"
	
	void reservarMesa(char mesas[], int numMesas)

		{
		int numMesa = 0; 
		do {
		cout<<"Qual a mesa a reservar (l-";
		cout<<numMesas<<")? "; cin>>numMesa;
	
	if (numMesa >= 1 && numMesa <= numMesas)
	{
		if (mesas[numMesa-1] == RESERVADA
			|| mesas[numMesa-1] == OCUPADA)
			{
			cout<<"A mesa escolhida, já está"; 
			cout<<" reservada ou ocupada!"<<endl;
			}
		else
			{
			mesas[numMesa-1] = RESERVADA;
			cout<<"Mesa reservada com sucesso!"<<endl;
			}
		}
	else
		{
		cout<<"Os mesas devem estar entre 1"; 
		cout<<" e "<<numMesas<<"!"<<endl;
	}
} while(numMesa <1 || numMesa > numMesas);
system("pause");
}	// Fim da função
//Função "MARCARMESA()"
	void marcarMesa(char mesas[], int numMesas)
	{
	int numMesa = 0;
	do{
	cout<<"Qua1 a mesa a ocupar (l-"; 
	cout<<numMesas<<")? "; cin>>numMesa;

	if (numMesa >= 1 && numMesa <= numMesas)
	{
	if (mesas[numMesa-1] == LIVRE
	|| mesas[numMesa-1] == RESERVADA)
	{
	cout<<"Mesa ocupada com sucesso!"<<endl;
	}
	else
		{
		cout<<"A mesa escolhida, já está";
		cout<<" ocupada!"<<endl;
		}
	}
	else
		{
		cout<<"Os mesas devem estar entre 1";
		cout<<" e "<<numMesas<<"!"<<endl;
	}
} while(numMesa <1 || numMesa > numMesas
		|| mesas[numMesa-1] == OCUPADA); 
		mesas[numMesa-1] = OCUPADA; 
system("pause");
}	// Fim da função.

//* Função "libertarMesa()"
	void libertarMesa(char mesas[], int numMesas)
	{
	int numMesa = 0; 
	do {
		cout<<"Qual a mesa a libertar (1-";
		cout<<numMesas<<")?";
		cin>>numMesa;
		if (numMesa >= 1 && numMesa <= numMesas)
		{
		if (mesas[numMesa-1] == OCUPADA
		|| mesas[numMesa-1] == RESERVADA)
	{
	mesas[numMesa-1] = LIVRE;
	cout<<"Mesa libertada com sucesso!"<<endl;
	 
	}else
		{
		cout<<"A mesa escolhida, já está"; 
		cout<<" livre!"<<endl;
		}
	}
	else
		{
		cout<<"As mesas devem estar entre 1"; 
		cout<<" e "<<numMesas<<"!"<<endl;
	}
} while(numMesa <1 || numMesa > numMesas);
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

