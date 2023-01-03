//第一种解法
#include <iostream>

using namespace std;

const int N = 10;

int path[N];
bool st[N];
int n;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++ ) cout << path[i] << ' ';
        puts("");
        return;
    }
    
    for (int i = 1; i <= n; i ++ ) {
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
    
    dfs(0);
    
    return 0;
    
}
//第二种解法
#include <iostream>

using namespace std;

const int N = 10;

int path[N];
int n;

void dfs(int u, int state){
    if (u == n) {
        for (int i = 0; i < n; i ++ ) cout << path[i] << ' ';
        puts("");
        return ;
    }
    
    for (int i = 0; i < n; i ++ ){
        if (!(state >> i & 1)){
            path[u] = i + 1;
            dfs(u + 1, state + (1 << i));
        }
    }
}

int main(){
    cin >> n;
    dfs(0, 0);
    return 0;
}