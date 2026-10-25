// ---------------- Competitive Programming Template for ICPC and Other Competitions ----------------

#include <bits/stdc++.h>
using namespace std;

// ---------------- Fast Input and Output ----------------
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

// ---------------- Type Aliases ----------------
using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;

// ---------------- Macros ----------------
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) static_cast<ll>((x).size())
#define nl "\n"

// ---------------- Debugging Macro ----------------
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << (x) << endl;
#else
    #define debug(x)
#endif

// ---------------- Constants ----------------
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

// ---------------- Utility Functions ----------------
template<typename T>
void read_vector(vector<T>& v) {
    for (auto& x : v) cin >> x;
}

template<typename T>
void print_vector(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

// ---------------- Priority Queue Types ----------------
template<typename T>
using max_heap = priority_queue<T>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

// ---------------- Number Theory Functions ----------------
// GCD and LCM
ll gcd(ll a, ll b) {
    while (b) { 
        ll t = a % b; 
        a = b; 
        b = t; 
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

// Binary Exponentiation (Fast Power)
ll binpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

// Modular Exponentiation
ll binpowmod(ll a, ll b, ll mod) {
    ll ans = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

// Modular Inverse using Fermat's Theorem (Works if mod is prime)
ll mod_inv(ll a, ll mod) {
    return binpowmod(a, mod - 2, mod);
}

// Extended Euclidean Algorithm for Modular Inverse
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { 
        x = 1; y = 0; 
        return a; 
    }
    ll x1, y1;
    ll g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll mod_inv_euclid(ll a, ll mod) {
    ll x, y;
    ll g = ext_gcd(a, mod, x, y);
    if (g != 1) return -1; // Inverse does not exist
    return (x % mod + mod) % mod;
}

// ---------------- Sieve of Eratosthenes ----------------
const ll MAXN = 1000005;
vector<bool> is_prime(MAXN, true);
vll primes;

void sieve(ll n) {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.pb(i);
    }
}

// ---------------- Prime Factorization ----------------
vll prime_factors(ll n) {
    vll factors;
    for (ll p : primes) {
        if (p * p > n) break;
        while (n % p == 0) {
            factors.pb(p);
            n /= p;
        }
    }
    if (n > 1) factors.pb(n);
    return factors;
}

// ---------------- Disjoint Set Union (DSU) ----------------
struct DSU {
    vll parent, rank;
    DSU(ll n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(all(parent), 0);
    }

    ll find(ll v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

// ---------------- Segment Tree with Lazy Propagation ----------------
struct SegmentTree {
    ll n;
    vll tree, lazy;
    SegmentTree(ll size) : n(size), tree(4 * size, 0), lazy(4 * size, 0) {}

    void apply(ll idx, ll l, ll r, ll val) {
        tree[idx] += val * (r - l + 1);
        lazy[idx] += val;
    }

    void push(ll idx, ll l, ll r) {
        if (lazy[idx] != 0) {
            ll mid = (l + r) / 2;
            apply(2 * idx, l, mid, lazy[idx]);
            apply(2 * idx + 1, mid + 1, r, lazy[idx]);
            lazy[idx] = 0;
        }
    }

    void update(ll idx, ll l, ll r, ll ql, ll qr, ll val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(idx, l, r, val);
            return;
        }
        push(idx, l, r);
        ll mid = (l + r) / 2;
        update(2 * idx, l, mid, ql, qr, val);
        update(2 * idx + 1, mid + 1, r, ql, qr, val);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    ll query(ll idx, ll l, ll r, ll ql, ll qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        push(idx, l, r);
        ll mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
    }
};

ll factorial (ll n) {
    if (n < 0) return 0;
    ll result = 1;
    for (ll i = 2; i <= n; ++i) {
        result *= i;
        if (result < 0) return -1;
    }
    return result;
}

// --------- Digits ---------

// ---------------- Solve Function ----------------
void solve() {
    ll n, d;
    cin >> n >> d;

    vll ans = {1};
    if (n >= 3 || d % 3 == 0) ans.eb(3);
    if (d == 5) ans.eb(5);
    if (n >= 3 || d == 7) ans.eb(7);
    if (n >= 6 || d == 9 || (n > 2 && d % 3 ==0)) ans.eb(9);
    sort(all(ans));

    for (auto &x: ans) cout << x << " "; cout << nl;
    // vll arr(n);
    // for (auto& x : arr) cin >> x;
    
    // sort(all(arr));
    
    // cout << "Sorted Array: ";
    // print_vector(arr);
}

// ---------------- Main Function ----------------
int main() {
    fast_io;
    
    // sieve(MAXN); // Precompute primes

    ll _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}
