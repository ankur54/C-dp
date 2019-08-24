#include <iostream>
int a[100001], b[100001], c[100001], n, m, i, j, k, l ,r;

int main(int argc, char const *argv[])
{
    std::cin >> n >> m;
    for(; i < n; i++) {
        c[i] = i;
        for(int x; j < m; j++) {
            std::cin >> x;
            if(x < a[j]) b[j] = i;
            a[j] = x;
            if(c[i] > b[j]) c[i] = b[j]; 
        }
    } 

    std::cin >> k;
    while(k--) {
        std::cin >> l >> r;
        if(c[r] <= l) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    return 0;
}
