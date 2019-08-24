#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;


int numDecodings(string s) {
    int n = s.length();
    if(!n || s[0] == '0') return 0;
    ll dp[n + 1] = {1, ((s[0] == '*') ? 9 : 1)};
    
    for(int i = 2; i <= n; i++) {
        dp[i] += ((s[i-1] == '*') ? (dp[i-1]%MOD * 9ll) % MOD : ((s[i-1] != '0') ? dp[i-1] : 0ll));

        if(s[i-2] == '*') dp[i] += ((dp[i-2]%MOD)*((s[i-1] == '*') ? 15ll : ((s[i-1] <= '6') ? 2ll : 1ll))) % MOD;
        else if(s[i-2] == '1') dp[i] += ((dp[i - 2]%MOD)*((s[i-1] == '*') ? 9ll : 1ll)) % MOD;
        else if(s[i-2] == '2') dp[i] += ((dp[i - 2]%MOD)*((s[i-1] == '*') ? 6ll : ((s[i-1] <= '6') ? 1ll : 0ll))) % MOD;
    }
    
    return dp[n]%MOD;
}

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    cout << numDecodings(s) << endl;
    return 0;
}
