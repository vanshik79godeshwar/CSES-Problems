#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,m,k; cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    vector<vector<long long>> dist(n+1,vector<long long>(k,1e17));
    dist[0][0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        ll cost = node.first;
        ll ele = node.second;
        if(dist[ele][k-1] < cost) continue;
        for(auto nb : adj[ele]){
            ll ew = nb.second, nbb=nb.first;
            if(cost+ew < dist[nbb][k-1]){
                dist[nbb][k-1] = cost+ew;
                pq.push({dist[nbb][k-1],nbb});
                sort(dist[nbb].begin(),dist[nbb].end());
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<dist[n][i]<<" ";
    }
    return 0;
}