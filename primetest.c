#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TRUE 0
#define FALSE 1

/*a és b legnagyobb közös osztójának megkeresése.*/
int lnko(int a, int b)
{
    int i=0;
    int elozo, c;
    while(1)
    {
        c = a % b;
        a = b;
        b = c;
        if(c == 0)
        {
            break;
        }
        else
        {
            elozo = c;
        }
    }
    return elozo;
}

/*Generálunk egy random számot a felhasználó által adott modulus
és RAND_MAX között, amit a Miller-Rabin teszttel ellenőrzünk majd.*/
int generateRandom(int modulus)
{
    srand(time(NULL));
    rand();
    int randomNumber = (rand()%(RAND_MAX - modulus+1) + modulus);
    return randomNumber;
}

/*Random 'a' szám generálása 2 és n-2 között a Miller-Rabin teszthez.*/
int randomForPrimalityTest(int n)
{
    int lower = 2;
    int upper = n - 2;
    srand(time(NULL));
    rand();
    int a = (rand()%(upper - lower + 1) + lower);
    return a;
}

/*Moduláris hatványozás a Miller-Rabin teszthez.*/
int modularExp(int x, unsigned int y, int p)
{
    int eredmeny = 1;
    x = x % p;
    while(y > 0)
    {
        if(y & 1)
        {
            eredmeny = (eredmeny * x) % p;
        }
        y = y>>1;
        x = (x * x) % p;
    }
    return eredmeny;
}

/*Miller-Rabin prímteszt.*/
int millerRabin(int n, int d)
{
    int a = randomForPrimalityTest(n);
    int x = modularExp(a, d, n);
    if(x == 1 || x == n-1)
    {
        return TRUE;
    }
    while(d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
        if(x == 1)
        {
            return FALSE;
        }
        if(x == n-1)
        {
            return TRUE;
        }
    }
    return TRUE;
}
int prime(int n, int k)
{
    if(n <= 1 || n == 4)
    {
        return FALSE;
    }
    if(n <= 3)
    {
        return TRUE;
    }
    int d = n - 1;
    while(d % 2 == 0)
    {
        d /= 2;
    }
    for(int i = 0; i < k; i++)
    {
        if(!millerRabin(d, n))
        {
            return FALSE;
        }
    }
    return TRUE;
}

int main()
{
    int k, modulus;
    printf("A kulcs alsó határa: ");
    scanf("%d", &modulus);
    printf("\nHányszor tesztelje a rendszer a kapott számot? ");
    scanf("%d", &k);
    int prim;
    while(prim != 0)
    {
        prim = prime(generateRandom(modulus),k);
    }
    printf("\nGenerált szám: %d", generateRandom(modulus));
    return EXIT_SUCCESS;
}