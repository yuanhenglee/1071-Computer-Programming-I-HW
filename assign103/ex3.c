#include <stdio.h>

int main() {
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p=0,j=2;
		scanf("%d",&a);
		while(j*j<=a)
		{
			if(a%j==0)
			{
				p++;
				break;
			}
			j++;
		}

		
		if(p==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
