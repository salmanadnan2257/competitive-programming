#include <bits/stdc++.h>
using namespace std;

int main() {
    int _;
    int n, k;
    cin >> _;
    while (_--) {
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x: a) cin >> x;

        int cnt=1, ans=1;
        if (k == n) {
            for (int i=1; i < n; i+=2) {
                if (a[i] == cnt) {
                    cnt++;
                    ans++;
                } else {
                    break;
                }
            }
            cout << ans << "\n";
        } else {
            // int c_a = n-k, i=2;
            // for (int i=0; i < n; i++) {
            //     if (a[i] != 1) {
            //         if ((n-i+1) >= (k-1))
            //     }
            // }
            if (n == 2) {
                if (a[1] == 1) {
                    cout << "2\n";
                } else {
                    cout << "1\n";
                }
                goto ed;
            } else {
                // bool found = false;
                for (int i = 1; i < n; i++) {
                    if (a[i] != 1) {
                        if ((n-i) >= (k-1)) {
                            cout << "1\n";
                        } else {
                            cout << "2\n";
                        }
                        goto ed;
                    }
                }

                // if (n == 2) {
                //     if (a[1] == 1) {
                //         cout << "2\n";
                //     } else {
                //         cout << "1\n";
                //     }
                // } else if (a[3] == 1) {
                // }
                cout << "2\n";
            }
            ed:;
        }
    }
    return 0;
}
