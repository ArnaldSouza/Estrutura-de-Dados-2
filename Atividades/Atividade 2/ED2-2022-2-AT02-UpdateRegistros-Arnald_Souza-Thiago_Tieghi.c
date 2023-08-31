#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char nome[31];
    char sexo;
    int idade;
    char especialidade[31];
    char telefone[15];
} Professor;

void recuperaRegistro(FILE *arq, Professor p);

int main(int argc, const char *argv[]){
    FILE *arq1;
    int tamVet = -1;
    int size;
    int top;
    char fim = 0;

    Professor *professores;

    arq1 = fopen(argv[1], "r");

    while (1){
        fim = fgetc(arq1);
        if (fim == '\n'){
            tamVet++;
        }
        if (fim == EOF){
            break;
        }//if
    }//while

    printf("tamanhoVetor = %d\n", tamVet);
    professores = malloc(tamVet * sizeof(Professor));
    rewind(arq1);
    fscanf(arq1, "size=%d top=%d\n", &size, &top);
    printf("Size=%d top=%d\n", size, top);

    for (int i = 0; i < tamVet; i++){
        fscanf(arq1, "%d", &professores[i].codigo);
        fim = fgetc(arq1);

        fgets(professores[i].nome, 31, arq1);
        fim = fgetc(arq1);

        professores[i].sexo = fgetc(arq1);
        fim = fgetc(arq1);

        fscanf(arq1, "%2d", &professores[i].idade);
        fim = fgetc(arq1);

        fgets(professores[i].especialidade, 31, arq1);
        fim = fgetc(arq1);

        fgets(professores[i].telefone, 15, arq1);
        fim = fgetc(arq1);
    }//for

    FILE *op;
    FILE *temp;
    Professor leitura;
    int index = 0;
    char destino[4] = "";
    char idade[3] = "";
    int cod = 0;
    op = fopen(argv[2], "r");

    if (op == NULL)    {
        printf("erro ao abrir o arquivo");
        exit(1);
    }//if

    temp = fopen(argv[3], "w");
    if (temp == NULL){
        printf("erro ao abrir o arquivo");
        exit(1);
    }//if
    rewind(arq1);

    while (1){ // preenche o temp com o tamanho do vetor de professores
        fim = fgetc(arq1);
        if (fim == EOF){
            break;
        }//if
        fputc(fim, temp);
    }//while

    while (1){ // lendo o temp e modificando
        index = 0;
        cod = 0;
        fim = fgetc(op); // i
        if (fim == 'i'){ // ele add no temp
            fim = fgetc(op); // le o espaço
            while (1){
                fim = fgetc(op);
                if (fim == '\n'){
                    leitura.telefone[cod] = '\0';
                    break;
                }else if (fim == ','){
                    if (index == 1){
                        leitura.nome[cod] = '\0';
                    }//if
                    if (index == 4){
                        leitura.especialidade[cod] = '\0';
                    }//if
                    index++;
                    cod = 0;
                }else if (index == 0){
                    destino[cod] = fim;
                    cod++;
                }else if (index == 1){
                    leitura.nome[cod] = fim;
                    cod++;
                }else if (index == 2){
                    leitura.sexo = fim;
                }else if (index == 3){
                    idade[cod] = fim;
                    cod++;
                }else if (index == 4){
                    leitura.especialidade[cod] = fim;
                    cod++;
                }else if (index == 5){
                    leitura.telefone[cod] = fim;
                    cod++;
                }//if
            }//while
            leitura.codigo = atoi(destino);
            leitura.idade = atoi(idade);

            // adiciona ------------------------------------------------------------------------------------------------------------------------------------
            int aaa = 0; // controle
            int size;
            int top1;
            char auxs[4];
            int newtop = 99;
            fclose(temp);
            temp = fopen(argv[3], "r+");
            fscanf(temp, "size=%d top=%d\n", &size, &top1);

            if (top1 == -1){
                fseek(temp, 0, SEEK_END);
                fprintf(temp, "%03d|%-30s|%c|%02d|%-30s|%14s|\n", leitura.codigo, leitura.nome, leitura.sexo, leitura.idade, leitura.especialidade, leitura.telefone);
                tamVet++;
                professores = realloc(professores, tamVet * sizeof(Professor));
                professores[tamVet - 1] = leitura;
            }else{

                fclose(temp);
                temp = fopen(argv[3], "w+");
                fprintf(temp, "size=%d top=%d\n", size, top1);
                for (int i = 0; i < tamVet; i++){
                    if (i == (top1 - 1) && professores[i].codigo == -99){
                        professores[i] = leitura;
                        for (int j = 0; j < tamVet; j++){
                            if (professores[j].codigo == -99){
                                if (newtop < j){
                                    newtop = j + 1;
                                }//if
                            }//if
                        }//for
                    }//if
                }//for

                rewind(temp);
                fprintf(temp, "size=%d top=%d\n", size, newtop);
                for (int j = 0; j < tamVet; j++){
                    if (professores[j].codigo == -99){
                        itoa(professores[j].codigo, auxs, 10);
                        auxs[0] = '*';
                        fprintf(temp, "%03s|%-30s|%c|%02d|%-30s|%14s|\n", auxs, professores[j].nome, professores[j].sexo, professores[j].idade, professores[j].especialidade, professores[j].telefone);
                    }//if
                    // printf("CODIGO: %d = %d\n", vet[j].codigo, vet[m].codigo);
                }//for
            }//else
        }else if (fim == 'd'){
            fim = fgetc(op);
            while (1){
                fim = fgetc(op);
                if (fim == '\n' || fim == EOF){
                    break;
                }//if
                destino[cod] = fim;
                cod++;
            }//while

            char aux[tamVet][4];
            int size;
            int top;
            int indextop = 0;
            fclose(temp);
            temp = fopen(argv[3], "r+");
            fscanf(temp, "size=%d top=%d\n", &size, &top);
            if (top == -1){
                top = 10;
            }//if
            fclose(temp);
            temp = fopen("temp2.txt", "w+");
            for (int i = 0; i < tamVet; i++){
                if (atoi(destino) == professores[i].codigo){
                    sprintf(aux[i], "%03d", professores[i].codigo);
                    professores[i].codigo = -99;
                    if (i + 1 < top){
                        indextop = i + 1;
                    }else{
                        indextop = top;
                    }//else
                    aux[i][0] = '*';
                }else{
                    sprintf(aux[i], "%03d", professores[i].codigo);
                }//else
            }//for
            fprintf(temp, "size=%d top=%d\n", size, indextop);
            for (int x = 0; x < tamVet; x++){
                if (professores[x].codigo == -99){
                    aux[x][0] = '*';
                }//if

                fprintf(temp, "%3s|%-30s|%c|%02d|%-30s|%14s|\n", aux[x], professores[x].nome, professores[x].sexo, professores[x].idade, professores[x].especialidade, professores[x].telefone);
            }//for
        }else if (fim == EOF){}
            break;
    }//while

//main

    fclose(temp);

    FILE *output;
    temp = fopen(argv[3], "r");
    fscanf(temp, "size=%d top=%d\n", &size, &top);

    output = fopen(argv[4], "w");
    top = -1;
    fprintf(output, "size=%d top=%d\n", size, top);
    for (int x = 0; x < tamVet; x++){
        if (professores[x].codigo != -99){
            fprintf(output, "%03d|%-30s|%c|%02d|%-30s|%14s|\n", professores[x].codigo, professores[x].nome, professores[x].sexo, professores[x].idade, professores[x].especialidade, professores[x].telefone);
        }//if
    }//for
    return 0;
}
