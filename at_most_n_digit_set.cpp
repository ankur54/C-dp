#include <bits/stdc++.h>
using namespace std;


int atMostNGivenDigitSet(vector<string>& D, int N) {
    int n = D.size(), m = N;
    string num = to_string(N);
    vector<int> lesser(10, 0);
    unordered_set<int> contain;

    for(string x:D) contain.insert(stoi(x));
    for(int i = 1, j = 0; i < 10; i++) {
        lesser[i] += lesser[i - 1];
        while(j < n && stoi(D[j]) < i) lesser[i]++, j++; 
    }

    if(N >= 1 && N <= 9) return lesser[N] + (contain.find(N) != contain.end());     

    int digits = num.length();

    long long ans = (n * pow(n, digits - 1))/(n - 1);
    int extra = 0;
    for(int i = 0; i < digits; i++) {
        extra += (lesser[num[i] - '0']) * pow(n, digits - i - 1);
        if(contain.find(num[i] - '0') == contain.end()) {
            extra = 0;
            break;
        }
    }

    extra++;
    for(char x : num) 
        if(contain.find(x - '0') == contain.end()) {
            extra -= 1;
            break;
        }
    return ans + extra;
}