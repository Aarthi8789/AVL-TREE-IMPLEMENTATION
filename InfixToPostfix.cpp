#include<stdio.h>
#define operand(x)(x>='a'&&x<='z'||x>='A'&&x<='Z')
void infixtopostfix();
int priority(char);
void push(char);
char pop();
int top=-1;
char infix[20],stack[20],postfix[20];
int main()
{
	printf("Enter the expression:");
	scanf("%s",infix);
	infixtopostfix();
	printf("%s",postfix);
}
void infixtopostfix()
{
	int j,i=0;
	char x,y;
	for(j=0;(x=infix[j])!='\0';j++)
	{
		if(operand(x))
		postfix[i++]=x;
		else if(x=='(')
		push(x);
		else if(x==')')
		{
	 	while((y=pop())!='(')
		postfix[i++]=y;	
		}
		else
		{		
		while(priority(stack[top])>=priority(x)&&stack[top]!='(')
		postfix[i++]=pop();
		push(x);
	    }
	}
		while(top>=0)
		postfix[i++]=pop();
}
void push(char n)
{
	stack[++top]=n;
}
int priority(char x)
{
	int y;
	y=(x=='('?3:x=='*'?2:x=='/'?2:x=='+'?1:x=='-'?1:-1);
	return y;
}
char pop()
{
	char n;
	n=stack[top];
	top--;
	return n;
}














