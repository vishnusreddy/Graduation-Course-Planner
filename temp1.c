#include <stdio.h>
#include <stdlib.h>//include "graph.h"
//adjacency list element
struct graph_node {
    struct graph_node *link;
    int v;
};
typedef struct graph_node graph_node;
struct graph {
    int n;   // # of vertices
    int edgeCount;  // # of edges
    graph_node **alist;
};
typedef struct graph Graph;

Graph *graphCreate(int n)
{
    Graph *g = malloc(sizeof(Graph));
    g->n = n;
    g->edgeCount = 0;
    g->alist = calloc(n, sizeof(graph_node *));
    return g;
}

void graphAddEdge(Graph *g, int u, int v)
{
    graph_node *e = malloc(sizeof(graph_node));
    e->v = v;
    e->link = g->alist[u];
    g->alist[u] = e;
    g->edgeCount++;
}

void readgraph(Graph *g)
{   int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==-1)&&(j==-1))
           break;
        graphAddEdge(g,i,j);
    }

}

void graphDestroy(Graph *g)
{
    for(int u = 0; u < g->n; u++) {
        while(g->alist[u]) {
            graph_node *nextnode = g->alist[u]->link;
            free(g->alist[u]);
            g->alist[u] = nextnode;
        }
    }
    free(g->alist);
    free(g);
}

int graphSize(const Graph *g)
{
    return g->n;
}

int graphEdgeCount(const Graph *g)
{
    return g->edgeCount;
}

void dfs(Graph *g,int v,int *visited, int *departed,int time)
{
    graph_node *p;
    time++;
    int w;
    visited[v]=1;
    printf("%d ",v);
   
    for(p=(g->alist[v]);p!=NULL;p=(p->link))
    {
      w=p->v;
      if(visited[w]==0)//not visited
        dfs(g,w,visited,departed,time);
    }
    departed[time]=v;
    time++;
}

void doTopologicalSort(Graph *g,int *visited, int *departed)
{
    int time=0;
    for(int i=0;i<g->n;i++)
    {
        if(!visited[i])
        {
            dfs(g,i,visited,departed,&time);
        }
    }
    for(int i= (2*(g->n)-1);i>=0;i--)
        if(departed[i]!=0)
            printf("%d ",departed[i]);

}
//////////////////////////////////////////////////////////////////////
int main()
{
   int i,v,k,n,src;    
   printf("Enter the number of vertices..");
   scanf("%d",&n);
   Graph *g = graphCreate(n);
   readgraph(g);
   int *visited;
   int *departed;
   visited=calloc(sizeof(int),n);
   departed=calloc(sizeof(int),n);
   doTopologicalSort(g,visited,departed);
   printf("The vertices reachable from %d using DFS are..\n",src);
   
   for(i=0;i<n;i++)
       visited[i]=0;
  
}