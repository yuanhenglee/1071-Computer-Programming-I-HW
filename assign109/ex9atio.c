#include<stdlib.h>
#include<ctype.h>
#include <stdio.h>
char str[999999];
/*int savenum(char *str)
{
	if(isdigit(*str))
		return (int)*str-48+10*savenum(str-1);	
	else
		return 0;
}*/
int main() 
{
	while(scanf("%s",str)!=EOF)
	{
		char sum[99999]={0};
		int k=0;
		int result=0;
		int j=0;
		for(int i=0;i<99999;i++)
		{
			if(isdigit(str[i]) || str[i]=='-')
			{
				sum[j]=str[i];				
				j++;						
			}
			else
			{
				if(j>0)
				{
					result+=atoi(sum);
					sum[j]=NULL;
				}
				
			}
		}	

		printf("%d\n",result);
	}
	return 0;
}
