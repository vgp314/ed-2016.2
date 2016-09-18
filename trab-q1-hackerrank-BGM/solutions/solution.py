# Helper code to read input
lista = list(map(int, input().split()))


def countInversion(lista):
    count = 0

    def mergeSort(l1):
        size = len(l1)
        if size <= 1:
            return l1
        leftL = l1[:size // 2]
        rightL = l1[size // 2:]
        return sort_and_count_inversions_2(mergeSort(leftL), mergeSort(rightL))

    def sort_and_count_inversions_2(l1, l2):
        ''' Recebe duas listas, faz o merge das duas ordenadamente e retorna a
        lista resultante do merge. Durante este processo, conta as inversões,
        somente quando o dobro do valor invertido também é menor.
        Exemplo: [3,1,2] conta uma inversão pois 3 > 2*1, mas 3 < 2*2. '''
        nonlocal count
        i = 0
        j = 0
        size1 = len(l1)
        size2 = len(l2)
        newL = []
        for k in range(size1 + size2):
            if (i < size1) and (j < size2):
                if l1[i] > l2[j]:
                    for i_tmp in range(i, size1):
                        if l1[i_tmp] > (2 * l2[j]):
                            count += size1 - i_tmp
                            break
                    newL.append(l2[j])
                    j += 1
                else:
                    newL.append(l1[i])
                    i += 1
            elif (i == size1):
                newL.append(l2[j])
                j += 1
            else:
                newL.append(l1[i])
                i += 1
        return newL

    lista = mergeSort(lista)
    return count


# Helper code to print output
print(countInversion(lista))