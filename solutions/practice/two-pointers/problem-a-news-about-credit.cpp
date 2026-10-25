// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// bool aa(int x, int y) {
//     return x > y;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     vector<bool> check(n, false);
//     check[0] = true;
//     int false_left = n-1;

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int op = 0;
//     vector<vector<int>> ans;
//     if (arr[0] == '0') {
//         return 0;
//     }

//     int i = 0;
//     sort(arr.begin()+1, arr.end(), aa);
//     // cout << "Checking start" << endl;
//     // for (int i = 0; i < n; i++) {
//     //         cout << arr[i] << endl;
//     //     }
//     // cout << "Checking end" << endl;
//     while (i < n && false_left > 0) {
//         int j = i + 1;
//         while (arr[i] > 0 && j < n) {
//             // cout << i << " " << arr[i] << endl;
//             if (false_left == 0) {
//                 break;
//             }
//             if (check[j] == true) {
//                 j++;
//                 continue;
//             }
//             // cout << j << " " << check[j] << endl;
//             if (arr[i] == '1' && j == n - 1) {
//                 op++;
//                 arr[i]--;
//                 false_left--;
//                 check[j] = true;
//                 ans.push_back({i+1, j+1});
//             } else {
//                 arr[i]--;
//                 op++;
//                 false_left--;
//                 check[j] = true;
//                 ans.push_back({i+1, j+1});
//             }
//             j++;
//             // cout << "mid" << endl;
//             // cout << i << " " << arr[i] << endl;
//         }
//         i++;
//         if (false_left == 0) {
//             break;
//         }
//     }

//     // cout << false_left << endl;
//     // cout << "Checking start" << endl;
//     // for (int i = 0; i < ans.size(); i++) {
//     //         cout << ans[i][0] << " " << ans[i][1] << endl;
//     //     }
//     // cout << "Checking end" << endl;

//     if (false_left == 0) {
//         cout << op << endl;
//         for (int i = 0; i < ans.size(); i++) {
//             cout << ans[i][0] << " " << ans[i][1] << endl;
//         }
//     } else {
//         cout << -1 << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second; 
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n); 
    vector<bool> check(n, false);
    check[0] = true;
    int false_left = n - 1;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr[i] = {i, val}; 
    }

    int op = 0;
    vector<vector<int>> ans;

    if (arr[0].second == 0) {
        cout << -1 << endl;
        return 0;
    }

    int i = 0;
    

    sort(arr.begin() + 1, arr.end(), cmp);


    unordered_map<int, int> index_map;
    for (int j = 0; j < n; j++) {
        index_map[arr[j].first] = j;
    }

    while (i < n && false_left > 0) {
        int j = i + 1;
        while (arr[i].second > 0 && j < n) {
            if (false_left == 0) break;
            if (check[arr[j].first]) {
                j++;
                continue;
            }

            if (arr[i].second == 1 && j == n - 1) {
                op++;
                arr[i].second--;
                false_left--;
                check[arr[j].first] = true;
                ans.push_back({arr[i].first + 1, arr[j].first + 1});
            } else {
                arr[i].second--;
                op++;
                false_left--;
                check[arr[j].first] = true;
                ans.push_back({arr[i].first + 1, arr[j].first + 1});
            }
            j++;
        }
        i++;
    }

    if (false_left == 0) {
        cout << op << endl;
        for (const auto& pair : ans) {
            cout << pair[0] << " " << pair[1] << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}

