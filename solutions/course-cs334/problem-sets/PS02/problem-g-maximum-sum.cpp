#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll maxi = 0;
        sort(a.begin(), a.end());

        vector<ll> b(n+1, 0);
        for (int i = 0; i < n; i++) {
            b[i + 1] = b[i] + a[i];
        }

        for (int i = 0; i <= k; i++) {
            maxi = max(maxi, b[n-i] - b[2 * (k-i)]);
        }

        cout << maxi << endl;
    }

    return 0;
}
