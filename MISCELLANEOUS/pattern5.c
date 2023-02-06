#include<stdio.h>
void main()
{
int coloumns=1,i,j,N;
printf("Enter The Number Of Coloumns:");
scanf("%d",&N);
for(i=1;i<(N*2-1);i++)
{
 for(j=1;j<=coloumns;j++)
 {
 printf("* ");
 }
 
 printf("\n");
if (i<=N)
  coloumns++;
else
  coloumns=coloumns-1;
}
return;
}
