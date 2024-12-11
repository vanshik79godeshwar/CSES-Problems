#include<bits/stdc++.h>
using namespace std;
bool flag = false;
vector<int> res;
bool dfs(int node, vector<bool>& vis, vector<vector<int>>& adj,int par){
    vis[node]=true;
    for(int nb:adj[node]){
        if(flag) break;
        if(nb!=par){
            if(vis[nb]){
                res.push_back(nb);
                res.push_back(node);
                flag=true;
                return true;
            }
            if(dfs(nb,vis,adj,node)){
                res.push_back(node);
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m ; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bool check = dfs(i,vis,adj, -1);
            if(flag) break;
        }
    }
    if(res.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> ans;
    int start = res[0];
    ans.push_back(start);
    for(int i=1;i<res.size();i++){
        if(res[i]==start){
            ans.push_back(res[i]);
            break;
        }
        else ans.push_back(res[i]);
    }
    cout<<ans.size()<<endl;
    for(auto y:ans) cout<<y<<" ";
    return 0;
}