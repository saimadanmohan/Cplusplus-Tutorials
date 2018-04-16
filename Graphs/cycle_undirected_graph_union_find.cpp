#include <iostream>
#include <vector>
using namespace std;
class Graph{
	int v;
	vector<int> parent;
	vector<pair<int,int> > edges;
	int find(int v);
	void Union(int u,int v);
public:
	Graph(int v);
	void add_edge(int v,int w);
	bool is_cyclic();
};


Graph::Graph(int v){
	this->v = v;
	for(int i = 0; i < v; i++)
		parent.push_back(i);
}

int Graph::find(int v){
	if(v != parent[v]){
		parent[v] = find(parent[v]);
	}
	return parent[v];
}

void Graph::Union(int u,int v){
	int parent_src = find(u);
	int parent_dest = find(v);
	parent[v] = parent_src;
}


bool Graph::is_cyclic(){
	for(int i = 0; i < edges.size(); i ++){
		int src = edges[i].first;
		int dest = edges[i].second;

		int parent_src = find(src);
		int parent_dest = find(dest);
		cout<<"src "<<src<<" dest "<<dest<<endl;
		cout<<"parent_src "<<parent_src<<" parent_dest "<<parent_dest<<endl;
		if(parent_src == parent_dest)
			return true;
		Union(src,dest);
	}
	return false;
}

void Graph::add_edge(int u,int v){
	edges.push_back(make_pair(u,v));
}


int main(){
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    //g.add_edge(1, 2);
    //g.add_edge(2, 0);
    g.add_edge(2, 3);
    //g.add_edge(3, 3);
 
    if(g.is_cyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}