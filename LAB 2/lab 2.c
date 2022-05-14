#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct stack
{
int top;
char data[40];
};
typedef struct stack STACK;
void push(STACK *s, char ele)
{
s->data[++(s->top)]= ele;
}
char pop(STACK *s)
{
return s->data[(s->top)--];
}
int preced(char symbol)
{
switch(symbol)
{
case '^': return 5;
case '*':
case '/': return 3;
case '+':
case '-': return 1;
}
}
void infixtopostfix(char infix[40], STACK *s)
{
char postfix[40], symbol,temp;
int i,j=0;
for(i=0;infix[i]!='\0';i++)
{
symbol = infix[i];
if(isalnum(symbol))
{
postfix[j++]=symbol;
}
else
{
switch(symbol)
{
case '(': push(s,symbol);
break;
case ')': temp = pop(s);
while(temp!='(')
{
postfix[j++]=temp;
temp = pop(s);
}
break;
case '^':
case '*':
case '+':
case '/':
case '-':if(s->top==-1||s->data[s->top]=='(')
push(s,symbol);
else
{
while(preced(s->data[s->top])>=preced(symbol)&&s->top!=-1&&s->data[s->top]!=')')
postfix[j++]=pop(s);
push(s,symbol);
}
break;
}
}
}
while(s->top!=-1)
{
postfix[j++]=pop(s);
}
postfix[j]='\0';
printf("\nPostfix of the expression is %s", postfix);
}
int main()
{
char infix[40];
STACK s;
s.top = -1;
printf("\nRead the infix expression\n");
scanf("%s",infix);
infixtopostfix(infix,&s);
return 0;
}
