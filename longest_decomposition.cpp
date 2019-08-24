#include <bits/stdc++.h>
using namespace std;


int longestDecomposition(string s) {
    int n = s.length();
    int i = 0, j = n - 1;
    string str = "";
    while(str != s.substr(i, str.length())) {
        while(j > i && s[j] != s[i]) str = s[j--] + str;
        str = s[j] + str;
    }

    if(j == i) return 1;
    return 2 + longestDecomposition(s.substr(str.length(), n - 2*str.length()));
}