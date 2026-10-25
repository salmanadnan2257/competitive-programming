#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, x, y;
    cin >> n >> m >> k;
    cin.ignore();
    // vector<vector<int>> chat_emp(m), mess_sent(m);
    // vector<int> notifs_rec(n, 0);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cin >> x;
    //         if (x == 1) {
    //             chat_emp[j].push_back(i);
    //         }
    //     }
    // }

    // int ind = 0;
    // int chat = 0, emp = 0;
    // for (int i = 0; i < k; i++) {
    //     cin >> x >> y;
    //     mess_sent[y-1].push_back(x-1);
    //     chat = y-1;
    //     emp = x-1;
    //     for (int j = 0; j < chat_emp[chat].size(); j++) {
    //         ind = static_cast<int>(chat_emp[chat][j]);
    //         if (ind != emp) {
    //             notifs_rec[ind] += 1;
    //         }
    //     }
    // }

    vector<string> testing;
    string line;
    for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++) {
        //     cin >> x;
        //     if (x == 1) {
        //         chat_emp[j].push_back(i);
        //     }
        // }
        getline(cin, line);
        // cin.ignore();
        testing.push_back(line);
    }
    // for (auto &line: testing) cout << line << "\n";

    int chat = 0;
    int emp = 0;
    int ind = 0;
    int find_ind = 0;
    char check;
    vector<int> notifs_rec(n);
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        chat = 2 * (y-1);
        emp = x-1;
        for (int j = 0; j < n; j++) {
            // chat = 2 * (j);
            ind = static_cast<int>(testing[emp][chat]);
            check = testing[j][chat];
            // cout << emp << " " << chat << " " << ind << " " << check << endl;
            if (j == emp) continue;
            if (check == '1') {
                notifs_rec[j] += 1;
            }
        }
        // cout << testing[emp][chat] << endl;
    }
    for (auto &x: notifs_rec) cout << x << " ";

    // for (auto &x: chat_emp) {
    //     for (auto &y: x) cout << y << " ";
    //     cout << endl;
    // }
    // cout << endl;

    // for (auto &x: mess_sent) {
    //     for (auto &y: x) cout << y << " ";
    //     cout << endl;
    // }
    // cout << endl;

    // int size = 0, size_2 = 0;
    // for (int i = 0; i < m; i++) {
    //     size = mess_sent[i].size();
    //     for (int j = 0; j < size; j++) {
    //         for (int k = i; k < i+1; k++) {
    //             size_2 = chat_emp[k].size();
    //             for (int l = 0; l < size_2; l++) {
    //                 // cout << i << " " << j << " " << mess_sent[i][j] << endl;
    //                 // cout << k << " " << l << " " << chat_emp[k][l] << endl;
    //                 if (chat_emp[k][l] != mess_sent[i][j]) {
    //                     ind = static_cast<int>(chat_emp[k][l]);
    //                     notifs_rec[ind] += 1;
    //                     // cout << "Adding: " << chat_emp[k][l] << " " << mess_sent[i][j] << " " << notifs_rec[l] << endl;
    //                 }
    //             }
    //         }
    //     }
    // }



    // for (auto &x: notifs_rec) cout << x << " ";

    return 0;
}
