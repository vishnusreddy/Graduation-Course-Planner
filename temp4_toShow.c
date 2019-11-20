// http://pythontutor.com/c.html#code=//Including%20all%20Libraries%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%23include%20%3Cstdbool.h%3E%0A//Stack%20Functions%0Aint%20top%20%3D%20-1%3B%0Aint%20stack%5B60%5D%3B%0Avoid%20push%28int%20arr%5B%5D,%20int%20ele%29%0A%7B%0A%20%20%20%20arr%5B%2B%2Btop%5D%20%3D%20ele%3B%0A%7D%0Aint%20pop%28int%20arr%5B%5D%29%0A%7B%0A%20%20%20%20if%20%28top%20%3D%3D%20-1%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20return%20-1%3B%0A%20%20%20%20%7D%0A%20%20%20%20else%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20return%20arr%5Btop--%5D%3B%0A%20%20%20%20%7D%0A%7D%0A%0A//Graph%20implementation%0Atypedef%20struct%20node%0A%7B%0A%20%20%20%20int%20vertex%3B%0A%20%20%20%20struct%20node%20*next%3B%0A%7D%20node%3B%0Atypedef%20struct%20Graph%0A%7B%0A%20%20%20%20int%20numVertices%3B%0A%20%20%20%20bool%20*visited%3B%0A%20%20%20%20struct%20node%20**adjLists%3B%20//%20we%20need%20int**%20to%20store%20a%20two%20dimensional%20array.%20Similary,%20we%20need%20struct%20node**%20to%20store%20an%20array%20of%20Linked%20lists%0A%7D%20Graph%3B%0Anode%20*createNode%28int%20v%29%0A%7B%0A%20%20%20%20struct%20node%20*newNode%20%3D%20malloc%28sizeof%28struct%20node%29%29%3B%0A%20%20%20%20newNode-%3Evertex%20%3D%20v%3B%0A%20%20%20%20newNode-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20return%20newNode%3B%0A%7D%0AGraph%20*createGraph%28int%20vertices%29%0A%7B%0A%20%20%20%20struct%20Graph%20*graph%20%3D%20malloc%28sizeof%28struct%20Graph%29%29%3B%0A%20%20%20%20graph-%3EnumVertices%20%3D%20vertices%3B%0A%20%20%20%20graph-%3EadjLists%20%3D%20malloc%28vertices%20*%20sizeof%28node%20*%29%29%3B%0A%20%20%20%20graph-%3Evisited%20%3D%20malloc%28vertices%20*%20sizeof%28bool%29%29%3B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20i%20%3C%20vertices%3B%20i%2B%2B%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20graph-%3EadjLists%5Bi%5D%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20graph-%3Evisited%5Bi%5D%20%3D%20false%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20graph%3B%0A%7D%0Avoid%20addEdge%28struct%20Graph%20*graph,%20int%20src,%20int%20dest%29%0A%7B%0A%20%20%20%20//%20Add%20edge%20from%20src%20to%20dest%0A%20%20%20%20struct%20node%20*newNode%20%3D%20createNode%28src%29%3B%0A%20%20%20%20newNode-%3Enext%20%3D%20graph-%3EadjLists%5Bdest%5D%3B%0A%20%20%20%20graph-%3EadjLists%5Bdest%5D%20%3D%20newNode%3B%0A%7D%0Avoid%20topologicalSortUtil%28int%20v,%20Graph%20*g%29%0A%7B%0A%20%20%20%20g-%3Evisited%5Bv%5D%20%3D%20true%3B%0A%20%20%20%20struct%20node%20*adjList%20%3D%20g-%3EadjLists%5Bv%5D%3B%0A%20%20%20%20struct%20node%20*temp%20%3D%20adjList%3B%0A%20%20%20%20while%20%28temp%20!%3D%20NULL%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20int%20connectedVertex%20%3D%20temp-%3Evertex%3B%0A%20%20%20%20%20%20%20%20if%20%28!g-%3Evisited%5BconnectedVertex%5D%29%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20topologicalSortUtil%28connectedVertex,%20g%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20temp%20%3D%20temp-%3Enext%3B%0A%20%20%20%20%7D%0A%20%20%20%20push%28stack,%20v%29%3B%0A%7D%0Avoid%20topologicalSort%28Graph%20*g%29%0A%7B%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20g-%3EnumVertices%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20if%20%28g-%3Evisited%5Bi%5D%20%3D%3D%20false%29%0A%20%20%20%20%20%20%20%20%20%20%20%20topologicalSortUtil%28i,%20g%29%3B%0A%20%20%20%20while%20%28pop%28stack%29%20!%3D%20-1%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%25d%20%22,%20pop%28stack%29%29%3B%0A%20%20%20%20%7D%0A%7D%0A//Main%20Function%20to%20call%20all%20other%20functions%0Aint%20main%28%29%0A%7B%0A%20%20%20%20Graph%20*graph%20%3D%20createGraph%286%29%3B%0A%20%20%20%20addEdge%28graph,%205,%202%29%3B%0A%20%20%20%20addEdge%28graph,%205,%200%29%3B%0A%20%20%20%20addEdge%28graph,%204,%200%29%3B%0A%20%20%20%20addEdge%28graph,%204,%201%29%3B%0A%20%20%20%20addEdge%28graph,%202,%203%29%3B%0A%20%20%20%20addEdge%28graph,%203,%201%29%3B%0A%20%20%20%20topologicalSort%28graph%29%3B%0A%7D%0A&curInstr=118&mode=display&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D

//Including all Libraries
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
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct node *newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void dfs(int v, Graph *g)
{
    g->visited[v] = true;
    struct node *adjList = g->adjLists[v];
    while (adjList != NULL)
    {
        
        int connectedVertex = adjList->vertex;
        if (!g->visited[connectedVertex])
        {
            dfs(connectedVertex, g);
        }
        adjList = adjList->next;
    }
    push(stack, v);
    count++;
}
void topologicalSort(Graph *g)
{
    for (int i = 0; i < g->numVertices; i++)
        if (g->visited[i] == false)
            dfs(i, g);
   
}

//Main Function to call all other functions
int main()
{
    int numberofsubjects;
    printf("Enter the number of subjects :\n");
    scanf("%d",&numberofsubjects);

    Graph *graph = createGraph(numberofsubjects);
    printf("Enter the prerequisite in case there is any.");
    printf("Enter -1 -1 to end.\n");
    while(1)
    {
        int a,b;
        printf("Enter subject code and its pre-requisite :\n");
        scanf("%d %d",&a,&b);
        if(a==-1)
        {
            break;
        }
        addEdge(graph,b,a);

    }
    topologicalSort(graph);
    int n=0;
    int *arr=malloc(count*sizeof(int));
    for(int i=0;i<count;i++)
    {
        arr[i]=pop(stack);
    }
    int j=0;
    for(int i=count-1;i>=0;i--)
    {
        if(j%4==0)
        printf("\n");
        printf("%d ",arr[i]);
        j++;
    }
}
