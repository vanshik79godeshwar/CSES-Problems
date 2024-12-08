#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin>>c;
            grid[i][j] = (c=='*'?-1:0);
        }
    }
    if(grid[0][0]==-1 || grid[n-1][n-1]==-1){
        cout<<0<<endl;
        return 0;
    }
    grid[0][0] = 1;
    for(int i=1;i<n;i++){
        if(grid[0][i]!=-1) grid[0][i] = grid[0][i-1];
        else break;
        
    }
    for(int i=1;i<n;i++){
        if(grid[i][0]!=-1) grid[i][0] = grid[i-1][0];
        else break;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]!=-1){
                if(grid[i-1][j]!=-1) grid[i][j] = (grid[i][j] + grid[i-1][j])%1000000007;
                if(grid[i][j-1]!=-1) grid[i][j] = (grid[i][j] + grid[i][j-1])%1000000007;
            }
        }
    }
    cout<<(grid[n-1][n-1]==-1?0:grid[n-1][n-1])<<endl;
}