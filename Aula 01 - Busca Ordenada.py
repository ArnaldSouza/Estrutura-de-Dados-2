# ---------------------------------------------------------------------------------------
# Busca Ordenada: testa todas as posições até encontrar o elemento desejado, ou até
# que o valor da posição testada for maior do que o elemento, ou chegou até o final do 
# vetor
# ---------------------------------------------------------------------------------------

def BuscaOrdenada(vetor, elemento):
    if ordenado != vetor:
        print("Vetor não é ordenado!")
        return False

    for i in range(len(vetor)):
        if elemento == vetor[i]:
            return True
        if vetor[i] > elemento:
            return False

    return False

if __name__ == '__main__':
    
    n_ordenado = [1, 2, 32, 8, 17, 19, 42, 13, 0]
    ordenado = [0, 1, 2, 8, 13, 17, 19, 32, 42] 

    print("* Busca Ordenada")
    print(BuscaOrdenada(n_ordenado, 3))
    print(BuscaOrdenada(ordenado, 13))
