#include<stdio.h>

int main()
{
    int a[10],min,max;
    float sum=0;
    int n,i;
    float avg;

    printf("Enter size of the array : ");
    scanf("%d",&n);

    printf("Enter elements in array : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    min=a[0];
    max=a[0];
    for(int i=0; i<n; i++)
    {
        if(min>a[i])
            min=a[i];

        if(max<a[i])
            max=a[i];

        sum=sum+a[i];
    }


    printf("Sum of the array elements = %f \n",sum);
    printf("minimum of array is : %d\n",min);
    printf("maximum of array is : %d\n",max);
    printf("average value is : %f\n",sum/n);


    return 0;
}
