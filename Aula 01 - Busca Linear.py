# ---------------------------------------------------------------------------------------
# Busca Linear:  testa todas as posições até encontrar o elemento desejado ou até
# chegar ao final do vetor
# ---------------------------------------------------------------------------------------

def BuscaLinear(vetor, elemento):
    pos = 0
    encontrado = False
    while pos < len(vetor) and not encontrado:
        if vetor[pos] == elemento:
            encontrado = True
        else:
            pos = pos+1
    return encontrado

if __name__ == '__main__':

    n_ordenado = [1, 2, 32, 8, 17, 19, 42, 13, 0]
    ordenado = [0, 1, 2, 8, 13, 17, 19, 32, 42]

    print("* Busca Linear")
    print(BuscaLinear(n_ordenado, 3))
    print(BuscaLinear(ordenado, 13))