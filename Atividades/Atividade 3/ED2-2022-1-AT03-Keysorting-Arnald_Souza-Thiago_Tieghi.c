#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

// Estrutura de Heroi
typedef struct{
    char chave[3];         // chave numerica pode ter até 3 digitos
    char primeiroNome[16]; // primero nome do heroi
    char sobrenome[16];    // sobrenome
    char nomeHeroi[16];    // nome
    char poder[16];        // poder
    char fraqueza[21];     // fraqueza
    char cidade[21];       // cidade que deffime
    char profissao[21];    // profissao da sua identidade secreta
} Heroi;

void merge(int *v, int comeco, int meio, int fim){
    int *temp;
    int i, j, k;
    int p1, p2;
    int tamVet;

    bool f1 = false;
    bool f2 = false;

    tamVet = (fim - comeco) + 1;

    p1 = comeco;
    p2 = meio + 1;

    temp = (int *)malloc(tamVet * sizeof(int));

    if (temp != NULL){
        for (i = 0; i < tamVet; i++){
            if (!f1 && !f2){
                if (v[p1] < v[p2]){
                    temp[i] = v[p1++];
                }else{
                    temp[i] = v[p2++];
                }

                if (p1 > meio){
                    f1 = true;
                }
                if (p2 > fim){
                    f2 = true;
                }
            }else{
                // copiando os elementos restantes
                if (!f1)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }
        //copiando elentos de temp para v
        for (j = 0, k = comeco; j < tamVet; j++, k++){
            v[k] = temp[j];
        }
    } // if
    free(temp);
}

/* ------------------------------------------------------- */


void mergeSort(int *v, int comeco, int fim){

    int meio;

    if(comeco < fim){
        //encontrando o elemento do meio
        meio = (int)floor((comeco + fim) / 2);

        // chamando recursivamente as duas metades originais do vetor e reduzindo o problema
        mergeSort(v, comeco, meio);
        mergeSort(v, (meio + 1), fim);

        // arrumando na ordem correta
        merge(v, comeco, meio, fim);
    }
}

void insertionSort(int *v, int n, char ordem){

    int i, j, escolhido;

    for (i = 1; i < n; i++){
        escolhido = v[i];
        j = i - 1;

        // escolhfimo valor que podem trocar uma posição para frente

        if (ordem == 'c'){
            while (j >= 0 && escolhido < v[j]){
                v[j + 1] = v[j];
                j = j - 1;
            }
        }else if (ordem == 'd'){
            while (j >= 0 && escolhido > v[j]){
                // para ordem crescente muda  key> vetor[j] para key < arr[j].
                v[j + 1] = v[j];
                j = j - 1;
            }
        }
        v[j + 1] = escolhido;
    }
}

int Max_Heapify(int *v, int i, int tam){
    int comp = 0;
    int esq = (2 * i) + 1;
    int dir = (2 * i) + 2;
    int maior = i;
    int temp = 0;

    if (esq <= tam - 1 && v[esq] > v[i]){
        comp++;
        maior = esq;
    }

    if (dir <= tam - 1 && v[dir] > v[maior]){
        comp++;
        maior = dir;
    }

    if (maior != i){
        comp++;
        temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;
        Max_Heapify(v, maior, tam);
    }
    return comp;
}

void heapify(int vetor[], int n, int i){

    int aux;
    int menor = i;  //Inicializa o maior como raiz
    int l = 2 * i + 1; // esquerda = 2*i + 1
    int r = 2 * i + 2; // direita = 2*i + 2

    // se um filho é maior que a raiz
    if (l < n && vetor[l] < vetor[menor]){
        menor = l;
    }

    // se o filho da direita pe menor que o menor de tods
    if (r < n && vetor[r] < vetor[menor]){
        menor = r;
    }
    // Se o menor de todos não é raiz
    if (menor != i){
        aux = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = aux;

        // chama recursivamente a função heapify que afeta a subarvore
        heapify(vetor, n, menor);
    }
}

int Build_Max_Heap(int *v, int tam){
    int comp = 0;

    int i = (tam - 2) / 2;
    while (i >= 0){
        comp++;
        Max_Heapify(v, i--, tam);
    }
    return comp;
}

int HeapSort(int *v, int tam, char ordem){
    int temp = 0;
    int aux = 0;
    int comp = 0;
    ordem = tolower(ordem);
    if (ordem == 'c'){
        comp = comp + Build_Max_Heap(v, tam);

        while (tam != 1){
            comp++;
            temp = v[0];
            v[0] = v[tam - 1];
            v[tam - 1] = temp;
            tam--;

            comp = comp + Max_Heapify(v, 0, tam);
        }
    }else if (ordem == 'd'){
        for (int i = tam / 2 - 1; i >= 0; i--)
            heapify(v, tam, i);

        // Tira um elemento por um do heap
        for (int i = tam - 1; i >= 0; i--){
            // move a raiz atual para o fim
            aux = v[0];
            v[0] = v[i];
            v[i] = aux;

            // chama o elemento minimo do heapify no heap reduzido
            heapify(v, i, 0);
        }
    }
    return comp;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int vetor[], int menor, int maior){

    // seleciona o maior elemento como pivo
    int pivo = vetor[maior];

    //ponteiro para o maior elemento
    int i = menor - 1;

    // passa por cada elemento do vetor e compara ele com o pivo
    for (int j = menor; j < maior; j++){
        if (vetor[j] <= pivo){
            // se o menor elemento que o pivo e achado trocam eles com o maior elemento apontado como i
            i++;

            // troca o elemento i com o elemento j
            swap(&vetor[i], &vetor[j]);
        }
    }

    // troca o pivo com o maior elemento em i
    swap(&vetor[i + 1], &vetor[maior]);

    // retorna ao ponto incial
    return (i + 1);
}

void quickSort(int vetor[], int menor, int maior, char ordem){
    if (ordem == 'c'){
        if (menor < maior){
            // encontra o elemento chamado pivo
            // elementos menor que o pivo vao para a parte esquerda do pivo
            // elementos maior que o pivo vao para o lado direito do pivo
            int pi = partition(vetor, menor, maior);

            // chamada recursiva da parte esquerda do pivo
            quickSort(vetor, menor, pi - 1, ordem);

            // chamada recursiva da parte direita do pivo
            quickSort(vetor, pi + 1, maior, ordem);
        }
    }
    else if (ordem == 'd'){
        int i = menor;
        int j = maior;
        int temp = vetor[i];

        if (menor < maior){
            while (i < j){
                while (vetor[j] <= temp && i < j){
                    j--;
                }
                vetor[i] = vetor[j];

                while (vetor[i] >= temp && i < j){
                    i++;
                }
                vetor[j] = vetor[i];
            }
            vetor[i] = temp;

            quickSort(vetor, menor, i - 1, ordem);
            quickSort(vetor, j + 1, maior, ordem);
        }
    }
    else{
        printf("Erro ao inserir a ordenação do vetor");
        exit(1);
    }
}

int main(int argc, const char *argv[]){
    FILE *arq = fopen(argv[1], "r");
    FILE *saida = fopen(argv[2], "w");
    int size;
    int top;
    int qtde = 0;
    char sort;
    char order;

    fscanf(arq, "SIZE=%d TOP=%d QTDE=%d SORT=%c ORDER=%c\n", &size, &top, &qtde, &sort, &order);

    sort = tolower(sort);
    order = tolower(order);

    // criando os herois de acordo com qtde
    Heroi conjunto[qtde];

    // lendo os herois
    char c;
    int pipe = 0;
    int i = 0;
    int aux = 0;
    char string[22];
    while (1){
        c = fgetc(arq);

        if (c == EOF){
            break;
        }
        if (c == '|' || c == '\n'){
            if (c == '\n'){
                pipe = 0;
                aux = 0;
                i++;
            }else{
                pipe++;
                aux = 0;
            }
        }else{

            switch (pipe){
              case 0:
                  string[aux] = c;
                  aux++;
                  string[aux] = '\0';

                  strcpy(conjunto[i].chave, string);
                  break;

              case 1:
                  string[aux] = c;
                  aux++;
                  string[aux] = '\0';
                  strcpy(conjunto[i].primeiroNome, string);

                  break;

              case 2:

                  string[aux] = c;
                  aux++;
                  string[aux] = '\0';
                  strcpy(conjunto[i].sobrenome, string);

                  break;

              case 3:
                  string[aux] = c;
                  aux++;
                  string[aux] = '\0';
                  strcpy(conjunto[i].nomeHeroi, string);
                  break;

              case 4:
                  string[aux] = c;
                  aux++;
                  string[aux] = '\0';
                  strcpy(conjunto[i].poder, string);
                  break;

              case 5:
                  string[aux] = c;
                  aux++;
                  string[aux] = '\0';
                  strcpy(conjunto[i].fraqueza, string);

                  break;

              case 6:
                  string[aux] = c;
                  aux++;
                  string[aux] = '\0';
                  strcpy(conjunto[i].cidade, string);

                  break;

              case 7:
                  string[aux] = c;
                  aux++;
                  string[aux] = '\0';
                  strcpy(conjunto[i].profissao, string);
                  break;

              default:
                  fprintf(saida, "Erro\n");
                  break;
            }
        }

    }

    int vetor[qtde];
    for (int l = 0; l < qtde; l++){
        vetor[l] = atoi(conjunto[l].chave);
    }

    int merge = 0;
    sort = tolower(sort);
    switch (sort){
      case 'q':
          quickSort(vetor, 0, qtde - 1, order);
          break;

      case 'h':
          HeapSort(vetor, qtde, order);
          break;

      case 'm':
          mergeSort(vetor, 0, qtde);
          if (order == 'd'){
              merge = 1;
          }
          break;

      case 'i':
          insertionSort(vetor, qtde, order);
          break;

      default:
          fprintf(saida, "Erro no arquivo");
          exit(1);
          break;
    }
    for (int x = 0; x < qtde; x++){

    }

    if (qtde == i){

        fprintf(saida, "SIZE=%d TOP=%d QTDE=%d SORT=%c ORDER=%c\n", size, top, qtde, sort, order);
        if (!merge){
            for (int x = 0; x < qtde; x++){
                for (int y = 0; y < qtde; y++){
                    if (vetor[x] == atoi(conjunto[y].chave))
                    {
                        fprintf(saida, "%-3s|%-16s|%-16s|%-16s|%-20s|%-21s|%-21s|%-21s\n", conjunto[y].chave, conjunto[y].primeiroNome, conjunto[y].sobrenome, conjunto[y].nomeHeroi, conjunto[y].poder, conjunto[y].fraqueza, conjunto[y].cidade, conjunto[y].profissao);
                    }
                }

            }
        }else{
            for (int x = qtde - 1; x >= 0; x--){
                for (int y = 0; y < qtde; y++){
                    if (vetor[x] == atoi(conjunto[y].chave)){
                        fprintf(saida, "%-3s|%-16s|%-16s|%-16s|%-20s|%-21s|%-21s|%-21s\n", conjunto[y].chave, conjunto[y].primeiroNome, conjunto[y].sobrenome, conjunto[y].nomeHeroi, conjunto[y].poder, conjunto[y].fraqueza, conjunto[y].cidade, conjunto[y].profissao);
                    }
                }

            }
        }
    } else {
        fprintf(saida, "arquivo vazio");
    }
    if (qtde == 0){
        fprintf(saida, "arquivo vazio");
    }
   return 0;
}
