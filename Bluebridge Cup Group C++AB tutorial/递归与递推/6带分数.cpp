#include <iostream>

using namespace std;

const int N = 10;

int n, res;
int path[N];
bool st[N];

int calc(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i ++ ) {
        res = res * 10 + path[i];
    }
    return res;
}

void dfs(int u) {
    if (u > 9) {
        for (int i = 1; i <= 7; i ++ ) {
            for (int j = i + 1; j <= 8; j ++ ) {
                int a = calc(1, i);
                int b = calc(i + 1, j);
                int c = calc(j + 1, 9);
                if (n * c == a * c + b) res ++ ;
            }
        }
        return;
    }
    
    for (int i = 1; i < 10; i ++ ) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
    
}

int main() {
    cin >> n;
    
    dfs(1);
    
    cout << res << endl;
    
    return 0;
    
}