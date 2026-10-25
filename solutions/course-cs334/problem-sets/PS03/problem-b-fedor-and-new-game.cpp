#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
using namespace std;
#define vi vector<int>
#define vs vector<string>
#define rep(x,y,z) for (int x = y; x < z; x++)

int main() {
    int n, m, k, x;
    cin >> n >> m >> k;
    size_t len;
    m++;
    vi m_len(m);
    vs m_arr(m);
    vi test(m);
    rep(i, 0, m) {
        cin >> x;
        test[i] = x;
        // len = floor(log2(x) + 1); 
        // string binary = bitset<64>(x).to_string();
        // m_arr[i] = binary.substr(64 - len);
        // m_len[i] = len;
        // cout << m_len[i] << "\n";
    }
    // cout << "\n";

    int ans = 0;
    rep(i, 0, m-1) {
        int check = test[i] ^ test[m-1];
        int diff = 0;
        // cout << "check: " << check << "\n";
        if (check > 0) {
            len = floor(log2(check)+1);
            string binary = bitset<64>(check).to_string();
            binary = binary.substr(64 - len);
            size_t size_check = binary.size();
            // cout << check << " " << binary << " " << size_check << " " << __builtin_popcount(test[i] ^ test[m-1]) << "\n";
            rep(j, 0, size_check) {
                if (binary[j] == '1') {
                    diff++;
                    if (diff > k) {
                        break;
                    }
                }
            }
        } else {
            len = 0;
        }
        // cout << diff << "\n\n";
        if (diff <= k) {
            ans++;
        }
    }

    // int m_itr = m-1;
    // int ans=0;
    // while (m_itr--) {
    //     int iter = min(m_len[m_itr], m_len[m-1]);
    //     int diff = 0;
    //     cout << m_len[m_itr] << " " << m_len[m-1] << "\n";
    //     cout << iter << " " << m_itr << " " << m_arr[m_itr] << " " << m_arr[m-1] << "\n";
    //     cout << to_string(test[m_itr] ^ test[m-1]) << "\n";
    //     cout << to_string(__builtin_popcount(test[m_itr] ^ test[m-1])) << "\n";
    //     while (iter--) {
    //         cout << iter << " " << m_itr << " ";
    //         cout << m_arr[m_itr][iter] << " ";
    //         cout << m_arr[m-1][iter] << "\n";
    //         if (m_arr[m_itr][iter] != m_arr[m-1][iter] && (m_arr[m_itr][iter] == '1' || m_arr[m-1][iter] == '1')) {
    //             diff++;
    //         }
    //         if (diff > k) {
    //             break;
    //         }
    //     }
    //     cout << diff << "\n\n";
    //     if (diff <= k) {
    //         ans++;
    //     }
    // }

    cout << ans << "\n";

    return 0;
}

