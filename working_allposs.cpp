#include<bits/stdc++.h>
using namespace std;
 
 
class Graph
{
	int V;
	list<int> *adj;
	vector<int> indeg;
	void dfsUtil(vector<int>& res,bool visited[]);
public:
	/*constructor*/
	Graph(int v)
	{
		V = v;
		adj = new list<int>[v];
		for(int i=0;i<v;i++)
			indeg.push_back(0);
	}
	/*destructor for no memory leakage */
	~Graph()
	{
		delete[] adj;
		indeg.clear();
	}
	void dfs();
	void addEdge(int u,int w);
};
 
/*adding edge to adj list to make a directed graph */
void Graph::addEdge(int u,int w)
{
	adj[u].push_back(w);
	indeg[w]++;
}
/*dfs to the indegree arr and visited arr */
void Graph::dfsUtil(vector<int>& res,bool visited[])
{
	/*instead of flag we check for if the res vector size equals to V */
	if(res.size()==V)
	{
		for(int i=0;i<V;i++)
			cout<<res[i]<<" ";
		cout<<endl;
	}
	for(int i=0;i<V;i++)
	{
		if(indeg[i]==0 && visited[i]==false)
		{
			visited[i] = true;
			res.push_back(i);
			for(auto j=adj[i].begin();j!=adj[i].end();j++)
				indeg[*j]--;
 
			dfsUtil(res,visited);
 
		/*backtracking step below */
			for(auto j=adj[i].begin();j!=adj[i].end();j++)
				indeg[*j]++;
 
		/*unmark visited nodes */
			visited[i] = false;
			res.pop_back();    //pop the last vertex
		}
	}
}
/*simple dfs with making of visited array for dfs */
void Graph::dfs()
{
	bool *visited = new bool[V]{0};
 
	vector<int> res;
 
		dfsUtil(res,visited);
 
	delete[] visited;   /*no memory leakage */
}
 
int main()
{
	Graph g(6);
	g.addEdge(5,2);
	g.addEdge(5,0);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);
 
	//here the final answer
	cout<<"All Topological Sort: \n";
	g.dfs();
 
	return 0;
}