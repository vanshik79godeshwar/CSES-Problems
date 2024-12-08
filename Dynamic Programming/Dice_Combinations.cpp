#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;


    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=i-1; j>=max(0,i-6); j--){
            dp[i] = (dp[i] + dp[j])%1000000007;
        }
    }
    cout<<dp[n]<<endl;
}