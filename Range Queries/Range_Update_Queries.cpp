#include<bits/stdc++.h>
using namespace std;
#define ll long long

class segtree{
    public:
        ll n;
        vector<ll> tree;
        vector<ll> lazy;
        segtree(ll n){
            this->n = n;
            tree.resize(4*n);
            lazy.resize(4*n);
        }
        void build(vector<ll>& v, ll node, ll start, ll end){
            if(start == end){
                tree[node] = v[start];
            }else{
                ll mid = (start+end)/2;
                build(v,2*node,start,mid);
                build(v,2*node+1,mid+1,end);
                tree[node] = tree[2*node] + tree[2*node+1];
            }
        }
        void update(ll node, ll start, ll end, ll l, ll r, ll val){
            if(lazy[node] != 0){
                tree[node] += (end-start+1)*lazy[node];
                if(start != end){
                    lazy[2*node] += lazy[node];
                    lazy[2*node+1] += lazy[node];
                }
                lazy[node] = 0;
            }
            if(r<start || end<l){
                return;
            }
            if(l<=start && end<=r){
                tree[node] += (end-start+1)*val;
                if(start != end){
                    lazy[2*node] += val;
                    lazy[2*node+1] += val;
                }
                return;
            }
            ll mid = (start+end)/2;
            update(2*node,start,mid,l,r,val);
            update(2*node+1,mid+1,end,l,r,val);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
        ll query(ll node, ll start, ll end, ll l, ll r){
            if(lazy[node] != 0){
                tree[node] += (end-start+1)*lazy[node];
                if(start != end){
                    lazy[2*node] += lazy[node];
                    lazy[2*node+1] += lazy[node];
                }
                lazy[node] = 0;
            }
            if(r<start || end<l){
                return 0;
            }
            if(l<=start && end<=r){
                return tree[node];
            }
            ll mid = (start+end)/2;
            ll p1 = query(2*node,start,mid,l,r);
            ll p2 = query(2*node+1,mid+1,end,l,r);
            return p1+p2;
        }
};

int main(){
    ll n,q; cin>>n>>q;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    segtree st(n);
    st.build(a,1,1,n);
    while(q--){
        ll type; cin>>type;
        if(type == 1){
            ll l,r,u; cin>>l>>r>>u;
            st.update(1,1,n,l,r,u);
        }else{
            ll l; cin>>l;
            cout<<st.query(1,1,n,l,l)<<endl;
        }
    }
    return 0;
}