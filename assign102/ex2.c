#include <stdio.h>

int main() {
	float h, w, b, n;
	scanf("%f",&n);
	for(int i=0;i<n;i++)
		{
		scanf("%f%f",&h,&w);
		b=w*10000/h/h;
		if(b<18.5)
			printf("Underweight\n");
		else if(b<=25)
			printf("Normal\n");
		else if(b<30)
			printf("Overweight\n");
		else
			printf("Obese\n");
		}
	return 0;
}
