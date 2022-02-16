#include <stdio.h>
#include<string.h>
#define comptr ","
char dictemp[9999];
char searchword[9999];
char *dicptr[9999];
int dicsize=0;
void token() 
{
	scanf("%s",dictemp);
	char *s = strtok(dictemp, comptr);
	while(s != NULL)
	{
		*(dicptr+dicsize) = s;
		s = strtok(NULL, ",");
		dicsize++;
	}
}
int main() 
{	
	token();
	while(scanf("%s",searchword)!=EOF)
	{
		int count=1,exist=0;
		for(int i=0;i<dicsize;i++)
		{
			if(*searchword==**(dicptr+i))
			{	
				if(strcmp(searchword,*(dicptr+i))>0)
					count++;
				if(strcmp(searchword,*(dicptr+i))==0)
					exist=1;
			}
		}
		if(exist)
		{
			printf("%c %d\n",searchword[0]-32,count);
			continue;
		}
		else
			printf("NOT FOUND\n");
	}
	return 0;
}
