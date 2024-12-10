#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

void generate(int i, int col, int m, int n,int next_msk, int curr_msk, vector<int>& next_msks){
    if(i==n){
        next_msks.push_back(next_msk);
        return;
    }

    if(curr_msk & (1<<i)){
        generate(i+1,col,m,n,next_msk,curr_msk,next_msks);
    }
    if((curr_msk & (1<<i))==0){
        generate(i+1,col,m,n,next_msk+(1<<i),curr_msk,next_msks);
    }
    if(i+1<n && (curr_msk&(1<<i))==0 && (curr_msk&(1<<(i+1)))==0){
        generate(i+2,col,m,n,next_msk,curr_msk,next_msks);
    }
}

int dp[1001][(1<<11)];
int rec(int mask,int col, int m, int n){

    if(col == m+1){
        if(mask==0) return 1;
        else return 0;
    }

    if(dp[col][mask]!=-1) return dp[col][mask];
    vector<int> next_msks;
    int ans = 0;
    generate(0,col,m,n,0,mask,next_msks);

    for(int p:next_msks){
        ans = (ans+rec(p,col+1,m,n))%mod;
    }
    return dp[col][mask] = ans;

}

int main(){
    int n,m; cin>>n>>m;
    memset(dp, -1, sizeof dp);
    cout<<rec(0,1,m,n)<<endl;
    return 0;
}