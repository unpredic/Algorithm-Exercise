//https://www.acwing.com/solution/content/8747/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 10;
int n;
char g[N][N], backup[N][N];
int dx[] = {-1, 0, 1, 0, 0}, dy[] = {0, 1, 0, -1, 0};

void turn(int x, int y) {
    for (int i = 0; i < 5; i ++ ) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < 5 && b >= 0 && b < 5) {
            // 0011 0000	0
            // 0011 0001	1
            g[a][b] ^= 1;   //异或最后一位二进制数
        }
    }
}

int main() {
    cin >> n;
    while (n -- ) {
        for (int i = 0; i < 5; i ++ ) {
            cin >> g[i];
        }
        
        int res = 10;
        
        // 这里我们枚举了第一行的32种按法，不用管是亮是灭，把第一行所有情况都按一遍
        // (如op = 0表示第一行不按 op = 1表示按最后一个灯的开关 以此类推...)
        // 按每种情况的第一行，去遍历接下来的行
        // 枚举32种第一行的按法只是可能会减少步数，如果直接从第二行开始答案一定是固定的了，找不到最优解或者可能没有解
        for (int op = 0; op < 32; op ++ ) {
            memcpy(backup, g, sizeof g);
            
            int step = 0;
            
            // 枚举第 0 行
            for (int i = 0; i < 5; i ++ ) {
                if (op >> i & 1) {
                    step ++ ;
                    turn(0, i);
                }
            }
            
            // 枚举接下来的1 ~ 4行
            for (int i = 0; i < 4; i ++ ) {
                for (int j = 0; j < 5; j ++ ) {
                    //  i表示当前行的前一行
                    if (g[i][j] == '0') {
                        step ++ ;
                        turn(i + 1, j);
                    }
                }
            }
            
            // 判断最后一行的状态是否有灯没亮的
            bool dark = false;
            for (int i = 0; i < 5; i ++ ) {
                if (g[4][i] == '0') dark = true;
            }
            
            if (!dark) res = min(res, step);
            
            // 备份回去，尝试另一种方式，找到最小次数
            memcpy(g, backup, sizeof g);
            
        }
        
        if (res > 6) res = -1;
        cout << res << endl;
        
    }
    
    return 0;
}