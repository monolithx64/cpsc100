#include<stdio.h>
int main ()
{
    int num;

    printf("Non-prime Factorizer!\nEnter a number: ");
    scanf(" %d", &num);

    for (int x = 1; x <= num; x++) {
        if ((num % x) == 0) {
            printf("%d is a factor!\n", x);
        }
    }

    printf("\n");
    return 0;
}