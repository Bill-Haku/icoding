//
//  main.c
//  8-15
//
//  Created by HakuBill on 2020/9/29.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int mo;
    char a[1000];
    char b[1000];
//    char *string = a;
    int m;
    gets(a);
    m=strlen(a);
    for(int i=0;i<=m;i++)
        b[i]=a[i];
//    while(1) {
//        scanf("%c",&a[m]);
//        gets(a);
//        b[m]=a[m];
//        if(a[m]==EOF)
//            break;
//        m++;
//    }
    scanf("%d",&mo);
//    if(a[m-1]>=48&&a[m-1]<=57) {
//        mo=(a[m-1]-48)*10+(a[m]-48);
//        m-=2;
//    }
//    else {
//        mo=a[m]-48;
//        m--;
//    }
    for(int i=0;i<=m;i++) {
        if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))
            if(a[i]>=65&&a[i]<=90&&a[i]+mo>=91)
                b[i]=a[i]+mo-26;
            if(a[i]>=65&&a[i]<=90&&a[i]+mo<91)
                b[i]=a[i]+mo;
            if(a[i]>=97&&a[i]<=122&&a[i]+mo>=123)
                b[i]=a[i]+mo-26;
            if(a[i]>=97&&a[i]<=122&&a[i]+mo<123)
                b[i]=a[i]+mo;
    }
    for(int i=0;i<=m;i++)
        printf("%c",b[i]);
    printf("\n");
    return 0;
}
