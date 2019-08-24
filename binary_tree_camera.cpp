#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX


typedef struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> minCamCoverUtil(TreeNode* root) {
    if(!root) return {0, 0, INF};

    vector<int> l = minCamCoverUtil(root->left);
    vector<int> r = minCamCoverUtil(root->right);
    int v1 = l[1] + r[1];
    int v2 = min(l[1] + r[2], l[2] + r[1]);
    int v3 = min(l[0], l[1]) + min(r[0], r[1]) + 1;
    return {v1, v2, v3};
}

int minCameraCover(TreeNode* root) {
    vector<int> ans = minCamCoverUtil(root);
    return min(ans[1], ans[2]);
}