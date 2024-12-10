#include<bits/stdc++.h>
using namespace std;

pair<int,int> dp[(1<<21)];

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> w(n);
    for(int i=0;i<n;i++) cin>>w[i];

    for(int i=0;i<(1<<n);i++){
        dp[i].first = dp[i].second = 1e9;
    }
    dp[0] = {1,0};

    for(int mask = 1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                int temp = mask^(1<<i);
                int val = dp[temp].first;
                int size = dp[temp].second;

                if(w[i]+size <= x){
                    dp[mask] = min(dp[mask],{val,size+w[i]});
                }
                else{
                    dp[mask] = min(dp[mask],{val+1,min(w[i],dp[temp].second)});
                }
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
    
    return 0;
}