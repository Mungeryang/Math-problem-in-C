#include<stdio.h>
#include<stdlib.h>

//创建表达式与符号数组
char postfixExp[20];
char infixExp[20];
char operatorStack[20];

int i = 0,j = 0,top = 0;

//符号的优先级判断
int lowPriority(char opr,char oprStack)
{
	int k,p1,p2;
	char oprlist[] = {'+','-','*','/','%','^','('};
	int priolist[] = {0,0,1,1,2,3,4};
	if(oprStack == '(')
	{
		return 0;
	}
	for(k = 0;k < 6;k++)
	{
		if(opr == oprlist[k])
		{
			p1 = priolist[k];
		}
	}
	for(k = 0;k < 6;k++)
	{
		if(oprStack == oprlist[k])
		{
			p2 = priolist[k];
		}
	}
	if(p1 < p2)
	{
		return 1;
	}
	else{
		return 0;
	}
}

void pushOpr(char opr)
{
	if(top == 0)
	{
		operatorStack[top] = opr;
		top++;
	}
	else{
		if(opr != '(')
		{
			while(lowPriority(opr,operatorStack[top-1]) == 1 && top > 0)
			{
				postfixExp[j] = operatorStack[--top];
				j++;
			}
		}
		operatorStack[top] = opr;
		top++;
	}
	
}

void popOpr()
{
	while(operatorStack[--top] != '(')
	{
		postfixExp[j] = operatorStack[top];
		j++;
	}
}

int main()
{
	char k;
	printf("*********==========************\n");
	printf("Enter Infix expression:\n");
	gets(infixExp);
	while((k = infixExp[i++]) != '\0')
	{
		switch(k)
		{
			case ' ': break;
			case '(': 
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				pushOpr(k);
				break;
			case ')':
				popOpr();
				break;
			default : 
				postfixExp[j] = k;
				j++;
			
			
		}
		
	}
	while(top >= 0)
	{
		postfixExp[j] = operatorStack[--top];
		j++;
	}
	postfixExp[j] = '\0';
	printf("postfix is %s\n",postfixExp);
	printf("infix is %s\n",infixExp);
	return 0;
}
