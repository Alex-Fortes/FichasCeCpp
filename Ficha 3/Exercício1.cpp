
// Bibliotecas em C
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 

	//  Função "alteraValorDeA1 ()"
 
	void alteraValorDeA1(int a)	{ a=17; }
 
// Função alteraValorDeA2 
 
	void alteraValorDeA2 (int *a) { *a=27;	}	
	
 
// Função principal
 
int main() {
	setlocale (LC_ALL, "Portuguese");
	
	int a=37;

	printf ("Valor de \"a\": %d.\n",a); 
	alteraValorDeA1(a);
	printf ("Valor de \"a\": %d.\n",a); 
	alteraValorDeA2(&a);
	printf ("Valor de \"a\": %d.\n",a); 
	
	return 0;
}

 

