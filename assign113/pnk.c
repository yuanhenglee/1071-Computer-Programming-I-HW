#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int x[2][2];
	int y[2][2];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			scanf("%d%d",&x[i][j],&y[i][j]);
	for(int i=0;i<2;i++)
		if(x[i][0]>x[i][1])
			swap(&x[i][0],&x[i][1]);
	for(int i=0;i<2;i++)
		if(y[i][0]>y[i][1])
			swap(&y[i][0],&y[i][1]);
	printf("%d\n",abs(x[0][1]-x[1][0])*abs(y[0][1]-y[1][0]));
	return 0;
}
