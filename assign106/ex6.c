#include <stdio.h>

int main()
{
int a[1000]={0};
int i=0,sum=0,max=0;
while(scanf("%d ",&a[i])!=EOF){
	sum+=a[i];
	sum=(sum<0)?0:sum;	
	max=(sum>max)?sum:max;
	i++;
}
printf("Maximum contiguous sum is %d\n",max);
	return 0;
}
