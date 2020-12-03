//
//  main.c
//  6-6
//
//  Created by HakuBill on 2020/9/17.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int n,ans=0;
    scanf("%d",&n);
    for(int i=2;i<=sqrt(n);i+=2) {
        ans=i*i;
        if(ans<=n)
            printf("%d\n",ans);
    }
    return 0;
}
