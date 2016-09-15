#include <iostream>
#include <cmath>

using namespace std;
static int g[26][26];
static int lbl[26];

//DFS
void dfs(int v,int b)
{
  lbl[v]=1;
  for(int i=0;i<b;i++){
     if(g[v][i]==1 && lbl[i]==0){
                     dfs(i,b);
     }
  }
}

 
//chama o dfs
void call_dfs(int v,int b){
  int i;
  for(i=0;i<b;i++){             
    lbl[i]=0;
  }
  dfs(v,b);          
}

int main() {
  int a,b,i,j,k,visited[26],done[26],cont,verif=0;
  char resp;
  char valor1,valor2;            	
   cont=0;
   cin>>a>>b;
   for(j=0;j<26;j++){
     for(k=0;k<26;k++){
       g[k][j]=0;
       visited[k]=0;
       done[k]=0;
     }
   }
   for(j=1;j<=b;j++){
     cin>>valor1>>valor2;
     g[valor1%97][valor2%97]=1;
     g[valor2%97][valor1%97]=1;                                             
   }
   //percorrer todos os nós, se foi visitado alguma vez, pulo pro
   //próximo. No inicio, nenhum foi visitado
   for(j=0;j<a;j++){                                                                           
      //se não foi visitado
     if(visited[j]==0){
        cont++;
        call_dfs(j,a);
        //verifico no dfs quais já foram visitados
        for( k=0;k<a;k++){
          if(lbl[k]==1)
            visited[k]=1;
        }                                                                            
     }
     for( k=0;k<a;k++){                                                                                           //vejo quem foi visitado nessa rodada. Formam mais um
       //componente conexo
        if(visited[k]!=done[k]){				
          resp = k+97;
          done[k]=1;
        }
    }                                                                                                                 
   }
  cout<<cont<<endl;                                                            
  return 0;
}
