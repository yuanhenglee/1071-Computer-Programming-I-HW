#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define SIZE 1999
int fbn[5000][SIZE]={0};
int gcd(int m, int n) 
{
	/* Fucntion for question 2 */
	return n==0?m:gcd(n,m%n);
}

void printPascal(long double n)
{
	/* Fucntion for question 3 */
	if(n!=0)
		printf("1 ");
	long double top=1,bot=1,ptr=n;
	for(long double i=1;i<n;i++)
	{
		top*=ptr;
		top/=i;
		ptr--;
		printf("%.0Lf ",top);	
	}
	printf("1\n");
}

int fibonacci(unsigned long long n){
	/* Fucntion for question 4 */
	// Caculate Fibonacci-Series at first
	if(n<2)
		return n;
	if(fbn[n][0]<0)
	{
		for(int i=0;i<SIZE;i++)
		{
			if(fbn[fibonacci(n-2)][i]>-1 || fbn[fibonacci(n-1)][i]>-1)
			{
				if(fbn[n][i]<0)
					fbn[n][i]=0;
				fbn[n][i]+=(fbn[fibonacci(n-2)][i]+fbn[fibonacci(n-1)][i]);
			}
			if((fbn[fibonacci(n-2)][i]<0 || fbn[fibonacci(n-1)][i]<0) && !(fbn[fibonacci(n-2)][i]<0 && fbn[fibonacci(n-1)][i]<0))
				fbn[n][i]++;
			if(fbn[n][i]>9 && fbn[n][i+1]<0)
				fbn[n][i+1]=0;
			fbn[n][i+1]+=(fbn[n][i]/10);
			fbn[n][i]%=10;
		}
	}
	return n;
}

int main(int argc, char *argv[]){
	int menu = 0;
	int quit = 0;
	while(!quit){
		printf( "=======MENU=========\n"
				"1 - Matrix multiply\n"
				"2 - Find GCD\n"
				"3 - Pascal triangle\n"
				"4 - Fibonaci\n"
				"5 - Relative frequency\n"
				"7 - EXIT\n"
				"====================\n"
				"Enter Your choice:\n");
		scanf("%d", &menu);
		getchar();
		switch( menu ){
			case 1: 
				{
					/* write Matrix Multiply solution here*/

					int n;
					int arr1[99][99];
					int arr2[99][99];
					scanf("%d",&n);
					for(int i=0;i<n;i++)
					{
						for(int j=0;j<n;j++)
							scanf("%d",&arr1[i][j]);
						for(int j=0;j<n;j++)
							scanf("%d",&arr2[i][j]);
					}
					for(int i=0;i<n;i++)
						for(int j=0;j<n;j++)
						{
							int sum=0;
							for(int k=0;k<n;k++)
								sum+=arr1[i][k] * arr2[k][j];
							printf("%d",sum);
							printf("%c",j==n-1?'\n':' ');
						}
					break;

				}
			case 2: 
				{
					int a,b;
					scanf("%d%d",&a,&b);
					printf("%d\n",gcd(a,b));
					break;
					/* write Find GCD solution here */
				}
			case 3:
				{
					/* write Pascal triangle solution here */
					for(int i=0;i<5;i++)
					{
						long double n;
						scanf("%Lf",&n);
						printPascal(n);
					}
					break;
				}
			case 4:
				{
					memset(fbn,-1,sizeof(fbn));
					fbn[0][0]=0;
					fbn[1][0]=1;
					while(1)
					{
						unsigned long long n;
						scanf("%llu",&n);
						if(n==-1)
							break;
						for(int i=SIZE-1;i>=0;i--)
							if(fbn[fibonacci(n)][i]>-1)
								printf("%d",fbn[fibonacci(n)][i]);
						printf("\n");
					}				/* write Fibonacci solution here */
					break;
				}
			case 5: 
				{
					/* write Relative frequency solution here */
					char c;
					int total=0,digit=0,vowel=0,consonant=0;
					while(1)
					{
						c=getchar();
						if(c=='\n')
							break;
						if(c==' ')
							continue;
						if(isdigit(c))
							digit++;
						if(isalpha(c))
						{
							if(c=='a' || c=='A' || c=='e' || c=='E' || c=='I' || c=='O' || c=='i' || c=='o' || c=='U' || c=='u' )
								vowel++;
							else
								consonant++;
						}
						total++;
					}
					printf("digits:%.3f\nvowels:%.3f\nconsonants:%.3f\n",(float)(digit)/total,(float)(vowel)/total,(float)(consonant)/total);
					break;
				}
			case 7:
				quit = 1;
				break;
			default:
				printf("Wrong choice!\n");
				break;
		}
		printf("\n");
	}

	return 0;
}
