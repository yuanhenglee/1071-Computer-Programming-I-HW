#include<stdio.h>

void output(int a,int b)
{	
	printf("A");
	for(int i=0;i<a;i++)
		printf("=");
		printf("\n");
		printf("B");
	for(int j=0;j<b;j++)
		printf("=");
		printf("\n");
}
int main( void )
{
	int a,b,af,bf;
	char ad,bd;
	scanf("%d%d",&a,&b);
	output(a,b);
		while(scanf("%d %c\n%d %c",&af,&ad,&bf,&bd)!=EOF&&(a>0&&b>0))
		{	
			if(af==0&&bf==5)
				af=6;
			if(af==5&&bf==0)
				bf=6;
			if(af>bf&&ad==bd)
			{
				a--;
				
				output(a,b);
			}
			else if(af<bf&&ad==bd)
			{
				b--;
				
				output(a,b);
			}
		}
	if(a==0&&b!=0)
		printf("B win\n");
	else if(a!=0&&b==0)
		printf("A win\n");
	else
		printf("Tie\n");
	return 0;
}
