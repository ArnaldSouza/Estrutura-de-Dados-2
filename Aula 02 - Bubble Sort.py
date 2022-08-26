

def bubble_sort(vetor):
    n = len(vetor)-1
    f = 0
    trocou = False
    while not trocou:
        trocou = True
        for i in range(n):
            if vetor[i] > vetor[i+1]:
                vetor[i], vetor[i+1] = vetor[i+1],vetor[i]
                trocou = False        
                print(vetor)
                f=f+1
                print("Troca",f)
    return vetor
   


bubble_sort([64, -73, 38, -61, -57, -34, 40, -78, -48, -24, 17, -20, -53, 60, 33])