//
//  2.cpp
//  test
//
//  Created by HakuBill on 2020/9/16.
//  Copyright © 2020 HakuBill. All rights reserved.
//

//#include "2-4.hpp"
#include <stdio.h>
//#include <stdlib.h>

int main()
{
    float a;
    printf("Enter an amount ");
    scanf("%f", &a);
    a = a * 1.05;
    printf("with tax added ");
    printf("%.2f\n", a);
    return 0;
}

