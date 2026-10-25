// --------- Enlarge GCD ---------

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

const ll MX = 15000003;
vll pf(MX + 1, 0);

void sieve() {
    for (ll i = 2; i <= MX; i++) pf[i] = i;
    for (ll i = 2; i * i <= MX; i++) {
        if (pf[i] == i) {
            for (ll j = i * i; j <= MX; j += i) {
                if (pf[j] == j) pf[j] = i;
            }
        }
    }
}

vll getPrimeFactors(ll num) {
    vll factors;
    while (num > 1) {
        factors.push_back(pf[num]);
        num /= pf[num];
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    ll n;
    cin >> n;
    vll arr(n);
    for (auto &x : arr) cin >> x;

    ll g = arr[0];
    for (ll i = 1; i < n; ++i) g = gcd(g, arr[i]);

    bool flag = false;
    for (ll &x : arr) {
        x /= g;
        if (x > 1) flag = true;
    }

    if (!flag) {
        cout << -1 << endl;
        return 0;
    }

    unordered_map<ll, ll> cnt;
    ll ans = 0;

    for (ll num : arr) {
        set<ll> unique_factors;
        while (num > 1) {
            ll p = pf[num];
            unique_factors.insert(p);
            num /= p;
        }
        for (ll p : unique_factors) {
            cnt[p]++;
            ans = max(ans, cnt[p]);
        }
    }

    cout << n - ans << endl;
    return 0;
}
