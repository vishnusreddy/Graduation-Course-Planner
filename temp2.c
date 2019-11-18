#include <stdio.h>
#include <stdlib.h>
int time=0;
struct node
{
    int vertex;
    struct node* next;
};
struct node* createNode(int v);
struct Graph
{
    int numVertices;
    int* visited;
    int* depart;
    struct node** adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};
struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);
void DFS(struct Graph*, int, int);
void doTopologicalSort(struct Graph*,int );
int main()
{
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    
    doTopologicalSort(graph,4);
    printGraph(graph);
    
    return 0;
}
void DFS(struct Graph* graph, int vertex, int time) {
        struct node* adjList = graph->adjLists[vertex];
        struct node* temp = adjList;
        
        graph->visited[vertex] = 1;
        time++;
        graph->depart[(time)]=vertex;
    
        while(temp!=NULL) {
            int connectedVertex = temp->vertex;
        
            if(graph->visited[connectedVertex] == 0) {
                DFS(graph, connectedVertex,time);
            }
            temp = temp->next;
        }
        
        time++;       
}
void doTopologicalSort(struct Graph* graph, int n)
{
    
    for(int i=0;i<n;i++)
    {
        if(!graph->visited[i])
        {
            DFS(graph, i, time);
        }
    }
    //Now printing the order in which they are visited
    for(int i = 2*n-1; i>=0;i--)
    {
        if(graph->depart[i]!=0)
        {
            printf("%d ",graph->depart[i]);
        }
    }
}
 
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    graph->depart=calloc(2*vertices,sizeof(int));
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
