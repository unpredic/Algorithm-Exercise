#include <iostream>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N], f2[N];

int main() {
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &a[i]);
    }
        
    // 正向LIS
    for (int i = 1; i <= n; i ++ ) {
        f[i] = 1;
        for (int j = 1; j < i; j ++ ) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
    }
        
    // 反向LIS
    for (int i = n; i; i -- ) {
        f2[i] = 1;
        for (int j = n; j > i; j -- ) {
            if (a[i] > a[j]) f2[i] = max(f2[i], f2[j] + 1);
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        res = max(res, f[i] + f2[i]);
    }
    
    printf("%d\n", res - 1);
    
    return 0;
}