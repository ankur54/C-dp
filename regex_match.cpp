#include "bits/stdc++.h"
using namespace std;


bool regexMatch(string s, string p, int i, int j, vector<vector<int>> &dp) {
    int n = s.length(), m = p.length();
    bool ans;
    if(dp[i][j] > -1) return dp[i][j];

    if(j == m) ans = (i == n);
    else {
        bool initial_cond = (i < n) && ((s[i] == p[j]) || (p[j] == '.'));
        if(j + 1 < m && p[j + 1] == '*') 
            ans = regexMatch(s, p, i, j + 2, dp) || (initial_cond && regexMatch(s, p, i + 1, j, dp));
        else ans = initial_cond && regexMatch(s, p, i + 1, j + 1, dp);
    }

    dp[i][j] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    string s, p;
    cin >> s >> p;
    vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
    cout << regexMatch(s, p, 0, 0, dp) << endl;
    // for(auto x: dp) {
    //     for(auto y:x) cout << y << " ";
    //     cout << endl;
    // }
    return 0;
}
