def InsertionSort(vet, tam):

    for i in range(1, len(vet)):
        aux = vet[i]
        j = i - 1
        while(j >= 0 and aux < vet[j]):
            vet[j+1] = vet[j]
            j = j - 1
        vet[j+1] = aux


vet = [64, -73, 38, -61, -57, -34, 40, -78, -48, -24, 17, -20, -53, 60, 33]

tam = len(vet)
print("Vetor desornado: ")
print(vet)

InsertionSort(vet,tam)

print("Vetor ordenado após Insertion Sort")
print(vet)