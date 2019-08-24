#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> dp;

vector<string> wordBreakUtil(string s, unordered_set<string> &dict) {
    if(dp[s].size() != 0) return dp[s]; 
    int n = s.length();
    if(n == 0) return {};

    vector<string> ans;
    string curr = "";
    for(int i = 0; i < n; i++) {
        curr += s[i];
        if(dict.count(curr) != 0) {
            vector<string> temp = wordBreakUtil(s.substr(i + 1), dict);
            for(string x:temp) ans.push_back(curr + " " + x);
            if(i == n-1) {
                ans.push_back(curr);
                dp[s] = ans;
            }
        }
    }

    dp[s] = ans;
    return ans;
}

// Shorter version of above function:
vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
    unordered_map<int, vector<string>> memo {{s.length(), {""}}};
    int n = s.length();

    function<vector<string>(int)> sentence = [&] (int i) {
        if(!memo[i].size()) 
            for(int j = i + 1; j <= n; j++) 
                if(wordDict.count(s.substr(i, j-i))) 
                    for(auto x:sentence(j)) 
                        memo[i].push_back(s.substr(i, j-i) + (x == "" ? "" : " ") + x);
                
        return memo[i];
    };

    return sentence(0);
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    // return wordBreakUtil(s, dict);
    return wordBreak(s, dict);
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> arr;
    for(int i = 0; i < n; i++) {
        string x;
        cin >> x;
        arr.push_back(x);
    }
    vector<string> ans = wordBreak(s, arr);
    for(auto x:ans) cout << x << endl;
    return 0;
}
