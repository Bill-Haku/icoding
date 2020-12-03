//
//  main.c
//  5-4
//
//  Created by HakuBill on 2020/9/17.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    float a;
    scanf("%f",&a);
    if(a<1)
        printf("Clam\n");
    else if(a>=1&&a<4)
        printf("Light Air\n");
    else if(a>=4&&a<28)
        printf("Breeze\n");
    else if(a>=28&&a<48)
        printf("Gale\n");
    else if(a>=48&&a<=63)
        printf("Storm\n");
    else if(a>63)
        printf("Hurricane\n");
    return 0;
}
