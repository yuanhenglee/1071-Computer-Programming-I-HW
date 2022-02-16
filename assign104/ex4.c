#include<stdio.h>
void one(int x)
{
	x=x%10;
	if(x%5==4)
		printf ("I");
	if(x==9)
		printf("X");
	else if(x>3)
		printf("V");
	switch(x%5)
	{
		case 3:
			printf ("I");
		case 2:
			printf ("I");
		case 1:
			printf ("I");
	}

}
void ten(int x)
{
	x-=x%10;
	x/=10;
	if(x%5==4)
			printf ("X");
	if(x>8)
			printf("C");
	else if(x>3)
		printf("L");
	switch(x%5)
	{
		case 3:
			printf ("X");
		case 2:
			printf ("X");
		case 1:
			printf ("X");
	}

}
int main( void ){
	/* decide the digits in tens*/
	int a,b;
	char o;
	while(scanf("%d%c%d",&a,&o,&b)!=EOF)	
	{
		if (o=='+')
			a+=b;
		else
			a-=b;
		if(a<0)
			a=-a;
		if(a==0)
			printf("?");
		ten(a);
		one(a);
		printf("\n");			
		

	}
	/* decide the digits in ones*/

	return 0;
}
