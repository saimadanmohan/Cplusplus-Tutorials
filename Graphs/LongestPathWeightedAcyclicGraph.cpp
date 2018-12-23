#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
class Graph {
	map<int,vector<int> > adjList;
	map<pair<int,int>, int> weightMap;
	set<int> distinctVertices;
	int vertexCount;
	public:
	Graph() {
		vertexCount = 0;
	}
	void addEdge(pair<int,int> edge, int weight) {
		adjList[edge.first].push_back(edge.second);
		distinctVertices.insert(edge.first);
		distinctVertices.insert(edge.second);
		weightMap[edge] = weight;
		vertexCount = distinctVertices.size();
	}

	int getSourceNode() {
		vector<int> indegree(vertexCount, 0);
		for(auto itr: adjList) {
			for(auto c: itr.second) {
				indegree[c]++;
			}
		}
		for(int i = 0; i < indegree.size(); i++) {
			if(indegree[i] == 0) {
				return i;
			}
		}
		return -1;// error
	}

	void topoSort(vector<bool>& visited, stack<int>& stck, int node) {
		visited[node] = true;
		for(auto ch: adjList[node]) {
			if(!visited[ch]) {
				topoSort(visited, stck, ch);
			}
		}
		stck.push(node);
	}

	vector<int> longestPath(vector<int>& next, int node, int src) {
		vector<int> result;
		result.push_back(node);
		while(src != node) {
			result.push_back(next[node]);
			node = next[node];
		}
		reverse(result.begin(), result.end());
		return result;
	}

	vector<int> findLongestPath() {
		stack<int> stck;
		vector<int> distance(vertexCount, INT_MIN);
		vector<bool>  visited(vertexCount, false);
		vector<int>  next(vertexCount);
		for(int i = 0; i < visited.size(); i++)  {
			next[i] = i;
			if(!visited[i]) {
				topoSort(visited, stck, i);
			}
		}
		int srcNode = getSourceNode();
		//cout<<"srcNode: "<<srcNode<<endl;
		distance[srcNode] = 0;
		while(!stck.empty()) {
			int node = stck.top();
			stck.pop();
			if(distance[node] != INT_MIN) {
				for(auto ch: adjList[node]) {
					int weight = weightMap[make_pair(node, ch)];
					if(distance[ch] < distance[node] + weight) {
						distance[ch] = distance[node] + weight;
						next[ch] = node;
					}
				}
			}
		}
		int maxDistance = INT_MIN;
		int maxIndex = 0;
		for(int i = 0; i < distance.size(); i++) {
			//cout<<distance[i]<<" ";
			if(distance[i] > maxDistance) {
				maxDistance = distance[i];
				maxIndex = i;
			}
		}
		// cout<<endl;
		// cout<<"maxIndex:"<<" "<<maxIndex<<endl;
		// cout<<"maxDistance:"<<" "<<maxDistance<<endl;
		// for(int i = 0; i < next.size(); i++) { 
		// 	cout<<next[i]<<" ";
		// }
		// cout<<endl;
		return longestPath(next, maxIndex, srcNode);
	}
};
int main() {
	Graph g;
	g.addEdge(make_pair(2,4), 4);
	g.addEdge(make_pair(2,5), 2);
	g.addEdge(make_pair(2,3), 7);
	g.addEdge(make_pair(3,4), -1);
	g.addEdge(make_pair(4,5), -2);
	g.addEdge(make_pair(3,5), 1);
	g.addEdge(make_pair(0,1), 5);
	g.addEdge(make_pair(0,2), 3);
	g.addEdge(make_pair(1,3), 6);
	g.addEdge(make_pair(1,2), 2);
	vector<int> path = g.findLongestPath();
	for(auto v: path) {
		cout<<v<<" ";
	}
	cout<<endl;
	return 0;
}

// V Vertices
// Time Complexity - O(V + E)