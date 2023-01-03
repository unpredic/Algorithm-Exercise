#include <iostream>

using namespace std;

int p, q;

bool dfs(int m, int p, int q) {
    if (!m) return true;
    if (m >= p && dfs(m - p, p, q)) return true;
    if (m >= q && dfs(m - q, p, q)) return true;
    return false;
}

int main() {
    cin >> p >> q;
    
    int res = 0;
    for (int i = 1; i <= 1000; i ++ ) {
        if (!dfs(i, p, q)) res = i;
    }
    cout << res << endl;
    return 0;
}


#include <iostream>

using namespace std;

int p, q;


int main() {
    scanf("%d%d", &p, &q);
    
    printf("%d\n", (p - 1) * (q - 1) - 1);
    
    return 0;
}