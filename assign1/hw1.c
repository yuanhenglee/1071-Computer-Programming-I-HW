#include<stdio.h>
#include<string.h>
int checkcommon(char a[],char b[])
{
	for(int i=0;i<strlen(a);i++)
		if(strchr(b,a[i]))
			return 0;
	return 1;
}
int main()
{
	int max=0,i=0;
	char s[999];
	char *strarr[999];
	gets(s);
	char *token;
	token = strtok(s, ",");
	while( token != NULL ) 
	{
		strarr[i++]=token;
		token = strtok(NULL, ",");
	}
	for(int k=0;k<i-1;k++)
		for(int l=k+1;l<i;l++)
		{		
			int lenk=strlen(strarr[k]),lenl=strlen(strarr[l]);
			if(checkcommon(strarr[k],strarr[l]))
				max=max>(lenk*lenl)?max:lenk*lenl;
		}
	printf("%d\n",max);
	return 0;
}
