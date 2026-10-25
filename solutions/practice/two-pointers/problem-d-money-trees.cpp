// --------- Money Trees ---------

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
    while (t--) {
        // Your code here
        lli n, k;
        cin >> n >> k;
        vlli arr(n, 0);
        for (auto &x: arr) cin >> x;
        vlli h(n, 0);
        for (auto &x: h) cin >> x;

        lli curr=arr[0], ans=0, i=0, j=1;

        if (curr <= k) ans = 1;
        while (j < n) {
            if (h[j-1] % h[j] == 0) {
                curr += arr[j];
            } else {
                curr = arr[j];
                i = j;
            }

            while (curr > k) {
                curr -= arr[i++];
            }

            ans = max(ans, j-i+1);
            j++;
        }

        cout << ans << nl;
    }

    return 0;
}

