from collections import deque

list_adj = []
distancias = []
visitados = []
fila = deque([])
 
line = raw_input().strip().split(" ")
n = int(line[0])
m = int(line[1])

for i in range(n + 1):
    list_adj.append([])
    visitados.append(False)
    distancias.append(-1)
   
for i in range(m):
    line = raw_input().strip().split(" ")
    x = int(line[0])
    y = int(line[1])
    list_adj[x].append(y)
    list_adj[y].append(x)
   
line = raw_input().strip().split(" ")
noInicial = int(line[0])
noAlvo = int(line[1])

distancias[noInicial] = 0
fila.append(noInicial)
visitados[noInicial] = True
tamanho_fila = 1;

while(tamanho_fila > 0):
    no = fila.popleft()
    tamanho_fila -= 1
    
    for noVizinho in list_adj[no]:
        if (visitados[noVizinho] == False):
            visitados[noVizinho] = True
            fila.append(noVizinho)
            tamanho_fila += 1
            distancias[noVizinho] = distancias[no] + 1
        
        if (noVizinho == noAlvo):
            print distancias[noAlvo] 
            exit(0)

print "-1"


        
        
        
        
        
        
        
        



