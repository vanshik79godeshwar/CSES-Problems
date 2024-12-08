#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;

    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    sort(coins.begin(),coins.end());
    // vector<vector<int>> dp(n,vector<int>(x+1,0));

    vector<int> prev(x+1,1e9);

    for(int i=1;i<=x;i++){
        if(i%coins[0]==0) prev[i] = i/coins[0];
    }

    for(int i=1;i<n;i++){
        vector<int> curr(x+1,0);
        for(int j=1;j<=x;j++){
            if(j-coins[i]>=0){
                curr[j] = min(prev[j],1+curr[j-coins[i]]);
            }else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    cout<<(prev[x]==1e9?-1:prev[x])<<endl;
}