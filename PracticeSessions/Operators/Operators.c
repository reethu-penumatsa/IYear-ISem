#include<stdio.h>
void main()
{
    //Declare 2 integer variables
    int iFirstNum,iSecondNum;

    //Read first number
    printf("Enter the First Integer No  : ");
    scanf("%d",&iFirstNum);

    //Read second number
    printf("Enter the Second Integer No : ");
    scanf("%d",&iSecondNum);

    //Apply Add, Subtract, Multiply, Division and Modulus operators
    printf(" Sum of %d and %d is        : %d \n", iFirstNum,iSecondNum,iFirstNum + iSecondNum);
    printf(" Subtract %d from %d is     : %d \n", iSecondNum,iFirstNum,iFirstNum - iSecondNum);
    printf(" Multiply %d with %d is     : %d \n", iFirstNum,iSecondNum,iFirstNum * iSecondNum);
    printf(" Divide %d by %d is         : %d \n", iFirstNum,iSecondNum,iFirstNum / iSecondNum);
    printf(" Modulus of %d and %d is    : %d \n\n", iFirstNum,iSecondNum,iFirstNum % iSecondNum);

    //Apply Greater and Less tan operators
    printf(" Less than Operator (%d<%d) is     : %d \n",iFirstNum,iSecondNum,iFirstNum<iSecondNum);
    printf(" Greater than Operator (%d>%d) is  : %d \n\n",iFirstNum,iSecondNum,iFirstNum>iSecondNum);

    //Apply AND, OR and NOT operators
    printf(" Logical AND Operator (%d>%d && %d<%d) is : %d \n", iFirstNum,iSecondNum,iFirstNum,iSecondNum,iFirstNum>iSecondNum&&iFirstNum<iSecondNum);
    printf(" Logical AND Operator (%d>%d && %d!=%d)is : %d \n", iFirstNum,iSecondNum,iFirstNum,iSecondNum,iFirstNum>iSecondNum&&iFirstNum!=iSecondNum);
    printf(" Logical OR Operator (%d>%d || %d<%d) is  : %d \n", iFirstNum,iSecondNum,iFirstNum,iSecondNum,iFirstNum>iSecondNum||iFirstNum<iSecondNum);
    printf(" Logical OR Operator (%d<%d || %d==%d) is : %d \n", iFirstNum,iSecondNum,iFirstNum,iSecondNum,iFirstNum<iSecondNum||iFirstNum==iSecondNum);
    printf(" Logical NOT Operator !(%d>%d) is          : %d \n", iFirstNum,iSecondNum,!(iFirstNum>iSecondNum));
    printf(" Logical NOT Operator !(%d<%d) is          : %d \n\n", iFirstNum,iSecondNum,!(iFirstNum<iSecondNum));

    //Apply Bitwise Operators
    printf(" Bitwise AND Operator (%d>%d & %d<%d) is   : %d \n",iFirstNum,iSecondNum,iFirstNum,iSecondNum,iFirstNum>iSecondNum&iFirstNum<iSecondNum);
    printf(" Bitwise AND Operator (%d>%d & %d!=%d) is  : %d \n",iFirstNum,iSecondNum,iFirstNum,iSecondNum,iFirstNum>iSecondNum&iFirstNum!=iSecondNum);
    printf(" Bitwise OR Operator (%d>%d | %d<%d) is    : %d \n",iFirstNum,iSecondNum,iFirstNum,iSecondNum,iFirstNum>iSecondNum|iFirstNum<iSecondNum);
    printf(" Bitwise OR Operator (%d<%d | %d==%d) is   : %d \n\n",iFirstNum,iSecondNum,iFirstNum,iSecondNum,iFirstNum<iSecondNum|iFirstNum==iSecondNum);


    //Apply Increment Operators
    iSecondNum=iFirstNum;
    printf(" Pre-increment Operator ++%d is   : %d \n",iSecondNum,++iFirstNum);

    iSecondNum=iFirstNum;
    printf(" Post-increment Operator %d++ is  : %d \n",iSecondNum,iFirstNum++);
    printf(" After Post-increment value is    : %d \n\n",iFirstNum);

    //Apply Decrement Operators
    iSecondNum=iFirstNum;
    printf(" Pre-decrement Operator --%d is   : %d \n",iSecondNum,--iFirstNum);

    iSecondNum=iFirstNum;
    printf(" Post-decrement Operator %d-- is  : %d \n",iSecondNum,iFirstNum--);
    printf(" After Post-decrement value is    : %d \n",iFirstNum);

    //Return main
    return;
}
