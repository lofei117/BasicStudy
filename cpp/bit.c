#include <stdio.h>

struct test
{
int a;
char b;
struct test *p;
};

int main()
{
	printf("sizeof int:%ld\n", sizeof(int));
  printf("sizeof int*:%ld\n", sizeof(int*));
  printf("sizeof char:%ld\n", sizeof(char));
  printf("sizeof char*:%ld\n", sizeof(char*));
  printf("sizeof long:%ld\n", sizeof(long));
  printf("sizeof long*:%ld\n", sizeof(long*));
  printf("sizeof struct:%ld\n", sizeof(struct test));
  printf("sizeof struct*:%ld\n", sizeof(struct test *));


}
