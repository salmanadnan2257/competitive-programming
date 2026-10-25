#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define per(x,y) for (int x = y; x >= 1; x--)
#define ll long long

int main() {
    int n;
    ll l, r, x;
    cin >> n >> l >> r >> x;
    vi n_arr;
    int _;
    rep(i, 0, n) {
        cin >> _;
        n_arr.emplace_back(_);
    }

    int s = 0;
    // if (n > 2) {
    s = 0;
    ll m_l, m_r;
    int diff, ans=0;
    bool check = true;
    rep(i, 1, (1<<n)+1) {
        check = true;
        s = 0, m_l = 100000000, m_r = 0;
        rep(j, 0, n) {
            if (i & (1 << j)) {
                s += n_arr[j];
                m_l = min(m_l, static_cast<ll>(n_arr[j]));
                m_r = max(m_r, static_cast<ll>(n_arr[j]));
                if (s > r) {
                    check = false;
                    break;
                }
            }
        }

        // cout << check << " " << s << " " << l << " " << r << " " << m_l << " " << m_r  << " " << (m_r-m_l) << " " << x << "\n";
        if (check == true && s >= l && s <= r && (m_r-m_l) >= x) {
            // cout << "IN" << "\n";
            ans++;
            // diff = m_r - m_l;
            // if (diff > x) {
            // }
        }
    }
    
    cout << ans << "\n";
    // }

    return 0;
}
