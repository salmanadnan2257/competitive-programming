#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n=0, k=0;
        cin >> n >> k;

        string s;
        // getline(cin, s);
        cin >> s;

        int count_w = count(s.begin(), s.end(), 'W');
        string f_s(k, 'B');
        // cout << f_s << endl;

        if (s.find(f_s) != string::npos) {
            cout << 0 << endl;
        } else if (k == n) {
            cout << (k - (n - count_w)) << endl;
        } else {
            int left = 0;
            int right = k;
            int b_count = count(s.begin(), s.begin() + k, 'B');
            int final_b = b_count;
            while (right < n) {
                if (s[left] == 'B') {
                    b_count -= 1;
                }

                if (s[right] == 'B') {
                    b_count += 1;
                }

                left += 1;
                right += 1;
                final_b = max(final_b, b_count);
            }
            cout << (k-final_b) << endl;
        }
    }

    return 0;
}
