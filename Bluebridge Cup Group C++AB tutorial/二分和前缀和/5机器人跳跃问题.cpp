// 该题具有单调性，可以使用二分来做
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N];

bool check(int x) {
    for (int i = 1; i <= n; i ++ ) {
        x = x * 2 - a[i];
        if (x >= 1e5) return true;
        if (x < 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    int l = 0, r = 1e5;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << r << endl;
    
    return 0;
    
}