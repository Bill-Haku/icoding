//
//  main.c
//  5-10
//
//  Created by HakuBill on 2020/9/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    scanf("%d",&a);
    if(a>100||a<0) {
        printf("Error, grade must be between 0 and 100.\n");
        return 0;
    }
    a=a/10;
    switch (a) {
        case 9:
            printf("A\n");
            break;
        case 10:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        case 5:
            printf("F\n");
            break;
        case 4:
            printf("F\n");
            break;
        case 3:
            printf("F\n");
            break;
        case 2:
            printf("F\n");
            break;
        case 1:
            printf("F\n");
            break;
        case 0:
            printf("F\n");
            break;
    }
    return 0;
}
