#include<stdio.h>
int stairf(int n){
	int ways=0;
	if(n>5)
		for(int i=1;i<5;i++)
			ways+=stairf(n-i);
	switch(n){
		case 5:
			ways+=15;
			break;			
		case 4:
			ways+=8;
			break;			
		case 3:
			ways+=4;			
			break;			
		case 2:
			ways+=2;
			break;			
		case 1:
			ways+=1;
			break;			}
	return ways;			}
int main( void )
{
	int a;
	while(scanf("%d",&a)!=-1)
		printf("%d\n",stairf(a));
	return 0;
}
