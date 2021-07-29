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
   FILE *fpEscrita; 
   char nomefichEscrita[MAXNOME], dados[MAXNOME];
   char c; int i;
	
	// Inicialização das variáveis 
	fpEscrita =NULL;
	for (i=0; i<MAXNOME; i++) nomefichEscrita [i]='\0';
	for (i=0; i<MAXNOME; i++) dados [i]='\0';
	
// Abertura do ficheiro de leitura 
	strcpy (nomefichEscrita, "ficheiro.txt"); 
	if ((fpEscrita = fopen(nomefichEscrita, "a")) == NULL){
		//puts ( "Não pode abrir o ficheiro %s	nomefich) o
	printf("Não	pode abrir ficheiro %s. \n",nomefichEscrita);
	system ("pause"); 
	exit(1);
}
	printf("Ficheiro aberto com sucesso!\n");_sleep(500);
	printf("Quais os dados a acrescentar? ");fflush(stdin);
	gets(dados);
	
	printf("Escrevendo os dados ");
	for(i=0;i<5;i++){putchar('.');_sleep(500);putchar('.');}
	putchar('\n');
	
	//envia os dados letra a letra
	for(i=0;i<strlen(dados); i++)
		putc(dados[i],fpEscrita);
		putc('\n',fpEscrita);

// Fecho do ficheiro - OBRIGATÓRIO 
	fclose(fpEscrita); 
	fpEscrita =NULL;
// Quando os ponteiros já não são necessários coloca-los a NUL
	printf("Dados escritos com sucesso!\n"); 
system ("pause"); 
return 0;
}





