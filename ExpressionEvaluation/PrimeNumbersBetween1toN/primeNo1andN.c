#include<stdio.h>
void main()
{
    //Declare integer variable
    int iNum,iFlag=0,i,j;

    printf(" Enter Number :");
    scanf("%d",&iNum);

    for( i=1;i<=iNum;i++)
    {
        iFlag=0;
            for( j=2;j<=i/2;j++)
            {
                if(i%j==0)
                    iFlag++;
            }
        if(iFlag==0)
            printf("%d is prime number\n",i);
    }

    return;
}
