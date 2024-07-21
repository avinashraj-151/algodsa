#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100100];

void dfs(int node, int parent){

    for(auto neighbour:graph[node]){
        if(neighbour!= parent){
            dfs(neighbour, node);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}