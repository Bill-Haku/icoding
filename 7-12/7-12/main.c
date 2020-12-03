//
//  main.c
//  7-12
//
//  Created by HakuBill on 2020/9/28.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char ch;
    float ans, a;
    scanf("%f",&ans);
    while(scanf("%c",&ch)!=EOF) {
        scanf("%f",&a);
        if(ch=='+')
            ans+=a;
        if(ch=='-')
            ans-=a;
        if(ch=='*')
            ans*=a;
        if(ch=='/')
            ans/=a;
    }
    printf("Value of expression:%g\n",ans);
    return 0;
}
