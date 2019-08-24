#include <bits/stdc++.h>
using namespace std;

vector<int> coinPath(vector<int> &cost, int B) {
    int n = cost.size();
    long dp[n], next[n];
    memset(dp, 0, sizeof dp);
    memset(next, -1, sizeof next);

    for(int i = n - 2; i >= 0 && cost[i] >= 0; i--) {
        long min_cost = INT_MAX;
        for(int j = i + 1; cost[j] >= 0 && j <= i + B && j < n; j++) {
            long coin = cost[i] + dp[j];
            if(coin < min_cost) {
                min_cost = coin;
                next[i] = j;
            }
        }
        dp[i] = min_cost;
    }

    vector<int> path;
    int i;
    for(i = 0; i < n && next[i] >= 0; i++) path.push_back(i + 1);
    if(i == n && cost[i] >= 0) {
        path.push_back(n);
        return path;
    }
    return vector<int> ();
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
