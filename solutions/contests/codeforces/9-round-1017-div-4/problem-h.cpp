#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX_VAL = 100001;
vector<ll> pos[MAX_VAL];

vector<ll> get_divisors(ll k) {
    vector<ll> divisors;
    if (k <= 1) return divisors; 
    ll sqrt_k = static_cast<ll>(sqrt(k)); 
    for (ll i = 1; i <= sqrt_k; ++i) {
        if (k % i == 0) {
            if (i >= 2) {
                divisors.push_back(i); 
            }
            ll other_divisor = k / i;
            if (i != other_divisor && other_divisor >= 2) { 
                divisors.push_back(other_divisor);
            }
        }
    }
    return divisors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        
        vector<ll> distinct_a_values; 
        distinct_a_values.reserve(n); 

        vector<ll> a(n + 1); 
        for (ll i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] >= 2 && a[i] < MAX_VAL) { 
                if (pos[a[i]].empty()) {
                    distinct_a_values.push_back(a[i]);
                }
                pos[a[i]].push_back(i);
            }
        }

        for (ll qi = 0; qi < q; ++qi) {
            ll k_init, l, r;
            cin >> k_init >> l >> r;

            ll current_k = k_init;
            ll total_ans = 0;
            ll current_idx = l;

            while (current_idx <= r) {
                if (current_k == 1) {
                    total_ans += (ll)(r - current_idx + 1); 
                    break; 
                }

                vector<ll> divisors = get_divisors(static_cast<ll>(current_k));
                ll next_j = r + 1; 

                for (ll d : divisors) {
                    if (d < MAX_VAL) { 
                        const vector<ll>& p = pos[d];
                        if (!p.empty()) {
                            auto it = lower_bound(p.begin(), p.end(), current_idx);
                            if (it != p.end()) {
                                ll found_idx = *it; 
                                if (found_idx <= r) {
                                    next_j = min(next_j, found_idx);
                                }
                            }
                        }
                    }
                }

                if (next_j > r) { 
                    total_ans += (ll)(r - current_idx + 1) * current_k;
                    break; 
                } 
                else {
                    if (next_j > current_idx) {
                        total_ans += (ll)(next_j - current_idx) * current_k;
                    }

                    current_idx = next_j; 
                    ll val_aj = a[current_idx]; 
                    ll k_after_division = current_k;

                    while (k_after_division > 0 && k_after_division % val_aj == 0) {
                        k_after_division /= val_aj;
                    }

                    total_ans += k_after_division;
                    current_k = k_after_division;
                    current_idx++;
                }
            }
            cout << total_ans << "\n";
        }
        
        for(ll val : distinct_a_values) {
            if (val >= 2 && val < MAX_VAL) { 
                pos[val].clear(); 
            }
        }
    }
    return 0; 
}
