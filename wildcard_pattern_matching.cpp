#include "bits/stdc++.h"
using namespace std;

bool isMatch(string s, string p) {
    int n = s.length(), m = p.length();
    int i = 0, j = 0;
    int check_star = -1, str_pos = -1;

    while(i < n) {
        if(j < m && p[j] == s[i]) i++, j++;
        else if(j < m && p[j] == '?') i++, j++;
        else if(j < m && p[j] == '*') str_pos = i, check_star = j++;
        else if(check_star != -1) i = str_pos++ + 1, j = check_star + 1;
        else return false;
    }

    while(j < m && p[j] == '*') j++;
    if(j == m) return true;
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
