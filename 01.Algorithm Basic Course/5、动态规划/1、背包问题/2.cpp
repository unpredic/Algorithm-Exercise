// 朴素做法,时间复杂度太高
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            for (int k = 0; k * v[i] <= j; k ++ ) {
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    
    cout << f[n][m] << endl;
    
}

// 将第三个循环优化掉
// f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
// 
// f[i , j ] = max( f[i-1,j] , f[i-1,j-v]+w ,  f[i-1,j-2*v]+2*w , f[i-1,j-3*v]+3*w , .....)
// f[i , j-v]= max(            f[i-1,j-v]   ,  f[i-1,j-2*v] + w , f[i-1,j-3*v]+2*w , .....)
// 由上两式，可得出如下递推关系： 
//                        f[i][j]=max(f[i,j-v]+w , f[i-1][j]) 

#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
            }
        }
    }
    
    cout << f[n][m] << endl;
    
}

// 优化成一维
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = v[i]; j <= m; j ++ ) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    cout << f[m] << endl;
    
}