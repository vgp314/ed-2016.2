#include <iostream>
using namespace std;
 
int v[51];
int p[51];
int dp[51][101];
 
 
int main() {
    int n,i,j,k,w,r;
    //leitura da entrada
    cin>>n;
    for(j=1;j<=n;j++){
        cin>>v[j]>>p[j];
    }
    cin>>w>>r;
    //inicializando a matriz do problema da mochila
    for(k=0;k<=n;k++){
        dp[k][0]=0;
    }
    //inicializando a matriz do problema da mochila
    for(j=0;j<=w;j++){
        dp[0][j]=0;
    }
    //percorrendo a matriz aplicando a relação de recorrência
    for(j=1;j<=w;j++){
        for(k=1;k<=n;k++){
            if(p[k]>j)
            dp[k][j]=dp[k-1][j];
            else{
                dp[k][j]= max(dp[k-1][j-p[k]]+v[k],dp[k-1][j]);
            }
        }
    }
    if(dp[n][w]>=r)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;
    return 0;
}