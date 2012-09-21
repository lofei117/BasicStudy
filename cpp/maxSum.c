#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define max(a,b) (a>b?a:b)

int func0(int *a, int n)
{
	int maxsofar=0, sum=0;;
	int i, j,k;
	for(i=0; i<n; i++)
		for(j=i; j<n; j++)
		{
			sum=0;
			for(k=i; k<=j;k++)
			{
				sum+=a[k];
				maxsofar= max(maxsofar, sum);
			}
		}
	return maxsofar;
}

int func1(int *a, int n)
{
	int maxsofar=0, sum=0;
	int i, j;	
	for(i=0; i<n; i++)
	{
		sum=0;
		for(j=i; j<n; j++)
		{
			sum+=a[j];
			maxsofar=max(maxsofar, sum);	
		}
	}
	return maxsofar;
}

int func2(int *a, int l, int r)
{
	if(l>r)return 0;
	if(l==r) return max(a[l], 0);
	int lmax=0, rmax=0, i, sum=0;
	int m = (l+r)/2;
	for(i=m; i>=l; i--)
	{
		sum+=a[i];
		lmax=max(sum, lmax);
	}
	sum=0;
	for(i=m+1; i<=r; i++)
	{
		sum+=a[i];
		rmax=max(sum, rmax);	
	}
	return max(max(func2(a, l, m), func2(a, m+1, r)), lmax+rmax);
}

int func3(int *a, int n)
{
	int maxending=0, maxsofar=0, i;
	for(i=0; i<n; i++)
	{
		maxending=max(maxending+a[i], 0);
		maxsofar=max(maxsofar, maxending);
	}
	return maxsofar;
}

int main()
{
	srand((unsigned)time(NULL));
	int a[MAX], i, j;
	for(i=0; i<MAX; i++)	
	{
		a[i]=rand()%200-100;
		printf("%d,", a[i]);
	}
//	int b[10]={40,-19,-16,53,-95,-77,6,52,34,57};
//	printf("\nmax by O(n3):%d", func0(a, MAX));
	printf("\nmax by O(n2):%d", func1(a, MAX));
	printf("\nmax by O(nlogn):%d", func2(a, 0, MAX-1));
	printf("\nmax by O(n):%d\n", func3(a, MAX));
	return 0;
}
