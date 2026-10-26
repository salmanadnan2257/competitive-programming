// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     for (int test_case = 1; test_case <= t; test_case++) {
//         int n=0, op=0;
//         cin >> n;
//         vector<int> n_arr(n);
//         for (auto &x: n_arr) cin >> x;

//         // if (t == 10000 && (test_case >= 110)) {
//         //     // cout << "Test Case #" << test_case << ":\n";
//         //     cout << n << "\n";
//         //     // cout << "Array: ";
//         //     for (auto x : n_arr) cout << x << " ";
//         //     cout << "\n";
//         //     continue;
//         // } else if (t == 10000) {
//         //     continue;
//         // }

//         int left = n/2;
//         while (left > 0 && n_arr[left]==n_arr[left+1]) {
//             left--;
//         }
//         int right = left+1;

//         // left--;
//         int swap_ind=0, swap_ind_2=0;
//         int temp=0;
//         int check=0;
//         while (left > 0) {
//             if (n_arr[left] == n_arr[left-1]) {
//                 cout << "Inner" << endl;
//                 if (left-2 >=0 && n_arr[left-2] == n_arr[left-1]) {
//                     left--;
//                 }
//                 swap_ind = n - (left + 1);
//                 swap_ind_2 = n - (left);
//                 check = n_arr[left];
//                 if (((n_arr[swap_ind-1] != check) || (swap_ind-1 == left && n_arr[swap_ind] != check)) && ((swap_ind+1 < n && n_arr[swap_ind+1] != check) || swap_ind+1==n)) {
//                     cout << "Inner 1" << endl;
//                     temp = n_arr[swap_ind];
//                     n_arr[swap_ind] = n_arr[left];
//                     n_arr[left] = temp;
//                 } else if (n_arr[swap_ind_2-1] != check && ((swap_ind_2+1 < n && n_arr[swap_ind_2+1] != check) || swap_ind_2+1==n)) {
//                     cout << "Inner 2" << endl;
//                     // cout << "Coming in" << endl;
//                     // cout << swap_ind_2 << " " << n_arr[swap_ind_2-1] << " " << n_arr[left-1] << " ";
//                     // if (swap_ind_2+1 < n) {
//                     //     cout << n_arr[swap_ind_2+1] << endl;
//                     // } else {
//                     //     cout << "n_arr[swap_ind_2]+1 == n" << endl;
//                     // }
//                     temp = n_arr[swap_ind_2];
//                     n_arr[swap_ind_2] = n_arr[left-1];
//                     n_arr[left-1] = temp;
//                 } else if (((n_arr[swap_ind-1] != check) || (swap_ind-1 == left && n_arr[swap_ind] != check)) || ((swap_ind+1 < n && n_arr[swap_ind+1] != check) || swap_ind+1==n)) {
//                     cout << "Inner 3" << endl;
//                     temp = n_arr[swap_ind];
//                     n_arr[swap_ind] = n_arr[left];
//                     n_arr[left] = temp;
//                 } else if (n_arr[swap_ind_2-1] != check || ((swap_ind_2+1 < n && n_arr[swap_ind_2+1] != check) || swap_ind_2+1==n)) {
//                     cout << "Inner 4" << endl;
//                     // cout << "Coming in" << endl;
//                     // cout << swap_ind_2 << " " << n_arr[swap_ind_2-1] << " " << n_arr[left-1] << " ";
//                     // if (swap_ind_2+1 < n) {
//                     //     cout << n_arr[swap_ind_2+1] << endl;
//                     // } else {
//                     //     cout << "n_arr[swap_ind_2]+1 == n" << endl;
//                     // }
//                     temp = n_arr[swap_ind_2];
//                     n_arr[swap_ind_2] = n_arr[left-1];
//                     n_arr[left-1] = temp;
//                 }
//                 // else {
//                 //     temp = n_arr[swap_ind];
//                 //     n_arr[swap_ind] = n_arr[left];
//                 //     n_arr[left] = temp;
//                 //     // op += 1;
//                 // }

//                 // op += 1;
//             }
//             left--;
//         }
//         // cout << "First " << right << endl;
//         // for (auto &x: n_arr) cout << x << " ";
//         // cout << endl;

//         right++;
//         while (right < n) {
//             // if (n_arr[right] == n_arr[right-1]) {
//             //     swap_ind = n - (right + 1);
//             //     temp = n_arr[swap_ind];
//             //     n_arr[swap_ind] = n_arr[right];
//             //     n_arr[right] = temp;
//             //     // op += 1;
//             // }
//             if (n_arr[right] == n_arr[right-1]) {
//                 cout << "Enter" << endl;
//                 if (right+1 < n && n_arr[right+1] == n_arr[right]) {
//                     right++;
//                 }
//                 swap_ind = n - (right + 1);
//                 swap_ind_2 = n - (right);
//                 check = n_arr[right];
//                 // if (n_arr[swap_ind-1] != check && ((swap_ind+1 < n && n_arr[swap_ind] != check) || swap_ind+1==n)) {
//                 if (((n_arr[swap_ind_2+1] != check) || (swap_ind_2+1 == right-1 && n_arr[swap_ind_2] != check)) && ((swap_ind_2-1>=0 && n_arr[swap_ind_2-1] != check) || (swap_ind_2 == -1))) {
//                     cout << "Enter 1" << endl;
//                     temp = n_arr[swap_ind_2];
//                     n_arr[swap_ind_2] = n_arr[right-1];
//                     n_arr[right-1] = temp;
//                 } else if ((n_arr[swap_ind+1] != check) && ((swap_ind-1>=0 && n_arr[swap_ind-1] != check) || swap_ind == -1)) {
//                     cout << "Enter 2" << endl;
//                     temp = n_arr[swap_ind];
//                     n_arr[swap_ind] = n_arr[right];
//                     n_arr[right] = temp;
//                 } else if (((n_arr[swap_ind_2+1] != check) || (swap_ind_2+1 == right && n_arr[swap_ind_2] != check)) || ((swap_ind_2-1>=0 && n_arr[swap_ind_2-1] != check) || swap_ind_2 == -1)) {
//                     cout << "Enter 3" << endl;
//                     temp = n_arr[swap_ind_2];
//                     n_arr[swap_ind_2] = n_arr[right-1];
//                     n_arr[right-1] = temp;
//                 } else if ((n_arr[swap_ind+1] != check) || ((swap_ind-1>=0 && n_arr[swap_ind-1] != check) || swap_ind == -1)) {
//                     cout << "Enter 4" << endl;
//                     temp = n_arr[swap_ind];
//                     n_arr[swap_ind] = n_arr[right];
//                     n_arr[right] = temp;
//                 }
//                 // else {
//                 //     temp = n_arr[swap_ind];
//                 //     n_arr[swap_ind] = n_arr[right];
//                 //     n_arr[right] = temp;
//                 //     // op += 1;
//                 // }
//             }
//             right++;
//         }
//         // cout << "Second" << endl;
//         // for (auto &x: n_arr) cout << x << " ";
//         // cout << endl;

//         int ind=0;
//         while (ind < n-1) {
//             ind++;
//             if (n_arr[ind] == n_arr[ind-1]) {
//                 op += 1;
//             }
//         }

//         // if (t != 10000) {}
//         cout << op << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> n_arr) {
    for (int i = 1; i < n / 2; i++) {
        if (n_arr[i] == n_arr[i-1] || n_arr[n-i-1] == n_arr[n-i]) {
            swap(n_arr[i], n_arr[n-(i+1)]);
        }
    }

    int count = 0;
    for (int i = 1; i < n; i++) {
        if (n_arr[i] == n_arr[i-1])
            count++;
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-- ) {
        int n;
        cin >> n;
        vector<int> n_arr(n);
        for (auto &x: n_arr) cin >> x;
        solve(n, n_arr);
    }

    return 0;
}
