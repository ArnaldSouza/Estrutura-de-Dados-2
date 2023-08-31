def heapify(array, n, i):
    # encontrar o maior e o filho
    menor = i
    e = 2 * i + 1
    d = 2 * i + 2
  
    if e < n and array[e] < array[menor]:
        menor = e
  
    if d < n and array[d] < array[menor]:
        menor = d
  
    # indentifica o menor e faz a troca
    if menor != i:
        array[i], array[menor] = array[menor], array[i]
        heapify(array, n, menor)
  
  
def heapSort(array):
    n = len(array)
  
    # heap max
    for i in range((n//2)-1, -1, -1):
        heapify(array, n, i)
  
    for i in range(n-1, -1, -1):
        # troca
        array[0], array[i] = array[i], array[0]
  
          
        heapify(array, i, 0)
  
print("Vetor antes do Heap Sort")
array = [64, -73, 38, -61, -57, -34, 40, -78, -48, -24, 17, -20, -53, 60, 33]
print(array)

heapSort(array)
n = len(array)

print("Vetor ordenado após Heap Sort")
for i in range(n):
    print("%d " % array[i], end='')