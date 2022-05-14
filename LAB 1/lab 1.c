#include <stdio.h>
#include <process.h>
struct stack
{
int top;
int data[10];
};
typedef struct stack STACK;
void push(STACK *p,int ele)
{
if(p->top==(10-1))
printf("\nStack Overflow\n");
else
{
p->top = p->top+1;
p->data[p->top] = ele;
}
}
int pop(STACK *p)
{
if(p->top==-1)
{
printf("\nStack Underflow\n");
return -1;
}
else
{
return p->data[(p->top)--];
}
}
void popn(STACK *p,int n)
{
if(n> p->top)
printf("\nLesser Elements in the Stack");
else
{
printf("\nThe popped elements are\n");
for(int i = 0;i<n;i++)
{
printf("\n%d", pop(p));
}
}
}
void top3(STACK *p)
{
STACK s1;
int n,y;
s1.top = -1;
n = p->top+1;
if(n<3)
printf("Less Number of elements in Stack");
else
{
push(&s1,pop(p));
push(&s1,pop(p));
y = p->data[p->top];
printf("\nThe third element in the stack is %d", y);
while(s1.top!=-1)
{
push(p,pop(&s1));
}
}
}
void bottom3(STACK *p)
{
int n,x;
STACK s1;
s1.top=-1;
n = p->top+1;
if(n<3)
printf("Less Number of elements in Stack");
else
{
for(int i = p->top;i>2;i--)
{
push(&s1,pop(p));
x = p->data[p->top];
}
printf("\nThe bottom third element in the stack is %d", x);
while(s1.top!=-1)
{
push(p,pop(&s1));
}
}
}
void display(STACK p)
{
if(p.top==-1)
{
printf("\nThe Stack is Empty\n");
}
else
{
printf("\nThe contents of stack are\n");
for(int i=p.top; i>=0; i--)
{
printf("\n%d", p.data[i]);
}
}
}
int main()
{
STACK s;
s.top = -1;
int ch, item, del,n;
for(int i = 0; i!=-1;i++)
{
printf("\n1. Push");
printf("\n2. Pop");
printf("\n3. Display");
printf("\n4. Pop 'n' elements");
printf("\n5. Top third element");
printf("\n6. Bottom third element");
printf("\n7. Exit");
printf("\n Read Choice\n");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("\n Read element to be pushed\n");
scanf("%d", &item);
push(&s,item);
break;
case 2: del = pop(&s);
if(del!=-1)
printf("\n%d",del);
break;
case 3: display(s);
break;
case 4: printf("\nRead the number of elements to be popped\n");
scanf("%d",&n);
popn(&s,n);
break;
case 5: top3(&s);
break;
case 6: bottom3(&s);
break;
/*case 4: i = -1;
exit(0);
break;*/
default:
exit(0);
break;
}
}
}
