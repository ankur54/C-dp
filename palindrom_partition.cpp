#include <bits/stdc++.h>
using namespace std;

int minCut(string s) {
    int n = s.length();
    vector<int> dp(n + 1, INT_MAX);

    for(int i = 0; i < n; i++) {
        for(int j = 0; i-j >= 0 && i+j < n && s[i - j] == s[i + j]; j++)
            dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
        for(int j = 1; i-j >= 0 && i+j-1 < n && s[i + j - 1] == s[i + j]; j++)
            dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
    }
    return dp[n];
}