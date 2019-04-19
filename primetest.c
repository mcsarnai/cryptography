#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TRUE 0
#define FALSE 1

int generateRandom(int modulus)
{
    srand(time(NULL));
    rand();
    int randomNumber = (rand()%(modulus+1));
    return randomNumber;
}

int randomForPrimalityTest(int n)
{
    int lower = 2;
    int upper = n - 2;
    srand(time(NULL));
    rand();
    int a = (rand()%(upper - lower + 1) + lower);
    return a;
}

int modularExp()
{

}

int millerRabin(int n, int k)
{
    int i;
    int a = randomForPrimalityTest(n);
    for(i = 0; i < k; i++)
    {
        if(n%2==0)
        {
            return FALSE;
        }
        else
        {
            
        }
        
    }
}

int main()
{
    int modulus;
    printf("Modulus: ");
    scanf("%d", &modulus);

    printf("Random: %d", generateRandom(modulus));
}