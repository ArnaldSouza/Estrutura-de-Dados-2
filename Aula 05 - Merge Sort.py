def mergeSort(vet):
    
    if len(vet) > 1:
        
        meio = len(vet)//2
        A = vet[:meio]
        B = vet[meio:]

        mergeSort(A)
        mergeSort(B)

        i = j = k = 0

        while i < len(A) and j < len(B):
            if A[i] < B[j]:
                vet[k] = A[i]
                i += 1
            else:
                vet[k] = B[j]
                j += 1
            k += 1

        
        while i < len(A):
            vet[k] = A[i]
            i += 1
            k += 1

        while j < len(B):
            vet[k] = B[j]
            j += 1
            k += 1


vet = [64, -73, 38, -61, -57, -34, 40, -78, -48, -24, 17, -20, -53, 60, 33]
print("Vetor desordenado: ")
print(vet)

mergeSort(vet)
print("Vetor ordenado após Merge Sort: ")
print(vet)