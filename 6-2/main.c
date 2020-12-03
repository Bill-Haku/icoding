//
//  main.c
//  6-2
//
//  Created by HakuBill on 2020/9/17.
//

#include <stdio.h>

int gcd(int m,int n) {
    for(int i=1;i<=100000000;i++) {
        if(n==0)
            return m;
        else {
            int c;
            c=m%n;
            m=n;
            n=c;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",gcd(a,b));
    return 0;
}
