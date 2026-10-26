#include<bits/stdc++.h>
using namespace std;

// --------- Card Game ---------

long long dp[65][65][3];

void solve(int n)
{
    memset(dp, 0, sizeof dp);
    int k = n / 2;
    dp[0][0][2] = 1;
    for(int i = 0; i <= k; i++)
        for(int j = 0; j <= k; j++)
            for(int t = 0; t <= 2; t++)
            {
                int turn = (i + j) % 4;
                if (turn == 0 || turn == 3)
                {
                    if(i < k) dp[i + 1][j][t == 2 ? 0 : t] += dp[i][j][t];
                    if(j < k) dp[i][j + 1][t] += dp[i][j][t];
                }
                else
                {
                    if(i < k) dp[i + 1][j][t] += dp[i][j][t];
                    if(j < k) dp[i][j + 1][t == 2 ? 1 : t] += dp[i][j][t];
                }
            }
    for(int i = 0; i < 3; i++)
        cout << dp[k][k][i] % 998244353 << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        solve(n);
    }
}