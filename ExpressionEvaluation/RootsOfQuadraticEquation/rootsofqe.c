#include<stdio.h>
#include<math.h>
void main()
{
    //Declare integer variables
    int a,b,c,d;
    float r1,r2;
    printf(" Enter a, b, c numbers :");
    scanf("%d,%d,%d",&a,&b,&c);

    d = b*b-(4*a*c);

    if (d>0)
    {
        r1 = -b+sqrt(d)/(2*a);
        r2 = -b-sqrt(d)/(2*a);
        printf(" Root 1 : %f \n",r1);
        printf(" Root 2 : %f \n",r2);
        printf(" Roots are Real \n");
    }
    else if(d==0)
    {
        r1 = -b/2*a;
        r2 = -b/2*a;
        printf(" Root 1 : %f \n",r1);
        printf(" Root 2 : %f \n",r2);
        printf(" Roots are equal \n");

    }
    else{
        printf(" Roots are imaginary \n");
    }

    return;
}
