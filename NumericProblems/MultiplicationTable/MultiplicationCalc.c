#include<stdio.h>
void main()
{
    //Declare variable for multiplier and loop iterator
    int iMult,iIterator=1;

    //Read Multiplier as input
    printf(" Enter the Multiplier :");
    scanf("%d",&iMult);

    //Loop for 5 times
    while(iIterator<=5)
    {
        //Display current iterator details by multiplying iterator value with multiplier
        printf(" %d*%d = %d \n",iMult,iIterator,iMult*iIterator);

        //Increment iterator
        iIterator=iIterator+1;
    }
    return;
}
