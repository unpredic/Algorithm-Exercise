#include <iostream>

using namespace std;

const int N = 110;

int a[N][N];
int f[N][N];

int main() {
    
    int t;
    cin >> t;
    
    while (t -- ) {
        int r, c;
        cin >> r >> c;
        for (int i = 1; i <= r; i ++ ) {
            for (int j = 1; j <= c; j ++ ) {
                cin >> a[i][j];
                f[i][j] = max(f[i][j - 1], f[i - 1][j]) + a[i][j];
            }
        }
        
        cout << f[r][c] << endl;
        
    }
    
    return 0;
}