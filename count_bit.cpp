#include "bits/stdc++.h"
using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n+1, 0);
    
    for(int i = 0; i <= n; i++) {
        if((i << 1) <= n) dp[(i << 1)] = dp[i];
        if(((i << 1) | 1) <= n) dp[(i << 1) | 1] = dp[i] + 1;
    }
    return dp;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> ans = countBits(n);
    for(auto x: ans) cout << x << " ";
    return 0;
}
