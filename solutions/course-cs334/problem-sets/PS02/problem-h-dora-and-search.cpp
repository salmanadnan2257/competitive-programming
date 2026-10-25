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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int start, end, least, most;
        start = 0;
        end = n-1;
        least = 1;
        most = n;

        while ((a[start] == least || a[start] == most || a[end] == least || a[end] == most) and ((end-start)+1) > 3) {
            if (a[start] == least) {
            least += 1;
            start += 1;
            }

            if (a[start] == most) {
                most -= 1;
                start += 1;
            }

            if (a[end] == least) {
                least += 1;
                end -= 1;
            }

            if (a[end] == most) {
                most -= 1;
                end -= 1;
            }
        
            // cout << start << " " << end << " " << least << " " << most << endl;
        }

        if (((end-start) + 1) > 3) {
            cout << start + 1 << " " << end + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
