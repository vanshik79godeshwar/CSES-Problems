#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<long long,long long>>> adj(n+1);
    for(int i=0;i<m;i++){
        long long a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
        // adj[b].push_back({a,c});
    } 
    vector<long long> dist(n+1,1e18);
    set<pair<long long,long long>> s;
    s.insert({0,1});
    dist[1]=0;
    while(!s.empty()){
        auto node = *s.begin();
        s.erase(node);
        long long weight = node.first;
        long long ele = node.second;
        for(auto nb:adj[ele]){
            long long nbn = nb.first;
            long long dt = nb.second;
            if(weight+dt < dist[nbn]){
                if(dist[nbn]!=1e18) s.erase({dist[nbn],nbn});
                dist[nbn] = weight+dt;
                s.insert({dist[nbn],nbn});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    return 0;
}