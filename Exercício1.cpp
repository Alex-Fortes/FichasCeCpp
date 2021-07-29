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
 
int main(){
	setlocale (LC_ALL, "Portuguese");
system("cls");

cout<<"Vetor de inteiros - Navegação com operadores."<<endl;
	int x[3] = {10, 20, 30};
	int *p = x;
	
	cout<< p <<'\n'; //escreve o endereço de x[0] (valor de x) (40)
	cout<< ++p <<'\n'; // p = p + 1; cout<<p; (44)
						//primeiro incrementa depois mostra
						//escreve o endereço de x [1]
	cout<< p++ <<'\n';	//cout <<p; p=p+1;
						//Primeiro mostra e depois incrementa
						//escreve o endereço de x [1] (44)
	cout<< p <<'\n';	//escreve o endereço de x [2] (48)	
	
	p = x;				//volta ao inicio
	cout << *p <<'\n';	//escreve 10
	cout << *(p+1) <<'\n';	//escreve 20
	cout << *p <<'\n';	//escreve 10
	cout << *p++ <<'\n';	//escreve 10
	cout << *p <<'\n';	//escreve 20
	
	p = x;
	cout<< *p++ <<'\n';	//escreve 10
						//cout<<*p; p++;
	cout<< *p-- <<'\n';	//escreve 20
						//cout<<*p; p--;
	cout<< *(p++) <<'\n';//escreve 10
						//cout<<*p; p++;
	cout<< *++p <<'\n';	//escreve 30
						
	p = x;
	cout<< (*p)++ <<'\n'; //escreve 10
	cout<< ++*p <<'\n';	// escreve 30
	system("pause");
	return 0;
}
