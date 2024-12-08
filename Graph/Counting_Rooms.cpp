#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<int> dir = {0,1,0,-1,0}; // R D L U
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    auto check = [&](int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    };
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && !visited[i][j]){
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j]=true;
                ans++;
                while(!q.empty()){
                    int x,y;
                    tie(x,y) = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx,ny;
                        nx = x+dir[k];
                        ny = y+dir[k+1];
                        if(check(nx,ny) && grid[nx][ny]=='.' && !visited[nx][ny]){
                            q.push({nx,ny});
                            visited[nx][ny]=true;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}