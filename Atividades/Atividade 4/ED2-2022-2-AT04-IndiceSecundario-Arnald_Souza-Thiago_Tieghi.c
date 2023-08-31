//Declara��o de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura Musica
typedef  struct{
  char ano[5];
  char duracao[6];
  char titulo[31];
  char artista[21];
  char genero[12];
  char idioma[12];
}Musica;

int contaLinha(FILE* arq) {
  //Declara��o de char que percorre o arquivo e contador
  char percorre;
  int contalinha = 0;
  while((percorre = getc(arq)) != EOF ){
    if(percorre == '\n') contalinha++;
  }//while
  //Move o ponteiro do arquivo para o in�cio do mesmo
  rewind(arq);
  //Retorna o valor de contaLinha como valor da fun��o
  return contalinha;
}//contaLinha

void CompAno(char procura[31], Musica* s, int quant, FILE* arq){
  //Declara��o de contador
  int cont = 0;
  //Looping para percorrer as posi��es do vetor s
  for (int i = 0; i < quant; i++) {
    //Verifica se a string procura � uma substring de s[i].ano
    if (strstr(s[i].ano,procura) != NULL) {
      //Salva as informa��es da m�sica no arquivo de sa�da
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementa��o no contador
      cont--;
    }//if
    //Incrementa��o no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de sa�da que n�o foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompAno

void CompTitulo(char procura[31], Musica* s, int quant, FILE* arq){
  //Declara��o de uma string auxiliar, duas vari�veis e um contador
  char aux[31];
  int j = 0, k = 0, cont = 0;
  //Enquanto n�o chegar ao fim da string procura
  while (procura[j] != '\0') {
    //O char na posi��o j da string recebe o mesmo char em uppercase
    procura[j] = toupper(procura[j]);
    //Incrementa��o no valor de j
    j++;
  }//while
  //Looping para percorrer as posi��es do vetor s
  for (int i = 0; i < quant; i++) {
    //Copia o conte�do da string s[i].titulo na string auxiliar
    strcpy(aux, s[i].titulo);
    //Enquanto n�o chegar ao fim da string auxiliar
    while (aux[k] != '\0') {
      //O char na posi��o k da string recebe o mesmo char em uppercase
      aux[k] = toupper(aux[k]);
      //Incrementa��o no valor de k
      k++;
    }//while
    //Verifica se a string procura � uma substring de aux
    if (strstr(aux,procura) != NULL) {
      //Salva as informa��es da m�sica no arquivo de sa�da
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementa��o no contador
      cont--;
    }//if
    //Vari�vel k recebe zero
    k = 0;
    //Incrementa��o no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de sa�da que n�o foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompTitulo

void CompArtista(char procura[31], Musica* s, int quant, FILE* arq){
  //Declara��o de uma string auxiliar, duas vari�veis e um contador
  char aux[21];
  int j = 0, k = 0, cont = 0;
  //Enquanto n�o chegar ao fim da string procura
  while (procura[j] != '\0') {
    //O char na posi��o j da string recebe o mesmo char em uppercase
    procura[j] = toupper(procura[j]);
    //Incrementa��o no valor de j
    j++;
  }//while
  //Looping para percorrer as posi��es do vetor s
  for (int i = 0; i < quant; i++) {
    //Copia o conte�do da string s[i].artista na string auxiliar
    strcpy(aux, s[i].artista);
    //Enquanto n�o chegar ao fim da string auxiliar
    while (aux[k] != '\0') {
      //O char na posi��o k da string recebe o mesmo char em uppercase
      aux[k] = toupper(aux[k]);
      //Incrementa��o no valor de k
      k++;
    }//while
    //Verifica se a string procura � uma substring de aux
    if (strstr(aux,procura) != NULL) {
      //Salva as informa��es da m�sica no arquivo de sa�da
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementa��o no contador
      cont--;
    }//if
    //Vari�vel k recebe zero
    k = 0;
    //Incrementa��o no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de sa�da que n�o foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompArtista

void CompGenero(char procura[31], Musica* s, int quant, FILE* arq){
  //Declara��o de uma string auxiliar, duas vari�veis e um contador
  char aux[12];
  int j = 0, k = 0, cont = 0;
  //Enquanto n�o chegar ao fim da string procura
  while (procura[j] != '\0') {
    //O char na posi��o j da string recebe o mesmo char em uppercase
    procura[j] = toupper(procura[j]);
    //Incrementa��o no valor de j
    j++;
  }//while
  //Looping para percorrer as posi��es do vetor s
  for (int i = 0; i < quant; i++) {
    //Copia o conte�do da string s[i].genero na string auxiliar
    strcpy(aux, s[i].genero);
    //Enquanto n�o chegar ao fim da string auxiliar
    while (aux[k] != '\0') {
      //O char na posi��o k da string recebe o mesmo char em uppercase
      aux[k] = toupper(aux[k]);
      //Incrementa��o no valor de k
      k++;
    }//while
    //Verifica se a string procura � uma substring de aux
    if (strstr(aux,procura) != NULL) {
      //Salva as informa��es da m�sica no arquivo de sa�da
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementa��o no contador
      cont--;
    }//if
    //Vari�vel k recebe zero
    k = 0;
    //Incrementa��o no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de sa�da que n�o foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompGenero

void CompIdioma(char procura[31], Musica* s, int quant, FILE* arq){
  //Declara��o de uma string auxiliar, duas vari�veis e um contador
  char aux[12];
  int j = 0, k = 0, cont = 0;
  //Enquanto n�o chegar ao fim da string procura
  while (procura[j] != '\0') {
    //O char na posi��o j da string recebe o mesmo char em uppercase
    procura[j] = toupper(procura[j]);
    //Incrementa��o no valor de j
    j++;
  }//while
  //Looping para percorrer as posi��es do vetor s
  for (int i = 0; i < quant; i++) {
    //Copia o conte�do da string s[i].idioma na string auxiliar
    strcpy(aux, s[i].idioma);
    //Enquanto n�o chegar ao fim da string auxiliar
    while (aux[k] != '\0') {
      //O char na posi��o k da string recebe o mesmo char em uppercase
      aux[k] = toupper(aux[k]);
      //Incrementa��o no valor de k
      k++;
    }//while
    //Verifica se a string procura � uma substring de aux
    if (strstr(aux,procura) != NULL) {
      //Salva as informa��es da m�sica no arquivo de sa�da
      fprintf(arq, "%s|%s|%s|%s|%s|%s\n", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
      //Decrementa��o no contador
      cont--;
    }//if
    //Vari�vel k recebe zero
    k = 0;
    //Incrementa��o no contador
    cont++;
  }//for
  //Se cont for igual a quant
  if (cont == quant) {
    //Salva no arquivo de sa�da que n�o foi encontrada nada referente a procura
    fprintf(arq, "Nenhum registro foi encontrado!\n");
  }//if
}//CompIdioma

int main(int argc, char const *argv[]) {
  //Condi��o para verificar se 3 arquivos (entrada, busca e sa�da) foram inseridos
  if (argc != 4) {
    //Exibe que a quantidade de param�tros � inv�lida
    printf("Quantidade de param�tros inv�lida!\n");
    //Retorna 0 como valor da fun��o e encerra o programa
    return 0;
  }//if
  //Abre e retorna um ponteiro para cada arquivo
  FILE* entrada = fopen(argv[1],"r");
  FILE* busca = fopen(argv[2],"r");
  FILE* saida = fopen(argv[3],"w");
  //Verifica se existe erro na abertura dos arquivos
  if(entrada == NULL || busca == NULL || saida == NULL){
    //Exibe a mensagem de erro
    perror("Error ");
    //Retorna 0 como valor da fun��o e encerra o programa
    return 0;
  }//if
  //Declara��o de vari�veis
  int size = 0, top = 0, quant = 0, linhas = 0, status = 0;
  //Variav�l linhas recebe o valor da fun��o contaLinha
  linhas = contaLinha(entrada);
  //L� o header do arquivo de entrada e armazena as informa��es nas vari�veis
  fscanf(entrada, "SIZE=%d TOP=%d QTDE=%d STATUS=%d", &size, &top, &quant, &status);
  //Se o n�mero de linhas for diferente da quantidade de registros + header
  if (linhas != (quant + 1)) {
   //Salva no arquivo de sa�da que o arquivo � invalido
   fprintf(saida, "Arquivo Inv�lido!\n");
   //Fecha os arquivos
   fclose(entrada);
   fclose(busca);
   fclose(saida);
   //Retorna 0 como valor da fun��o e encerra o programa
   return 0;
 }//if
  //Variav�l linhas recebe o valor da fun��o contaLinha
  linhas = contaLinha(busca);
  //Se o n�mero de linhas do arquivo de busca for diferente de 2
  if (linhas != 2) {
   //Salva no arquivo de sa�da que o arquivo � invalido
   fprintf(saida, "Arquivo Inv�lido!\n");
   //Fecha os arquivos
   fclose(entrada);
   fclose(busca);
   fclose(saida);
   //Retorna 0 como valor da fun��o e encerra o programa
   return 0;
  }//if
  //Declara��o de vetor s de tamanho quant com estrutura Musica
  Musica s[quant];
  //Looping para percorrer os vetores
  for(int i = 0; i < quant; i++){
    //L� do arquivo de entrada as informa��es presentes em uma linha e salva na posi��o i do vetor s
    fscanf(entrada, "\n%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]", s[i].ano, s[i].duracao, s[i].titulo, s[i].artista, s[i].genero, s[i].idioma);
  }//for
  //Declara��o de strings
  char campo[10];
  char procura[31];
  //Armazena na string campo o campo em que o usu�rio quer buscar uma informa��o
  fscanf(busca, "%s\n", campo);
  //Armazena na string procura a informa��o que o usu�rio quer buscar
  fscanf(busca, "%[^\n]", procura);
  //Verifica se o usu�rio quer o campo ano
  if (strcasecmp(campo,"ano") == 0) {
    //Chama a fun��o CompAno
    CompAno(procura, s, quant, saida);
  }//if
  //Verifica se o usu�rio quer o campo titulo
  if (strcasecmp(campo,"titulo") == 0) {
    //Chama a fun��o CompTitulo
    CompTitulo(procura, s, quant, saida);
  }//if
  //Verifica se o usu�rio quer o campo artista
  if (strcasecmp(campo,"artista") == 0) {
    //Chama a fun��o CompArtista
    CompArtista(procura, s, quant, saida);
  }//if
  //Verifica se o usu�rio quer o campo genero
  if (strcasecmp(campo,"genero") == 0) {
    //Chama a fun��o CompGenero
    CompGenero(procura, s, quant, saida);
  }//if
  //Verifica se o usu�rio quer o campo idioma
  if (strcasecmp(campo,"idioma") == 0) {
    //Chama a fun��o CompIdioma
    CompIdioma(procura, s, quant, saida);
  }//if
  //Se o usu�rio n�o procura uma informa��o em nenhum dos campos descritos acima
  if (strcasecmp(campo,"ano") != 0 && strcasecmp(campo,"titulo") != 0 && strcasecmp(campo,"artista") != 0 && strcasecmp(campo,"genero") != 0 && strcasecmp(campo,"idioma") != 0) {
    //Salva no arquivo de sa�da que o arquivo � invalido
    fprintf(saida, "Arquivo Inv�lido!\n");
  }//if
  //Fecha os arquivos
  fclose(entrada);
  fclose(busca);
  fclose(saida);
  //Retorna 0 como valor da fun��o e encerra o programa
  return 0;
}//main
