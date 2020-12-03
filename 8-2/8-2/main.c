//
//  main.c
//  8-2
//
//  Created by HakuBill on 2020/9/29.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, const char * argv[]) {
    int a[100];
    char ch[100];
    int b[100];
    int m=1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
//    int n,m=0,nn;
//    scanf("%d",&n);
//    nn=n;
//    do {
//        m++;
//        n/=10;
//    }while(n>0);
//    n=nn;
//    for(int i=1;i<=m;i++) {
//        a[i]=n%10;
//        n/=10;
//    }
    while(1){
        ch[m]=getchar();
        m++;
        if(ch[m]==EOF)
            break;
    }
    for(int i=1;i<=m;i++)
        a[i]=ch[i]-48;
    for(int i=1;i<m;i++)
        b[a[i]]++;
    printf("Digit:0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences:");
    for(int i=0;i<=9;i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}
