#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans=0;
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else{
            n--;ans++;
        }
    }
    cout << ans+1;

    return 0;
}

