#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,sum=0; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        sum+=nums[i];
    }

    vector<bool> dp(sum+1,false);
    dp[0]=true;

    for(int i=0;i<n;i++){
        for(int j=sum;j>=0;j--){
            if(dp[j]==false && nums[i]<=j){
                dp[j] = dp[j-nums[i]];
            }
        }
    }
    vector<int> res;
    for(int i=1;i<=sum;i++){
        if(dp[i]){
            res.push_back(i);
        }
    }
    cout<<res.size()<<endl;
    for(int num:res) cout<<num<<" ";
    cout<<endl;
}