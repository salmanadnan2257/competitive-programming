// --------- Data Structures Fan ---------

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod =998244353;

void solve(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for (auto &p:arr) cin>>p;
    vector<ll> pre(n+1,0);
    for (ll i=0;i<n;i++) pre[i+1]=pre[i]^arr[i];
    ll a=0,b=0;
    string s;
    cin>>s;
    for (ll i=0;i<n;i++) {
        if (s[i]=='0') a^=arr[i];
        else b^=arr[i];
    }
    ll k;
    cin>>k;
    while(k--){
        ll x;
        cin>>x;
        if (x==2){
            ll p;
            cin>>p;
            if (p==0) cout<<a<<" ";
            else cout<<b<<" ";
            continue;
        }
        ll l,r;
        cin>>l>>r;
        a^=pre[r]^pre[l-1];
        b^=pre[r]^pre[l-1];
    }
    cout<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}
