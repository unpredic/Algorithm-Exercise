// 项数 = （尾项 - 首项）/ 公差 + 1
// 要使项数最少只能选公差最大（即所有项与第一项的差的最大公约数）

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    
    sort(a, a + n);
    
    int d = 0;
    for (int i = 1; i < n; i ++ ) {
        d = gcd(d, a[i] - a[i - 1]);
    }
    
    if (!d) cout << n << endl;
    else cout << (a[n - 1] - a[0]) / d + 1 << endl;
    
    return 0;
    
}