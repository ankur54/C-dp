#include <iostream>
typedef long long int ll;
ll cnt[2][(1 << 20) + 5];
ll n, c, ans;

int main(int argc, char const *argv[])
{
    cnt[0][0] = 1;
    scanf("%lld", &n);
    for(int i = 1, x; i <= n; i++) std::cin >> x, ans += cnt[(i & 1ll)][c ^= x]++;
    std::cout << ans;    
    return 0;
}


/*
Concepts:
    * prefex[i] = prefex[j] :===>  prefex[i,j] = 0     ;     prefex[x] = a[0] ^ a[1] ^ ... ^ a[n - 2] ^ a[n - 1]
    * odd - odd = odd,  even - even = even
*/