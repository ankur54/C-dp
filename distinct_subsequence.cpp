#include <bits/stdc++.h>
using namespace std;


int numDistinct(string s, string t) {
    long long int n = t.length(), m = s.length();
    long long int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= m; i++) dp[0][i] = 1;
    for(int i = 1; i <= m; i++) dp[1][i] = dp[1][i - 1] + (s[i - 1] == t[0]);
    for(int i = 2; i <= n; i++) {
        int count = 0;
        for(int j = i; j <= m; j++) 
            dp[i][j] = (s[j - 1] == t[i - 1]) ? (dp[i - 1][j - 1] + dp[i][j - 1]) : dp[i][j - 1];
    }

    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= m; j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[n][m];
}

int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    cout << "Ans: " << numDistinct(s, t) << endl;
    return 0;
}
