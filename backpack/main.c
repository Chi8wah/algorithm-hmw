#include <stdio.h>
#include <stdlib.h>
int w[101]={0};
int v[101]={0};
int f[101][101];
int a[101]={0};

void getpack(int n,int we,int k){
    if(f[n][we]==0) return;
    if(f[n-1][we]==f[n][we]){
        getpack(n-1,we,k);
        return;
    }else{
        a[k]=n;
        getpack(n-1,we-w[n],k+1);
    }
}

int max(int a,int b){
    if (a>b) {
        return a;
    }else{
        return b;
    }
}

int MFKnapsack(int i,int j){ // 这个算法有瑕疵, 只能求全部物品之和, 无法求部分物品之和
    if(f[i][j]>0) return f[i][j]; // 关键
    int value=0;
    if (f[i][j]<0) {
        if (j<w[i]) {
            value=MFKnapsack(i-1,j);
        }
        else{
            value=max(MFKnapsack(i-1,j),(v[i]+MFKnapsack(i-1,j-w[i])));
        }
    }
    f[i][j]=value;
    return f[i][j];
}

int main()
{
    int n=0;
    printf("n=");
    scanf("%d",&n);
    int weight=0;
    printf("weight=");
    scanf("%d",&weight);
    for(int i=1;i<=n;i++){
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
        printf("w[%d]=",i);;
        scanf("%d",&w[i]);
    }

    for(int i=0;i<=weight;i++){
        f[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        f[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=weight;j++){
            f[i][j]=-1;
        }
    }

    f[n][weight]=MFKnapsack(n,weight);
    getpack(n,weight,0);

    printf("MaxValue=%d\npack=",f[n][weight]);
    int k=0;
    while(a[k]!=0){
        printf("%d, ",a[k]);
        k++;
    }
    printf("\n");
    return 0;
}
