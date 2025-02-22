#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007

int main(){
    ll n; cin>>n;

    auto binpower = [&](ll a, ll b)->ll{
        ll res = 1;
        while(b){
            if(b&1) res = (res*a)%MOD;
            a = (a*a)%MOD;
            b >>= 1;
        }
        return res;
    };

    while(n--){
        ll a,b; cin>>a>>b;
        cout << binpower(a,b) << endl;
    }
    return 0;
}