#include<stdio.h>
void main()
{
int rows,i,j;
int num=1;
printf("Enter the Number of Rows:");
scanf("%d",&rows);
for(i=1;i<=rows;i++)
{
  for(j=1;j<=i;j++)
  {
  printf("%d ",num);
  num=num+1;
  }
  
  printf("\n");
}
return;
}
