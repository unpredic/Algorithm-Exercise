// 子序列可以不连续，但必须从前往后

//状态表示f[i, j]:
//  ->集合:所有在第一个序列的前i个字母中出现，且在第二个序列的前j个字母中出现的子序列
//  ->属性:MAX(集合中的最长长度)
//状态计算:
//  状态划分:00|01|10|11 -> f[i - 1][j - 1], f[i - 1][j], f[i][j - 1], f[i - 1][j - 1] + 1

#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {
    cin >> n >> m;
    cin >> a + 1 >> b + 1;
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
    
}