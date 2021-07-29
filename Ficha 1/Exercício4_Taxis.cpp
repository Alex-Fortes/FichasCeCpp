/*
	Taxis
	Fazer um programa que gere uma frota de 10 taxis. O programa deve 
	apresentar um menu com as seguintes opções: - Listar taxi; 
	- Reservar taxi; - Chamar taxi; - Libertar taxi; - Sair do programa.   
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
	const char LIVRE = 'L', RESERVADO = 'R', OCUPADO = 'O' ;

	void inicializaTaxis(char[], int); 
	void mostraMenu();
	char obtemEscolha(char );
	bool processaEscolha(char, char[], int, bool); 
	void listarTaxis(char[], int); 
	void reservarTaxi(char[], int); 
	void marcarTaxi(char[], int); 
	void libertarTaxi(char[], int); 
	bool sairDoPrograma(bool);
	void escolhaInvalida(char); 
	void despedida();

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	const int NUMTAXIS = 7; 
	char taxis[NUMTAXIS]; 
	char escolha = '\0' ; 
	bool queroSair = false;
	
	inicializaTaxis(taxis, NUMTAXIS); 
	do {
		mostraMenu();
		escolha = obtemEscolha(escolha); 
		queroSair = processaEscolha(escolha,taxis,NUMTAXIS, queroSair);
	}while(!queroSair); 
	despedida();
return 0;
}
	//* Função "inicializaTaxis()"
	void inicializaTaxis(char taxis[], int numElementos)
	{
	for(int cTaxi= 0; cTaxi < numElementos;	cTaxi++) 
	taxis[cTaxi] = LIVRE;
}

 //* Função "mostraMenu()"

	void mostraMenu()
	{
	system("cls"); system("color A");
	cout<<"**********************************"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*         Taxis Guest            *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*         A. Listar táxis        *"<<endl;	
	cout<<"*         B. Reservar táxi       *"<<endl;
	cout<<"*         C. Chamar táxi         *"<<endl;
	cout<<"*         D. Libertar táxi       *"<<endl;
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
 		char taxis[], int numTaxis, bool queroSair)
	{
	switch(escolha)
	{
	case 'a': case 'A': 
	listarTaxis(taxis, numTaxis); break;
	case 'b': case 'B': 
	reservarTaxi(taxis, numTaxis); break;
	case 'c': case 'C': 
	marcarTaxi(taxis, numTaxis); break;
	case 'd': case 'D': 
	libertarTaxi(taxis, numTaxis); break;
	case 'e': case 'E':
	queroSair = sairDoPrograma(queroSair); break;
	default: 
	escolhaInvalida(escolha);
}
return queroSair;
}	// Fim da função.

// Função "listarTaxis()"

	void listarTaxis(char taxis[], int numTaxis)

	{
	cout<<"Listagem de táxis: "<<endl; 
	for (int cTaxi=0; cTaxi < numTaxis; cTaxi++)
	{
	cout<<"Táxi "<<(cTaxi+1)<<": "; 
	if (taxis[cTaxi] == LIVRE)
		cout<<"1ivre."<<endl;
	else if (taxis[cTaxi] == RESERVADO) 
		cout<<"reservado."<<endl;
	else
		cout<<"ocupado."<<endl;
	}
system("pause");
}	// Fim da função.

// Função "marcarTaxi()"
	
	void reservarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do{
		cout<<"Qual o táxi a reservar (1-"; 
		cout<<numTaxis<<")? "; cin>>numTaxi;

	if (numTaxi >= 1 && numTaxi <= numTaxis)
	{
	if (taxis[numTaxi-1] == RESERVADO || taxis[numTaxi-1] == OCUPADO)
	{
	cout<<"O táxi escolhido, já está"; 
	cout<<" reservado ou ocupado!"<<endl;
	}
	else
		{
		taxis[numTaxi-1] = RESERVADO;
		cout<<"Táxi reservado com sucesso!"<<endl;
		}
	}
	else
		{
		cout<<"Os táxis devem estar entre 1"; 
		cout<<" e "<<numTaxis<<"!"<<endl;
	}
} while(numTaxi <1 || numTaxi > numTaxis);
system("pause");
}	// Fim da função

//Função "marcarTaxi()"
	void marcarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do{
	cout<<"Qua1 o táxi a ocupar (l-";
	cout<<numTaxis<<")? ";	cin>>numTaxi;

	if (numTaxi >= 1 && numTaxi <= numTaxis)
	{
	if (taxis[numTaxi-1] == LIVRE || taxis[numTaxi-1] == RESERVADO)
	{
	cout<<"Táxi ocupado com sucesso!"<<endl;
	}
	else
		{
		cout<<"O táxi escolhido, já está"; 
		cout<<" ocupado!"<<endl;
		}
	}
	else
		{
		cout<<"Os táxis devem estar entre 1";
		cout<<" e "<<numTaxis<<"!"<<endl;
		}
	} while(numTaxi <1 || numTaxi > numTaxis || taxis[numTaxi-1] == OCUPADO); 
	taxis[numTaxi-1] = OCUPADO; 
system("pause");
}	// Fim da função.

//* Função "libertarTaxi()"
	void libertarTaxi(char taxis[], int numTaxis)
	{
	int numTaxi = 0;
	do {
		cout<<"Qual o táxi a libertar (l-"; 
		cout<<numTaxis<<")? "; cin>>numTaxi;
	if (numTaxi >= 1 && numTaxi <= numTaxis)
		{
		if (taxis[numTaxi-1] == OCUPADO
		|| taxis[numTaxi-1] == RESERVADO)
		{
		taxis[numTaxi-1] = LIVRE;
		cout<<"Taxi libertado com sucesso!"<<endl;
	}
	else
	{
	cout<<"O taxi escolhido, já está"; 
	cout<<" livre!"<<endl;
		}
	}
	else
		{
		cout<<"Os taxis devem estar entre 1"; 
		cout<<" e "<<numTaxis<<"!"<<endl;
	}
} while(numTaxi <1 || numTaxi > numTaxis);
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

