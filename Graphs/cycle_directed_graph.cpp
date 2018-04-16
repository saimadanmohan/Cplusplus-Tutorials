#include <iostream>
#include <vector>
using namespace std;
class Graph{
	int v;
	vector<vector<int> > adj_list;
	bool is_cycle_exists(int v,vector<bool> &visited,vector<bool> &rec_visited);
public:
	Graph(int v);
	void add_edge(int v,int w);
	bool is_cyclic();
};


Graph::Graph(int v){
	this->v = v;
	for(int  i = 0; i < v;  i++)
		this->adj_list.push_back({});
}
void Graph::add_edge(int v,int w){
	this->adj_list[v].push_back(w);
}



//   0 
//  / \
// 1   2
//  \3/

// 3->0


// 0 1 2 3
// f f f f
// f f f f


bool Graph::is_cycle_exists(int v,vector<bool> &visited,vector<bool> &rec_visited){
	if(!visited[v]){
		visited[v] = true;
		rec_visited[v] = true;
		for(auto c:adj_list[v]){
			if(!visited[c] && is_cycle_exists(c,visited,rec_visited))
				return true;
			else if(rec_visited[c])
				return true;
		}
	}
	rec_visited[v] = false;
	return false;
}

bool Graph::is_cyclic(){
	std::vector<bool> visited(this->v,false);
	std::vector<bool> rec_stack(this->v,false);

	for(int i = 0; i < v; i++){
		if(is_cycle_exists(i,visited,rec_stack))
			return true;
	}
	return false;
}
 //  	  0
 // 	/   \
	// 1 - 2 - 0
	//     \
	//      3--
	//      |__|




int main(){
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
 
    if(g.is_cyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}