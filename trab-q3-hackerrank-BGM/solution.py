# Helper code to read input
moedas = list(map(int, input().split()))
valor = int(input())


def qtde_moedas(moedas, n):
    """ Função retorna quantidade de moedas necessárias, de acordo com os
    parâmetros:
    moedas (list) = lista de valores de moedas disponíveis;
    n      (int)  = valor que se deseja obter
    """

    # Inicializando matriz
    m = [[0 for _ in range(n + 1)] for _ in range(len(moedas) + 1)]
    for i in range(n + 1):
        m[0][i] = i

    for col in range(1, len(moedas) + 1):
        moeda = moedas[col - 1]
        for lin in range(1, n + 1):
            if moeda == lin:
                # utiliza a moeda
                m[col][lin] = 1
            # senão der para usar a moeda:
            elif moeda > lin:
                # Se moeda vale mais que o valor, usar solução da moeda
                # anterior
                m[col][lin] = m[col - 1][lin]
            else:
                # Se a moeda vale menos que valor, algoritmo escolherá a opção
                # que dará menor quantidade dentre as opções abaixo:
                # 1. quantidade de moedas da moeda anterior;
                # 2. usar a moeda, calculando a quantidade de moedas que havia
                # da última vez que a moeda foi usada + 1
                m[col][lin] = min(m[col - 1][lin], 1 + m[col][lin - moeda])

    return m[-1][-1]


# Helper code to print output
print(qtde_moedas(moedas, valor))
