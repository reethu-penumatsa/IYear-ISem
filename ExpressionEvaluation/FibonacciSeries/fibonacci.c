#include<stdio.h>
void main()
{
    int iNum1=0,iNum2=1,iSum=0,iInputNum;

    printf(" Enter Number :");
    scanf("%d",&iInputNum);

    printf("%5d\n",iNum1);
    printf("%5d\n",iNum2);

    for(int i=3;i<=iInputNum;i++)
    {
        iSum = iNum1+iNum2;
        printf("%5d\n",iSum);
        iNum1 = iNum2;
        iNum2 = iSum;
    }
    return;
}
