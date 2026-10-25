// --------- Sheikh (Easy Version) ---------

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
    bool valid = true;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vll a(n+1), ps(n+1), px(n+1);
        ll sum=0, x=0;

        rep(i, 1, n+1) {
            cin >> a[i];
            sum += a[i];
            x ^= a[i];
            ps[i] = ps[i-1] + a[i];
            px[i] = px[i-1] ^ a[i];
        }

        int l=1, r=n, ans=n;
        int ans_l=1, ans_r=r;
        while (l <= r) {
            int mid = (l+r)/2;
            bool is = false;
            rep(i, 1, n-mid+2) {
                if ((ps[i+mid-1] - ps[i-1]) - (px[i+mid-1] ^ px[i-1]) == sum-x) {
                    is = true;
                    ans_l = i;
                    ans_r = i+mid-1;
                    break;
                }
            }

            if (is) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << ans_l << " " << ans_r << nl;
        }
    }

    return 0;
}

