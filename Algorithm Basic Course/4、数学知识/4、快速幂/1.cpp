// 4^4 % 5 = 1;

// a = 4, b = 4, p = 5;

// 最后求出的幂结果实际上就是在变化过程中所有当指数为奇数时底数的乘积。

#include <iostream>

using namespace std;

typedef long long LL;

int kmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        // b的二进制最低位是否为1
        if (b & 1) res = (LL) res * a % p;
        b >>= 1;
        a = (LL) a * a % p;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    
    while (n -- ) {
        int a, b, p;
        //数据范围大建议用scanf
        scanf("%d%d%d", &a, &b, &p);
        printf("%d\n", kmi(a, b, p));
    }
    
    return 0;
}