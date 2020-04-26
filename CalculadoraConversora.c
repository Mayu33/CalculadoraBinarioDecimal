#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Biblioteca para funções getch() e getche()
#include <string.h> // Funções de manipulação de strings
#include <ctype.h>  // Função isdigit
#include <math.h>   // Função POV
#include <locale.h> // Configurar a acentuação

/*                      Calculadora Conversora de Binário e Decimal

                    Faz conversões de Decimal para Binário e Binário para Decimal

    Autoras: Laudiane de O.
             Mayara B. da Silva

    Data: 26/04/2020
*/

char valor[50];     // Variável que armazena o número digitado pelo usuário


// Função para parte escrita do Menu
void imprimeMenu(){
     printf ("Calculadora Conversora Binário Decimal\n\n");
     printf ("Escolha a conversão:\n\n\t");
     printf ("1 - Decimal     -> Binário\n\t");
     printf ("2 - Binário     -> Decimal\n\t");
     printf ("0 - Sair\n\n");
}

// Função principal do Menu
void menu()
{
     char opc;              // variável que recebe a opção escolhida pelo usuário
     imprimeMenu();         // função que imprime a parte escrita menu
     printf ("Opção: ");
     opc = getche();        // função que lê a opção digitada pelo usuário sem necessidade de teclar "enter"

     switch (opc)           // Função para executar o menu de acordo com a opção digitada pelo usuário
     {
            case '1':
                 DecParaBin();      // Função correspondente ao cálculo desejado
                 voltaMenu(&opc);   // Função que consulta o usuário para retornar ao menu ou encerrar a calculadora
                 break;             // Fim do case
            case '2':
                 BinParaDec();
                 voltaMenu(&opc);
                 break;
            case '0':
                 exit(1);
            default:                                // Caso o usuário digite alguma opção inválida
                    system ("cls");                 // Limpa a tela
                    imprimeMenu();                  // Imprime o menu
                    printf("Opção inválida.\n");    // Informa que a opção é inválida
                    system("pause");                // Pede ao usuário para pressionar qualquer tecla para continuar
                    system ("cls");                 // Limpa a tela
                    menu();                         // Chama o menu novamente
     }
}

// Função que pergunta ao usuário se deseja retornar ao menu após as conversões.
void voltaMenu()
{
     char op = '0';
     printf ("\n\nDeseja retornar ao menu? [1] Sim | [2] Não ");
     op = getche();             // Função que lê a opção digitada pelo usuário sem necessidade de pressionar enter. Essa função só pode ser usada com tipo char

     if (op=='1'){
        system ("cls");
        menu();
     }else if (op=='2'){
        printf("\nEncerrando...");
     }else{                     // Caso o usuário digite uma opção inválida, ele irá retornar ao menu após pressionar qualquer tecla.
        printf("\nOpção inválida. Retornando ao menu...\n");
        system("pause");
        system("cls"); // Limpa a tela
        menu();
        }
}

// Função que converte Decimal para Binário
void DecParaBin()
{
     char binario[33];      // String em C: vetor da função "char" chamado binário com 33 posições
     char buffer[33];       //              vetor chamado buffer com 33 posições
     char c;
     int divisor = 2;
     int resto = 0, i = 0, j = 0, quociente = 0, temp = 0;

     printf ("\n\nInforme o número inteiro desejado: ");

     // Bloco de código abaixo verifica se o número digitado é válido

     do{
        c=getch();          // captura a tecla digitada pelo usuário
        if (isdigit(c)!=0){ // Função isdigit verifica se um caractere é um digito decimal, em caso positivo
          valor[j] = c;     // variável valor recebe o caractere digitado pelo usuário
          j++;              // a variável de controle é incrementada
          printf ("%c", c); // exibido na tela o número digitado
       }else if(c==8&&j){   // condição para saber se a tecla pressionada foi o BACKSPACE e se foram digitados caracteres para serem apagados
          valor[j]='\0';    // é colocada a terminação "\0" no indice atual do vetor
          j--;              // a variável de controle é decrementada
          printf("\b \b");  // o caractere é apagado da tela
       }
     }while(c!=13);         // o loop ocorrerá até que seja pressionado enter
     valor[j]='\0';         // ao final do loop colocamos a terminação "\0" na posição atual do vetor

     // Bloco de código abaixo faz a conversão do valor decimal em binário.
     quociente = atoi(valor);   // função "atoi" converte string em número inteiro. O vetor "valor" é uma variável global;
     strcpy(binario, "");       // copia " " para a string binario, ou seja, esvazia ela.
     while (quociente >= divisor)
     {
           resto = quociente%divisor;
           temp = quociente/divisor;
           quociente = temp;
           sprintf (buffer, "%d", resto); // formata uma string e guarda o resultado em um array, funciona igual ao printf, mas salva o resultado em um ponteiro
           strcat (binario, buffer);      // junta na variável "binário" o conteúdo da variável "binário e buffer"
     }
     sprintf (buffer, "%d", quociente);   // assim como dentro do loop while
     strcat (binario, buffer);            // novamente a função srtcat

     printf ("\n\nConvertido em binário: %s\n\n", strrev(binario)); // imprime a string invertida
}

void BinParaDec()
{
     int tamanho = 0, result = 0, temp = 0, i = 0, j = 0;
     char c;
     printf ("\n\nInforme um valor binário para ser convertido: ");

     // Bloco de código abaixo verifica se o número digitado é válido
     do{
       c=getch();
       if (c=='0' || c=='1'){
          valor[j] = c;         // atribuição do caractere informado a variável "valor"
          j++;                  // a variável de controle é incrementada
          printf ("%c", c);     // o valor é impresso na tela
       }else if(c==8&&j){ // condição para saber se a tecla pressionada foi BACKSPACE e se foram digitados caracteres para que sejam apagados
          valor[j]='\0';        // é colocada a terminação "\0" no indice atual do vetor
          j--;                  // a variável de controle é decrementada
          printf("\b \b");      // o caractere é apagado da tela
       }
    }while(c!=13);              // o loop acontecerá até que seja pressionada a tecla enter

     valor[j]='\0';             // ao final do loop, colocamos a terminação "\0" na posição do atual vetor

     // Bloco de código abaixo faz a conversão do número binário em decimal
     tamanho = strlen(valor);           // Função strlen lê o tamanho da string e passa para uma var do tipo int, nessa caso a int tamanho
     tamanho--;                         // tamanho é decrementado em 1
     while (tamanho >= 0){              // este loop irá acontecer enquando a variável tamanho for maior ou igual a 0, a cada loop ela é decrementada
           temp = pow (2, tamanho);                 // a variavel temp recebe 2 no expoente do tamanho da string
           result += ((valor[i] - 48) * temp);      // result recebe a soma da "string" (valor[i] - 48) * variável temp
           tamanho--;                               // tamanho é decrementado no loop em execução
           i++;                                     // e i é incrementado no loop em execução
     }

     printf ("\n\nConvertido em decimal: %d\n\n", result);

}



// Função Principal da calculadora
int main (void)
{
    setlocale(LC_ALL,"portuguese"); // Configura a acentuação

    menu();
    printf("\n\n");

    system ("pause");
    return 0;
}
