#include <bits/stdc++.h>
using namespace std;

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res;
    int n = nums1.size(), m = nums2.size();
    
    if(k == n+m) {
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(nums1[i] > nums2[j]) res.push_back(nums1[i++]);
            else res.push_back(nums2[j++]);
        }
        while(i < n) res.push_back(nums1[i++]);
        while(j < m) res.push_back(nums2[j++]);
    } else {
        pair<int, int> max1[n], max2[m];
        int i = n - 2, j = m - 1;

        max1[n-1] = {nums1[n-1], n-1}, max2[m-1] = {nums2[m-1], m-1};
        while(i >= 0) {
            if(max1[i + 1].first > nums1[i]) max1[i] = max1[i + 1]; 
            else max1[i] = {nums1[i], i};
        }
        while(j >= 0) {
            if(max2[j + 1].first > nums2[j]) max2[j] = max2[j + 1]; 
            else max2[j] = {nums2[j], j};
        }

        i = 0, j = 0;
        while(i < n && j < m && k--) {
            if(max1[i] > max2[j]) res.push_back(max1[i].first), i = max1[i].second;
            else res.push_back(max2[j].first), j = max2[j].second;
        }

        if(k > 0) {
            while(k-- && i < n) res.push_back(max1[i].first), i = max1[i].second + 1;
            while(k-- && j < m) res.push_back(max2[j].first), j = max2[j].second + 1;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
