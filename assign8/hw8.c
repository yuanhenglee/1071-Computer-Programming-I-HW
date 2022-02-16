#include<stdio.h>
#include<string.h>
char strtemp[9999][9999],inputstr[9999],key[9999];
char *token[9999];
char *comptr=":., ";//³ë¯àà ':'??
int main()
{
	int i=0;
	while(scanf("%[^\n]%c%[^\n]%c",*(strtemp+i),inputstr,key,inputstr)!=EOF)
	{
		strcpy(inputstr,*(strtemp+i));
		int count=-1;
		char *s = strtok(inputstr,comptr);
		while(s != NULL){count++;
			*(token+count) = s;
			s = strtok(NULL,comptr);
		}
		int j=0;
		while(*(token+j)!='\0'){j++;
			if(!strstr(key,*(token+j-1)))
			{
				strtemp[i][0]='\0';
				printf("Fake\n");
				break;
			}
		}
		if(strtemp[i][0]!='\0')
			printf("Real\n");
		memset(*token,'\0',9999);
		i++;
	}
	for(int i=0;strtemp[i][0]!=0||strtemp[i][1]!=0;i++)
		if(strtemp[i][0]!='\0')
			printf("%s\n",strtemp[i]);
	return 0;
}
