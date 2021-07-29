// Bibliotecas em C
#include <stdio.h> 
#include <stdlib.h> 	
#include <locale.h> 
#include <time.h> 
#include <string.h>

// Bibliotecas de C++
#include <iostream>	
#include <iomanip> 
using namespace std; 

// Variaveis Globais
int numeroAg = 10, numeroBg = 5;
 
// Função trocaValor
 
	void trocaValor (int numA, int numB) { 
int copoVazio = 0;
copoVazio = numA; 
numA = numB; 
numB = copoVazio;
}
// Função trocaRef 
 
	void trocaRef (int* pNumA, int* pNumB) { 
	int copoVazio; 
	copoVazio = *pNumA;
	*pNumA = *pNumB;
	*pNumB = copoVazio;
}

//Função principal
 
	int main(){
	setlocale (LC_ALL, "Portuguese");
	 
	 // 1 . Dados 
	int numeroAL = 10 , numeroBL = 5;
	
// 2 . Testes para variáveis locais
 	cout<<"Variáveis Locais:  "<<endl;
	trocaValor (numeroAL, numeroBL);
	cout<<"\"main()\" -> Passagem por valores: "<<endl;
	cout<<"Número A local: "<<numeroAL<<"."<<endl;
	cout<<"Número B local: "<<numeroBL<<"."<<endl; 	 	 	 	 	 	
	
	trocaRef (&numeroAL, &numeroBL);
 	cout<<"\"main()\" -> Passagem por endereço: "<<endl;
  	cout<<"Número A local: "<<numeroAL<<"."<<endl;
	cout<<"Número B local: "<<numeroBL<<"."<<endl;

// 3. Testes para variáveis globais
 	cout<<"Variáveis Globais: "<<endl;
	trocaValor (numeroAg, numeroBg);
	cout<<"\"main()\" -> Passagem por valores: "<<endl;  	 	 	 	
 	cout<<"Número A global: "<<numeroAg<<"."<<endl;
	cout<<"Número B global: "<<numeroBg<<"."<<endl;  
		
	trocaRef (&numeroAg, &numeroBg);
 	cout<<"\"main()\" -> Passagem por endereço: "<<endl;
  	cout<<"Número A global: "<<numeroAg<<"."<<endl;
	cout<<"Número B global: "<<numeroBg<<"."<<endl;
return 0 ;
} // Fim da função principal .


