#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    vector<unordered_map<long long, int>> numSeq(n);
    ll ans = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            ll diff = (ll)A[i] - (ll)A[j];
            int sum = 0;
            if(numSeq[j].find(diff) != numSeq[j].end()) sum = numSeq[j].count(diff);
            numSeq[i][diff] += sum + 1;
            ans += (ll)sum;
        }
    }
    return ans;
}