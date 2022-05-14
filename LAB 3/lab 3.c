#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 5
struct queue
{
int front,rear;
char data[SIZE][20];
};
typedef struct queue CQUEUE;
void sender(CQUEUE *q, char item[20])
{
if(q->front==(q->rear+1)%SIZE)
printf("\nQueue is full");
else
{
q->rear = (q->rear+1)%SIZE;
strcpy(q->data[q->rear], item);
if(q->front==-1)
q->front++;
}
}
void receiver(CQUEUE *q)
{
char *del;
if(q->front==-1)
printf("\nThe Queue is Empty\n");
else
{
del = q->data[q->front];
printf("\nThe message retrived is %s\n", del);
if(q->front == q->rear)
{
q->front = -1;
q->rear = -1;
}
else
{
q->front = (q->front+1)%SIZE;
}
}
}
void display(CQUEUE q)
{
int i;
if(q.front==-1)
printf("\nThe Queue is Empty");
else
{
printf("\nThe contents of the Queue are:\n");
for(i=q.front;i!=q.rear;i=(i+1)%SIZE)
printf("%s\n",q.data[i]);
printf("%s\n", q.data[i]);
}
}
int main()
{
char item[20];
int ch;
CQUEUE q;
q.front=-1;
q.rear=-1;
for(;;)
{
printf("\n1. Sender");
printf("\n2. Receiver");
printf("\n3. Display");
printf("\n4. Exit");
printf("\nRead Choice\n");
scanf("%d",&ch);
getchar();
switch(ch)
{
case 1: printf("\nRead Element to be sent\n");
gets(item);
sender(&q,item);
break;
case 2: receiver(&q);
break;
case 3: display(q);
break;
default: exit(0);
}
}
return 0;
}
