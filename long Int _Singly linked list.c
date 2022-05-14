#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
int data;
struct node *addr;
};
typedef struct node * NODE;
NODE insertbegin(NODE head, int item)
{
NODE temp;
temp = (NODE) malloc(sizeof(struct node));
temp->data = item;
temp->addr = head->addr;
head->addr = temp;
return head;
}
NODE insertend(NODE head, int item)
{
NODE temp, curr;
temp = (NODE) malloc(sizeof(struct node));
temp->data = item;
temp->addr = NULL;
if(head->addr==NULL)
{
head->addr = temp;
return head;
}
curr = head->addr;
while(curr->addr!=NULL)
curr = curr->addr;
curr->addr = temp;
return head;
}
void display(NODE head)
{
NODE temp = NULL;;
if(head->addr==NULL)
printf("The List is Empty");
else
{
temp = head->addr;
printf("\n");
while(temp!=NULL)
{
printf("%d",temp->data);
temp = temp->addr;
}
}
}
void addzero(NODE head1, NODE head2)
{
int ct1 = 1, ct2 = 1, i;
NODE t1, t2;
t1 = head1->addr;
t2 = head2->addr;
while(t1!=NULL)
{
ct1++;
t1 = t1->addr;
}
while(t2!=NULL)
{
ct2++;
t2 = t2->addr;
}
if(ct1>ct2)
{
for(i=1;i<=(ct1-ct2);i++)
head2 = insertbegin(head2,0);
}
else
{
for(i=1;i<=(ct2-ct1);i++)
head1 = insertbegin(head1,0);
}
}
NODE reverse(NODE head)
{
NODE curr, prev, temp;
curr = head->addr;
prev = NULL;
temp = NULL;
while(curr!=NULL)
{
    temp = prev;
    prev = curr;
    curr = curr->addr;
    prev->addr = temp;

}
head->addr=prev;
return head;
}
void add(NODE head1, NODE head2)
{
NODE head, t1, t2;
int sum = 0, carry = 0, x;
head = (NODE)malloc(sizeof(struct node));
head->addr = NULL;
head1 = reverse(head1);
head2 = reverse(head2);
t1 = head1->addr;
t2 = head2->addr;
while(t1!=NULL&&t2!=NULL)
{
x = t1->data + t2->data +carry;
sum = x%10;
carry = x/10;
head = insertbegin(head,sum);
t1 = t1->addr;
t2 = t2->addr;
}
if(carry>0)
head = insertbegin(head, carry);
printf("\nThe Final Added Number is\n");
display(head);
}
int main()
{
char first[20], second[20];
NODE head1, head2;
head1 = (NODE) malloc(sizeof(struct node));
head2 = (NODE) malloc(sizeof(struct node));
head1->addr = NULL;
head2->addr = NULL;
printf("\nEnter the first number\n");
scanf("%s", first);
printf("\nEnter the second number\n");
scanf("%s", second);
for(int i = 0; first[i]!='\0';i++)
head1 = insertend(head1,first[i]-'0');
for(int j = 0; second[j]!='\0';j++)
head2 = insertend(head2,second[j]-'0');
printf("\nThe first number is\n");
display(head1);
printf("\nThe second number is\n");
display(head2);
addzero(head1,head2);
printf("\nThe first number is\n");
display(head1);
printf("\nThe second number is\n");
display(head2);
add(head1,head2);
return 0;
}
