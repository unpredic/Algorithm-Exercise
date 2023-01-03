#include <iostream>

using namespace std;

const int N = 40, M = 20010;

int n;
int f[N][M];

int main() {
    
    int m;
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ ) {
        int v;
        cin >> v;
        for (int j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j];
            if (j >= v) f[i][j] = max(f[i][j], f[i - 1][j - v] + v);
        }
    }
    
    cout << m - f[n][m] << endl;
    
    return 0;
}