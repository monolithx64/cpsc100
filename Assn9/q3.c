#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

bool luhn(int *ccnum)    {
    int i = 0;
    int sum = 0;
    
    while (i < 16) {
        if (i%2 == 0) {
            int sub = (2 * ccnum[i]);
            if (sub >= 10)  {
                sub = 1 + (sub%10);
                sum = (sum + sub);
            }   else    {
                sum = (sum + 2 * ccnum[i]);
            }
        }   else {
            sum = (sum + ccnum[i]);
        }
        i++;
    }

    // printf("%d", sum);
    if ((sum % 10) == 0)    {
        return true;
    }   else {
        return false;
    }

}

int main (int argc, char * argv[])  {
    if(argc != 2) {
        printf("Invalid number of arguments\n");
        return 0;
    }   else if (strlen(argv[1]) != 16) {
        printf("Invalid number of digits in CC number\n");
        return 0;
    }

    int i = strlen(argv[1]);
    // printf("%d", i);
    int ccnum[16];

    ccnum[i] = (int) (argv[1][i] - '0');
    i--;
    while (i >= 0) {
        // printf("%c", argv[1][i]);
        if (isdigit(argv[1][i]) == 0) {
            printf("CC Number contains non-numerical character.\n");
            return 0;
        }
        ccnum[i] = (int) (argv[1][i] - '0');
        i--;
    }

    if (luhn(ccnum)) {
        printf("Valid CC Number");
    }   else {
        printf("Invalid CC Number");
    }

    printf("\n");
    return 0;
}