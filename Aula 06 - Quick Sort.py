
def particao(vet, menor, maior):

  # escolhe o elemento mais a direita como pivo
  pivo = vet[maior]

  # ponteiro para o maior elemento
  i = menor - 1

  # passa por todos os elementos e 
  # compara cada elemento com o pivo
  for j in range(menor, maior):
    if vet[j] >= pivo:
      # se o elemento é menor que o pivo achado 
      # troca ele com o maior elemento apontado por i
      i = i + 1

      # troca o elemento da posição i com a j
      (vet[i], vet[j]) = (vet[j], vet[i])

  # Troca o pivo com o maior elento chamado de i
  (vet[i + 1], vet[maior]) = (vet[maior], vet[i + 1])

  # retorna a posição de onde foi divido
  return i + 1

def quickSort(vet, menor, maior):
  if menor < maior:

    # find pivot element such that
    # elemntos menores que o pivot estão na esquerda
    # elemntos maiores que o pivot estão na direita
    pi = particao(vet, menor, maior)

    # chamada recursiva pivo esquerda
    quickSort(vet, menor, pi - 1)

    # chamada recursiva pivo direita
    quickSort(vet, pi + 1, maior)


vetor = [64, -73, 38, -61, -57, -34, 40, -78, -48, -24, 17, -20, -53, 60, 33]
print("Vetor desordenado:")
print(vetor)

tam = len(vetor)

quickSort(vetor, 0, tam - 1)

print("Vetor ordenado após Quick Sort")
print(vetor)