#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9, M = 1 << N;

// ones[i]:表示i的二进制数有多少个1
// map可以快速找出这行哪一列可以填，比如map[16]=4
int ones[M], map[M];
// 分别表示行，列，大方格子有哪些数字没有填
int row[N], col[N], cell[3][3];
char str[100];

// 预处理行、列和九宫格三个数组
void init() {
    for (int i = 0; i < N; i ++ ) {
        row[i] = col[i] = (1 << N) - 1;
    }
    for (int i = 0; i < 3; i ++ ) {
        for (int j = 0; j < 3; j ++ ){
            cell[i][j] = (1 << N) - 1;
            // cout << cell[i][j] << " ";
        }
    }
}

// draw(0, 0, 3, true);
void draw(int x, int y, int t, bool is_set) {
    if (is_set) {
        str[x * N + y] = '1' + t;
    }
    else str[x * N + y] = '.';

    int v = 1 << t;
    if (!is_set) v = -v;

    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

int lowbit(int x) {
    return x & -x;
}

int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
    // 填完所有数字，则返回
    if (!cnt) return true;
    // 最多可以填多少个数字
    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i ++ ) {
        for (int j = 0; j < N; j ++ ) {
            if (str[i * N + j] == '.') {
                int state = get(i, j);
                if (ones[state] < minv) {
                    minv = ones[state];
                    x = i, y = j;
                }
            }
        }
    }
    int state = get(x, y);
    for (int i = state; i; i -= lowbit(i)) {
        int t = map[lowbit(i)];
        draw(x, y, t, true);
        if (dfs(cnt - 1)) return true;
        draw(x, y, t, false);
    }

    return false;
}

int main()
{
    for (int i = 0; i < N; i ++ ) map[1 << i] = i;
    for (int i = 0; i < 1 << N; i ++ )
        for (int j = 0; j < N; j ++ )
            ones[i] += i >> j & 1;

    while (cin >> str, str[0] != 'e') {
        init();
        // 计算有多少个 '.',即有多少个数未填
        int cnt = 0;
        for (int i = 0, k = 0; i < N; i ++ ){
            for (int j = 0; j < N; j ++, k ++ ) {
                if (str[k] != '.'){
                    int t = str[k] - '1';
                    draw(i, j, t, true);
                } else cnt ++ ;
            }
        }
        dfs(cnt);
        puts(str);
    }

    return 0;
}