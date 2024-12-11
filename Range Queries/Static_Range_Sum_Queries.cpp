#include<bits/stdc++.h>
using namespace std;

long long pref[1000005];
int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>pref[i];
        pref[i]+=pref[i-1];
    }
    for(int i=0;i<q;i++){
        int l,r; cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<endl;
    }
}