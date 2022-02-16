#include<ctype.h>
#include <stdio.h>
char str[99999];
int sum[9999]={0};
int j=0;
int savenum(int i)
{
	if(isdigit(str[i]))
		return (int)str[i]-48+10*savenum(i-1);	
	else
		return 0;
}
int main() 
{

	scanf("%s",str);
	printf("%d",savenum(5));
	return 0;
}
