// --------- Divisors of Two Integers ---------

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define endl "\n"

int main() {
    ll _ = 1;
    // cin >> _;
    while (_--) {
        ll n;
        cin >> n;
        vll arr(n), freq(10001, 0);

        for (int i=0; i < n; ++i) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; ++i) {
            freq[arr[i]]++;
        }

        sort(arr.begin(), arr.end());
        int mx = arr[n-1], mx_2;
        for (int i = 0; i < n; ++i) {
            if (arr[n-1] % arr[i] == 0) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0) {
                    arr[i] = 0;
                }
            }
        }

        // for (auto &x: arr) cout << x << " "; cout << "\n";
        sort(arr.begin(), arr.end());
        mx_2 = arr[n-2];
        cout << mx << " " << mx_2 << endl;
    }

    return 0;
}
