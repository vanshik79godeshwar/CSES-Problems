#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n),b(n),p(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>p[i];
        b[i]++;
        mp[a[i]];
        mp[b[i]];
    }
    int point = 0;
    for(auto& v:mp){
        v.second = point;
        point++;
    }
    vector<vector<pair<int,int>>> v(point);
    for(int i=0;i<n;i++){
        v[mp[b[i]]].push_back({mp[a[i]],p[i]});
    }
    vector<long long> dp(point);
    for(int i=0;i<point;i++){
        if(i>0) dp[i] = dp[i-1];

        for(auto nb:v[i]){
            dp[i] = max(dp[i],dp[nb.first]+nb.second);
        }
    }
    cout<<dp[point-1]<<endl;
    return 0;
}