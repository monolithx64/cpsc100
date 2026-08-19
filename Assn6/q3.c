#include<stdio.h>
int main ()
{
    int primes[1000];

    for(int i = 0; i<1000; i++)
        primes[i] = 0;

    primes[0] = 1;
    primes[1] = 1;

    for (int x = 2; x <= 1000; x++) {
//        printf("hi");
        if (primes[x] != 1) {
            for (int y = 2; x * y <= 1000; y++) {
                primes[(x * y)] = 1;
            }
        }
    }
    
    printf("Primes less than 1000:\n");
    for (int x = 0; x <= 999; x++) {
        if (primes[x] != 1) {
            printf("%d, ", x);
        }
    }

    printf("\n");
    return 0;
}