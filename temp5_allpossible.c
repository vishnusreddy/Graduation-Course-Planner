#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Stack Functions
int top = -1;
int stack[60];
int count=0;
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
typedef struct node
{
    int vertex;
    struct node *next;
} node;
typedef struct Graph
{
    int numVertices;
    bool *visited;
    int *indeg;
    struct node **adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
} Graph;
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
    graph->indeg=malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
        graph->indeg[i]=0;
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct node *newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
    graph->indeg[dest]++;
}

void dfsutil(Graph *g)
{

}

dfs(Graph *g)
{
    int *res=malloc(g->numVertices*sizeof(int));
    dfsutil(g);
}

int main()
{
	Graph *graph = createGraph(6);
	addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
 
	//here the final answer
	printf("All Topological Sort: \n");
	dfs(graph);
 
	return 0;
}
