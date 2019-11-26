typedef struct node
{
    int vertex;
    struct node *next;
} node;

typedef struct Graph
{
    int numVertices;
    bool *visited;
    int *indegree;
    node **adjLists;
} Graph;

void push(int [], int);
int pop(int []);
Graph* createGraph(int);
void addEdge(Graph *, int, int);
void printAllTopologicalOrders(Graph *);