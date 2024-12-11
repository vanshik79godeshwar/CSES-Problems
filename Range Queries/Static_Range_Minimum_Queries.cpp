#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> tree;

void build(vector<int>& arr, int node, int left, int right) {
    if (left == right) {
        tree[node] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build(arr, 2*node + 1, left, mid);
    build(arr, 2*node + 2, mid + 1, right);
    tree[node] = min(tree[2*node + 1], tree[2*node + 2]);
}

int query(int s, int e, int l, int r, int node) {
    if (r < s || l > e) return 1e9; 
    if (l <= s && r >= e) return tree[node];
    int mid = s + (e - s) / 2;
    return min(query(s, mid, l, r, 2*node + 1), query(mid + 1, e, l, r, 2*node + 2));
}

int main() {
    int q; 
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    tree.resize(4 * n);
    build(arr, 0, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int l, r; 
        cin >> l >> r;
        cout << query(0, n - 1, l - 1, r - 1, 0) << endl;
    }
}
