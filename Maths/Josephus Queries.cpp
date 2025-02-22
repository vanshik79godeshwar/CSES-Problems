#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int main(){
    ll q; cin>>q;

    auto fxn = [&](ll n, ll k, auto&& self)->ll{
        if(n==1) return 1;
        if(k <= (n+1)/2){
            if(2*k == n+1) return 1;
            else return 2*k;
        }

        ll temp = self(n/2, k - (n+1)/2, self);
        if(n%2 == 1) return 2*temp + 1;
        return 2*temp-1;
    };

    while(q--){
        ll n, k; cin>>n>>k;
        cout<<fxn(n, k, fxn)<<endl;
    }
}