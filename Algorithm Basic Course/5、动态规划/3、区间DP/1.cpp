状态表示f[i, j]：表示从i到j这段区间
	->集合：所有将第i堆石子到第j堆石子合并成一堆石子的合并方式的集合
	->属性：MIN(所有合并方式里的代价的最小值)
状态计算：
	状态划分：以最后一次合并的分界线为界

最后一步一定是将两堆合并成一堆

//https://www.acwing.com/solution/content/13945/

#include <iostream>

using namespace std;

const int N = 310;

int n;
int s[N];
int f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
    }
    
    for (int i = 1; i <= n; i ++ ) {
        s[i] += s[i - 1];
    }
    //区间长度从2开始
    for (int len = 2; len <= n; len ++ ) {
        for (int i = 1; i + len - 1 <= n; i ++ ) {
            int l = i, r = i + len - 1;
            f[l][r] = 1e8;
            for (int k = l; k < r; k ++ ) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    
    cout << f[1][n] << endl;
}