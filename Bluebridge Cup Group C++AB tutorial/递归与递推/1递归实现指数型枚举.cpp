//递归实现指数型枚举
#include <iostream>

using namespace std;

const int N = 20;

int n;
int st[N];

void dfs(int u) {
    if (u > n) {
        for (int i = 1; i <= n; i ++ ) {
            if (st[i] == 1) cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    //每一层都有选与不选两种方案 顺序没关系
    st[u] = 2;  //不选
    dfs(u + 1);
    st[u] = 0;
    
    st[u] = 1;  //选
    dfs(u + 1);
    st[u] = 0;
    
}

int main() {
    cin >> n;
    
    dfs(1);
    
    return 0;
    
}

#include <iostream>

using namespace std;

const int N = 20;

int n;
bool st[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++ ) {
            // 建议使用printf, 快好多
            if (st[i]) printf("%d ", i + 1);
        }
        // 不建议使用cout<<endl;慢好多
        puts("");
        return;
    }
    
    //不选
    dfs(u + 1);
    //选
    st[u] = true;
    dfs(u + 1);
    st[u] = false;
    
}

int main() {
    cin >> n;
    
    dfs(0);
    
    return 0;
    
}
