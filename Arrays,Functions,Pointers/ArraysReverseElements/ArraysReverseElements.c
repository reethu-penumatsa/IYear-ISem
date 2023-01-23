#include<stdio.h>

int main()
{
    int a[10];
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
    printf("elements of array in reverse order:");
    for(int i=0; i<n; i++)
    {
        ptr--;
        printf("%5d",*(ptr));
    }


    return 0;
}
