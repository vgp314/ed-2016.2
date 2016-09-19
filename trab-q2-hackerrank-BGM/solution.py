# Helper code to read input
lista = list(map(int, input().split()))


def maxcontsub(lista):
    maxvalue = finalvalue = 0
    for x in lista:
        maxvalue = max(0, maxvalue + x)
        finalvalue = max(maxvalue, finalvalue)
    return finalvalue


# Helper code to print output
print(maxcontsub(lista))
