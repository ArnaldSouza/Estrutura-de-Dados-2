# ---------------------------------------------------------------------------------------
# Busca Binária: utiliza a divisão e conquista. testa sempre o elemento na metade do 
# intervalo válido.
# ---------------------------------------------------------------------------------------

def BuscaBinaria(vetor, elemento):

    encontrado = False
    if sorted(vetor) != vetor:
        print("Vetor não está Ordenado")
        return encontrado

    primeiro = 0
    ultimo = len(vetor)-1

    while primeiro<=ultimo and not encontrado:
        meio = (primeiro + ultimo)//2
        if vetor[meio] == elemento:
            encontrado = True
        else:
            if elemento < vetor[meio]:
                primeiro = meio-1
            else:
                primeiro = meio+1
    return encontrado

# ---------------------------------------------------------------------------------------
# ---------------------------------------------------------------------------------------


if __name__ == '__main__':

    n_ordenado = [1, 2, 32, 8, 17, 19, 42, 13, 0]
    ordenado = [0, 1, 2, 8, 13, 17, 19, 32, 42]


    print("* Busca Binaria")
    print(BuscaBinaria(n_ordenado, 3))
    print(BuscaBinaria(ordenado, 13))