#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007


ll dp[1000000][2];
int main(){
    int t; cin>>t;

    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<1000000;i++){
        dp[i][0] = 4*dp[i-1][0]+dp[i-1][1];
        dp[i][1] = 2*dp[i-1][1]+dp[i-1][0];
        dp[i][0]%=mod;
        dp[i][1]%=mod;
    }
    int n;
    while(t--){
        cin>>n;

        cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    }
    return 0;
}