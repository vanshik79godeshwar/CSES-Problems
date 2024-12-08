#include<bits/stdc++.h>
using namespace std;

long long dp[5001][5001], a[5001];

long long fxn(int i, int j){
    if(i>j) return 0;
    if(i==j) return  a[i];
    if(j-i==1) return max(a[i],a[j]);
    if(dp[i][j]!=-1) return dp[i][j];

    long long temp1 = a[i] + min(fxn(i+2,j),fxn(i+1,j-1));
    long long temp2 = a[j] + min(fxn(i,j-2),fxn(i+1,j-1));
    return dp[i][j] = max(temp1,temp2);
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    memset(dp, -1, sizeof(dp));
    cout<<fxn(0,n-1)<<endl;
}