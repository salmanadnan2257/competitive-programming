#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> b(n, false);
        int found = true;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            int seat = a[i]-1;
            if (i == 0) {
                b[seat] = true;
                // cout << i << " " << a[i] << " " << seat << " " << b[seat] << endl;
                continue;
            } 

            // cout << i << " " << a[i] << " " << seat << " " << b[seat-1] << endl;
            // if (seat < n-1) {
            //     cout << "seat+1 " << b[seat + 1] << endl;
            // }
            if (((seat-1 >= 0 && b[seat-1] == false) or seat - 1 < 0) && ((seat < n-1 and b[seat+1] == false) or seat == n-1)) {
                // if (b[seat-1] == false) {
                //     cout << "false seat-1" << endl;
                // } else {
                //     cout << "false " << seat << n << " " << b[seat+1] << endl;
                // }
                found = false;
                break;
            }
            b[seat] = true;
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
