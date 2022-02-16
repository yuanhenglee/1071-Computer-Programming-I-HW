#include<stdio.h>
int divisor(int n,int m)
{
	if(n>m){
	  
		  for(int i=m;i>0;i--)
			  if(n%i==0&&m%i==0)
				  return i;
	}
	else if(n<m)
	{
		for(int j=n;j>0;j--)
			if(m%j==0&&n%j==0)
				return j;
	}

	else
		return n;
}
int main( void ){
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
		printf("%d\n",divisor(a,b));
	return 0;
}
