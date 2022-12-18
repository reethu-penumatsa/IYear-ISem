#include<stdio.h>
#include<math.h>
void main()
{
    //Declare integer variables
    int iNum,iRem,a[10],i;
    printf(" Enter number :");
    scanf("%d",&iNum);

    if(iNum>0&&iNum<255)
    {
        i=0;
        while(iNum>=1)
        {
            iRem = iNum%2;
            iNum = iNum/2;
            a[i]=iRem;
            i=i+1;
        }
        for(int j=i-1;j>=0;j--)
            printf(" %d",a[j]);

        printf("\n");
    }


    else
        printf("enter between 0-255");

    return;
}
