#include <iostream>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int v[N];
int f[N][M];

int main() {
    
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        cin >> v[i];
    }
    
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] += f[i - 1][j - v[i]];
            }
        }
    }
    
    cout << f[n][m] << endl;
    
    return 0;
}