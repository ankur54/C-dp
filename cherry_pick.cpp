#include <bits/stdc++.h>
using namespace std;

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else if(i == 0) dp[i][j] = (dp[i - 1][j] != -1 && grid[i][j] != -1) ? dp[i - 1][j] + grid[i][j] : -1 ;
            else if(j == 0) dp[i][j] = (dp[i][j - 1] != -1 && grid[i][j] != -1) ? dp[i][j - 1] + grid[i][j] : -1;
            else {
                if(grid[i][j] == -1) dp[i][j] = -1;
                else {
                    if(dp[i - 1][j] == -1 && dp[i][j - 1] == -1) dp[i][j] = -1;
                    else if(dp[i - 1][j] == -1) dp[i][j] = dp[i][j - 1] + grid[i][j]; 
                    else if(dp[i][j - 1] == -1) dp[i][j] = dp[i - 1][j] + grid[i][j]; 
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
    }

    return dp[n - 1][n - 1];
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; i++) cin >> grid[i][j];

    cout << cherryPickup(grid) << endl;
    return 0;
}
