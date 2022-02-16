#include<stdio.h>
#include<string.h>

int main()
{
	char key[99999];
	char docs[99999];
	char cc;
	while(scanf("%[^\n]%c%[^\n]%c",docs,&cc,key,&cc)!=EOF)
	{
		int i=0,j=0,k=0;
		while(i<strlen(docs))
		{
			if(docs[i]==','||docs[i]==' ')
			{
				i++;
				continue;
			}
			if(key[j]!=docs[i])
			{
				printf("Rejection\n");
				k=1;
				break;
			}
			j++;
			i++;
		}
		if(k==0)
			printf("Admission\n");	
	}

	return 0;
}
