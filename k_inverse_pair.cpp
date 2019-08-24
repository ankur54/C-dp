#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int kInveresePairs(int n, int k) {
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k && j <= ((i - 1)*i)/2; j++) {
            if(j == 0) dp[i][j] = 1;
            else {
                int val = (dp[i - 1][j] + MOD - ((j >= i) ? 0 : dp[i - 1][j - i]))%MOD;
                dp[i][j] = (dp[i][j - 1] + val) % MOD;
            }
        }
    }

    return dp[n][k];
}