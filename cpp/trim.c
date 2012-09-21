#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim_start(char *s)
{
	int i=0;
	while(*s && s[i]==' ')i++;
	return s+i;
}

char *trim_end(char *s, int n)
{
	while(n>0 && s[n-1]==' '){s[n-1]='\0';n--;};
	return s;
}

char *trim_mid(char *s, int n)
{
	s=trim_start(s);
	s=trim_end(s, n);
	char *new_s=(char *)malloc(n);
	int i=0, k=0;
	for(;;i++)
	{
		if(s[i]=='\0')break;
		else if(s[i]==' ')
		{
			new_s[k]=' ';
			while(s[i++]==' ');
			i-=2;
		}
		else
			new_s[k]=s[i];
		k++;		
	}
	new_s[k]='\0';
	strcpy(s, new_s);
	free(new_s);
	return s;
}

int main(int argc, char **args)
{
	printf("trim start:_%s_\n", trim_start(args[1]));
	printf("trim end:_%s_\n", trim_end(args[1], strlen(args[1])-1));
	printf("trim mid:_%s_\n", trim_mid(args[1], strlen(args[1])-1));
	return 0;
}
