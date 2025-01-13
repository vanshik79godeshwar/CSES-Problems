#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,q; cin>>n>>q;
    vector<ll> a(n);
    for(auto& it : a) cin>>it;
    vector<ll> prefXOR(n+1);
    for(int i=1;i<=n;i++){
        prefXOR[i] = prefXOR[i-1] ^ a[i-1];
    }

    while(q--){
        ll a,b; cin>>a>>b;
        cout<<(prefXOR[b]^prefXOR[a-1])<<endl;
    }
    return 0;
}