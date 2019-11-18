#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;

int count = 0;

node* create_node(int ele)
{
    node *nodes;
    nodes = malloc(sizeof(node));
    nodes->data = ele;
    nodes->link = NULL;
    count++;
    return nodes;
}

void push(node* *pstart,char ele)
{
    node *nodes;
    nodes = create_node(ele);
    if(*pstart==NULL)
        *pstart = nodes;
    else
    {
        nodes->link = *pstart;
        *pstart = nodes;
        nodes->data = ele;
    }
}

void pop(node* *pstart)
{
    node *nodes = *pstart;
    if(count==0)
        printf("Stack is empty\n");
    else
    {
        free(*pstart);
        *pstart = NULL;
        *pstart = nodes->link;
        count--;
    }
}

void traverse(node* *pstart)
{
    node *nodes = *pstart;
    if(count==0)
        printf("The stack is empty\n");
    else
    {
        while (nodes->link!=NULL)
        {
            printf("%d\n",nodes->data);
            nodes=nodes->link;
        }
        printf("%d\n",nodes->data);
    }
}

int main()
{
    struct node *start = NULL;

    push(&start,1);
    push(&start,2);
    push(&start,3);
    push(&start,4);
    push(&start,5);

    //pop(&start);
    //pop(&start);
    //pop(&start);
    //pop(&start);
    //pop(&start);
    
    traverse(&start);

    return 0;
}