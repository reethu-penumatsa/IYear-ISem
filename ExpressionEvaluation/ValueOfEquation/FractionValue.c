#include<stdio.h>
#include<math.h>
void main()
{
    //Declare integer variables
    int i,j;
    float x,sum=1;
    printf(" Enter x in fractions :");
    scanf("%f",&x);

    printf("%f\n",sum);
    for(i=1,j=2;i<=3;i=i+1,j=j+2)
    {
        if(i%2==0)
            sum = sum + pow(x,i)/j;
        else
            sum = sum - pow(x,i)/j;

        printf("%f\n",sum);
    }
    printf("%f",sum);

    return;
}
