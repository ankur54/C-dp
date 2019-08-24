#include <bits/stdc++.h>
using namespace std;


int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if(n <= 1) return 0;
    if(k >= n/2) {
        int ans = 0;
        for(int i = 1; i < n; i += 2) ans += max(prices[i] - prices[i - 1], 0);
        return ans;
    }

    int dp[k+1][n];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= k; i++) {
        int localMax = dp[i - 1][0] - prices[0];
        for(int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i][j - 1], prices[j] + localMax);
            localMax = max(localMax, dp[i - 1][j] - prices[j]);
        }
    }

    return dp[k][n - 1];
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    };
    cout << maxProfit(k, arr) << endl;
    return 0;
}
