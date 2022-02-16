#include <stdio.h>
#include<string.h>
char dictemp[99]={0};
char searchword[99]={0};
char *dicptr[99]={0};
char dictionary[26][99][99]={0};
int dicprogress[26]={0};
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

void swap(char **a,char **b)
{
	char *temp = *a; 
	*a = *b; 
	*b = temp; 
}

void sorting()
{
	for(int i=0;i<dicsize;i++)
	{
		strcpy(dictionary[**(dicptr+i)-97][dicprogress[**(dicptr+i)-97]],*(dicptr+i));
		dicprogress[**(dicptr+i)-97]++;
	}
}
int main() 
{	
	scanf("%s",dictemp);
	token();
	sorting();
/*	for(int i=0;i<26;i++)
		for(int j=0;j<5;j++)
			printf("%s\n",dictionary[i][j]);
*/	while(scanf("%s",searchword)!=EOF)
	{
		int count=1,exist=0;
		for(int i=0;i<dicsize;i++)
		{
			if(dictionary[searchword[0]-97][i][0]=='\0')
				break;
			if(strcmp(searchword,dictionary[searchword[0]-97][i])>0)
				count++;
			if(strcmp(searchword,dictionary[searchword[0]-97][i])==0)
				exist=1;
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
