//
//  main.c
//  2-7
//
//  Created by HakuBill on 2020/9/17.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d",&num);
    int a = 0,b = 0,c = 0,d;
    int tmp=0;
    for(int i=0;tmp<=num;i++) {
        tmp=i*20;
        if(tmp>=num) {
            a=i-1;
            num=num-tmp+20;
        }
    }
    tmp=0;
    for(int i=0;tmp<=num;i++) {
        tmp=i*10;
        if(tmp>=num) {
            b=i-1;
            num=num-tmp+10;
        }
    }
    tmp=0;
    for(int i=0;tmp<=num;i++) {
        tmp=i*5;
        if(tmp>=num) {
            c=i-193;
            num=num-tmp+5;
        }
    }
    tmp=0;
    d=num;
    printf("%d\n%d\n%d\n%d\n",a,b,c,d);
    return 0;
}
