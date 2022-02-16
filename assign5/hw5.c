#include<stdio.h>
void setmatrix(int n)
{
	int usum=0,dsum=0;
	int a[100][100];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(j>i&&a[i][j]!=0)
				usum++;
			else if(i>j&&a[i][j]!=0)
				dsum++;
		}

//		printf("%d,%d\n",usum,dsum);
	if(dsum==0&&usum!=0)
		printf("Upper triangular matrix\n");
	else if(usum==0&&dsum!=0)
		printf("Lower triangular matrix\n");
	else
		printf("Symmetric matrix\n");

		}
int main()
{
	
	int n;
	scanf("%d\n",&n);
	setmatrix(n);

	return 0;
}
