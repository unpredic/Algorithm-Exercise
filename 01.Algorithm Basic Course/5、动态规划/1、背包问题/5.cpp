// 可转换为01背包问题
#include <iostream>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N][N];

int main() {
    
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j ++ ) {
            cin >> v[i][j] >> w[i][j];
        }
    }
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= s[i]; k ++ ) {
                if (j >= v[i][k]) {
                    f[i][j] = max(f[i][j], f[i - 1][j - v[i][k]] + w[i][k]);
                }
            }
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}

// 01背包问题优化
#include <iostream>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main() {
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
        for (int j = 0; j < s[i]; j ++ ) {
            cin >> v[i][j] >> w[i][j];
        }
    }
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = m; j >= 0; j -- ) {
            for (int k = 0; k < s[i]; k ++ ) {
                if (j >= v[i][k])
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
            }
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}