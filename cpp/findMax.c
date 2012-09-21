#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int comlen(char *p, char *q)
{
	int i=0;
	while((*p)&&(*p++==*q++))i++;
	//printf("%d\n", i);
	return i;
}

int pstrcmp(const void *s1, const void *s2)
{
//	printf("%s\n", *(char **)s1);
	return strcmp(*(char**)s1, *(char**)s2);
}

int main()
{
	char *s="Ask not what your country can do for you, but what you can do for your country";
	char *a[MAX];
	int maxlen=-1, i, j, maxi, maxj;
	int thislen=0;
	for(i=0; i<strlen(s); i++)
	{
		for(j=i+1; j<strlen(s); j++)
		{
			if((thislen=comlen(&s[i], &s[j]))>maxlen)
			{
				maxlen=thislen;
				maxi=i;
				maxj=j;	
			}
		}
	}
	printf("%.*s\n", maxlen, s+maxi);

	for (i=0; i<strlen(s); i++)
	{
		a[i]=s+i;
	}
	qsort(a, strlen(s), sizeof(a[0]), pstrcmp);

	maxlen=-1;
	for(i=0; i<strlen(s)-1; i++)
	{
		if(comlen(a[i], a[i+1])>maxlen)
		{
			maxlen=comlen(a[i], a[i+1]);
			maxi=i;
		}
	}
	printf("%.*s\n", maxlen, a[maxi]);
	return 0;
}
