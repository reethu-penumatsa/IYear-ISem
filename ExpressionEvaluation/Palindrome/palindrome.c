#include<stdio.h>
void main()
{
    //Declare integer variables
    int iNum,iNum2,iRev=0,iRem=0,iSum=0;

    //Read Number
    printf(" Enter the Number : ");
    scanf("%d",&iNum);
    iNum2=iNum;

    while(iNum>0)
    {
        iRem=iNum%10;
        iRev=iRev*10+iRem;
        iSum=iSum+iRem;
        iNum=iNum/10;
    }

    printf(" Sum is : %d \n",iSum);

    if (iNum2==iRev)
        printf(" It is palindrome");
    else
        printf(" It is not a palindrome");

    return;
}
