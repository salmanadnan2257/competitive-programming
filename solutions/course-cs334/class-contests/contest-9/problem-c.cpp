// --------- Lecture Sleep ---------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), t(n), sum_arr(n+1), sum_main(n+1);
    sum_arr[0] = 0;
    sum_main[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_arr[i+1] = sum_arr[i] + a[i];
        // cout << sum_arr[i+1] << " ";
    }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i]) {
            sum_main[i+1] = sum_main[i] + a[i];
        } else {
            sum_main[i+1] = sum_main[i];
        }
        // cout << sum_main[i+1] << " ";
    }
    // cout << endl;

    if (n == k) {
        // int i=-1, sum_ones=0;
        // while (i<n-1) {
        //     i++;
        //     sum_ones += a[i];
        // }
        cout << sum_arr[n] << endl;
        return 0;
    }
    int max_sum=sum_main[n];
    // int int_sum=0;
    for (int i = 0; i < n; i++) {
        // if (t[i] == 0) {
        if (i+k <= n) {
            // int_sum = max(sum_main[i] + (sum_arr[i+k]-sum_arr[i]), sum_main[i+1] + (sum_arr[i+k+1]-sum_arr[i+1]));
            max_sum = max({sum_main[i] + (sum_arr[i+k]-sum_arr[i]) + (sum_main[n] - sum_main[i+k]), max_sum});
            // max_sum = max({sum_main[i] + (sum_arr[i+k]-sum_arr[i]), sum_main[i+1] + (sum_arr[i+k+1]-sum_arr[i+1]), max_sum});
            // cout << i << " " <<  sum_main[i] << " " << sum_arr[i+k] << " " << sum_arr[i] << " " << max_sum << endl;
        } else {
            // int_sum = sum_main[i] + (sum_arr[n]-sum_arr[i]);
            max_sum = max(max_sum, sum_main[i] + (sum_arr[n]-sum_arr[i]));
            // cout << "here " << int_sum << endl;
            // cout << i << " " <<  sum_main[i] << " " << sum_arr[n] << " " << sum_arr[i] << " " << max_sum << endl;
        }
            // max_sum = max(max_sum, int_sum);
        // }
    }

    // max_sum = max(max_sum, sum_main[n]);
    cout << max_sum << endl;
    return 0;
}
