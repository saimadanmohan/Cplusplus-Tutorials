#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
class Graph {
	map<int,vector<int> > adjList;
	set<int> distinctVertices;
	int vertexCount;
	public:
	Graph() {
		vertexCount = 0;
	}
	void addEdge(pair<int,int> edge) {
		adjList[edge.first].push_back(edge.second);
		distinctVertices.insert(edge.first);
		distinctVertices.insert(edge.second);
		vertexCount = distinctVertices.size();
	}

	void dfs(int v, vector<bool>& visited, vector<int>& component) {
		visited[v] = true;
		component.push_back(v);
		for(auto c: adjList[v]) {
			if(!visited[c]) {
				dfs(c, visited, component);
			}
		}
	}

	vector<vector<int> > connectedComponents() {
		vector<bool> visited(vertexCount, false);
		vector<vector<int> > result;
		for(auto itr: adjList) {
			int v = itr.first;
			if(!visited[v]) {
				vector<int> component;
				dfs(v, visited, component);
				reverse(component.begin(), component.end());
				result.push_back(component);
			}
		}
		return result;
	}


};
int main() {
	Graph g;
	g.addEdge(make_pair(1,0));
	g.addEdge(make_pair(2,3));
	g.addEdge(make_pair(3,4));
	vector<vector<int> > result = g.connectedComponents();
	for(auto vec: result) {
		for(auto v: vec) {
			cout<<v<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// Time Complexity - O(V + E) 
// Space Complexity - O(V + E)