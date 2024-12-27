#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> ID(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ID[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ID[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto nb : adj[node]) {
            ID[nb]--;
            if (ID[nb] == 0) q.push(nb);
        }
    }

    vector<int> dist(n + 1, -1e9);
    vector<int> par(n + 1, -1);
    dist[1] = 0;

    for (int node : topo) {
        if (dist[node] == -1e9) continue;
        for (auto nb : adj[node]) {
            if (dist[node] + 1 > dist[nb]) {
                dist[nb] = dist[node] + 1;
                par[nb] = node;
            }
        }
    }

    if (dist[n] == -1e9) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> res;
    for (int node = n; node != -1; node = par[node]) {
        res.push_back(node);
    }

    reverse(res.begin(), res.end());

    cout << res.size() << endl;
    for (int node : res) cout << node << " ";
    cout << endl;

    return 0;
}
