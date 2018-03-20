#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int> > pr;



int find(int v,unordered_map<int,int>& parentMap){
    if(parentMap[v] != v){
        parentMap[v] = find(parentMap[v],parentMap);
    }
    return parentMap[v];
}

void merge(unordered_map<int,int>& parentMap,unordered_map<int,int>& rankMap,int u,int v){
    int uParent = find(u,parentMap);
    int vParent = find(v,parentMap);
    if(rankMap[u] > rankMap[v]){
        parentMap[v] = uParent;
    }else
        parentMap[u] = vParent;
    if(rankMap[uParent] == rankMap[vParent])
        rankMap[vParent]++;
}


int mst(int n, vector < vector<int> >& edges) {
    // Complete this function
    priority_queue<pr,vector<pr>,greater<pr>> pq;
    unordered_map<int,int> parentMap;
    unordered_map<int,int> rankMap;
    for(int i = 0;i<edges.size();i++){
        parentMap[edges[i][0]] = edges[i][0];
        parentMap[edges[i][1]] = edges[i][1];
        rankMap[edges[i][0]] = 0;
        rankMap[edges[i][1]] = 0;        
        pq.push(make_pair(edges[i][2],make_pair(edges[i][0],edges[i][1])));
    }
    int sum= 0;
    int limit = parentMap.size()-1;
    int edgeCount = 0;
    while(edgeCount < limit){    
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        int weight =  pq.top().first;
        pq.pop();
        
        int p1 = find(node1,parentMap);
        int p2 = find(node2,parentMap);
        if(p1 != p2) {
            //cout<<node1<<" "<<node2<<" "<<sum<<endl;
            //cout<<parentMap[node1]<<" "<<parentMap[node2]<<" "<<endl;
            sum += weight;
            edgeCount++;
            merge(parentMap,rankMap,p1,p2);
        }

    }
    return sum;
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
    int result = mst(n, edges);
    cout << result << endl;
    return 0;
}
