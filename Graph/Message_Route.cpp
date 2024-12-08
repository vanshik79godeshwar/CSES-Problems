#include<bits/stdc++.h>
using namespace std;

vector<int> res;

// bool rec(vector<vector<int>>& adj, vector<bool>& vis, int node, int n){
//     if(node==n){
//         res.push_back(n);
//         return true;
//     }

//     for(int nb:adj[node]){
//         if(vis[nb] && rec(adj,vis,nb,n)){
//             res.push_back(node);
//             return true;
//         }
//     }
//     return false;
// }

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    bool flag = false;
    int level = 0;
    vector<bool> vis(n+1,false);
    vector<int> path(n+1,-1);
    vis[1]=true;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            int node = q.front();
            q.pop();
            if(node==n){
                flag = true;
                goto NEXT;
            }
            for(int nb:adj[node]){
                if(!vis[nb]) {
                    vis[nb]=true;
                    path[nb]=node;
                    q.push(nb);
                }
            }
        }
        level++;
    }
    NEXT:
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> res;
    path[1] = 1;
    cout<<level+1<<endl;
    // flag = rec(adj,vis,1,n);
    // reverse(res.begin(),res.end());
    // for(auto p:res) cout<<p<<" ";
    int x = n;
    while(path[x]!=x){
        res.push_back(x);
        x = path[x];
    }
    res.push_back(1);
    reverse(res.begin(),res.end());
    for(auto p:res) cout<<p<<" ";

    return 0;
}