#include<stdio.h>
void main()
{
    //Declare 3 integer variable
    int iFirstNum,iSecondNum,iThirdNum;

    //Read first number
    printf("Enter the 1st Number :");
    scanf("%d",&iFirstNum);
    //Read second number
    printf("Enter the 2nd Number :");
    scanf("%d",&iSecondNum);
    //Read third number
    printf("Enter the 3rd Number :");
    scanf("%d",&iThirdNum);

    //Compare First number with Second and Third numbers to find the greatest number
    if( (iFirstNum>iSecondNum) && (iFirstNum>iThirdNum) )
    {
        printf("%d is the greatest number \n",iFirstNum);

        //Compare second and third number to find the smallest
        if(iSecondNum<iThirdNum)
            printf("%d is the smallest number \n",iSecondNum);
        else
            printf("%d is the smallest number \n",iThirdNum);
    }
    //Compare Second number with Third number
    else if(iSecondNum>iThirdNum)
    {
        printf("%d is the greatest number \n",iSecondNum);

        //Compare first and third number to find the smallest
        if(iThirdNum<iFirstNum)
            printf("%d is the smallest number \n",iThirdNum);
        else
            printf("%d is the smallest number \n",iFirstNum);
    }
    //else consider third number is the greatest number
    else
    {
        printf("%d is the greatest number \n",iThirdNum);

        //Compare first and second number to find the smallest
        if(iFirstNum<iSecondNum)
            printf("%d is the smallest number \n",iFirstNum);
        else
            printf("%d is the smallest number \n",iSecondNum);
    }
    return;
}
















































