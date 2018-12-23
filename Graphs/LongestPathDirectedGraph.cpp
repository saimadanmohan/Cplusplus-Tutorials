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

	vector<int> computeIndegree() {
		vector<int> indegree(vertexCount, 0);
		for(auto itr: adjList) {
			//vector<int> children = adjList[itr.first];
			for(auto c: itr.second) {
				indegree[c]++;
			}
		}
		return indegree;
	}

	vector<int> findLongestPath() {
		vector<int> indegree = computeIndegree();
		vector<int> rank(vertexCount);
		queue<int> que;
		for(int i = 0; i < indegree.size(); i++) {
			if(indegree[i] == 0) {
				que.push(i);
			}
			rank[i] = 0;
		}
		while(!que.empty()) {
			int sz = que.size();
			while(sz > 0) {
				int v = que.front();
				que.pop();
				for(auto ch: adjList[v]) {
					indegree[ch]--;
					if(indegree[ch] == 0) {
						que.push(ch);
						rank[ch] = rank[v] + 1;
					}
				}
				sz--;
			}
		}
		int maxRankVertex;
		int maxRank = 0;
		for(int i = 0; i < rank.size(); i++) {
			if(rank[i] > maxRank) {
				maxRank = rank[i];
				maxRankVertex = i;
			}
		}
		map<int, vector<int>> rankMap;
		for(int i = 0; i < rank.size(); i++) {
			rankMap[rank[i]].push_back(i);
		} 
		///cout<<"maxRank:"<<maxRank<<endl;
		//cout<<"maxRankVertex:"<<maxRankVertex<<endl;
		vector<int> result;
		result.push_back(maxRankVertex);
		while(maxRank != 0) {
			maxRank -= 1;
			for(auto ch: rankMap[maxRank]) {
				if(std::find(adjList[ch].begin(), adjList[ch].end(), maxRankVertex) != adjList[ch].end()) {
					maxRankVertex = ch;
					result.push_back(maxRankVertex);
					break;
				}
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
int main() {
	Graph g;
	g.addEdge(make_pair(2,3));
	g.addEdge(make_pair(0,2));
	g.addEdge(make_pair(1,2));
	//g.addEdge(make_pair(2,3));
	vector<int> longestPath = g.findLongestPath();
	for(auto v: longestPath) {
		cout<<v<<" ";
	}
	cout<<endl;

	return 0;
}

// V Vertices
// Time Complexity - O(V + E)
// Space Complexity - O(V + E)