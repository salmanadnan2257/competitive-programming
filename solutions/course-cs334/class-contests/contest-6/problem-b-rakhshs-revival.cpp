#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;

        int j=0, op=0;
        while (j < n) {
            size_t ind = s.find('0', j);
            if (ind == string::npos) {
                break;
            }
            j = ind;
            int tries = 0;

            while (j < n && s[j] == '0' and tries < m) {
                tries += 1;
                j += 1;
            }
            
            if (tries == m) {
                op += 1;
                j = k + (j - 1);
            } else {
                j += 1;
            }
        }

    cout << op << endl;
    }
}
