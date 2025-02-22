#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

ll dp[1000001];
int main(){
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=1000000; i++){
        for(int j=i; j<=1000000; j+=i){
            dp[j]++;
        }
    }
    ll n; cin>>n;
    while(n--){
        ll x; cin>>x;
        cout << dp[x] << endl;
    }
    return 0;
}