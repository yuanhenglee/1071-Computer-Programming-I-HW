#include<stdio.h>

int main(){
	char str[999];
	int position;
	while(scanf("%s%d",str,&position)>0)
		printf("%c\n",str[position]);
    return 0;
}
