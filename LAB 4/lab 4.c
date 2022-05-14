#include <stdio.h>
#include <stdlib.h>
struct node
{
int co,po;
struct node *addr;
};
typedef struct node * NODE;
NODE insertend(NODE start, int co, int po)
{
NODE temp, curr;
temp = (NODE) malloc(sizeof(struct node));
temp->co = co;
temp->po = po;
temp->addr = NULL;
if(start==NULL)
return temp;
curr = start;
while(curr->addr!=NULL)
{
curr=curr->addr;
}
curr->addr = temp;
return start;
}
void display(NODE start)
{
NODE temp;
temp = start;
if(start==NULL)
printf("\nPolynomial is Empty");
else
{
while(temp->addr!=NULL)
{
printf("\n%d*X^%d+", temp->co, temp->po);
temp = temp->addr;
}
printf("\n%d*X^%d", temp->co, temp->po);
}
}
NODE addterm(NODE res, int co, int po)
{
int flag=0;
NODE temp, curr;
temp = (NODE)malloc(sizeof(struct node));
temp->co = co;
temp->po = po;
temp->addr = NULL;
if(res==NULL)
return temp;
curr = res;
while(curr!=NULL)
{ if(curr->po == po)
{
curr->co = curr->co + co;
flag = 1;
}
curr = curr->addr;
}
if(flag==0)
{
curr = res;
while(curr->addr!=NULL)
curr = curr->addr;
curr->addr = temp;
}
return res;
}
NODE multiplypoly(NODE poly1, NODE poly2)
{
NODE first, second, res = NULL;
for(first = poly1; first!=NULL; first = first->addr )
for(second = poly2; second!=NULL; second = second->addr)
res = addterm(res, first->co*second->co, first->po+second->po);
return(res);
}
int main()
{
NODE poly = NULL,poly2 = NULL, res =NULL;
int i,n,co,po;
printf("\nRead the number of terms of 1st Polynomial");
scanf("%d", &n);
for(i=1;i<=n;i++)
{
printf("Read co and po of %d terms", i);
scanf("%d%d",&co,&po);
poly = insertend(poly,co,po);
}
printf("\nThe first polynomial is \n");
display(poly);
printf("\nRead the number of terms of 2nd Polynomial");
scanf("%d", &n);
for(i=1;i<=n;i++)
{
printf("Read co and po of %d terms", i);
scanf("%d%d",&co,&po);
poly2 = insertend(poly2,co,po);
}
printf("\nThe second polynomial is \n");
display(poly2);
res = multiplypoly(poly,poly2);
printf("\nThe resultant polynomial is \n");
display(res);
return 0;
}
