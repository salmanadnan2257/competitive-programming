#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        size_t l_s = s.length();  
        int ind = -1, a = -1, b = -1, c = -1;
        ll sub_string = 20000000000LL; 

        while (ind < static_cast<int>(l_s) - 1) { 
            ind += 1;
            if (s[ind] == '1') {
                a = ind;
            } else if (s[ind] == '2') {
                b = ind;
            } else {
                c = ind;
            }

            if (a >= 0 && b >= 0 && c >= 0) {  
                int max_ind = max({a, b, c});  
                int min_ind = min({a, b, c});  
                ll dis = max_ind - min_ind;
                sub_string = min(sub_string, dis);
            }
        }

        if (sub_string == 20000000000LL) {  
            cout << 0 << endl;
        } else {
            cout << sub_string+1 << endl;
        }
    }

    return 0;
}
