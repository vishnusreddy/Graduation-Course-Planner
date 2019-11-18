#include<stdio.h>
#include<stdlib.h>

int top = -1;

void push(int arr[], int ele)
{
    arr[++top] = ele;
}

void pop(int arr[])
{
    if(top == -1)
    {
        printf("Stack is empty.");
    }
    else
    {
        arr[top--];
    }
}

void show(int arr[])
{
    if(top == -1)
    {
        printf("The stack is empty.\n");
    }
    for(int i = top; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{

    int *stack = malloc(sizeof(int) * 5);
    int ele;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    //pop(stack);
    //pop(stack);
    //pop(stack);
    //pop(stack);
    //pop(stack);

    show(stack);

    return 0;
}