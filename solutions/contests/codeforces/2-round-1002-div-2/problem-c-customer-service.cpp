#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int x = (y); x < (z); x++)
#define per(x, y, z) for(int x = (y); x >= (z); x--)

int main() {
    int _;
    cin >> _;
    while (_--) {
        int n;
        cin >> n;
        vector<int> ans;
        vector<int> a(n);
        int c;
        rep(i,0,n) {
            for (auto &x: a) cin >> x;
            c = 0;
            per(j, n-1, 0) {
                // cout << a[j] << "\n";
                if (a[j] == 1) {
                    c++;
                } else {
                    break;
                }
            }
            // cout << "c: " << c << "\n\n";
            // ans.insert(c);
            ans.emplace_back(c);
        }

        sort(ans.begin(),ans.end());
        int res = 0;
        // for (auto &x: ans) cout << x << " ";
        // cout << endl;
        for (auto &x: ans) if (res <= x) res++;
        cout << res << "\n";
    }

    return 0;
}


/* 4
2
1 2
2 1
2
10 10
10 10
3
2 3 3
4 4 1
2 1 1
4
4 2 2 17
1 9 3 1
5 5 5 11
1 2 1 1 */
