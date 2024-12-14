#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> dijkstra(int src, vector<vector<pair<int,ll>>>& adj){
    // cout<<"functoin called..."<<endl;
    int n = adj.size()-1;
    vector<ll> dist(n+1,1e18);
    set<pair<ll,int>> s;
    s.insert({0,src});
    dist[src]=0;
    while(!s.empty()){
        auto node = *s.begin();
        s.erase(node);
        ll dst=node.first, u=node.second;
        for(auto nb:adj[u]){
            ll v=nb.first, wt=nb.second;
            if(dst + wt < dist[v]){
                if(dist[v]!=1e18) s.erase({dist[v],v});
                dist[v] = dst+wt;
                s.insert({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,ll>>> adj1(n+1);
    vector<vector<pair<int,ll>>> adj2(n+1);
    vector<vector<ll>> edges(m,vector<ll>(3));
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        adj1[a].push_back({b,c});
        adj2[b].push_back({a,c});
        edges[i] = {a,b,c};
        // cout<<a<<b<<c<<endl;
    }
    // for(auto e:edges){
    //     cout<<e[0]<<" "<<e[1]<<" "<<e[2]<<endl;
    // }

    vector<ll> predist = dijkstra(1,adj1);
    vector<ll> postdist = dijkstra(n,adj2);
    // for(auto x:predist) cout<<x<<" ";
    // cout<<endl;
    // for(auto x:postdist) cout<<x<<" ";
    // cout<<endl;
    ll ans = 1e18;
    for(auto e:edges){
        ll u=e[0],v=e[1],w=e[2];
        ans = min(ans,predist[u]+postdist[v]+w/2);
    }
    cout<<ans<<endl;
    return 0;
}

