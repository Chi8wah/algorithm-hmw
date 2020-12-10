#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[1024][1024];  // 比赛日表格
int b[1024][1024];  // 比赛对手表格
int n=1;

void fillSchedule(int k)
{
    int n1=pow(2,k)-1;
    if(n1+1>n) return;

//  横向翻转
    for(int i=0;i<=n1;i++){
        for(int j=i;j<=n1/2;j++){
            a[i][n1-j]=n1-a[i][j];
        }
    }

//  纵向翻转
    for(int i=0;i<=n1/2;i++){
        for(int j=i;j<=n1;j++){
            a[n1-j][n1-i]=a[i][j];
        }
    }

    fillSchedule(k+1);
}

int main()
{
    int n1=0;
    printf("k=");
    scanf("%d",&n1);
    n=pow(2,n1);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
            b[i][j]=0;
        }

    a[0][1]=1; // 确定初始表格
    fillSchedule(1);  // 从左上角开始翻转表格

//  补齐表格
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            // printf("i=%d,j=%d,a[%d][%d]=%d\n",i,j,i,j,a[i][j]);
            a[j][i]=a[i][j];
        }
    }

//  根据比赛日表格排出比赛对手表格
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // printf("%d ", a[i][j]);
            if(i!=j){
                b[i][a[i][j]]=j+1;
            }
        }
        // printf("\n");
    }

//  输出部分
    printf("   ");
    for(int i=1;i<n;i++) printf("%5d",i);
    printf("\n");
    printf("   ");
    for(int i=1;i<n;i++) printf("-----",i);
    printf("\n");

    for(int i=0;i<n;i++){
        printf("%2d|",i+1);
        for(int j=1;j<n;j++)
            printf("%5d", b[i][j]);
        printf("\n");
    }
}
