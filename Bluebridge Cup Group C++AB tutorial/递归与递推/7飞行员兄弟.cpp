// 飞行员问题是枚举所有行的状态，不可以递推实现
// 费解的开关问题是枚举第一行的状态，可以递推实现

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 5;

char g[N][N], backup[N][N];

int get(int x, int y) {
    return x * 4 + y;
}

void turn_one(int x, int y) {
    if (g[x][y] == '-') g[x][y] = '+';
    else g[x][y] = '-';
}

void turn_all(int x, int y) {
    for (int i = 0; i < 4; i ++ ) {
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y);
}

int main() {
    for (int i = 0; i < 4; i ++ ) cin >> g[i];
    
    vector<PII> res;
    memcpy(backup, g, sizeof g);
    
    // 枚举 2^16 种操作
    for (int op = 0; op < 1 << 16; op ++ ) {
        
        vector<PII> temp;
        
        // 进行操作
        for (int i = 0; i < 4; i ++ ) {
            for (int j = 0; j < 4; j ++ ) {
                if (op >> get(i, j) & 1) {
                    turn_all(i, j);
                    temp.push_back({i, j});
                }
            }
        }
        
        // 判断所有操作是否全亮
        bool flag = false;
        for (int i = 0; i < 4; i ++ ) {
            for (int j = 0; j < 4; j ++ ) {
                if (g[i][j] == '+') flag = true;
            }
        }
        
        if (!flag) {
            if (res.empty() || res.size() > temp.size()) {
                res = temp;
            }
        }
        
        memcpy(g, backup, sizeof g);
        
    }
    
    cout << res.size() << endl;
    for (auto t : res) {
        cout << t.first + 1 << " " << t.second + 1 << endl;
    }
    
    return 0;
    
}