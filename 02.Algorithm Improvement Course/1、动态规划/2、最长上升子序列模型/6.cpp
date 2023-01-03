// dp + 贪心
#include <iostream>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N], g[N];

int main() {
    
    while (cin >> a[n]) n ++ ;
    
    int res = 0;
    for (int i = n - 1; i >= 0; i -- ) {
        f[i] = 1;
        for (int j = n - 1; j > i; j -- ) {
            if (a[i] >= a[j]) f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
    
    int cnt = 0; // 子序列数量
    for (int i = 0; i < n; i ++ ) {
        int k = 0; // g[0]:存储0序列的最小高度 g[1]:存储1序列的最小高度
        while (k < cnt && g[k] < a[i]) {
            k ++ ;
        }
        g[k] = a[i];
        if (k >= cnt) cnt ++ ;
    }
    
    cout << cnt << endl;
    
    return 0;
}