#include<bits/stdc++.h>
using namespace std;
#define ll long long

class segtree{
    public:
        ll n;
        vector<ll> tree;
        segtree(ll n){
            this->n = n;
            tree.resize(4*n);
        }
        void build(vector<ll>& v, ll node, ll start, ll end){
            if(start == end){
                tree[node] = v[start];
            }else{
                ll mid = (start+end)/2;
                build(v,2*node,start,mid);
                build(v,2*node+1,mid+1,end);
                tree[node] = min(tree[2*node],tree[2*node+1]);
            }
        }
        void update(ll node, ll start, ll end, ll idx, ll val){
            if(start == end){
                tree[node] = val;
            }else{
                ll mid = (start+end)/2;
                if(start<=idx && idx<=mid){
                    update(2*node,start,mid,idx,val);
                }else{
                    update(2*node+1,mid+1,end,idx,val);
                }
                tree[node] = min(tree[2*node],tree[2*node+1]);
            }
        }
        ll query(ll node, ll start, ll end, ll l, ll r){
            if(r<start || end<l){
                return LLONG_MAX;
            }
            if(l<=start && end<=r){
                return tree[node];
            }
            ll mid = (start+end)/2;
            ll p1 = query(2*node,start,mid,l,r);
            ll p2 = query(2*node+1,mid+1,end,l,r);
            return min(p1,p2);
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
            ll k,u; cin>>k>>u;
            st.update(1,1,n,k,u);
        }else{
            ll l,r; cin>>l>>r;
            cout<<st.query(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}