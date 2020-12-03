//
//  main.c
//  3-1
//
//  Created by HakuBill on 2020/9/17.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char a[15];
    for(int i=1;i<=10;i++) {
        scanf("%c",&a[i]);
    }
    printf("%c%c%c%c",a[7],a[8],a[9],a[10]);
    printf("%c%c%c%c\n",a[1],a[2],a[4],a[5]);
    return 0;
}
