#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;

        int j = 0;
        int op = 0;
        if (s.find('B') != string::npos) {
            // cout << s << endl;
            while (j < n) {
                int ind = s.find('B', j);
                // cout << "ind: " << ind << endl;
                if (ind == string::npos) {
                    break;
                }
                ind += k;
                j = ind;
                op += 1;
            }
        }

        cout << op << endl;
    }

    return 0;
}
