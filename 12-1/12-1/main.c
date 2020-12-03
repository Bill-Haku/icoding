//
//  main.c
//  12-1
//
//  Created by HakuBill on 2020/9/29.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char ch[100];
    int top=0;
    while(1) {
        ch[top]=getchar();
        if(ch[top]=='\n')
            break;
        top++;
    }
    for(int i=top;i>=0;i--)
        printf("%c",ch[i]);
    printf("\n");
    return 0;
}
