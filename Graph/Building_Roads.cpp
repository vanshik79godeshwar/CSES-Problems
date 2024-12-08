#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;

    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> res;
    vector<bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            res.push_back(i);
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                vis[node] = true;
                for(int nb:adj[node]){
                    if(!vis[nb]) q.push(nb);
                }
            }
        }
    }
    cout<<res.size()-1<<endl;
    for(int i=0;i<res.size()-1;i++){
        cout<<res[i]<<" "<<res[i+1]<<endl;
    }
    return 0;
}