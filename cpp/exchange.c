/**
 *  exchange - exchange even bit and odd bit of an Integer number.
 *  AUTHOR: Lofei Lin (lofei117@qq.com)
 *  TIME: 09/26/2012
 **/
#include <stdio.h>
#include <stdlib.h>
#define ODD_MASK 0x55555555
#define EVEN_MASK 0xAAAAAAAA
#define EXCHANGE(x) (((x)&ODD_MASK)<<1)|(((x)&EVEN_MASK)>>1)

int main(int argc, char** args)
{
	if(argc>1)
		printf("%d, %d\n", atoi(args[1]), EXCHANGE(atoi(args[1])));
	return 0;
}
