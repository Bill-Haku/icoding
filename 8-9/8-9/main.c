//
//  main.c
//  8-9
//
//  Created by HakuBill on 2020/9/29.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char ch[15][15];
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
            ch[i][j]='.';
    int x=1,y=1;
    int rd,cx,cy;
    srand(time(NULL));
    for(int i=0;i<=25;i++) {
        ch[x][y]='A'+i;
        rd=rand()%4;
        cx=x;
        cy=y;
        if(rd==0)
            if(ch[x][y-1]=='.'&&(y-1)>=1)
                y=y-1;
        else if(rd==1)
            if(ch[x][y+1]=='.'&&(y+1)<=10)
                y=y+1;
        else if(rd==2)
            if(ch[x-1][y]=='.'&&(x-1)>=1)
                x=x-1;
        else if(rd==3);
            if(ch[x+1][y]=='.'&&(x+1)<=10)
                x=x+1;
        if(x==cx&&y==cy)
            break;
    }
    for(int i=1;i<=10;i++) {
        for(int j=1;j<=10;j++)
            printf("%c",ch[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}
