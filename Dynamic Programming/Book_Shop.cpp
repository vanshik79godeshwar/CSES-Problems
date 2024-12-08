#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n,x; cin>>n>>x;
    vector<int> price(n),pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];

    vector<int> prev(x+1,0);
    for(int i=1;i<=x;i++){
        if(i==price[0]) prev[i] = pages[0];
    }

    for(int i=1;i<n;i++){
        vector<int> curr(x+1,0);
        for(int j=1;j<=x;j++){
            if(j-price[i]>=0){
                curr[j] = max(prev[j],pages[i]+prev[j-price[i]]);
            }else{
                curr[j] = max(prev[j],curr[j-1]);
            }
        }
        prev = curr;
    }
    cout<<prev[x]<<endl;
    return 0;
}