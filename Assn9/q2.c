#include<stdio.h>

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n*factorial(n-1);
}

int nck(int n, int k) {
    int facn = factorial(n);
    int fack = factorial(k);
    int nk = (n - k);
    int facnk = factorial(nk);

    // printf("facn=%d\nfack=%d\nnk=%d\nfacnk=%d\n", facn, fack, nk, facnk);

    int nck = (facn/(fack*facnk));

    return (nck);
}

int main()
{
    int n, k;

    printf("Enter n: ");
    scanf(" %d", &n);
    printf("\nEnter k: ");
    scanf(" %d", &k);
    printf("\nnck = %d\n",  nck(n, k));
}