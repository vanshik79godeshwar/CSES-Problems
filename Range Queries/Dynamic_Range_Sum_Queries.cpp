#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> tree;
ll n;

void build(int left, int right, int node, vector<ll>& arr){
    if(left == right) {
        tree[node] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build(left, mid, 2 * node + 1, arr);
    build(mid + 1, right, 2 * node + 2, arr);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

ll query(int s, int e, int l, int r, int node){
    if(r < s || l > e) return 0; 
    if(l <= s && r >= e) return tree[node]; 
    int mid = s + (e - s) / 2;
    return query(s, mid, l, r, 2 * node + 1) + query(mid + 1, e, l, r, 2 * node + 2); 
}

void update(int s, int e, int idx, int val, int node){
    if(s == e) {
        tree[node] = val;
        return;
    }
    int mid = s + (e - s) / 2;
    if(idx <= mid) {
        update(s, mid, idx, val, 2 * node + 1);
    } else {
        update(mid + 1, e, idx, val, 2 * node + 2);
    }
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

int main(){
    ll q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    tree.resize(4 * n);

    build(0, n - 1, 0, arr);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) { 
            int idx, val;
            cin >> idx >> val;
            update(0, n - 1, idx - 1, val, 0); 
        } else if(type == 2) { 
            int l, r;
            cin >> l >> r;
            cout << query(0, n - 1, l - 1, r - 1, 0) << endl; 
        }
    }

    return 0;
}
