#include<stdio.h>
#include<math.h>
void main()
{
    //Declare integer variables
    int iPrincipalAmt,iTimeYears;

    //Declare float variable to capture rate of interest
    float fRateOfInterest;

    //Read Principal amount, Years and Rate of interest
    printf(" Enter Principal Amount :");
    scanf("%d", &iPrincipalAmt);
    printf(" Enter Time in Years :");
    scanf("%d", &iTimeYears);
    printf(" Enter Rate of Interest :");
    scanf("%f", &fRateOfInterest);

    printf("\n");

    //Calculate Simple interest and display
    printf(" Simple Interest is :%f \n",iPrincipalAmt*iTimeYears*fRateOfInterest/100);
    printf(" Total Amount with Simple Interest is :%f \n\n",(iPrincipalAmt*iTimeYears*fRateOfInterest/100)+iPrincipalAmt);

    //Calculate Compound interest and display
    printf(" Compound Interest is : %f \n",(iPrincipalAmt*pow(1+fRateOfInterest/100,iTimeYears))-iPrincipalAmt);
    printf(" Total Amount with Compound Interest is : %f \n",(iPrincipalAmt*pow(1+fRateOfInterest/100,iTimeYears)));

    return;
}
