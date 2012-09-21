#include <stdio.h>
#include <string.h>

void CounterSort(char str[], char help_str[])  
{  
    // 辅助计数数组  
    int help[26] = {0};  
	int i,j,k;
    // help[index]存放了等于index + 'A'的元素个数  
    for ( i = 0; i < strlen(str); i++)  
    {  
        int index = str[i] - 'A';  
        help[index]++;  
    }  
  
    // 求出每个元素对应的最终位置  
    for ( j = 1; j < 26; j++)  
    {
	    help[j] += help[j-1];  
	    printf("%d,", help[j]);
    }
  
    // 把每个元素放到其对应的最终位置  
    for ( k = strlen(str) - 1; k >= 0; k--)  
    {  
        int index = str[k] - 'A';  
        int pos = help[index] - 1;  
        help_str[pos] = str[k];  
        help[index]--;  
    }  
}  

int main()  
{  
    char strOne[]  = "ABCDAK";  
  	char long_str[20];
	strcpy(long_str,"ABCDAK");
    // 对字符串进行计数排序  
    CounterSort(strOne, long_str);  
	printf("%s\n", strOne);
	printf("%s\n",long_str);
    return 0;  
}  
