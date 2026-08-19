#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isprime(int n)
{
    int x = 2;

    while(x < n) {
        // printf("x=%d", x);
        if((n % x) == 0) {
            return false;
        }
    x++;
    }
return true;
}

int main()
{
    int n;
    
    printf("Enter number:\n");
    scanf(" %d", &n);

    if (isprime(n)) {
        printf("%d is prime.", n);
    }   else {
        printf("%d is not prime.", n);
    }
    printf("\n");

    return 0;
}
