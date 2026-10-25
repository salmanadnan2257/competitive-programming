// --------- Remainders Game ---------

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

ll gcd(ll x, ll y) {
    return (ll)__gcd(x, y);
}
ll lcm(ll x, ll y) {
    return (x*y)/(ll)gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    ll curr = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        curr = (ll)gcd(k, lcm(curr, x));
    }

    if (curr == k) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
