#include <iostream>

using namespace std;

const int N = 1010, M = 510, K = 110;

// f[i][j][k]:所有只从前i个物品去选，且花费1不超过j，花费2不超过k的最大价值
// C，R，分别表示最多收服C个小精灵，以及收服C个小精灵时皮卡丘的剩余体力值最多为R。
// 最多收服C个小精灵即表示最大价值
// 本题中：f[k][i][j]:类比于背包问题，i和j代表体积，k代表物品
int n, m, k; // N，M，K，分别代表小智的精灵球数量、皮卡丘初始的体力值、野生小精灵的数量。
int v[N], w[M];
int f[K][N][M];

int main() {
    
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++ ) {
        cin >> v[i] >> w[i];
    }
    
    for (int i = 1; i <= k; i ++ ) {
        for (int j = 0; j <= n; j ++ ) {
            for (int u = 0; u <= m; u ++ ) {
                f[i][j][u] = f[i - 1][j][u];
                if (u >= w[i] && j >= v[i]) {
                    f[i][j][u] = max(f[i][j][u], f[i - 1][j - v[i]][u - w[i]] + 1);
                }
            }
        }
    }
    
    cout << f[k][n][m] << " ";
    
    int res = m;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= n; j ++ ) {
            for (int u = 0; u <= m; u ++ ) {
                if (f[i][j][u] == f[k][n][m]) {
                    res = min(res, u);
                }
            }
        }
    }
    cout << m - res << endl;
    
    return 0;
}

