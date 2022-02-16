#include<stdio.h>
#include<string.h>
struct file
{
	char name[999];
	int age;
}people[99999];
void swap(struct file *a,struct file *b)
{
	struct file temp = *a;
	*a = *b;
	*b = temp;
}
int main() 
{
	int i=0;
	while(scanf("%s%d",people[i].name,&people[i].age)>0)
		i++;
	for(int j=0;j<i;j++)
		for(int k=0;k < i-j-1;k++)
			if(people[k].age>people[k+1].age || (people[k].age==people[k+1].age && people[k].name[0]>people[k+1].name[0]))
				swap(&people[k],&people[k+1]);
	for(int j=0;j<i;j++)
		printf("%s %d\n",people[j].name,people[j].age);
	return 0;
}
