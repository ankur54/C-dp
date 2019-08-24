#include <bits/stdc++.h>
using namespace std;

bool isScramble(string s1, string s2) {
    // cout << s1 << " " << s2 << endl;
    if(s1 == "" || s2 == "" || s1.length() != s2.length()) return false;
    if(s1 == s2) return true;

    int n = s1.length();
    vector<int> freq(26, 0);
    for(int i = 0; i < n; i++) freq[s1[i] - 'a']++, freq[s2[i] - 'a']--;
    for(int i = 0; i < 26; i++)
        if(freq[i] != 0) return false;
    
    for(int i = 0; i < n; i++) {
        if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
        if(isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))) return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << isScramble(s1, s2) << endl;
    return 0;
}
