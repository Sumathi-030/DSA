#include <stdio.h>
#include <stdlib.h>

void TOH(int n, char s, char d, char t)
{
    if(n==1){
        printf("\n Move %d disc from %c to %c",n,s,d);
    }
    else{
        TOH(n-1, s, t, d);
        printf("\n Move %d disc from %c to %c",n, s,d);
        TOH(n-1,t,d,s);
    }
}

int main()
{
    int n;
    printf("\n read number of disk: ");
    scanf("%d",&n);
    TOH(n,'S','D','T');
    int totalmoves = (1<<n)-1;
    printf("\n Total number of moves = %d\n",totalmoves);
    return 0;
}
