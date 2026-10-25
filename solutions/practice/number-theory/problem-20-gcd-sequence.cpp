// --------- GCD Sequence ---------

#include <bits/stdc++.h>
using namespace std;

#define fl(i, n) for (ll i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using vll = vector<long long>;

// Function to check if removing an element sorts the array
bool check(vll &v, ll in) {
    vll temp;
    fl(i, v.size()) {
        if (i != in) {
            temp.push_back(v[i]);
        }
    }
    vector<ll> g(temp.size() - 1);
    for (int i = 0; i < temp.size() - 1; i++) {
        g[i] = gcd(temp[i], temp[i + 1]);
    }
    return is_sorted(g.begin(), g.end());
}

// Main logic function
void asquare() {
    ll n;
    cin >> n;
    vll v(n);
    for (auto &x : v) cin >> x;

    vector<ll> g(n - 1);
    for (int i = 0; i < n - 1; i++) {
        g[i] = gcd(v[i], v[i + 1]);
    }

    if (is_sorted(g.begin(), g.end())) {
        cout << "Yes\n";
        return;
    }

    ll in = 0;
    fl(i, n - 2) {
        if (g[i] > g[i + 1]) {
            in = i;
            break;
        }
    }

    if (check(v, in) || check(v, in + 1) || check(v, in + 2)) {
        cout << "Yes\n";
        return;
    }

    cout << "No" << endl;
}

// Main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    fl(i, t) {
        asquare();
    }
    return 0;
}
