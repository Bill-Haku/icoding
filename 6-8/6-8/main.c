//
//  main.c
//  6-8
//
//  Created by HakuBill on 2020/9/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int d,st,cnt;
    scanf("%d%d",&d,&st);
    printf("一二三四五六日\n");
    cnt=1;
    for(int i=1;i<=st-1;i++)
        printf("  ");
    for(int i=1;i<=7-st+1;i++) {
        cnt=i;
        printf("%d ",cnt);
    }
    printf("\n");   //first week
    cnt++;
    for(int j=1;j<7;j++) {
        if(cnt<=d) {
            if(cnt<10)
                printf("%d ",cnt);
            else
                printf("%d",cnt);
        }
        cnt++;
    }
    printf("\n");   //second week;
    for(int j=1;j<=7;j++) {
        if(cnt<=d)
            printf("%d",cnt);
        cnt++;
    }
    printf("\n");   //third week;
    for(int j=1;j<=7;j++) {
        if(cnt<=d)
            printf("%d",cnt);
        cnt++;
    }
    printf("\n");   //forth week;
    for(int j=1;j<=7;j++) {
        if(cnt<=d)
            printf("%d",cnt);
        cnt++;
    }
    printf("\n");   //fifth week;
    return 0;
}
