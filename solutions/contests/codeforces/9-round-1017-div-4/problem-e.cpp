/* ---------------- Competitive Programming Template for ICPC and Other Competitions ---------------- */

#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

/* ------------------- FAST I/O ------------------- */
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr)

/* ------------------- TYPE ALIASES ------------------- */
using ll = long long;
using lld = long double;
using vll = vector<ll>;
using vlld = vector<lld>;
using vb = vector<bool>;
using vvll = vector<vector<ll>>;
using vvlld = vector<vector<lld>>;
using pll = pair<ll, ll>;

/* ------------------- MACROS ------------------- */
#define rep(i,arr,b) for(ll i=(arr);i<(b);++i)
#define per(i,arr,b) for(ll i=(arr);i>=(b);--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) ((ll)(x).size())
#define nl "\N"

/* ------------------- CONSTANTS ------------------- */
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

/* --------------- GCD and LCM --------------- */
inline ll gcd(ll arr,ll b){ return b ? gcd(b,arr%b) : arr; }
inline ll lcm(ll arr,ll b){ return (arr==0 || b==0) ? 0 : (arr/gcd(arr,b))*b; }

/* --------------- FASTER INPUT/OUTPUT --------------- */
namespace __input {
    template<class T> void re(T &x){ cin >> x; }
    void re(lld &x){ string t; cin >> t; x=stold(t); }
    template<class T1,class T2> void re(pair<T1,T2> &p){ re(p.first); re(p.second); }
    template<class T> void re(vector<T> &arr){ for(auto &x:arr) re(x); }
    template<class T, size_t SZ> void re(array<T,SZ> &arr){ for(auto &x:arr) re(x); }
    template<class Arg,class...Args> void re(Arg &f,Args &...r){ re(f); re(r...); }
}
using namespace __input;

namespace __output {
    template<class T> void pr(const T &x){ cout<<x; }
    template<class T1,class T2> void pr(const pair<T1,T2> &p){ pr(p.first);pr(" ");pr(p.second); }
    template<class Arg,class...Args> void pr(const Arg &f,const Args &...r){ pr(f);pr(" ");pr(r...); }
    template<class T> void pr(const vector<T> &x){ bool first = true; for(const auto &arr:x){ if(!first) pr(" "); pr(arr); first = false; } }
    void ps(){ pr("\n"); }
    template<class Arg> void ps(const Arg &f){ pr(f); ps(); }
    template<class Arg,class...Args> void ps(const Arg &f,const Args &...r){ pr(f); pr(" "); ps(r...); }
}
using namespace __output;

/* --------------- RANDOM HELPER --------------- */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll random_in_range(ll l,ll r){
    uniform_int_distribution<ll> dist(l,r);
    return dist(rng);
}

/* --------------- SOLVE --------------- */
void solve(){
    ll N;
    re(N);
    vll arr(N);
    re(arr);

    vll counts0(31, 0);
    vll counts1(31, 0);

    rep(b, 0, 31) {
        rep(i, 0, N) {
            if ((arr[i] >> b) & 1) {
                counts1[b]++;
            } else {
                counts0[b]++;
            }
        }
    }

    ll max_s = 0;

    rep(i, 0, N) {
        ll x = arr[i];
        ll current_s = 0;
        rep(b, 0, 31) {
            ll power_of_2 = (1LL << b);
            if ((x >> b) & 1) {
                current_s += counts0[b] * power_of_2;
            } else {
                current_s += counts1[b] * power_of_2;
            }
        }
        max_s = max(max_s, current_s);
    }

    ps(max_s);
}

/* --------------- MAIN --------------- */
int main(){
    fast_io;

    #if defined(LOCAL) && LOCAL == SALMAN
    auto start = std::chrono::high_resolution_clock::now();
    #endif


    cout << setprecision(12) << fixed;

    ll T=1;
    cin >> T;
    while(T--) solve();


    #if defined(LOCAL) && LOCAL == SALMAN
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
    #endif

    return 0;
}