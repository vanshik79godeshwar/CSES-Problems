#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m; cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    vector<ll> dist(n+1,LLONG_MAX);
    vector<ll> count(n+1,0);

    vector<ll> minFlights(n+1,LLONG_MAX);
    vector<ll> maxFlights(n+1,LLONG_MIN);
    vector<bool> visited(n+1,false);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    dist[1]=0;
    count[1]=1;
    minFlights[1]=0;
    maxFlights[1]=0;
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        ll cost = node.first;
        ll u = node.second;
        if(visited[u]) continue;
        visited[u]=true;

        if(cost>dist[u]) continue;
        for(auto nb : adj[u]){
            ll v = nb.first;
            ll w = nb.second;
            ll nd = cost + w;
            if(nd == dist[v]){
                count[v] = (count[v] + count[u])%1000000007;
                minFlights[v] = min(minFlights[v],minFlights[u]+1);
                maxFlights[v] = max(maxFlights[v],maxFlights[u]+1);
            }
            else if(nd < dist[v]){
                dist[v] = nd;
                count[v] = count[u];
                minFlights[v] = minFlights[u]+1;
                maxFlights[v] = maxFlights[u]+1;
                pq.push({dist[v],v});
            }
        }
    }
    cout<<dist[n]<<" "<<count[n]<<" "<<minFlights[n]<<" "<<maxFlights[n]<<endl;
    return 0;
}