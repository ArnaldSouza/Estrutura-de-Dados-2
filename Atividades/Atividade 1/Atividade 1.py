import random
#TEMPO
import time
start = time.tempo()
print("O tempo usado é:")
fim = time.tempo()
print(end - start)
#--------------------------------------------INSERTIONSORT--------------------------------------------
#CRESCENTE
def InsertionSortC(vetor, tamanho):

    for i in range(1, len(vetor)):
        auxiliar = vetor[i]
        j = i - 1

        while(j >= 0 and auxiliar < vetor[j]):
            vetor[j+1] = vetor[j]
            j = j - 1

        vetor[j+1] = auxiliar

#DECRESCENTE
def InsertionSortD(vetor, tamanho):

    for i in range(1, len(vetor)):
        auxiliar = vetor[i]
        j = i - 1

        while(j >= 0 and auxiliar > vetor[j]):
            vetor[j+1] = vetor[j]
            j = j - 1

        vetor[j+1] = auxiliar

#--------------------------------------------SELECTIONSORT--------------------------------------------
#CRESCENTE
def SelectionSortC(vetor,tamanho):
    for n in range(tamanho):
        menor = n

    for i in range(n , tamanho - 1):

    if vetor[i] < vetor[menor]:
        menor = i

        (vetor[n],vetor[menor]) = (vetor[menor],vetor[n])

#DECRESCENTE
def SelectionSortD(vetor,tamanho):
    for n in range(tamanho):
        menor = n

    for i in range(n , tamanho):

    if vetor[i] > vetor[menor]:
        menor = i

        (vetor[n],vetor[menor]) = (vetor[menor],vetor[n])

#--------------------------------------------BUBBLESORT--------------------------------------------
#CRESCENTE
def BubbleSortC(vetor):

    n = len(vetor)-1
    trocou = False

    while not trocou:
        trocou = True
        for i in range(n):
            if vetor[i] > vetor[i+1]:
                vetor[i], vetor[i+1] = vetor[i+1],vetor[i]
                trocou = False

    return vetor

#DECRESCENTE
def BubbleSortD(vetor):

    n = len(vetor)-1
    trocou = False

    while not trocou:
        trocou = True
        for i in range(n):
            if vetor[i] < vetor[i+1]:
                vetor[i], vetor[i+1] = vetor[i+1],vetor[i]
                trocou = False

    return vetor
#--------------------------------------------MERGESORT--------------------------------------------
#CRESCENTE
def MergeSortC(vetor):

    if len(vetor) > 1:
        meio = len(vetor)//2
        A = vetor[:meio]
        B = vetor[meio:]

        MergeSortC(A)
        MergeSortC(B)

        i = j = k = 0

        while i < len(A) and j < len(B):
            if A[i] < B[j]:
                vetor[k] = A[i]
                i += 1
            else:
                vetor[k] = B[j]
                j += 1
                k += 1


        while i < len(A):
            vetor[k] = A[i]
            i += 1
            k += 1

        while j < len(B):
            vetor[k] = B[j]
            j += 1
            k += 1

#DECRESCENTE
def MergeSortD(vetor):

    if len(vetor) > 1:
        meio = len(vetor)//2
        A = vetor[:meio]
        B = vetor[meio:]

        MergeSortD(A)
        MergeSortD(B)

        i = j = k = 0

        while i < len(A) and j < len(B):
            if A[i] > B[j]:
                vetor[k] = A[i]
                i += 1
            else:
                vetor[k] = B[j]
                j += 1
                k += 1


        while i < len(A):
            vetor[k] = A[i]
            i += 1
            k += 1

        while j < len(B):
            vetor[k] = B[j]
            j += 1
            k += 1

#--------------------------------------------QUICKSORT--------------------------------------------
#CRESCENTE
def ParticaoC(vetor, menor, maior):

    # escolhe o elemento mais a direita como pivo
    pivo = vetor[maior]
    # ponteiro para o maior elemento
    i = menor - 1

    # passa por todos os elementos e
    # compara cada elemento com o pivo
    for j in range(menor, maior):
        if vetor[j] <= pivo:
            # se o elemento é menor que o pivo achado
            # troca ele com o maior elemento apontado por i
            i = i + 1

            # troca o elemento da posição i com a j
            (vetor[i], vetor[j]) = (vetor[j], vetor[i])

    # Troca o pivo com o maior elento chamado de i
    (vetor[i + 1], vetor[maior]) = (vetor[maior], vetor[i + 1])

    # retorna a posição de onde foi divido
    return i + 1

def QuickSortC(vetor, menor, maior):
    if menor < maior:
        # find pivot element such that
        # elementos menores que o pivot estão na esquerda
        # elementos maiores que o pivot estão na direita
        pi = ParticaoC(vetor, menor, maior)

        # chamada recursiva pivo esquerda
        QuickSortC(vetor, menor, pivo - 1)

        # chamada recursiva pivo direita
        QuickSortC(vetor, pivo + 1, maior)


#DECRESCENTE
def ParticaoD(vetor, menor, maior):

    # escolhe o elemento mais a direita como pivo
    pivo = vetor[maior]
    # ponteiro para o maior elemento
    i = menor - 1

    # passa por todos os elementos e
    # compara cada elemento com o pivo
    for j in range(menor, maior):
        if vetor[j] >= pivo:
            # se o elemento é menor que o pivo achado
            # troca ele com o maior elemento apontado por i
            i = i + 1

            # troca o elemento da posição i com a j
            (vetor[i], vetor[j]) = (vetor[j], vetor[i])

    # Troca o pivo com o maior elento chamado de i
    (vetor[i + 1], vetor[maior]) = (vetor[maior], vetor[i + 1])

    # retorna a posição de onde foi divido
    return i + 1

def QuickSortD(vetor, menor, maior):
    if menor < maior:
        # find pivot element such that
        # elementos menores que o pivot estão na esquerda
        # elementos maiores que o pivot estão na direita
        pi = ParticaoD(vetor, menor, maior)

        # chamada recursiva pivo esquerda
        QuickSortD(vetor, menor, pivo - 1)

        # chamada recursiva pivo direita
        QuickSortD(vetor, pivo + 1, maior)

#--------------------------------------------HEAPSORT--------------------------------------------
#CRESCENTE
def HeapifyC(vetor, n, i):
    # encontrar o maior e o filho
    maior = i
    esquerda = 2 * i + 1
    direita = 2 * i + 2

    if esquerda < n and vetor[i] < vetor[esquerda]:
        maior = esquerda

    if direita < n and vetor[maior] < vetor[direita]:
        maior = direita

    # indentifica o maior e faz a troca
    if maior != i:
        vetor[i], vetor[maior] = vetor[maior], vetor[i]
        HeapifyC(vetor, n, maior)

def HeapSortC(vetor):
    n = len(vetor)

    # heap max
    for i in range(n//2, -1, -1):
        HeapifyC(vetor, n, i)

    for i in range(n-1, 0, -1):
        # troca
        vetor[i], vetor[0] = vetor[0], vetor[i]

        HeapifyC(vetor, i, 0)

#DECRESCENTE
def HeapifyD(vetor, n, i):
    # encontrar o maior e o filho
    menor = i
    esquerda = 2 * i + 1
    direita = 2 * i + 2

    if esquerda < n and vetor[esquerda] < vetor[menor]:
        menor = esquerda

    if direita < n and vetor[direita] < vetor[menor]:
        menor = direita

    # indentifica o menor e faz a troca
    if menor != i:
        vetor[i], vetor[menor] = vetor[menor], vetor[i]
        HeapifyD(vetor, n, menor)

def HeapSortD(vetor):
    n = len(vetor)

    # heap max
    for i in range(n//2, -1, -1):
        HeapifyD(vetor, n, i)

    for i in range(n-1, 0, -1):
        # troca
        vetor[i], vetor[0] = vetor[0], vetor[i]

        HeapifyD(vetor, i, 0)

if __name__ == '__main__':

    file1 = open("input1.txt", "r")
    l1 = print(file1.readline())
    l2 = print(file1.readline())


    #linha de comando, ler argumento do
    #selecao = entrada pelo arquivo (argumento)
    match selecao:
        case 'c':
            InsertionSortC(vet)
            print("Insertion Sort:", vet)
            SelectionSortC(vet)
            print("Selection Sort:", vet)
            BubbleSortC(vet)
            print("Bubble Sort:", vet)
            MergeSortC(vet)
            print("Merge Sort:", vet)
            QuickSortC(vet)
            print("QuickSort:", vet)
            HeapSortC(vet)
            print("Heap Sort:", vet)
        case 'd':
            InsertionSortD(vet)
            print("Insertion Sort:", vet)
            SelectionSortD(vet)
            print("Selection Sort:", vet)
            BubbleSortD(vet)
            print("Bubble Sort:", vet)
            MergeSortD(vet)
            print("Merge Sort:", vet)
            QuickSortD(vet)
            print("QuickSort:", vet)
            HeapSortD(vet)
            print("Heap Sort:", vet)
        case 'r':
            saida = []
            for _ in range(l1):
                saida.append(random.choice(range(32000)))
                print saida
            InsertionSortC(vet)
            print("Insertion Sort:", vet)
            SelectionSortC(vet)
            print("Selection Sort:", vet)
            BubbleSortC(vet)
            print("Bubble Sort:", vet)
            MergeSortC(vet)
            print("Merge Sort:", vet)
            QuickSortC(vet)
            print("QuickSort:", vet)
            HeapSortC(vet)
            print("Heap Sort:", vet)

#abertura de arquivo
#linha de comando
#tempo
#random
#verificar se switch funciona
