//
//  main.c
//  2-8
//
//  Created by HakuBill on 2020/9/17.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float num,rate,pay;
    scanf("%f%f%f",&num,&rate,&pay);
    rate=rate/12/100;
    for (int i=1;i<=3;i++) {
        num=num*(1+rate);
        num=num-pay;
        printf("%.2f\n",num);
    }
    
    return 0;
}
