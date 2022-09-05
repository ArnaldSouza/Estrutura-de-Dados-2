
def selectionSort(v,tam):

    for n in range(tam):
        menor = n

        for i in range(n , tam - 1):

            if v[i] < v[menor]:
                menor = i
            
        (v[n],v[menor]) = (v[menor],v[n])        

vet = [64,-73,38,-61,-57,-34,40,-78,-48,-24,17,-20,-53,60,33]
tam = len(vet)
print("Vetor desordenado:")
print(vet)

selectionSort(vet,tam)

print("Vetor ordenado após Selection Sort:")
print(vet)
