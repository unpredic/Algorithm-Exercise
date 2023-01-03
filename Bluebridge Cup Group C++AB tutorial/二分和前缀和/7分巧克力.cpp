#include <iostream>

using namespace std;

const int N = 100010;

int n, k;
int h[N], w[N];

bool check(int mid) {
    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        res += (h[i] / mid) * (w[i] / mid); 
    }
    if (res >= k) return true;
    else return false;
}

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i ++ ) {
        cin >> h[i] >> w[i];
    }
    
    int res = 0;
    for (int i = 0; i < n; i ++ ) res = max(res, h[i]);
    for (int i = 0; i < n; i ++ ) res = max(res, w[i]);
    
    int l = 1, r = res;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << l << endl;
    
    return 0;
    
}