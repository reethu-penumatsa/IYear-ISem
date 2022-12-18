#include<stdio.h>
void main()
{
    int a,ch;
    float b;

    printf("Enter First Number :");
    scanf("%d",&a);
    printf("Enter Second Number :");
    scanf("%f",&b);
    printf("Enter Third Number which as to be converted in the Character :");
    scanf("%d",&ch);

    //implicit type casting
    printf("Implicit type casting : Division is %f\n",a/b);

    //Explicit type casting
    ch=(char)ch;
    printf("Explicit type casting : %c\n",ch);

    return;
}
