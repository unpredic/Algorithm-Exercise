#include <iostream>

using namespace std;

const int N = 110;

int t, r, c;
int a[N][N];
int f[N][N];

int main() {
    scanf("%d", &t);
    while (t -- ) {
        scanf("%d%d", &r, &c);
        for (int i = 1; i <= r; i ++ ) {
            for (int j = 1; j <= c; j ++ ) {
                scanf("%d", &a[i][j]);
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
            }
        }
        printf("%d\n", f[r][c]);
    }
    return 0;
}