#include<stdio.h>
char map[6][7];
int checkp(int i,int j,char player)
{
	int hoz=0,vtc=0,dia=0,Rdia=0;
	//hoz
	for(int h=0;i+h<7;h++)
	{
		if(*(*(map+j)+i+h)!=player)
			break;
		else 
			hoz++;
	}
	for(int h=0;i+h>=0;h--)
	{
		if(*(*(map+j)+i+h)!=player)
			break;
		else 
			hoz++;
	}
	//vtc
	if(*(*(map+j-1)+i)==player && *(*(map+j-2)+i)==player && *(*(map+j-3)+i)==player)
			return 1;
	//dia
	for(int h=0;i+h<7&&j+h<6;h++)
	{
		if(*(*(map+j+h)+i+h)!=player)
			break;
		else 
			dia++;
	}
	for(int h=0;i+h>=0&&j+h>=0;h--)
	{
		if(*(*(map+j+h)+i+h)!=player)
			break;
		else 
			dia++;
	}
//reverse dia
	for(int h=0;i-h>=0&&j+h<6;h++)
	{
		if(*(*(map+j+h)+i-h)!=player)
			break;
		else 
			Rdia++;
	}
	for(int h=0;i-h<7&&j+h>=0;h--)
	{
		if(*(*(map+j+h)+i-h)!=player)
			break;
		else 
			Rdia++;
	}
	return (hoz>4||vtc>3||dia>4||Rdia>4);
}

int putdisc(int i,char player)
{
	if(i>6)
		return 0;
	for(int j=0;j<6;j++)
	{
		if(*(*(map+j)+i)=='0')
		{
			*(*(map+j)+i) = player;
			return checkp(i,j,player);
		}
	}
	return 0;
}

void print(char player)
{
	if(player=='Y')
		printf("Yolanda won!\n");
	else
		printf("Ray won!\n");
}
int main() {
	int input;
	char player;
	for(int i=0;i<7;i++)
		for(int j=0;j<6;j++)
			*(*(map+j)+i)='0';	
	while(scanf("%d %c",&input,&player)!=EOF)
	{
		if(putdisc(input-1,player))
		{

			print(player);
			return 0;
		}
	}
	printf("Tied!\n");
	return 0;
}
