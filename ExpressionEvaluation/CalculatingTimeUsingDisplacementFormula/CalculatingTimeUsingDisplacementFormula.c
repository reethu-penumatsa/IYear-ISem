#include<stdio.h>
#include<math.h>
void main()
{
    //Declare variables
    int iVel=0,iDis=3,i;
    float iTime,iAcc=9.8;

    for(i=1; i<=10; i++,iDis=iDis+3)
    {
        iTime=sqrt((2*iDis-2*iVel*iTime)/iAcc);
        printf("Time taken is %f at floor:%d\n",iTime,i);
    }

    return;
}

