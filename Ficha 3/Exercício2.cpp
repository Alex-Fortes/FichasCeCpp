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
 
// Fun��o trocaValor
 
	void trocaValor (int numA, int numB) { 
int copoVazio = 0;
copoVazio = numA; 
numA = numB; 
numB = copoVazio;
}
// Fun��o trocaRef 
 
	void trocaRef (int* pNumA, int* pNumB) { 
	int copoVazio; 
	copoVazio = *pNumA;
	*pNumA = *pNumB;
	*pNumB = copoVazio;
}

//Fun��o principal
 
	int main(){
	setlocale (LC_ALL, "Portuguese");
	 
	 // 1 . Dados 
	int numeroAL = 10 , numeroBL = 5;
	
// 2 . Testes para vari�veis locais
 	cout<<"Vari�veis Locais:  "<<endl;
	trocaValor (numeroAL, numeroBL);
	cout<<"\"main()\" -> Passagem por valores: "<<endl;
	cout<<"N�mero A local: "<<numeroAL<<"."<<endl;
	cout<<"N�mero B local: "<<numeroBL<<"."<<endl; 	 	 	 	 	 	
	
	trocaRef (&numeroAL, &numeroBL);
 	cout<<"\"main()\" -> Passagem por endere�o: "<<endl;
  	cout<<"N�mero A local: "<<numeroAL<<"."<<endl;
	cout<<"N�mero B local: "<<numeroBL<<"."<<endl;

// 3. Testes para vari�veis globais
 	cout<<"Vari�veis Globais: "<<endl;
	trocaValor (numeroAg, numeroBg);
	cout<<"\"main()\" -> Passagem por valores: "<<endl;  	 	 	 	
 	cout<<"N�mero A global: "<<numeroAg<<"."<<endl;
	cout<<"N�mero B global: "<<numeroBg<<"."<<endl;  
		
	trocaRef (&numeroAg, &numeroBg);
 	cout<<"\"main()\" -> Passagem por endere�o: "<<endl;
  	cout<<"N�mero A global: "<<numeroAg<<"."<<endl;
	cout<<"N�mero B global: "<<numeroBg<<"."<<endl;
return 0 ;
} // Fim da fun��o principal .


