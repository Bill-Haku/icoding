//
//  main.c
//  5-2
//
//  Created by HakuBill on 2020/9/17.
//

#include <stdio.h>

int main(int argc, const char* argv[])
{
    int hr, min;
    scanf("%d:%d", &hr, &min);
    if (hr > 12) {
        hr = hr - 12;
        printf("%d:%.2d PM\n",hr,min);
//        if (min < 10)
//            printf("%d:0%d PM\n", hr, min);
//        else
//            printf("%d:%d PM\n", hr, min);
    } else if (hr == 0) {
        printf("12:%.2d AM\n", min);
//        if (min < 10)
//            printf("%d:0%d AM\n", hr, min);
//        else
//            printf("12:%d AM\n", hr, min);
    } else if (hr == 12) {
        hr = hr;
         printf("%d:%.2d PM\n", hr, min);
//        if (min < 10)
//            printf("%d:0%d AM", hr, min);
//        else
//            printf("%d:%d PM\n", hr, min);
    } else {
        printf("%d:%.2d AM\n", hr, min);
//        if (min < 10)
//            printf("%d:0%d AM", hr, min);
//        else
//            printf("%d:%d AM\n", hr, min);
    }
    return 0;
}
