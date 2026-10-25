#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n, k;
        cin >> n >> k;
        vector<int> n_arr(n, 0);
        vector<int> ans_arr(0);

        for (int i=0; i < n; i++) {
            cin >> n_arr[i];
            // cout << n_arr[i] << " ";
        }

        // if (t == 1000 && (test_case >= 31 && test_case <= 36)) {
        //     cout << "Test Case #" << test_case << ":\n";
        //     cout << "n: " << n << ", k: " << k << "\n";
        //     cout << "Array: ";
        //     for (auto x : n_arr) cout << x << " ";
        //     cout << "\n";
        // }

        // cout << endl;
        // for (auto &x: n_arr) cin >> x;
        sort(n_arr.begin(), n_arr.end());
        // for (auto &x: n_arr) cout << x << " ";
        // cout << "first out" << endl;

        int count=0, i=-1;
        while (i < n-1) {
            // cout << i << endl;
            i++;
            count = 1;
            // cout << i << " " << (i+1 < n) << " " << n_arr[i] << endl;
            while (i+1 < n && n_arr[i] == n_arr[i+1]) {
                i++;
                count++;
            }
            // cout << count << " out" << endl;

            // if (i+1 == n) {
            //     count++;
            // }
            
            if (count >= k) {
                // cout << "adding " << n_arr[i] << endl;
                ans_arr.push_back(n_arr[i]);
            }
            // i++;
        }
        // for (auto &x: ans_arr) cout << x << " ";
        // cout << "final out" << endl;

        int a_s = static_cast<int>(ans_arr.size());
        // cout << "a_s length: " << a_s << endl;
        if (a_s == 0) {
            cout << -1 << endl;
            // cout << endl;
            continue;
        } else if (a_s == 1) {
            cout << ans_arr[0] << " " << ans_arr[0] << endl;
            // cout << endl;
            continue;
        }

        i = -1;
        int l = ans_arr[0], r = ans_arr[0], dis = 0, m_v=0, ans_l=ans_arr[0], ans_r=ans_arr[0];
        while (i < a_s-1) {
            i++;
            if (i+1 < a_s && ans_arr[i]+1==ans_arr[i+1]) {
                r = ans_arr[i];
            } else if (i+1 < a_s) {
                r = ans_arr[i];
                dis = (r - l) + 1;
                // cout << l << " " << r << " " << dis << endl;
                if (dis > m_v) {
                    ans_l = l;
                    ans_r = r;
                    m_v = dis;
                }
                if (i+1 < a_s) {
                    l = ans_arr[i+1];
                    r = ans_arr[i+1];
                } else {
                    break;
                }
                // cout << "check " << l << " " << r << endl;
            }
        }
        r = ans_arr[a_s-1];
        if (a_s-2>=0 && ans_arr[a_s-2]+1 == r) {
            dis = (r - l) + 1;
            // cout << l << " " << r << " " << dis << endl;
            if (dis > m_v) {
                ans_l = l;
                ans_r = r;
            }
        }

        cout << ans_l << " " << ans_r << endl;
        // cout << endl;
    }
    return 0;
}
