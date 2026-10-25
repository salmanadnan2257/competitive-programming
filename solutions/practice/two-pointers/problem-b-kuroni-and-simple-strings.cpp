#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    size_t l_s = s.size();
    vector<int> ans;

    int start=-1, end=l_s;
    // cout << start << " " << end << " " << l_s << endl;
    bool left = false, right = false;
    while (start < end && start < static_cast<int>(l_s)) {
        while (not(left) && start < static_cast<int>(l_s)) {
            start++;
            if (s[start] == '(') {
                left = true;
            }
        }
        // cout << "start: " << start << endl;

        while (not(right) && end > start) {
            end--;
            if (s[end] == ')') {
                right = true;
            }
        }
        // cout << "end: " << end << endl;

        if (left && right) {
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            left = false;
            right = false;
        }
    }

    sort(ans.begin(), ans.end());
    size_t size_ans = ans.size();
    if (size_ans > 0) {
        cout << 1 << endl;
        cout << size_ans << endl;
        for (int i = 0; i < size_ans; i++) {
            cout << ans[i] << " ";
        }
    } else {
        cout << 0 << endl;
    }

    return 0;
}
