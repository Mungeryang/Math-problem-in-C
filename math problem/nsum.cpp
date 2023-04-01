#include<stdio.h>
#include<stdlib.h>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
	int n,cnt,flag;
	//无符号长整型数
	unsigned long int sum;
	char ch;
	do
	{
		do
		{
			flag = 0;
			printf("Enter a number:(0 < n < 3000)\n");
			scanf("%d",&n);
			if(n < 0 || n > 3000)
			{
				flag = 1;
			}
		}while(flag);
		sum = 0;
		for(cnt = 1;cnt <= n;cnt ++)
		{
			sum += cnt;
		}
		//这里如果知识输出整型数值的话结果会发出警告
		//必须输出长整型数值为%lu
		printf("Required sum is : %lu\n",sum);
		printf("Do you want to continue?(Y/N)\n");
			scanf("%c",&ch);
	}while((ch == 'Y') || (ch == 'y'));
	
	printf("Thank you!\n");
	return 0;
}
