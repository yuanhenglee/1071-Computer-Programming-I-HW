#include <stdio.h>
void output(int n,unsigned int bits)
{
	int count=0;
	printf("%d = ",n);
	for(unsigned int i=bits;i;i>>=1)
	{
		if(count==8||count==16||count==24)
			printf(" ");
		printf(i&n?"1":"0");
		count++;
	}
	printf("\n");
}
int main()
{
	int input,x,y;
	scanf("%d%d",&input,&x);
	switch (input)
	{
		case 1:
			scanf("%d",&y);
			output(x&y,2147483648);
			break;
		case 2:
			scanf("%d",&y);
			output(x|y,2147483648);
			break;
		case 3:
			scanf("%d",&y);
			output(x^y,2147483648);
			break;
		case 4:
			output(x<<3,32768);
			break;
		case 5:
			output(x>>3,32768);
			break;
	}

	return 0;
}
