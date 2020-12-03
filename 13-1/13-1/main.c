//
//  main.c
//  13-1
//
//  Created by HakuBill on 2020/9/29.
//

#include <stdio.h>
#include <string.h>

struct words {
    char str[30];
    int n;  //n is the length of the string
}w[100];

void swap(int a, int b) {
    struct words c;
    c=w[a];
    w[a]=w[b];
    w[b]=c;
}

void sort(int l) {
    for(int i=1;i<=l-1;i++)
        for(int j=i+1;j<=l;j++) {
            if(strcmp(w[i].str,w[j].str)<0)
                swap(i,j);
        }
}

int main(int argc, const char * argv[]) {
//    int ii=1,j=1;
//    while(1) {
//        w[ii].str[j]=getchar();
//        if(w[ii].str[j]=='\n') {
//            w[ii].n=j-1;
//            ii++;
//            j=0;
//        }
//        if(w[ii-1].n==4)
//            break;
//        j++;
//    }
//    sort(ii-1);
//    for(int i=1;i<=w[1].n;i++)
//        printf("%c",w[1].str[i]);
//    printf("\n");
//    for(int i=1;i<=w[ii-2].n;i++)
//        printf("%c",w[ii-2].str[i]);
//    printf("\n");
    char sh[30];
    char lo[30];
    char in[30];
    int flag=1;
    while(1) {
        gets(in);
        if(flag) {
            for(int i=0;i<=30;i++)
                sh[i]=in[i];
            for(int i=0;i<=30;i++)
                lo[i]=in[i];
            flag=0;
        }
        if(strcmp(in,sh)<0)
            for(int i=0;i<=30;i++)
                sh[i]=in[i];
        if(strcmp(in,lo)>0)
            for(int i=0;i<=30;i++)
                lo[i]=in[i];
        if(strlen(in)==4)
            break;
    }
    for(int i=0;i<=strlen(sh);i++)
        printf("%c",sh[i]);
    printf("\n");
    for(int i=0;i<=strlen(lo);i++)
        printf("%c",lo[i]);
    printf("\n");
    return 0;
}
