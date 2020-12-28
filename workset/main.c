#include <stdio.h>
#include <stdlib.h>

int a[100]={0};
int b[100]={0};
int c[100]={0}; // index

switchQue(int p1,int p2){
    int temp=0;
    temp=a[p1];    a[p1]=a[p2];    a[p2]=temp;
    temp=b[p1];    b[p1]=b[p2];    b[p2]=temp;
    temp=c[p1];    c[p1]=c[p2];    c[p2]=temp;
}

int seperate(int n){
    int p1=0; // from head
    int p2=n-1; // from end
    while(p1<p2){
        while((p1<n)&&(a[p1]<b[p1])) p1++;
        while((p2>=0)&&(a[p2]>=b[p2])) p2--;
        if(p1<p2) switchQue(p1,p2);
    }
    return p1-1;
}

j1sort(int n1){
    n1++;
    for(int i=0;i<n1-1;i++){
        for(int j=i+1;j<n1;j++){
            if(a[i]>a[j]) switchQue(i,j);
        }
    }
}

j2sort(int n2,int n){
    for(int i=n2;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]) switchQue(i,j);
        }
    }
}

int main()
{
    int n=0;
    int n1=0;
    int n2=0;

    printf("n=");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("a[%d]=",i+1);
        scanf("%d",&a[i]);
        printf("b[%d]=",i+1);
        scanf("%d",&b[i]);
        c[i]=i+1;
    }

    n1=seperate(n);
    n2=n1+1;

    j1sort(n1);
    j2sort(n2,n);

    printf("index = ");
    for(int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
    printf("\n");
    return 0;
}
