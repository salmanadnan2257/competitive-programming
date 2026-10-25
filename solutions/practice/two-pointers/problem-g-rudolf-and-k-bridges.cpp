// --------- Rudolf and k Bridges ---------

// To compile with the LOCAL macro defined, use the following command:
// g++ -DLOCAL -o program program.cpp

#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Type Aliases
using ll = long long;
using lli = long long int;
using vi = vector<int>;
using vll = vector<long long>;
using vlli = vector<long long int>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

// Macros
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) static_cast<int>((x).size())
#define nl "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Debugging Macro
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << (x) << endl;
#else
    #define debug(x)
#endif

// Constants
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = LONG_LONG_MAX;

// Utility Functions
template<typename T>
void read_vector(vector<T>& v) {
    for (auto& x : v) cin >> x;
}

template<typename T>
void print_vector(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

// Priority Queue Types
template<typename T>
using max_heap = priority_queue<T>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
    fast_io;

    #ifdef LOCAL
        // Redirect input from "input.txt" when LOCAL is defined
        ifstream in("input.txt");
        if (!in) {
            cerr << "Error: 'input.txt' not found." << endl;
            return 1;
        }
        cin.rdbuf(in.rdbuf());
    #endif

    int t = 1;
    // Uncomment the following line to read the number of test cases
    cin >> t;
    while (t--) {
        // Your code here
        ll n, m, k, d;
        cin >> n >> m >> k >> d;
        ll arr[n][m];
        rep(i, 0, n) {
            rep(j, 0, m) {
                cin >> arr[i][j];
            }
        }

        vll ans(n);
        rep(i, 0, n) {
            deque<ll> dq;
            vll v(m);
            v[0] = 1;
            dq.pb(0);
            for (int j=1;j <= min(d+1, m-2); j++) {
                v[j] = arr[i][j] + 2;
                while (dq.size() > 0 && v[dq.back()] >= v[j]) {
                    dq.pop_back();
                }
                dq.pb(j);
            }

            rep (j, d+2, m-1) {
                while (dq.front() < (j-d-1)) {
                    dq.pop_front();
                }
                v[j] = arr[i][j] + 1 + v[dq.front()];
                while (dq.size() && v[dq.back()] >= v[j]) {
                    dq.pop_back();
                }
                dq.pb(j);
            }
            
            while (dq.front() < (m-d-2)) {
                dq.pop_front();
            }
            ans[i] = 1+v[dq.front()];
        }

        rep(i, 1, n) {
            ans[i] += ans[i-1];
        }

        ll res = LINF;
        ll i=0, j=k-1;
        while (j < n) {
            if (i == 0) {
                res = min(res, ans[j]);
            } else {
                res = min(res, ans[j]-ans[i-1]);
            }
            i++;
            j++;
        }

        cout << res << nl;
    }

    return 0;
}

