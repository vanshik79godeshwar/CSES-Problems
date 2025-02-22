#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n; cin>>n;
    ll sum = 0;
    ll mod = 1e9+7;
    ll pos;
    for(ll i=1; i<=n; i++){
        sum += (n*(n/i));
        sum %= mod;
    }
    cout<<sum<<"\n";
    return 0;
}