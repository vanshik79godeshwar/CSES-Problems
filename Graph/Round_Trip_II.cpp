#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll man = 1e5 + 5;
bool vis[man];
bool pathVis[man];
ll cnode = -1;
vector<vector<int>> adj;
bool dfs(int node){
    vis[node] = true;
    pathVis[node] = true;
    for(auto nb : adj[node]){
        if(pathVis[nb]){
            cnode = nb;
            return true;
        }
        else if(vis[nb]) continue;
        else if(dfs(nb)) return true;
    }
    pathVis[node] = false;
    return false;
}
vector<int> res;
bool ndfs(int node){
    vis[node] = true;
    if(res.size()==0 && node==cnode){
        for(auto nb:adj[node]){
            if (ndfs(nb)){
                // cout<<"ifi : "<<node<<endl;
                res.push_back(node);
                return true;
            }
        }
    }
    if(node==cnode){
        // cout<<"base : "<<node<<endl;
        res.push_back(node);
        return true;
    }
    for(auto nb:adj[node]){
        if(nb == cnode){
            res.push_back(cnode);
            res.push_back(node);
            return true;
        }
        if(!vis[nb]){
            if(ndfs(nb)){
                // cout<<"itrmdt : "<<node<<endl;;
                // cout<<"nb : "<<nb<<endl;
                res.push_back(node);
                return true;
            }
        }
    }
    
    return false;
}
int main(){
    memset(vis, false, sizeof vis);
    memset(pathVis, false, sizeof pathVis);
    ll n,m; cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        ll a,b; cin>>a>>b;
        adj[a].push_back(b);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<": ";
    //     for(auto it : adj[i]) cout<<it<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++){
        if(cnode!=-1) break;
        if(!vis[i]){
            bool flag = dfs(i);
        }
    }
    // cout<<cnode<<endl;

    if(cnode==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    memset(vis, false, sizeof vis);
    vis[cnode] =true;
    bool fflag = ndfs(cnode);
    cout<<res.size()<<endl;
    reverse(res.begin(),res.end());
    for(auto it:res) cout<<it<<" ";
    return 0;
}