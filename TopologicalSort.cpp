// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;
 
// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency listsList
    list<int> *adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
     // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of the complete graph
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::topologicalSortUtil(int v, vector<bool>& visited, 
                                stack<int> &stck)
{
    visited[v] = true;
    for(auto i:adj[v]){
        if(!visited[i])
            topologicalSortUtil(i,visited,stck);
    }
    stck.push(v);
}
void Graph::topologicalSort()
{
    stack<int> stck;
    std::vector<bool> visited(V,false);

    for(int i=V-1;i>=0;i--)
        if(!visited[i])
            topologicalSortUtil(i,visited,stck);

    while(!stck.empty()){
        cout<<stck.top()<<" ";
        stck.pop();
    }
}
// Driver program to test above functions
int main()
{
    Graph g(6);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 1);

 
    cout << "Following is a Topological Sort of the given graph n";
    g.topologicalSort();
 
    return 0;
}