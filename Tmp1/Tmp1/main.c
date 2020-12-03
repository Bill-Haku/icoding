#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s;
    printf("Enter a wind speed:");
    scanf("%d", &s);
    if(s<1)
        printf("Calm");
    else if(s>1&&s<3)
        printf("Light air");
    else if(s>4&&s<27)
        printf("Breeze");
    else if(s>28&&s<47)
        printf("Gale");
    else if(s>48&&s<63)
        printf("Storm");
    else
        printf("Hurricane");

    return 0;
}
