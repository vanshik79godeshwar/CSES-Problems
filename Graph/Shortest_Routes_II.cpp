#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m,q; cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,1e18));
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(int i=0;i<m;i++){
        ll a,b,c; cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[a][b],c);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
                dist[k][j] = min(dist[k][j],dist[j][k]);
            }
        }
    }
    while(q--){
        ll x,y; cin>>x>>y;
        ll temp = dist[x][y];
        if(temp==1e18) cout<<-1<<endl;
        else cout<<temp<<endl;
    }
    return 0;
}