#include <bits/stdc++.h>
using namespace std;

// Method 1 : Using stack

int longestValidParentheses_1(string s) {
    int n = s.length();
    int ans = 0;
    stack<int> open;
    open.push(-1);

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') open.push(i);
        else {
            open.pop();
            if(open.empty()) open.push(i);
            else ans = max(ans, i - open.top());
        }
    }
    return ans;
}

// Method 2 : DP

int longestValidParentheses_2(string s) {
    int n = s.length();
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 2; i <= n; i++) {
        if(s[i - 1] == ')') {
            if(s[i - 2] == '(') dp[i] = dp[i - 2] + 2;
            else if(s[i - dp[i - 1] - 2] == '(') dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
        }
    }
    return dp[n];
}


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << longestValidParentheses_2(s) << endl;
    return 0;
}
