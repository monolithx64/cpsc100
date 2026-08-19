#include<stdio.h>
int main ()
{
    int num;
    int sum = 0;

    printf("Enter a number: ");
    scanf(" %d", &num);

    while (num > 0) {
        sum = (sum + (num % 10));             //add last digit to sum
        num = (num / 10);                     //move 'decimal' over
    }

    printf("Sum = %d\n", sum);

    return 0;
}