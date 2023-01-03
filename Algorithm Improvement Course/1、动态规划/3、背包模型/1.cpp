// 数据范围出错,f的第一维是物品数量，故应为110,f的第二维是体积,故应为1010
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) {
        cin >> v[i] >> w[i];
    }
    
    for (int i = 1; i <= m; i ++ ) {
        for (int j = 0; j <= n; j ++ ) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    
    cout << f[m][n] << endl;
    
    return 0;
}