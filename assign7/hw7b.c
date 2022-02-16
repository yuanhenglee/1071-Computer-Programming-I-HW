#include <stdio.h>
#include<string.h>
char dictemp[99]="jgoiqas,agh,asgih";
char searchword[15];
char *dicptr[99];
const char *comptr=",";
int dicsize=0;

void token() 
{
	char *s = strtok(dictemp, comptr);
	while(s != NULL)
   	{
		*(dicptr+dicsize) = s;
		s = strtok(NULL, comptr);
		dicsize++;
	}
}

int main() 
{

	while(scanf("%s",searchword)!=EOF)
	{
		printf("%s\n%s\n",dictemp,searchword);
	}
	return 0;
}
