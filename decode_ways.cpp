#include <bits/stdc++.h>
using namespace std;


int numDecodings(string s) {
    int n = s.length();
    if(!n || s[0] == '0') return 0;
    int dp[n + 1] = {1, 1};
    
    for(int i = 2; i <= n; i++)
        dp[i] += (int)(s[i-1] != '0')*dp[i-1] + (int)(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))*dp[i - 2];
    
    return dp[n];
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    cout << numDecodings(s) << endl;
    return 0;
}
