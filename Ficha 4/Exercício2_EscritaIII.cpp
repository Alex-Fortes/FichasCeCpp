/* 
	C.1 -> Passe o seguinte programa para o Visual Studio ou o Dev C++. 
	Este programa vai ler o ficheiro criado no ponto A.1, "ficheiro.txt", 
	e copia-lo para o ficheiro "copia.txt". 
*/
#include <stdio.h>   
#include <stdlib.h>  
#include <locale.h> 
#include <string.h> 
#include <conio.h>
#define MAXNOME 20  
using namespace std;

int main() {
    
    setlocale(LC_ALL, "Portuguese");
   FILE *fpLeitura, *fpEscrita; char c; int i; 
   char nomefichleitura [MAXNOME], nomefichescrita[MAXNOME];
   
	// Inicialização das variáveis 
	fpLeitura =NULL; fpEscrita =NULL;
	for (i=0; i<MAXNOME; i++) nomefichleitura [i]='\0';
	for (i=0; i<MAXNOME; i++) nomefichescrita [i]='\0';
	
// Abertura do ficheiro de leitura 
	strcpy (nomefichleitura, "ficheiro.txt"); 
	if ((fpLeitura = fopen(nomefichleitura, "r")) == NULL){
		//puts ( "Não pode abrir o ficheiro %s	nomefich) o
	printf("Não	pode abrir ficheiro %s. \n",nomefichleitura);
	exit(1);
}
	//abertura do ficheiro de escrita
	strcpy(nomefichescrita,"copia.txt");
	if((fpEscrita = fopen(nomefichescrita, "w")) == NULL){
		printf("Não pode criar o ficheiro %s.\n",nomefichescrita);
		exit(1);
	}	
	// Leitura do ficheiro letra a letra e escrita
	// do ficheiro letra a letra
	// A função getc lê letra a letra - int getc (FILE *fp) 
	while((c=getc(fpLeitura)) !=EOF) {
	// Vai lendo letra a letra até chegar ao
	// fim o ficheiro: End Of File (EOF) 
	putch(c);	// Envia para o monitor a letra lida
	if (putc(c, fpEscrita)==EOF) break;
	//Envia para o ficheiro de fpwrite a letra lida - int putc (c char, FILE *fp)
}
scanf("*c", &c);
// Fecho do (s) ficheiro (s) - OBRIGATÓRIO 
	fclose (fpLeitura); fclose(fpEscrita); 
	fpLeitura = NULL; fpEscrita =NULL;
// Quando os ponteiros já não são necessários coloca-los a NULL 
system ("pause"); 
return 0;
}





