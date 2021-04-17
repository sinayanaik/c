#include<stdio.h>
 double fact(int n);

void main()
{
 
 double factorial[1000];

 for(int i=0;i<1000;i++)
 {
     factorial[i] = fact(i+1);
 }

  for(int i=1;i<=1000;i++)
 {
    printf("factorial[%d] = %e\n",i,factorial[i-1]);
 }

  
  
}

double fact(int n)
{
    if(n==1)
      return 1;
    else 
      return n*fact(n-1);
}