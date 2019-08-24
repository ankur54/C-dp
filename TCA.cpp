/* Increasing Contigous Array (shorter code) */

#include <iostream>
int n, m, l, t, ptr;
int main() {
    for(std::cin >> n; n; n--, ((ptr > t) ? l = 0 : (m < ++l) ? m = l : m = m), ptr = t) std::cin >> t;
    std::cout << m;
    return 0;
}

//6
// 2 2 1 3 4 1