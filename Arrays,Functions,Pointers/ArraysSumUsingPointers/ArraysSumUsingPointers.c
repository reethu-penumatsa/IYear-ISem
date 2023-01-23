#include<stdio.h>

int main()
{
    int a[10],sum=0;
    int *ptr;
    int n;

    printf("Enter size of the array : ");
    scanf("%d",&n);

    ptr=&a[0];

    printf("Enter elements in array :");
    for(int i=0; i<n; i++)
    {
        scanf("%d",ptr);
        ptr++;
    }

    ptr=&a[0];
    for(int i=0; i<n; i++)
    {
        sum = sum + *ptr;
        ptr++;
    }
    printf("Sum is : %d\n",sum);

    return 0;
}
