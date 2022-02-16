#include<stdio.h>
char request;
int map[100][100]={0};
int n,m;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sorting(char request)
{
	for(int i=0;i<n;i++)
		for(int count=0;count<m-1;count++)
			for(int j=0;j<m-1;j++)
				if(map[i][j]>map[i][j+1])
					swap(&map[i][j],&map[i][j+1]);	
}

int main(void)
{
	scanf("%c %d %d",&request,&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	sorting(request);	
	if(request=='a')
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%d ",map[i][j]);
			printf("\n");
		}
	else
		for(int i=0;i<n;i++)
		{
			for(int j=m-1;j>=0;j--)
				printf("%d ",map[i][j]);
			printf("\n");
		}
	return 0;
}
