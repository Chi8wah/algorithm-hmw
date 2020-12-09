#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

short a[1024][1024];

int checkblock(int lx,int ly,int rx,int ry,int sx,int sy)
{
    if((sx>=lx)&&(sx<=(rx+lx)/2)&&(sy>=ly)&&(sy<=(ly+ry)/2)) return 1;
    if((sx>=lx)&&(sx<=(rx+lx)/2)&&(sy>=(ly+ry)/2+1)&&(sy<=ry)) return 2;
    if((sx>=(rx+lx)/2+1)&&(sx<=rx)&&(sy>=ly)&&(sy<=(ly+ry)/2)) return 3;
    if((sx>=(rx+lx)/2+1)&&(sx<=rx)&&(sy>=(ly+ry)/2+1)&&(sy<=ry)) return 4;
}

void printA(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
}

void fill(int lx,int ly,int rx,int ry,int sx,int sy)
{

    if((rx-lx<1)&&(ry-ly<1)){
        return;
    }
    a[sx][sy]=1;
    int k=checkblock(lx,ly,rx,ry,sx,sy);
    if(k==1){
        fill(lx,ly,(rx+lx)/2,(ly+ry)/2,sx,sy);
    } else{
        fill(lx,ly,(rx+lx)/2,(ly+ry)/2,(rx+lx)/2,(ly+ry)/2);
    }
    if(k==2){
        fill(lx,(ly+ry)/2+1,(rx+lx)/2,ry,sx,sy);
    } else{
        fill(lx,(ly+ry)/2+1,(rx+lx)/2,ry,(rx+lx)/2,(ly+ry)/2+1);
    }if(k==3){
        fill((rx+lx)/2+1,ly,rx,(ly+ry)/2,sx,sy);
    } else{
        fill((rx+lx)/2+1,ly,rx,(ly+ry)/2,(rx+lx)/2+1,(ly+ry)/2);
    }if(k==4){
        fill((rx+lx)/2+1,(ly+ry)/2+1,rx,ry,sx,sy);
    } else{
        fill((rx+lx)/2+1,(ly+ry)/2+1,rx,ry,(rx+lx)/2+1,(ly+ry)/2+1);
    }
    return;
}

int main()
{
    int n1,x,y=0;
    int n=1;
    printf("k=");
    scanf("%d",&n1);
    for(int i=1;i<=n1;i++)
        n=n*2;
    //int a[n][n];
    printf("\nspecial block:\nx=");
    scanf("%d",&x);
    printf("y=");
    scanf("%d",&y);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            a[i][j]=0;
    }
    fill(0,0,n-1,n-1,x-1,y-1);
    a[x-1][y-1]=5;
    printA(n);
}
