
// --------- Cat, Fox, and the Array ---------

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
using vi = vector<int>;
using vll = vector<long long>;
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
const ll LINF = LLONG_MAX;

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


bool check(ll k, vll &v, int n) {
    vll bits(22, 0);
    rep(i, 0, k) {
        int j = 0;
        int x = v[i];
        while (x > 0) {
            if (x % 2) {
                bits[j]++;
            }
            j++;
            x /= 2;
        }
    }

    vll freq = bits;
    rep(i, k, n) {
        int j = 0;
        int x =v[i];
        while (x > 0) {
            if (x % 2) {
                freq[j]++;
            }
            j++;
            x /= 2;
        }

        j = 0;
        x = v[i-k];
        while (x > 0) {
            if (x % 2) {
                freq[j]--;
            }
            j++;
            x /= 2;
        }

        rep(i, 0, 22) {
            if (freq[i] > 0 && bits[i] == 0) return false;
            if (freq[i] == 0 && bits[i] > 0) return false;
        }
    }
    return true;
}


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
        int n;
        cin >> n;
        vll v(n);
        // cin >> v;
        for (auto &x: v) cin >> x;
        ll low=1;
        ll high=n;
        ll ans=n;
        
        while(low <= high) {
            ll mid = (low+high)/2;
            if (check(mid, v, n)) {
                high = mid-1;
                ans = mid;
            } else {
                low = mid+1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

