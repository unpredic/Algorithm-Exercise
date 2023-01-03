// 小于2*N-1时间 即等价于 不走回头路
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, INF = 1e9;

int n;
int a[N][N];
int f[N][N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 0; i <= n; i ++ ) {
        f[0][i] = INF;
        f[i][0] = INF;
    }
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            scanf("%d", &a[i][j]);
            if (i == 1 && j == 1) {
                f[i][j] = a[i][j];
            } else {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
            }
        }
    }
    
    printf("%d\n", f[n][n]);
    
    return 0;
}