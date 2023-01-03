#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;

int n;
PII a[N];
int f[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    
    sort(a + 1, a + n + 1);
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        f[i] = 1;
        for (int j = 1; j < i; j ++ ) {
            if (a[i].second > a[j].second) f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
    }
    
    printf("%d\n", res);
    
    return 0;
}