#include<stdio.h>
void main()
{
    //Declare integer variables
    int iNum,iIterator,iFlag;
    iFlag=0;

    //Read Number
    printf(" Enter the Number :");
    scanf("%d",&iNum);

    for(iIterator=2; iIterator<iNum/2; iIterator++)
    {
        if(iNum%iIterator==0)
            iFlag++;
    }

    if(iFlag==0)
        printf(" %d is a Prime Number ",iNum);
    else
        printf(" %d is not a Prime Number ",iNum);

    return;
}
