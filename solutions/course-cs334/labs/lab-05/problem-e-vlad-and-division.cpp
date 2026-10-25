#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <string>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define rep(x,y,z) for (int x = y; x < z; x++)
#define ll long long
#define eb(x) emplace_back(x)
#define all(a) sort(a.begin(), a.end())

const int MAX_NUM = (1 << 31) - 1;

int main() {
    int _;
    cin >> _;

    while (_--) {
        int n;
        cin >> n;
        vi n_arr(n);
        map<int, int> new_map;

        int ans = 0;
        
        rep(i, 0, n) {
            cin >> n_arr[i];

            if (new_map[MAX_NUM - n_arr[i]]) {
                new_map[MAX_NUM - n_arr[i]]--;
            } else {
                new_map[n_arr[i]]++;
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}