#include <stdio.h>
#include <string.h>
struct people
{
	char name[9999];
	int grade;
	float rate;	
} stu[100];
void swap(struct people *a,struct people *b)
{
struct people temp=*a;
*a=*b;
*b=temp;
}
int main()
{
	int	i=0;
	while(scanf("%s %d %f",stu[i].name,&stu[i].grade,&stu[i].rate)>0)i++;
	for(int j=0;j<i;j++)
		for(int k=0;k<i-j- 1;k++)
			if(stu[k].grade < stu[k+1].grade || (stu[k].grade == stu[k+1].grade && stu[k].rate < stu[k+1].rate))
			{
				swap (&stu[k],&stu[k+1]);
/*				struct people temp=stu[k];
				stu[k]=stu[k+1];
				stu[k+1]=temp;
*/			
			}
	for(int j=0;j<i;j++)
		printf("%s %d %.2f\n",stu[j].name,stu[j].grade,stu[j].rate);
	return 0;
}
