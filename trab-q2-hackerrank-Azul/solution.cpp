#include <bits/stdc++.h>
using namespace std;
int minDistance(int n, int dist[], bool sptSet[])
{
   int mini = 100001, min_index;

   for (int v = 0; v < n; v++){
     if (sptSet[v] == false && dist[v] <= mini)
         {mini = dist[v]; min_index = v;}}

   return min_index;
}

int printSolution(int dist[], int n)
{
   for (int i = 0; i < n; i++)
      {if(dist[i]==0)continue;
        if(dist[i]==100001){cout<<-1<<" "; continue;}
        cout<<dist[i]<<" ";}
}
void dijkstra(int V,int **graph, int src);
int main(){
    int i, j, t=0, m, s, v, n;
ifstream arq;
arq.open("Entrada.txt", ios::in);
arq>>n>>m>>s;
int **lista=new int*[n];
for(int i=0; i<n; i++)
    lista[i]=new int[n];
for(int l=0; l<n; l++)
    {for(int c=0; c<n; c++)
        lista[l][c]=0;}
for(int x=0; x<m; x++){
    arq>>i>>j>>v;
    if(lista[i-1][j-1]!=0)
        {
        if(v<lista[i-1][j-1])
            {lista[i-1][j-1]=v;
             lista[j-1][i-1]=v;
             continue;}
                }else{
                lista[i-1][j-1]=v;
                lista[j-1][i-1]=v;
                continue;}
}
dijkstra(n, lista, s-1);
return 0;}
void dijkstra(int V,int **graph, int src)
{
     int dist[V];
     bool sptSet[V];
     for (int i = 0; i < V; i++)
        {dist[i] =100001;
         sptSet[i] = false;}
     dist[src] = 0;
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(V, dist, sptSet);
       sptSet[u] = true;
       for (int v = 0; v < V; v++){
         if ((sptSet[v]==false) && (graph[u][v]!=0) && (dist[u]+graph[u][v] < dist[v]))
            dist[v] = dist[u] + graph[u][v];}
     }
     printSolution(dist, V);
}
