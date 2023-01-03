// 「0-1 背包」是较为简单的动态规划问题，也是其余背包问题的基础。

// 动态规划是不断决策求最优解的过程，「0-1 背包」即是不断对第 i 个物品做出决策，
// 「0-1」正好代表不选与选两种决定。

// f[i][j]:所有只从前i个物品中选，并且总体积不超过j的选法
//                              需要注意这里是 总体积不超过j的选法,而不是刚好等于j的选法

#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) {
        cin >> v[i] >> w[i];
    }
    // f[0][0~m]:选0件物品  即都为0
    // 所以从i = 1开始
    // 理解i=1,j=0~m:i=1表示只选一件物品的最优解
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            // 当前背包容量不够
            f[i][j] = f[i - 1][j];
            // 当前背包容量足够 不选与选中 取最大值  特别注意：加的是w[i]
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    
    cout << f[n][m] << endl;
    
}

// 优化算法
// f[j]:N件物品,背包容量不超过j的最优解

#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) {
        cin >> v[i] >> w[i];
    }
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = m; j >= v[i]; j -- ) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    cout << f[m] << endl;
    
}