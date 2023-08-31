#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//função auxiliar troca
void troca(int *posicao1, int *posicao2){
  int auxiliar = *posicao1;
  *posicao1 = *posicao2;
  *posicao2 = auxiliar;
}//troca

//--------------------------------------------INSERTIONSORT--------------------------------------------
void insertionSort(int *vetor, int tamanho, int *comparacao){
  *comparacao = 0;
  int auxiliar;
  int j = 0;

  for (int i = 1; i < tamanho; i++){
    *comparacao = *comparacao + 1;
    auxiliar = vetor[i];
    j = i - 1;
    while (j >= 0 && auxiliar < vetor[j]){
      *comparacao = *comparacao + 1;
      vetor[j + 1] = vetor[j];
      j = j - 1;
    }//while
    vetor[j + 1] = auxiliar;
  }//for
}//insertion

//--------------------------------------------SELECTIONSORT--------------------------------------------
void selectionSort(int *vetor, int tamanho, int *comparacao){
  *comparacao = 0;
  int menor;
  int indice;
  for (int n = 0; n < tamanho; n++){
    *comparacao = *comparacao + 1;
    indice = n;
    menor = vetor[indice];

    for (int i = n; i < tamanho; i++){
      if (menor > vetor[i]){
        *comparacao = *comparacao + 1;
        menor = vetor[i];
        indice = i;
      }//if
    }//for2

    if (menor != vetor[n]){
      *comparacao = *comparacao + 1;
      troca(&vetor[indice], &vetor[n]);
    }//if
  }//for1

}//selectionSort

//--------------------------------------------BUBBLESORT-----------------------------------------------
int bubbleSort(int *vetor, int n){
  int comparacao = 0;
  bool trocou = true;

  while (trocou){
    comparacao = comparacao + 1;
    trocou = false;

    for (int i = 0; i < n - 1; i++){
      if (vetor[i] > vetor[i + 1]){
        comparacao = comparacao + 1;
        troca(&vetor[i], &vetor[i + 1]);
        trocou = true;
      }//if
    }//for
  }//while
  return comparacao;
}//bubbleSort

//--------------------------------------------MERGESORT-----------------------------------------------
int merge(int *vetor, int comeco, int meio, int fim){
  int comparacao = 0;
  int *auxiliar;
  int i, j, k;
  int p1, p2;
  int tamanho;

  bool finalizado1 = false;
  bool finalizado2 = false;

  tamanho = (fim - comeco) + 1;

  p1 = comeco;
  p2 = meio + 1;

  auxiliar = (int *)malloc(tamanho * sizeof(int));

  if (auxiliar != NULL){
    comparacao = comparacao + 1;
    for (i = 0; i < tamanho; i++){
      comparacao = comparacao + 1;
      if (!finalizado1 && !finalizado2){
        if (vetor[p1] < vetor[p2]){
          comparacao = comparacao + 1;
          auxiliar[i] = vetor[p1++];
        }else{
          comparacao = comparacao + 1;
          auxiliar[i] = vetor[p2++];
        }//if
        //verificando se algum subvetor está finalizado
        if (p1 > meio){
          comparacao = comparacao + 1;
          finalizado1 = true;
        }//if
        if (p2 > fim){
          comparacao = comparacao + 1;
          finalizado2 = true;
        }//if
      }else{
        // copiando os elementos que restaram
        if (!finalizado1){
          auxiliar[i] = vetor[p1++];
          comparacao = comparacao + 1;
        }else{
          comparacao = comparacao + 1;
          auxiliar[i] = vetor[p2++];
        }//else
      }//else
    }//for

    // passando os elementos do vetor auxiliar para o vetor original
    for (j = 0, k = comeco; j < tamanho; j++, k++){
      vetor[k] = auxiliar[j];
    }//for

  }//if1
  free(auxiliar);
  return comparacao;
}//merge

int mergeSort(int *vetor, int comeco, int fim){
  int comparacao = 0;
  int meio;

  if (comeco < fim){
    //procura o elemento do meio
    meio = (int)floor((comeco + fim) / 2);

    // chama recursivamente as duas metades do vetor original
    mergeSort(vetor, comeco, meio);
    mergeSort(vetor, (meio + 1), fim);

    //coloca o vetor na ordem correta
    comparacao = merge(vetor, comeco, meio, fim);
  }//if
    return comparacao;
}//mergeSort

//--------------------------------------------QUICKSORT-----------------------------------------------
int particao(int vetor[], int menor, int maior, int *comparacao){

  //seleciona o elemento da direita como pivo
  int pivo = vetor[maior];

  //ponteiro para o maior elemento
  int i = menor - 1;

  // passa por cada elemento do vetor comparando com o pivo
  for (int j = menor; j < maior; j++){
    if (vetor[j] <= pivo){
      *comparacao = *comparacao + 1;
      // se é encontrado um elemento menor que o pivo  ele é trocado com o maior elemento na posição i
      i++;
      // troca o elemento na posição i com a posição j
      troca(&vetor[i], &vetor[j]);
    }//if
  }//for

  // troca o pivo com o maior elemento em i
  troca(&vetor[i + 1], &vetor[maior]);

    // retorna ao ponto da particao
  return (i + 1);
}//particao

void quickSort(int vetor[], int menor, int maior, int *comparacao){
  if (menor < maior){
    *comparacao = *comparacao + 1;
    // encontra o pivo
    // elementos menores que o pivo ficam a esquerda do pivo
    // elementos maiores que o pivo ficam a direita do pivo
    int pivo = particao(vetor, menor, maior, comparacao);

    //chamada recursiva na esquerda do pivo
    quickSort(vetor, menor, pivo - 1, comparacao);

    //chamada recursiva na direita do pivo
    quickSort(vetor, pivo + 1, maior, comparacao);
  }//if
}//quickSort

//--------------------------------------------HEAPSORT-----------------------------------------------
int maxHeapify(int *vetor, int i, int tamanho){
  int comparacao = 0;
  int esquerda = (2 * i) + 1;
  int direita = (2 * i) + 2;
  int maior = i;
  int tempo = 0;

  if (esquerda <= tamanho - 1 && vetor[esquerda] > vetor[i]){
    comparacao++;
    maior = esquerda;
  }//if

  if (direita <= tamanho - 1 && vetor[direita] > vetor[maior]){
    comparacao++;
    maior = direita;
  }//if

  if (maior != i){
    comparacao++;
    tempo = vetor[i];
    vetor[i] = vetor[maior];
    vetor[maior] = tempo;
    maxHeapify(vetor, maior, tamanho);
  }//if
  return comparacao;
}//max_heapify

int buildMaxHeap(int *vetor, int tamanho){
  int comparacao = 0;

  int i = (tamanho - 2) / 2;
  while (i >= 0){
    comparacao++;
    maxHeapify(vetor, i--, tamanho);
  }//while
  return comparacao;
}//buildMaxHeap

int HeapSort(int *vetor, int tamanho){
  int tempo = 0;
  int comparacao = 0;

  comparacao = comparacao + buildMaxHeap(vetor, tamanho);

  while (tamanho != 1){
    comparacao++;
    tempo = vetor[0];
    vetor[0] = vetor[tamanho - 1];
    vetor[tamanho - 1] = tempo;
    tamanho--;
    comparacao = comparacao + maxHeapify(vetor, 0, tamanho);
  }//while

  return comparacao;
}//heapsort

void copiar(int copia[], int original[], int n){
  for (int i = 0; i < n; i++){
    copia[i] = original[i];
  }
}

void apresentaArquivo(int *vetor, int numero, FILE *saida){
  int comparacao = 0;
  clock_t comeco, fim;
  clock_t diferenca;

  int *copiaVet;
  copiaVet = (int *)malloc(numero * sizeof(int));

  // insertionSort
  {
    copiar(copiaVet, vetor, numero);
    comeco = clock();
    insertionSort(copiaVet, numero, &comparacao);
    fim = clock();

    fprintf(saida, "insertionSort:");
    for (int i = 0; i < numero; i++){
      fprintf(saida, " %d", copiaVet[i]);
    }//for
    diferenca = (fim - comeco) / (CLOCKS_PER_SEC / 1000);
    fprintf(saida, ", %d comp, %d ms\n", comparacao, diferenca);
  }

  // SelectionSort
  {
    copiar(copiaVet, vetor, numero);
    comeco = clock();
    selectionSort(copiaVet, numero, &comparacao);
    fim = clock();

    fprintf(saida, "selectionSort:");
    for (int i = 0; i < numero; i++){
      fprintf(saida, " %d", copiaVet[i]);
    }//for
    diferenca = (fim - comeco) / (CLOCKS_PER_SEC / 1000);
    fprintf(saida, ", %d comp, %d ms\n", comparacao, diferenca);
  }

  // BubbleSort
  {
    copiar(copiaVet, vetor, numero);
    comeco = clock();
    comparacao = bubbleSort(copiaVet, numero);
    fim = clock();

    fprintf(saida, "bubbleSort:");
    for (int i = 0; i < numero; i++){
      fprintf(saida, " %d", copiaVet[i]);
    }//for
    diferenca = (fim - comeco) / (CLOCKS_PER_SEC / 1000);
    fprintf(saida, ", %d comp, %d ms\n", comparacao, diferenca);
  }

  // MergeSort
  {
    copiar(copiaVet, vetor, numero);
    comeco = clock();

    comparacao = mergeSort(copiaVet, 0, numero - 1);
    fim = clock();

    fprintf(saida, "mergeSort:");
    for (int i = 0; i < numero; i++){
      fprintf(saida, " %d", copiaVet[i]);
    }//for
    diferenca = (fim - comeco) / (CLOCKS_PER_SEC / 1000);
    fprintf(saida, ", %d comp, %d ms\n", comparacao, diferenca);
  }

  // quickSort
  {
    copiar(copiaVet, vetor, numero);
    comparacao = 0;
    comeco = clock();
    quickSort(copiaVet, 0, numero - 1, &comparacao);
    fim = clock();

    fprintf(saida, "quickSort:");
    for (int i = 0; i < numero; i++){
      fprintf(saida, " %d", copiaVet[i]);
    }//for
    diferenca = (fim - comeco) / (CLOCKS_PER_SEC / 1000);
    fprintf(saida, ", %d comp, %d ms\n", comparacao, diferenca);
  }

  // heapSort
  {
    copiar(copiaVet, vetor, numero);
    comeco = clock();
    comparacao = HeapSort(copiaVet, numero);
    fim = clock();

    fprintf(saida, "heapSort:");
    for (int i = 0; i < numero; i++){
      fprintf(saida, " %d", copiaVet[i]);
    }//for

      diferenca = (fim - comeco) / (CLOCKS_PER_SEC / 1000);
      fprintf(saida, ", %d comp, %d ms\n", comparacao, diferenca);
  }
    free(copiaVet);
}

int main(int argc, const char *argv[]){
  float aux;
  char leitura; // char que vai ler
  char conc[10] = "";
  int numero; // quantidade de numeros dentro do vetor
  FILE *entrada;
  int *vetor;
  int parada = 0; // condicao de parada do \n do arquivo
  int auxiliar;

  entrada = fopen("input2.txt", "r");
    if (entrada == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1); // 1 significa erro
    }// if

  FILE *saida;
  saida = fopen("outputeste.txt", "w");
    if (saida == NULL){
      printf("Erro ao abrir o arquivo!\n");
      exit(1); // 1 significa erro
    }// if

  while ((fscanf(entrada, "%c", &leitura)) != EOF){
    // se o numero float for diferente do int, significa q Ã© um float, entao finaliza o programa
    if (parada == 0){
      if (leitura == ' '){
        parada = 5;
      }else if (leitura == '\n'){
        parada = 1;
      }else{
        sprintf(conc, "%s%c", conc, leitura);
      }//else
    }else if (parada == 1){
      aux = atof(conc);
      numero = atoi(conc);
      if (aux != numero){ // verificacao de float
        printf("Arquivo Invalido!");
        fprintf(saida, "Arquivo Invalido!");
        fclose(entrada);
        exit(1);
      }//if
      // malloc
      vetor = (int *)malloc(numero * sizeof(int));
      // abrindo arquivo de saida

      switch (leitura){
        case 'c':
          auxiliar = 1;
          for (int i = 0; i < numero; i++){
            vetor[i] = auxiliar;
            auxiliar++;
          }//for
          apresentaArquivo(vetor, numero, saida);
          break;

        case 'd':
          auxiliar = numero;
          for (int i = 0; i < numero; i++){
            vetor[i] = auxiliar;
            auxiliar--;
          }//for
          apresentaArquivo(vetor, numero, saida);
          break;

        case 'r':
          srand(time(NULL));
          for (int i = 0; i < numero; i++){
            vetor[i] = rand() % 32000;
          }//for
          apresentaArquivo(vetor, numero, saida);
          break;

        default:
          printf("Arquivo Invalido!");
          fprintf(saida, "Arquivo Invalido!");
          fclose(entrada);
          fclose(saida);
          exit(1);
          break;
      }//switch
      parada++;
    }// elif

    if (parada == 5){
      printf("Arquivo vazio!");
      fprintf(saida, "Arquivo vazio!");
      fclose(entrada);
      fclose(saida);
      exit(1);
    }//if
  }//while

  free(vetor);
  fclose(entrada);
  fclose(saida);
}//main
