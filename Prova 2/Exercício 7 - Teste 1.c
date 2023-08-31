#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char** grep(FILE *arquivo, char *palavra, int *contador){
  char auxiliar[1001];
  *contador = 0;

  while(!feof(arquivo)){
    fgets(auxiliar, 1001, arquivo);
    if(strstr(auxiliar, palavra))
      (*contador)++;
  }

  char **letra = (char**)malloc(*contador * sizeof(char*));

  for(int i = 0; i < (*contador); i++) {
    letra[i] = (char*)malloc(1001 * sizeof(char));
  }

  rewind(arquivo);
  *contador = 0;

  while(!feof(arquivo)){
    fgets(auxiliar, 1001, arquivo);
    if(strstr(auxiliar, palavra)){
      strcpy(letra[*contador], auxiliar);
      (*contador)++;
    }
  }

  return letra;
}

int main(){
  char str[20];

  printf("Escreva o nome do arquivo a ser manipulado: ");
  scanf("%s", &str);

  FILE* arquivo = fopen(str,"r");
  if(arquivo == NULL){
    perror("Erro");
    return 0;
  }//if

  char buffer[1001];
  int contador = 0;
  char strObtida[200];

  printf("Escreva a palavra a ser encontrado no arquivo: ");
  scanf("%s", &strObtida);
  printf("\n");
  printf("----------------------------------------------------------\n");

  char **letra = grep(arquivo, strObtida, &contador);
  for(int i = 0; i < contador; i++){
    printf("%s", letra[i]);
  }

  printf("\n");
  printf("----------------------------------------------------------\n");
  printf("A palavra '%s' foi encontrada em %d registro(s) no arquivo...\n\n", strObtida, contador);
  return 0;
}
