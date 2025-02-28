#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main(){
    ll n; cin>>n;
    vector<vector<ll>> adj(n+1);

    for(int i=0; i<n-1; i++){
        ll x; cin>>x;
        adj[x].push_back(i+2);
    }
    vector<ll> dp(n+1, -1);
    auto fxn = [&](ll node, auto&& self)->ll{
        if(dp[node]!=-1) return dp[node];
        if(adj[node].size()==0){
            dp[node] = 0;
            return 0;
        }
        ll sum = 0;
        for(auto x: adj[node]){
            sum += self(x, self);
        }
        dp[node] = sum + adj[node].size();
        return dp[node];
    };
    fxn(1, fxn);
    for(int i=1; i<=n; i++) cout << dp[i] << " ";
    cout << endl;
    return 0;
}