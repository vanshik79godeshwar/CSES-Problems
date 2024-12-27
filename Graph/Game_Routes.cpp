#include<bits/stdc++.h>
using namespace std;

int main(){
    int mod = 1e9 + 7;
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> ID(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        ID[b]++;
    }
    queue<int> q;
    vector<int> topo;
    for(int i=1;i<=n;i++){
        if(ID[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto nb : adj[node]){
            ID[nb]--;
            if(ID[nb]==0) q.push(nb);
        }
    }
    vector<int> ways(n+1,0);
    ways[1]=1;
    for(auto it : topo){
        if(ways[it]==0) continue;
        for(auto nb : adj[it]){
            ways[nb]+=ways[it];
            ways[nb]%=mod;
        }
    }
    cout<<ways[n]%mod<<endl;
    return 0;
}