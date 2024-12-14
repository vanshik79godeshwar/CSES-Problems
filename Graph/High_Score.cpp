#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n,m; cin>>n>>m;
    // vector<vector<int>> adj(n+1);
    vector<vector<int>> edge(m,vector<int>(3));
    for(int i=0;i<m;i++){
        int a,b,x; cin>>a>>b>>x;
        edge[i] = {a,b,x};
    }
    // for(auto e:edge){
    //     for(auto  x:e) cout<<x<<" ";
    //     cout<<endl;
    // }
    vector<long long> dist(n+1,-1e17);
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(auto& e : edge){
            ll u=e[0],v=e[1],w=e[2];
            if(dist[u]!=-1e17 && dist[u]+w > dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }
    vector<bool> reach(n+1,true);
    for(auto& e:edge){
        ll u=e[0],v=e[1],w=e[2];
        if(dist[u]+w > dist[v]){
            reach[v]=false;
        }
        if(!reach[u]) reach[v]=false;
        if(!reach[v]) reach[u]=false;
    }
    if(!reach[n]){
        cout<<-1<<endl;
        return 0;
    }
    cout<<dist[n]<<endl;
    return 0;
}