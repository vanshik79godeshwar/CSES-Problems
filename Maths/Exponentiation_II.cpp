#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
// #define MOD 1000000007

int main(){
    ll n; cin>>n;
    const ll p = 1000000007;
    auto binpower = [&](ll a, ll b, ll MOD)->ll{
        ll res = 1;
        while(b){
            if(b&1) res = (res*a)%MOD;
            a = (a*a)%MOD;
            b >>= 1;
        }
        return res;
    };

    while(n--){
        ll a,b,c; cin>>a>>b>>c;
        cout << binpower(a, binpower(b,c,p-1), p)%p  << endl;
    }
    return 0;
}