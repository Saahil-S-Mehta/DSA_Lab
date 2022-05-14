#include<stdio.h>
#include<stdlib.h>

struct node{
int row,col,data;
struct node *next;
struct node *prev;
};
typedef struct node *NODE;

NODE insert_end(NODE start,int row,int col,int item)
{
    NODE temp, curr;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->row = row;
    temp->col = col;
    temp->next = NULL;
    temp->prev = NULL;
    if(start == NULL)
        return temp;
    curr = start;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return start;
}

void display(NODE start)
{
    NODE temp;
    if(start == NULL)
        printf("\nList is Empty");
    else
    {
        printf("\n\nROW\tCOL\tDATA\n");
        temp = start;
        while(temp != NULL)
        {
            printf("%d\t%d\t%d\n",temp->row,temp->col,temp->data);
            temp = temp->next;
        }
    }
}

void display_matrix(NODE start, int m, int n)
{
    NODE temp;
    int i,j;
    temp = start;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(temp != NULL && temp->row == i && temp->col == j)
            {
                printf("%d\t",temp->data);
                temp = temp->next;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main()
{
    NODE start = NULL;
    int m,n,i,j,item;
    printf("Enter order of Matrix:\t");
    scanf("%d %d",&m,&n);
    printf("\nEnter matrix elements\n");
    for(i=1;i<=m;i++)
    {
       for(j=1;j<=n;j++)
       {
           scanf("%d",&item);
           if(item != 0)
            start = insert_end(start,i,j,item);
       }
    }
    printf("\n\n");
    display(start);
    printf("\n\n");
    display_matrix(start,m,n);
    return 0;
}
