#include<stdio.h>
void main()
{
int rows,i,j;
printf("Enter The Number Of Rows:");
scanf("%d",&rows);
for(i=1;i<=rows;i++)
{
  for(j=1;j<=i;j++)
  {
  printf("* ");
  }
  
  printf("\n");
}
return;
}
