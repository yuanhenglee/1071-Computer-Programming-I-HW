#include<ctype.h>
#include<string.h>
#include <stdio.h>

int savenum(char *str)
{
	if(isdigit(*str))
		return (int)*str-'0'+10*savenum(str-1);	
	else
		return 0;
}

int main() 
{
	char str[1000];
	int len, sum[1000]={NULL}, k, result, i, j;
	while(scanf("%s",str)!=EOF)
	{
		len = strlen(str);
		for(i=0; i<len; i++)
			sum[i] = 0;
		k=0;
		result=0;
		//		printf("%d",savenum(5));
		j=0;
		for(i=0;i<len;i++)
		{
			if(str[i]=='-')
			{
				sum[j]=-2;
			}
			if(isdigit(str[i])&&isdigit(str[i+1])==0)
			{
//				printf("%d\n",savenum(i));
				(sum[j])++;
				sum[j] *= savenum(&str[i]);
				result+=sum[j];
				//printf("%lld ", sum[j]);
				j++;						
			}
//			if(str[i]=='\0')
//				break;
		}	
/*		while(sum[k]!=0)
		{
			result+=sum[k];
			k++;			
		}
*/
		printf("%d\n",result);
	}
	return 0;
}
