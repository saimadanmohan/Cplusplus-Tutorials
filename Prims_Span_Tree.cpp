#include <bits/stdc++.h>

using namespace std;

int prims(int n, vector < vector<int> > edges, int start) {
    unordered_map<int,vector<pair<int,int> > > mp;
    unordered_map<int,long> minWeight;
    unordered_map<int,bool> minSpanTree;
    unordered_map<int,int> parentMap;
    for(int edges_i = 0;edges_i < edges.size();edges_i++){
        mp[edges[edges_i][0]].push_back(make_pair(edges[edges_i][1],edges[edges_i][2]));
        mp[edges[edges_i][1]].push_back(make_pair(edges[edges_i][0],edges[edges_i][2]));
        minWeight[edges[edges_i][0]] = (long)INT_MAX+1;
        minWeight[edges[edges_i][1]] = (long)INT_MAX+1;
        minSpanTree[edges[edges_i][0]] = false;
        minSpanTree[edges[edges_i][1]] = false;
        //parentMap[edges[edges_i][0]] = false;
        //parentMap[edges[edges_i][1]] = false;
    }
    priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    minWeight[start] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        minSpanTree[node] = true;
        for(auto edgeVertex : mp[node]){
            int vertex = edgeVertex.first;
            int currEdgeWeight = edgeVertex.second;
            if(minSpanTree[vertex] == false && minWeight[vertex] > currEdgeWeight){
                //parentMap[vertex] = node;
                minWeight[vertex] = currEdgeWeight;
                pq.push(make_pair(currEdgeWeight,vertex));
            }
        }
    }
    long ans = 0;
    for(auto it:minSpanTree){
        ans += minWeight[it.first];
    }
    return (int) ans;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector< vector<int> > edges(m,vector<int>(3));
    for(int edges_i = 0;edges_i < m;edges_i++){
       for(int edges_j = 0;edges_j < 3;edges_j++){
          cin >> edges[edges_i][edges_j];
       }
    }
    int start;
    cin >> start;
    int result = prims(n, edges, start);
    cout << result << endl;
    return 0;
}
