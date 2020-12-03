//  main.c
//  3-6
//  Created by HakuBill on 2020/9/17.

/* addfrac.c
 * Adds two fractions
 */

#include <stdio.h>
int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    scanf("%d/%d+%d/%d", &num1, &denom1,&num2, &denom2);
    result_denom=denom1*denom2;
//    num1=num1*denom2;
//    num2=num2*denom1;
    result_num = num1*denom2 + num2*denom1;
    result_denom = denom1*denom2;
    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}
