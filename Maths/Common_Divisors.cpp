#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int dp[1000001];
int main(){
    memset(dp, 0, sizeof dp);
    ll n; cin>>n;
    while(n--){
        ll x; cin>>x;
        dp[x]++;
    }
    ll ans = 1;
    for(int i=2; i<=1000000; i++){
        ll cnt = 0;
        for(int j=i; j<=1000000; j+=i){
            if(dp[j]) cnt+=dp[j];
        }
        if(cnt > 1) ans = i;
    }
    cout << ans << endl;
    return 0;
}