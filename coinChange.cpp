#include "bits/stdc++.h"
using namespace std;
#define rep(i, s, e) for(int i = s; i < e; i++)


int main(int argc, const char** argv) {
    int dollar;
    int denomination[5] = {1 , 5, 10, 20, 100};
    cin >> dollar;

    int dp[6][dollar + 1];
    rep(i, 0, dollar + 1) dp[0][i] = INT_MAX;
    rep(i, 0, 6) dp[i][0] = 0;

    rep(i, 1, 6) {
        rep(j, 1, dollar + 1) {
            dp[i][j] = dp[i - 1][j];
            if(j >= denomination[i - 1] && dp[i][j - denomination[i - 1]] < INT_MAX) 
                dp[i][j] = min(dp[i][j - denomination[i - 1]] + 1, dp[i][j]);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    cout << dp[5][dollar] << endl;
    return 0;
}