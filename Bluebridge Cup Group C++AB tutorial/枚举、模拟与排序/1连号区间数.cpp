#include <iostream>

using namespace std;

const int N = 10010;

int n;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    int res = 0;
    for (int i = 0; i < n; i ++ ) { // 枚举区间左端点
        int maxv = -1e6, minv = 1e6;
        for (int j = i; j < n; j ++ ) {    // 枚举区间右端点
            maxv = max(maxv, a[j]);
            minv = min(minv, a[j]);
            if (maxv - minv == j - i) {
                res ++ ;
            }
        }
    }
    
    cout << res << endl;
    
    return 0;
    
}