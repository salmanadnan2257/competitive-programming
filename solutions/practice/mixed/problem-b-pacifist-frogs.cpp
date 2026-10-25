#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, int k, vector<pair<int, int>> m_arr, vector<int> k_arr) {

    int ind=0, ind_2=-1;
    int diff = 0;
    while (ind < k) {
        diff = k_arr[ind];
        ind_2 = 0;
        while (ind_2 < m) {
            if (diff - m_arr[ind_2].first < 0) {
                ind_2++;
                continue;
            }
            if (diff % m_arr[ind_2].first == 0) {
                m_arr[ind_2].second+=1;
            }
            ind_2++;
        }
        ind++;
    }

    int count = 0;
    int min = n;
    vector<int> ans_ind;
    for (int i = 0; i < m; i++) {
        if (m_arr[i].second == min) {
            count++;
            ans_ind.push_back(i+1);
        } else if (m_arr[i].second < min) {
            min = m_arr[i].second;
            count = 1;
            ans_ind = {i+1};
        }
    }

    cout << count << "\n";
    for (auto &x: ans_ind) cout << x << " ";
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> k_arr(k);
    vector<pair<int, int>> m_arr;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        m_arr.push_back({x, 0});
    }
    for (auto &x: k_arr) cin >> x;
    solve(n, m, k, m_arr, k_arr);

    return 0;
}
