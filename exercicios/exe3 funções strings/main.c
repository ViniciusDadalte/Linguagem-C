#include <stdio.h>
#include <string.h>

int main() {
  
   char string1[] = "Bro";
   char string2[] = "Code";
 
   strlwr(string1);                              // converte uma string para minúsculas
   //strupr(string1);                            // converte uma string para maiúsculas
   //strcat(string1, string2);                   // anexa string2 ao final de string1
   //strncat(string1, string2, 1);               // anexa n caracteres de string2 a string1
   //strcpy(string1, string2);                   // copia string2 para string1
   //strncpy(string1, string2, 2);               // copia n caracteres de string2 para string1
   
   //strset(string1, '?');                       // define todos os caracteres de uma string para um caractere específico
   //strnset(string1, 'x', 1);                   // define os primeiros n caracteres de uma string para um caractere específico
   //strrev(string1);                            // inverte uma string

   //int result = strlen(string1);               // retorna o comprimento da string como int
   //int result = strcmp(string1, string2);      // compara todas os caracteres das strings
   //int result = strncmp(string1, string2, 1);  // compara n caracteres das strings
   //int result = strcmpi(string1, string1);     // compara todas as strings (ignora maiúsculas/minúsculas)
   //int result = strnicmp(string1, string1, 1); // compara n caracteres das strings (ignora maiúsculas/minúsculas)

   printf("%s", string1);

   /*
   if (result == 0) 
   {
      printf("Essas strings são iguais");
   } 
   else 
   {
      printf("Essas strings são diferentes");
   }
   */

   return 0;
}
