#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>grid[i][j];
    }

    pair<int,int> start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A') start = {i,j};
            if(grid[i][j]=='B') end = {i,j};
        }
    }   
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<char>> path(n,vector<char>(m));

    auto check = [&](int x, int y){
        return x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y]!='#';
    };

    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    bool flag= false;
    while(!q.empty()){
        auto node = q.front();
        int x = node.first;
        int y = node.second;
        q.pop();
        if(node==end){
            flag=true;
            break;
        }
        
        if(check(x+1,y)){
            path[x+1][y] = 'D';
            vis[x+1][y] = true;
            q.push({x+1,y});
        }
        if(check(x,y+1)){
            path[x][y+1] = 'R';
            vis[x][y+1] = true;
            q.push({x,y+1});
        }
        if(check(x-1,y)){
            path[x-1][y] = 'U';
            vis[x-1][y] = true;
            q.push({x-1,y});
        }
        if(check(x,y-1)){
            path[x][y-1] = 'L';
            vis[x][y-1] = true;
            q.push({x,y-1});
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    vector<char> res;
    int x = end.first, y = end.second;
    while(grid[x][y]!='A'){
        res.push_back(path[x][y]);
        char ch = path[x][y];
        if(ch=='U') x++;
        else if(ch=='L') y++;
        else if(ch=='R') y--;
        else x--;
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(auto h:res) cout<<h;
    cout<<endl;
    return 0;
}