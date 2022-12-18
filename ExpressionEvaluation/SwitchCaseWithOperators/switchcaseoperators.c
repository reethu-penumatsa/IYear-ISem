#include<stdio.h>
void main()
{
    int choice,num1,num2,temp;

      printf("enter the 1st number:");
      scanf("%d",&num1);

      printf("enter the 2nd number:");
      scanf("%d",&num2);

      printf("Enter\n 1:addition\n 2:subtraction\n 3:multiplication\n 4:division\n 5:remainder\n :");
      scanf("%d",&choice);


    switch(choice)

    {


    case 1: temp=num1+num2;
            printf("sum is %d",temp);
    break;

    case 2: temp=num1-num2;
            printf("sub is %d",temp);
    break;

    case 3: temp=num1*num2;
            printf("mult is %d",temp);
    break;

    case 4: temp=num1/num2;
            printf("division is %d",temp);
    break;

    case 5: temp=num1%num2;
            printf("remainder is %d",temp);
    break;


    default:
              printf("enter choice between 1 to 5");

    }
    return;

}
