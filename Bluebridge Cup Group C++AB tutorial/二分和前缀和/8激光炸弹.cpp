#include <cstdio>
#include <iostream>

using namespace std;;

const int N = 5010;
int n, m;
int s[N][N];

int main(){
    int cnt, R;
    cin >> cnt >> R;
    R = min(5001, R);

    n = m = R;
    while(cnt --){
        int x, y, w;
        cin >> x >> y >> w;
        x ++, y ++; //规定坐标从1开始
        n = max(n, x), m = max(m ,y);
        s[x][y] += w;
    }
    //预处理前缀和
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; //这里用+=是因为a[i][j] = s[i][j]

    int res = 0;

    //枚举所有边长是R的矩形， 枚举(i,j)为右下角
    for(int i = R; i <= n; i ++)
        for(int j = R; j <= m; j ++)
            res = max(res, s[i][j] - s[i][j - R] - s[i - R][j] + s[i - R][j - R]);

    cout << res << endl;

    return 0;

}
