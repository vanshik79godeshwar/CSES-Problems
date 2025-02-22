#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll parent[200000+5][30];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n,q; cin>>n>>q;
    vector<ll> par(n+1);
    for(int i=1; i<=n; i++){
        cin>>parent[i][0];
    }
    for(int j=1; j<30; j++){
        for(int i=1; i<=n; i++){
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    auto jump = [&](ll x, ll k)->ll{
        for(int i=0; i<30; i++){
            if(k&(1<<i)){
                x = parent[x][i];
            }
        }
        return x;
    };
    while(q--){
        ll x,k; cin>>x>>k;
        cout<<jump(x,k)<<"\n";
    }
    return 0;
}