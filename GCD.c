#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b)
{
    if(a==0)
    {
        return b;
    }
    return GCD(b%a, a);
}

int main()
{
    int a, b;
    printf("\n read values for a and b\n");
    scanf("%d%d", &a, &b);
    printf("\n GCD of %d and %d is:%d",a, b, GCD(a, b));
    return 0;
}

