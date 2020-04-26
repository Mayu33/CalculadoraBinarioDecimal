#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Biblioteca para fun��es getch() e getche()
#include <string.h> // Fun��es de manipula��o de strings
#include <ctype.h>  // Fun��o isdigit
#include <math.h>   // Fun��o POV
#include <locale.h> // Configurar a acentua��o

/*                      Calculadora Conversora de Bin�rio e Decimal

                    Faz convers�es de Decimal para Bin�rio e Bin�rio para Decimal

    Autoras: Laudiane de O.
             Mayara B. da Silva

    Data: 26/04/2020
*/

char valor[50];     // Vari�vel que armazena o n�mero digitado pelo usu�rio


// Fun��o para parte escrita do Menu
void imprimeMenu(){
     printf ("Calculadora Conversora Bin�rio Decimal\n\n");
     printf ("Escolha a convers�o:\n\n\t");
     printf ("1 - Decimal     -> Bin�rio\n\t");
     printf ("2 - Bin�rio     -> Decimal\n\t");
     printf ("0 - Sair\n\n");
}

// Fun��o principal do Menu
void menu()
{
     char opc;              // vari�vel que recebe a op��o escolhida pelo usu�rio
     imprimeMenu();         // fun��o que imprime a parte escrita menu
     printf ("Op��o: ");
     opc = getche();        // fun��o que l� a op��o digitada pelo usu�rio sem necessidade de teclar "enter"

     switch (opc)           // Fun��o para executar o menu de acordo com a op��o digitada pelo usu�rio
     {
            case '1':
                 DecParaBin();      // Fun��o correspondente ao c�lculo desejado
                 voltaMenu(&opc);   // Fun��o que consulta o usu�rio para retornar ao menu ou encerrar a calculadora
                 break;             // Fim do case
            case '2':
                 BinParaDec();
                 voltaMenu(&opc);
                 break;
            case '0':
                 exit(1);
            default:                                // Caso o usu�rio digite alguma op��o inv�lida
                    system ("cls");                 // Limpa a tela
                    imprimeMenu();                  // Imprime o menu
                    printf("Op��o inv�lida.\n");    // Informa que a op��o � inv�lida
                    system("pause");                // Pede ao usu�rio para pressionar qualquer tecla para continuar
                    system ("cls");                 // Limpa a tela
                    menu();                         // Chama o menu novamente
     }
}

// Fun��o que pergunta ao usu�rio se deseja retornar ao menu ap�s as convers�es.
void voltaMenu()
{
     char op = '0';
     printf ("\n\nDeseja retornar ao menu? [1] Sim | [2] N�o ");
     op = getche();             // Fun��o que l� a op��o digitada pelo usu�rio sem necessidade de pressionar enter. Essa fun��o s� pode ser usada com tipo char

     if (op=='1'){
        system ("cls");
        menu();
     }else if (op=='2'){
        printf("\nEncerrando...");
     }else{                     // Caso o usu�rio digite uma op��o inv�lida, ele ir� retornar ao menu ap�s pressionar qualquer tecla.
        printf("\nOp��o inv�lida. Retornando ao menu...\n");
        system("pause");
        system("cls"); // Limpa a tela
        menu();
        }
}

// Fun��o que converte Decimal para Bin�rio
void DecParaBin()
{
     char binario[33];      // String em C: vetor da fun��o "char" chamado bin�rio com 33 posi��es
     char buffer[33];       //              vetor chamado buffer com 33 posi��es
     char c;
     int divisor = 2;
     int resto, i, j, quociente, temp = 0;

     printf ("\n\nInforme o n�mero inteiro desejado: ");

     // Bloco de c�digo abaixo verifica se o n�mero digitado � v�lido

     do{
        c=getch();          // captura a tecla digitada pelo usu�rio
        if (isdigit(c)!=0){ // Fun��o isdigit verifica se um caractere � um digito decimal, em caso positivo
          valor[j] = c;     // vari�vel valor recebe o caractere digitado pelo usu�rio
          j++;              // a vari�vel de controle � incrementada
          printf ("%c", c); // exibido na tela o n�mero digitado
       }else if(c==8&&j){   // condi��o para saber se a tecla pressionada foi o BACKSPACE e se foram digitados caracteres para serem apagados
          valor[j]='\0';    // � colocada a termina��o "\0" no indice atual do vetor
          j--;              // a vari�vel de controle � decrementada
          printf("\b \b");  // o caractere � apagado da tela
       }
     }while(c!=13);         // o loop ocorrer� at� que seja pressionado enter
     valor[j]='\0';         // ao final do loop colocamos a termina��o "\0" na posi��o atual do vetor

     // Bloco de c�digo abaixo faz a convers�o do valor decimal em bin�rio.
     quociente = atoi(valor);   // fun��o "atoi" converte string em n�mero inteiro. O vetor "valor" � uma vari�vel global;
     strcpy(binario, "");       // copia " " para a string binario, ou seja, esvazia ela.
     while (quociente >= divisor)
     {
           resto = quociente%divisor;
           temp = quociente/divisor;
           quociente = temp;
           sprintf (buffer, "%d", resto); // formata uma string e guarda o resultado em um array, funciona igual ao printf, mas salva o resultado em um ponteiro
           strcat (binario, buffer);      // junta na vari�vel "bin�rio" o conte�do da vari�vel "bin�rio e buffer"
     }
     sprintf (buffer, "%d", quociente);   // assim como dentro do loop while
     strcat (binario, buffer);            // novamente a fun��o srtcat

     printf ("\n\nConvertido em bin�rio: %s\n\n", strrev(binario)); // imprime a string invertida
}

void BinParaDec()
{
     int tamanho, result, temp, i, j = 0;
     char c;
     printf ("\n\nInforme um valor bin�rio para ser convertido: ");

     // Bloco de c�digo abaixo verifica se o n�mero digitado � v�lido
     do{
       c=getch();
       if (c=='0' || c=='1'){
          valor[j] = c;         // atribui��o do caractere informado a vari�vel "valor"
          j++;                  // a vari�vel de controle � incrementada
          printf ("%c", c);     // o valor � impresso na tela
       }else if(c==8&&j){ // condi��o para saber se a tecla pressionada foi BACKSPACE e se foram digitados caracteres para que sejam apagados
          valor[j]='\0';        // � colocada a termina��o "\0" no indice atual do vetor
          j--;                  // a vari�vel de controle � decrementada
          printf("\b \b");      // o caractere � apagado da tela
       }
    }while(c!=13);              // o loop acontecer� at� que seja pressionada a tecla enter

     valor[j]='\0';             // ao final do loop, colocamos a termina��o "\0" na posi��o do atual vetor

     // Bloco de c�digo abaixo faz a convers�o do n�mero bin�rio em decimal
     tamanho = strlen(valor);           // Fun��o strlen l� o tamanho da string e passa para uma var do tipo int, nessa caso a int tamanho
     tamanho--;                         // tamanho � decrementado em 1
     while (tamanho >= 0){              // este loop ir� acontecer enquando a vari�vel tamanho for maior ou igual a 0, a cada loop ela � decrementada
           temp = pow (2, tamanho);                 // a variavel temp recebe 2 no expoente do tamanho da string
           result += ((valor[i] - 48) * temp);      // result recebe a soma da "string" (valor[i] - 48) * vari�vel temp
           tamanho--;                               // tamanho � decrementado no loop em execu��o
           i++;                                     // e i � incrementado no loop em execu��o
     }

     printf ("\n\nConvertido em decimal: %d\n\n", result);

}



// Fun��o Principal da calculadora
int main (void)
{
    setlocale(LC_ALL,"portuguese"); // Configura a acentua��o

    menu();
    printf("\n\n");

    system ("pause");
    return 0;
}
