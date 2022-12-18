#include<stdio.h>
void main()
{
    //Declare integer variable to capture percentage scored
    int iPercent;

    //Read percentage scored
    printf(" Enter the percentage you scored in B-Tech :");
    scanf("%d",&iPercent);

    printf("\n");
    //Compare percentage and print the result
    if(iPercent>=70)
        printf(" Congratulations!, You got Distinction ");
    else if(iPercent>=60 && iPercent<70)
        printf(" Congratulations!, You got First class ");
    else if(iPercent>=40 && iPercent<60)
        printf(" Not bad!, You got Second class ");
    else
        printf(" You failed, need to do lot of hard work ");

    printf("\n");

    return;
}
