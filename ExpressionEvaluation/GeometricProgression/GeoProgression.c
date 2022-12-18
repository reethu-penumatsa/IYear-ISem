#include<stdio.h>
#include<math.h>
void main()
{
    //Declare integer variables
    int n,x,i;
    float sum=1;
    printf(" Enter no of times the loop should iterate :");
    scanf("%d",&n);
    printf(" Enter x value :");
    scanf("%d",&x);


    printf("%f ",sum);
    for(i=1;i<n;i=i+1)
    {
        sum = sum + pow(x,i);

        printf("+ %f ",pow(x,i));
    }
    printf(" = %f",sum);

    return;
}
