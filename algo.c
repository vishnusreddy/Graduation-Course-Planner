#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

//Stack Functions
int top = -1;
int count = 0;
void push(int arr[], int ele)
{
    arr[++top] = ele;
}
int pop(int arr[])
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return arr[top--];
    }
}

//Graph implementation
node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(node *));
    graph->visited = malloc(vertices * sizeof(bool));
    graph->indegree = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
        graph->indegree[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    graph->indegree[dest]++;
}

void show(int arr[])
{
    int c = 0;
    if (top == -1)
    {
        printf("The stack is empty.\n");
    }
    for (int i = 0; i <= top; i++)
    {
        if (c % 4 == 0)
            printf("\n");
        if (arr[i] != 0)
        {
            printf("%d\t", arr[i]);
            c++;
        }
    }
    printf("\n\n");
}

void findAllTopologicalOrders(Graph *graph, int *stack)
{
    //for every vertex

    for (int v = 0; v < graph->numVertices; v++)
    {
        //Proceed if indegree is 0 and not yet visited

        if (graph->indegree[v] == 0 && !graph->visited[v])
        {
            struct node *adjList = graph->adjLists[v];

            while (adjList != NULL)
            {

                int connectedVertex = adjList->vertex;
                graph->indegree[connectedVertex]--;
                adjList = adjList->next;
            }

            push(stack, v);
            graph->visited[v] = true;

            //Now recursively call this function
            findAllTopologicalOrders(graph, stack);

            //Now backtracking
            adjList = graph->adjLists[v];
            while (adjList != NULL)
            {

                graph->indegree[adjList->vertex]++;
                adjList = adjList->next;
            }
            pop(stack);
            graph->visited[v] = false;
        }
    }
    if (top == (graph->numVertices - 1))
    {
        show(stack);
    }
}

void printAllTopologicalOrders(Graph *graph)
{
    int *stack;
    stack = calloc(graph->numVertices, sizeof(int));
    findAllTopologicalOrders(graph, stack);
}