/* A.1 Utilizando o Bloco de Notas, crie um ficheiro contendo o seguinte 
conte�do: 
Primeira linha do ficheiro. 
Segunda linha do ficheiro 
Terceira linha do ficheiro.

 O ficheiro deve ser colocado na pasta onde se encontra o ficheiro de 
 c�digo do projecto. Sen�o deve indicar o caminho completo no programa 
 que se apresenta a seguir, mais concretamente na linha que utiliza a fun��o
"strcpy" 
A.2*Passe o seguinte programa para o Visual Studio ou o Dev C++. 
O programa vai ler o ficheiro "FT 1301 FOI .txt ". 
Guarde este programa com o nome 'FT 1301 A02.cpp" 
*/

#include <stdio.h>   // Fun��es: "fflush()", "printf()"  e "scanf()"
#include <stdlib.h>  // Fun��o: "system()"
#include <locale.h>  // Fun��o: "setlocale()". 
#include <string.h>
#define MAXNOME 20   
using namespace std;

int main() {
    
    setlocale(LC_ALL, "Portuguese");
    
    FILE *fpLeitura;      // "fpLeitura" - ponteiro para a estrutura 
                          //               FILE 
    char nomefichLeitura[MAXNOME];    // Nome do ficheiro
	char c;
	int i;
	
    // 2. Inicializa��o das vari�veis
    fpLeitura =NULL;
    for (int i=0; i<MAXNOME; i++) 
	 {
           nomefichLeitura[i]='\0';
        }
           
    // 3. Abertura do ficheiro para Leitura
    strcpy(nomefichLeitura,"ficheiro.txt");
      // Fun��o "strcpy()" - Fun��o "STRing CoPY()"
      
    if ((fpLeitura = fopen(nomefichLeitura, "r")) == NULL)
	{
	 printf("N�o pode ler o ficheiro %s. \n", nomefichLeitura);
	 scanf("%c", &c); 
	 exit(1); // For�a a sa�da do programa - void exit
     }
          
    // 3. L� os dados no ficheiro
         // L� o ficheiro letra a letra
    while ((c=getc (fpLeitura))!= EOF) {   // "EOF" - "End Of File" (-1)
       putchar(c);
        }
        scanf("%c", &c);
        //fecho do ficheiro - OBRIGATORIO
        
    fclose (fpLeitura); fpLeitura = NULL;
          // Quando os ponteiros j� n�o s�o necess�rios coloca-los a NULL
    system("pause");
return 0;
}



