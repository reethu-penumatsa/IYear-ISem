#include<stdio.h>

int main()
{
    int a[10];
    int n;

    printf("Enter size of the array : ");
    scanf("%d",&n);

    printf("Enter elements in array :");
    for(int i=0; i<n; i++)
    {
        scanf("%d",a+i);
    }

    printf("elements of the array are:");
    for(int i=0; i<n; i++)
    {
        printf("%5d",*(a+i));
    }


    return 0;
}
