/* 
	B.1 Desta vez, o processo � inverso. Usa-se um programa para escrever 
	um ficheiro e depois, localiza-se o ficheiro e a pasta onde este foi 
	criado e verifica-se se a informa��o que escreveu no programa est� de 
	facto no ficheiro. Passe o seguinte programa para o Visual
Studio ou o Dev C++. 
*/
#include <stdio.h>   // Fun��es: "fflush()", "printf()"  e "scanf()"
#include <stdlib.h>  // Fun��o: "system()"
#include <locale.h>  // Fun��o: "setlocale()". 
#include <string.h>   
using namespace std;

// Defini��o das Constantes globais
const int MAXNOME = 20;   // N�mero m�ximo de caracteres para o ficheiro

int main() {
    
    setlocale(LC_ALL, "Portuguese");
    // 1. Declara��o das vari�veis
    FILE *fpEscrita;          // "fpEscrita" - ponteiro para a estrutura 
                              //               FILE 
    char nomefichEscrita[MAXNOME],    // Nome do ficheiro
         mensagem[MAXNOME];           // Mensagem a escrever no ficheiro

    // 2. Inicializa��o das vari�veis
    fpEscrita =NULL;
    for (int cLetra=0; cLetra<MAXNOME; cLetra++) {
           nomefichEscrita[cLetra]='\0';
           mensagem[cLetra]='\0';
        }
           
    // 3. Abertura do ficheiro para escrita
    strcpy(nomefichEscrita,"ficheiro.txt");

      // Fun��o "strcpy()" - Fun��o "STRing CoPY()"
      
    fpEscrita = fopen(nomefichEscrita, "w");  
	   // Tentativa de abertura do ficheiro para escrita.
    
    if(fpEscrita == NULL)
     {
     printf("N�o pode criar o ficheiro %s para escrita. \n",
	       nomefichEscrita);
     system("pause");
     exit(1);        // For�a a sa�da do programa
     }
        // 3. Pede a informa��o a escrever
    system("color A");
    printf("Qual a mensagem a escrever? "); // TIS02 FOREVER.
	fflush(stdin);
    gets(mensagem);

    // 4. Escreve os dados no ficheiro
      // 4.1 Envia para o ficheiro letra a letra
            // 4.2 Envia a cadeia inteira para o ficheiro
       fputs(mensagem,fpEscrita);
    
    printf("Ficheiro \"%s\" escrito com sucesso!\n", nomefichEscrita);
    
    // 5. Fecho do(s) ficheiro(s) - OBRIGAT�RIO
    fclose(fpEscrita);
    fpEscrita = NULL;  
         // Quando os ponteiros j� n�o s�o necess�rios coloca-los a NULL
    system("pause");
    return 0;
    }



