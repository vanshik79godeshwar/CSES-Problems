#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> colors(n + 1, -1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            colors[i] = 1;
            queue<pair<int, int>> q;
            q.push({i, 1});
            while (!q.empty())
            {
                auto node = q.front();
                q.pop();
                int ele = node.first;
                int cl = node.second;
                vis[ele] = true;
                for (auto nb : adj[ele])
                {
                    if (colors[nb] == cl)
                    {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                    colors[nb]=1-cl;
                    if(!vis[nb]) q.push({nb,1-cl});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << colors[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}