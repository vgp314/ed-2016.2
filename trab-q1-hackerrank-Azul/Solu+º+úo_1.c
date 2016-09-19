#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int pos(int lis[],int l,int r,int key)
{
    int m;

    while( r - l > 1 )
    {
        m = l + (r - l)/2;
        if(lis[m] >= key)
            r= m; else l=m; // ternary expression returns an l-value
    }
    return r;

}

int LIS(int a[],int n)
{   int i;
    int *lis;
    lis=malloc(n*sizeof(int));
    lis[0]=a[0];
    int len=1;
    for(i=1;i<n;i++)
    {
            if(a[i]<lis[0]) lis[0]=a[i];
            else if(a[i]>lis[len-1]) lis[len++]=a[i];
            else lis[pos(lis,-1,len-1,a[i])]=a[i];

    }
    free(lis);
    return len;
}

int main(){
    int N, i, *b;
    FILE *arq;
    arq=fopen("Entrada.txt", "r");
        fscanf(arq, "%d", &N);
    //int b[1000000];
    b=malloc(sizeof(int)*N);
  // sample array.
    for(i=0; i<N; i++){
        fscanf(arq, "%d", &b[i]);
    }
    fclose(arq);
  // should return 5
  printf("%d\n", LIS( b, N ) );
  free(b);

}
