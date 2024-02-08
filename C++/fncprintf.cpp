#include <stdio.h> //biblioteca para entrada e saida de dados
#include <stdlib.h> //biblioteca para gerar numeros aleatorios

// int main() {
// printf("Teste de printf\n"); //printf (print formatted) é uma função da biblioteca padrão de C que imprime uma mensagem no ecra
// printf("Characters: %c %c \n", 'a', 65); // %c é o formato para caracteres
// printf("Decimals: %d %ld\n", 1977, 650000L); // %d é o formato para inteiros o l é para long int e o d é para decimal
// printf("Preceding with blanks: %10d \n", 1977); // %10d é o formato para inteiros com 10 espaços em branco sendo 10 o número de espaços
// printf("Preceding with zeros: %010d \n", 1977); // %010d é o formato para inteiros com 10 zeros
// return 0;

// int main() {

// char nome[50];

// system("clear");

// printf("Digite o seu nome: ");
// scanf("%s", nome);
// printf("Olá %s\n", nome);
//     return 0;
// }

int main ()
{
  char str [80]; // str é um array de 80 caracteres
  int i; // i é uma variável inteira

  printf ("Enter your family name: "); // %s é o formato para strings
  scanf ("%79s",str);  // %79s é o formato para strings com 79 caracteres
  printf ("Enter your age: "); // %d é o formato para inteiros
  scanf ("%d",&i); // &i é o endereço da variável i
  printf ("Mr. %s , %d years old.\n",str,i);    // %s é o formato para strings
  printf ("Enter a hexadecimal number: "); // %x é o formato para números hexadecimais
  scanf ("%x",&i); // &i é o endereço da variável i 
  printf ("You have entered %#x (%d).\n",i,i); // %#x é o formato para números hexadecimais com o prefixo 0x
  
  return 0; 
}