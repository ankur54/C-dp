#include "bits/stdc++.h"
using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
    int row = triangle.size();
    for(int i = row - 2; i >= 0; i--) {
        int n = triangle[i].size();
        for(int j = 0; j < n; j++) 
            triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j + 1]);
    }
    return triangle[0][0];
}

int main(int argc, char const *argv[])
{
    int n;

    return 0;
}
