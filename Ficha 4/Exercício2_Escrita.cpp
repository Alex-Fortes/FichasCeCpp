/* 
	B.1 Desta vez, o processo é inverso. Usa-se um programa para escrever 
	um ficheiro e depois, localiza-se o ficheiro e a pasta onde este foi 
	criado e verifica-se se a informação que escreveu no programa está de 
	facto no ficheiro. Passe o seguinte programa para o Visual
Studio ou o Dev C++. 
*/
#include <stdio.h>   // Funções: "fflush()", "printf()"  e "scanf()"
#include <stdlib.h>  // Função: "system()"
#include <locale.h>  // Função: "setlocale()". 
#include <string.h>   
using namespace std;

// Definição das Constantes globais
const int MAXNOME = 20;   // Número máximo de caracteres para o ficheiro

int main() {
    
    setlocale(LC_ALL, "Portuguese");
    // 1. Declaração das variáveis
    FILE *fpEscrita;          // "fpEscrita" - ponteiro para a estrutura 
                              //               FILE 
    char nomefichEscrita[MAXNOME],    // Nome do ficheiro
         mensagem[MAXNOME];           // Mensagem a escrever no ficheiro

    // 2. Inicialização das variáveis
    fpEscrita =NULL;
    for (int cLetra=0; cLetra<MAXNOME; cLetra++) {
           nomefichEscrita[cLetra]='\0';
           mensagem[cLetra]='\0';
        }
           
    // 3. Abertura do ficheiro para escrita
    strcpy(nomefichEscrita,"ficheiro.txt");

      // Função "strcpy()" - Função "STRing CoPY()"
      
    fpEscrita = fopen(nomefichEscrita, "w");  
	   // Tentativa de abertura do ficheiro para escrita.
    
    if(fpEscrita == NULL)
     {
     printf("Não pode criar o ficheiro %s para escrita. \n",
	       nomefichEscrita);
     system("pause");
     exit(1);        // Força a saída do programa
     }
        // 3. Pede a informação a escrever
    system("color A");
    printf("Qual a mensagem a escrever? "); // TIS02 FOREVER.
	fflush(stdin);
    gets(mensagem);

    // 4. Escreve os dados no ficheiro
      // 4.1 Envia para o ficheiro letra a letra
            // 4.2 Envia a cadeia inteira para o ficheiro
       fputs(mensagem,fpEscrita);
    
    printf("Ficheiro \"%s\" escrito com sucesso!\n", nomefichEscrita);
    
    // 5. Fecho do(s) ficheiro(s) - OBRIGATÓRIO
    fclose(fpEscrita);
    fpEscrita = NULL;  
         // Quando os ponteiros já não são necessários coloca-los a NULL
    system("pause");
    return 0;
    }



