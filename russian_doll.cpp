#include <bits/stdc++.h>
using namespace std;

int ceilIndex(vector<int> &A, int l, int r, int val) {
    int idx = 0;
    while(l <= r) {
        int mid = (l + r)/2;
        if(A[mid] < val) l = mid + 1;
        else if(A[mid] > val) idx = mid, r = mid - 1;
        else {
            idx = mid;
            break;
        }
    }
    return idx;
}

int lis(vector<vector<int>> &A) {
    int n = A.size(), len = 0;
    vector<int> B = {A[0][1]};
    for(int i = 0; i < n; i++) {
        if(A[i][1] < B[0]) B[0] = A[i][1];
        else if(A[i][1] > B[len]) B.push_back(A[i][1]);
        else B[ceilIndex(B, 0, len, A[i][1])] = A[i][1];
    }
    return len;
}

int russianDollEnvelope(vector<vector<int>> &envelope) {
    sort(envelope.begin(), envelope.end(), [] (const vector<int> &a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    return lis(envelope);
}