#include<stdio.h>
int gcd(int,int);
int main()
{
    int large,small,result;
    printf("Enter the smallest and largest numbers:");
    scanf("%d %d", &small, &large);
    result=gcd(large,small);
    printf("Gcd of given two numbers is %d",result);
    return 0;
}
int gcd(int large,int small)
{
    if(large<small)
    {
        return gcd(small,large);
    }
    if(small==0)
    {
        return large;
    }
    return gcd(small,large%small);
}

