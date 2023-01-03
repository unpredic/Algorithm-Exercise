状态表示f[i, j]
    ->集合：所有从起点，走到(i, j)的路径
    ->属性：MAX（集合当中的所有路径之和的最大值）

//状态表示f[i, j]:
//  ->集合:所有到点(i, j)的路径的集合
//  ->属性:MAX(集合中的路径的最大值)
//状态计算:
//  ->状态划分:

//从上到下计算
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e9;

int a[N][N];
int f[N][N];    //f[i][j]表示从(0, 0)走到(i, j)的路径最大值

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= i; j ++ ) {
            cin >> a[i][j];
        }
    }
    
    //处理边界问题、、多处理一个
    for (int i = 0; i <= n; i ++ ) {
        for (int j = 0; j <= i + 1; j ++ ) {
            f[i][j] = -INF;
        }
    }
    
    f[1][1] = a[1][1];

    for (int i = 2; i <= n; i ++ ) {
        for (int j = 1; j <= i; j ++ ) {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
        }
    }
    
    int res = -INF;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);
    
    cout << res << endl;
    
}

//从下到上计算
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n;
int a[N][N];
int f[N][N];

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= i; j ++ ) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i ++ ) f[n][i] = a[n][i];
    
    for (int i = n - 1; i; i -- ) {
        for (int j = 1; j <= i; j ++ ) {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
        }
    }
    
    cout << f[1][1] << endl;
    
}