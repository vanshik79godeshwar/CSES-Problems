#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    vector<int> prev(x+1,0);

    for(int i=1;i<=x;i++){
        if(i%coins[0]==0) prev[i] = 1;
    }

    for(int i=1;i<n;i++){
        vector<int> curr(x+1,0);
        curr[0] = 1;
        for(int j=1;j<=x;j++){
            if(j-coins[i]>=0){
                curr[j] = (prev[j] + curr[j-coins[i]])%1000000007;
            }else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    cout<<prev[x]<<endl;
}