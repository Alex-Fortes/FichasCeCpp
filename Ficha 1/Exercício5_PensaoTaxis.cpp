/*
	Pensao
	Fazer um programa que gere uma pens�o de tr�s andares e cinco quartos 
	por andar. O programa deve apresentar um menu com as seguintes op��es: 
	- Listar quartos; - Reservar quarto; - Ocupar quarto; - Desocupar quarto;
	 - Sair do programa.    
*/

// Inclus�o de Bibliotecas: C
#include <stdio.h>  // Fun��es: "scanf()", "printf()"
#include <stdlib.h> // Fun��es: "system()".
#include <locale.h> // "setlocale()"
#include <math.h>   // "pow()", "sqrt()"
#include <conio.h>  // "getch()"

// Inclus�o de Bibliotecas: C++

#include <iostream> // Cont�m o "cin" e o "cout"
#include <iomanip>  // Cont�m "setprecision()"
using namespace std; // Selecionar o "std" como espa�o de nomes
                     // predefinido.

//* 2. Dados Globais
	const char LIVRE = 'L', RESERVADO = 'R', OCUPADO = 'O' ;
	const int NUMANDARES = 3, NUMQUARTOSPORANDAR = 7;

	void inicializaPensao(char quartos[][NUMQUARTOSPORANDAR], int ,int);
	void mostraMenu();
	char obtemEscolha(char escolha); 
	bool processaEscolha(char ,
		char quartos[][NUMQUARTOSPORANDAR],int,int,bool );
	void despedida();

	void listarQuartos(char quartos[][NUMQUARTOSPORANDAR],int,int); 
	void reservarQuarto(char quartos[][NUMQUARTOSPORANDAR],int,int); 
	void checkIN(char quartos[][NUMQUARTOSPORANDAR],int,int); 
	void checkOUT(char quartos[][NUMQUARTOSPORANDAR],int,int); 
	bool sairDoPrograma(bool);
	void escolhaInvalida(char);

int main()
{
setlocale(LC_ALL, "Portuguese");

// 1. Dados
	char quartos[NUMANDARES][NUMQUARTOSPORANDAR];
	bool queroSair = false; 
	char escolha = '\0' ;

	
	// Inicializa��o do vetor 
	inicializaPensao(quartos, NUMANDARES, NUMQUARTOSPORANDAR);
	do {
		mostraMenu();
		escolha = obtemEscolha(escolha); 
		queroSair = processaEscolha(escolha,quartos,NUMANDARES, 
		NUMQUARTOSPORANDAR, queroSair);
	}while(!queroSair); 
	despedida();
return 0;
}
	// Fun��o "inicializaPensao()""
	void inicializaPensao(
		char quartos[][NUMQUARTOSPORANDAR], 
		int numAndares,
		int numQuartosPorAndar)
	{
	for(int cAndar=0; cAndar < numAndares; cAndar++) 
	for(int cQuarto=0; cQuarto<numQuartosPorAndar;
	cQuarto++) 
	quartos[cAndar][cQuarto] = LIVRE;
}

 // Fun��o "mostraMenu()"

	void mostraMenu()
	{
	system("cls"); system("color A");
	cout<<"**********************************"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*         Pens�o Guest           *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"*         A. Listar quartos      *"<<endl;	
	cout<<"*         B. Reservar quarto     *"<<endl;
	cout<<"*         C. Check-in            *"<<endl;
	cout<<"*         D. Check-out           *"<<endl;
	cout<<"*         E. Sair do programa.   *"<<endl;
	cout<<"*                                *"<<endl;
	cout<<"**********************************"<<endl;
cout<<endl;
} // Fim da fun��o.

	//* Fun��o "obtemEscolha()"

	char obtemEscolha(char escolha)
	{
	cout<<"Qual a sua escolha (A-E)? "; cin>>escolha;
return escolha;
}

//* Fun��o "processaEscolha()"

 	bool processaEscolha(char escolha, 
 		char quartos[] [NUMQUARTOSPORANDAR],
		int numAndares, int numQuartosPorAndar,
		bool queroSair)
	{
	switch(escolha)
	{
	case 'a': case 'A': 
	listarQuartos(quartos,numAndares,numQuartosPorAndar); 
	break;
	case 'b': case 'B': 
	reservarQuarto(quartos,numAndares,numQuartosPorAndar); break;
	case 'c': case 'C': 
	checkIN(quartos,numAndares,numQuartosPorAndar); break;
	case 'd': case 'D': 
	checkOUT(quartos,numAndares,numQuartosPorAndar); break;
	case 'e': case 'E':
	queroSair = sairDoPrograma(queroSair); break;
	default: 
	escolhaInvalida(escolha);
}
return queroSair;
}	// Fim da fun��o.

// Fun��o "listarQuartos()"

	void listarQuartos(
		char quartos[][NUMQUARTOSPORANDAR],
		int numAndares, int numQuartosPorAndar)
		{
		cout<<"Listagem de quartos: "<<endl;
		for(int cAndar=0; cAndar<numAndares; cAndar++)
		{
		cout<<"Andar "<<(cAndar+1)<<": "<<endl; 
		for(int cQuarto=0; cQuarto<numQuartosPorAndar; cQuarto++)
		{
			cout<<"-> Quarto "<<(cQuarto+1)<<": "; 
		if (quartos[cAndar][cQuarto] == LIVRE)
			cout<<"livre."<<endl;
		else if (quartos[cAndar][cQuarto] == RESERVADO) 
		cout<<"reservado."<<endl;
		else
		cout<<"ocupado."<<endl;
		} 
system("pause");
	} // Fim do ciclo "for" dos andares
} // Fim da fun��o.

		// Fun��o "reservarQuarto()"
	
	void reservarQuarto(char quartos[][NUMQUARTOSPORANDAR],
	int numAndares, int numQuartosPorAndar)
	{
	int numAndar = 0, numQuarto = 0; 
	cout<<"Qual � o andar a selecionar (l-"<<NUMANDARES<<")? ";cin>>numAndar;
	cout<<"Nesse piso, qual � o 'i!arto a reservar (l-"
		<<NUMQUARTOSPORANDAR<<")? ";cin>>numQuarto;
	
	quartos[numAndar-1][numQuarto-1] = RESERVADO; 
	cout<<"Quarto reservado com sucesso!"<<endl<<endl; 
system("pause");
}	// Fim da fun��o

	//Fun��o "checkIN()"
	void checkIN(char quartos[][NUMQUARTOSPORANDAR],
	int numAndares, int numQuartosPorAndar)
	{
	int numAndar = 0, numQuarto = 0; 
	cout<<"Qual � o andar a selecionar (1-"
		<<NUMANDARES<<")? "; cin>>numAndar;
	cout<<"Nesse piso, qual � o quarto a ocupar (1-"
		<<NUMQUARTOSPORANDAR<<")? "; cin>>numQuarto;

	quartos[numAndar-1][numQuarto-1] = OCUPADO; 
	cout<<"Quarto ocupado com sucesso!"<<endl<<endl; 
system("pause");
}	// Fim da fun��o.

//* Fun��o "checkOUT()"
	void checkOUT(char quartos[][NUMQUARTOSPORANDAR],
	int numAndares, int numQuartosPorAndar)
	{
	int numAndar = 0, numQuarto = 0; 
	cout<<"Qual � o andar a selecionar (l-"
	<<NUMANDARES<<")? "; cin>>numAndar;
	cout<<"Nesse piso, qual � o quarto a libertar (l-"
	<<NUMQUARTOSPORANDAR<<")? ";cin>>numQuarto;

	quartos[numAndar-1][numQuarto-1] = LIVRE; 
	cout<<"Quarto libertado com sucesso!"<<endl<<endl; 
 system("pause");
} // Fim da fun��o.

//* Fun��o "sairDoPrograma()"
	
	bool sairDoPrograma(bool queroSair)
	{
		cout<<"Tem a certeza que quer sair (S/N)? ";
		char resposta = '\0';
		fflush(stdin); cin>>resposta; fflush(stdin); 
		if (resposta == 's' || resposta == 'S')
		return true;
		else
		return false;
} //fim da fun��o
	
	//* Fun�ao "escolhalnvalida()"

	void escolhaInvalida(char escolha)
		{
		cout<<"\""<<escolha<<"\"";
		cout<<" � uma escolha inv�lida!\n";
	system("pause") ;
}  // Fim da fun��o.

//* Fun��o "despedida()"

	void despedida()
		{
		cout<<"Obrigado por ter usado o programa."; 
		cout<<endl;
system("pause");
}

