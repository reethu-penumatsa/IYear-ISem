#include<stdio.h>

int factorial(int a);

int main()
{
    int n,fact=1;

    printf("Enter Number : ");
    scanf("%d",&n);

    fact = factorial(n);
    printf("Factorial value of %d is %d ",n,fact);

    return 0;
}

int factorial(int a)
{
    if (a != 0)
        return a * factorial(a-1);
    else
        return 1;
}
