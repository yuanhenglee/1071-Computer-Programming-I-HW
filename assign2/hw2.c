#include<stdio.h>
#include<stdlib.h>
struct Interval {
	int start;
	int end;
}table[11111];
void swap(int a,int b)
{
	struct Interval temp=table[a];
	table[a]=table[b];
	table[b]=temp;
}
int main()
{
	int i,j,T,max=0;
	scanf("%d",&T);
	for(i=0;i<T;i++)
		scanf("%d%*[,]%d",&table[i].start,&table[i].end);
	for(i=0;i<T-1;i++)
		for(j=i+1;j<T;j++)
			if(table[i].start>table[j].start)
				swap(i,j);
	for(i=0;i<T-1;i++)
	{
		if(table[i].end<table[i+1].start)
			printf("%d,%d\n",table[i].start,table[i].end);
		else if(table[i].end<table[i+1].end)
			table[i+1].start=table[i].start;
		else
			swap(i,i+1);
	}
	printf("%d,%d\n",table[T-1].start,table[T-1].end);
	return 0;
}
