#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> vis;
vector<bool> pathVis;
vector<vector<int>> adj;
stack<int> res;
bool flag = false;
void dfs(int node, int par){
    vis[node] = true;
    pathVis[node] = true;
    for(auto nb:adj[node]){
        if(pathVis[nb]){
            flag = true;
            return;
        }
        else if(vis[nb]) continue;
        else  dfs(nb,node);
    }
    pathVis[node] = false;
    res.push(node);
}

int main(){
    int n,m; cin>>n>>m;
    vis.resize(n+1);
    pathVis.resize(n+1);
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i,-1);
    }
    if(flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    return 0;
}