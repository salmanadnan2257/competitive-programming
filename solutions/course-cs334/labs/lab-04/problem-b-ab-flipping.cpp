#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n;
        cin >> s;

        string part = s.substr(0, n-1);
        int a_ind = part.find('A');
        // cout << s.substr(0, n-1) << endl;

        if (a_ind == string::npos) {
            cout << 0 << endl;
            continue;
        }

        int b_ind = n-1;
        bool found=false;
        int temp = n-1;
        while (temp >= 0 && not(found)) {
            if (s[temp] == 'B') {
                found = true;
                b_ind = temp;
            }
            temp--;
        }

        if (not(found) || a_ind > b_ind) {
            cout << 0 << endl;
        } else {
            cout << b_ind - a_ind << endl;
        }
    }

    return 0;
}
