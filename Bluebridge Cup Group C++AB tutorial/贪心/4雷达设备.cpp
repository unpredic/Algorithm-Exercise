// 思路：https://www.acwing.com/solution/content/1061/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1010;

struct Range {
    double l, r;
    bool operator< (const Range &w)const {
        return r < w.r;
    }
}range[N];

int n, d;

int main() {
    cin >> n >> d;
    bool success = true;
    for (int i = 0; i < n; i ++ ) {
        int x, y;
        cin >> x >> y;
        if (y > d) {
            success = false;
            break;
        }
        double len = sqrt(d * d - y * y);
        range[i].l = x - len, range[i].r = x + len;
    }
    
    if (!success) puts("-1");
    else {
        sort(range, range + n);
        int res = 0;
        double st = -1e18, ed = -1e18;
        for (int i = 0; i < n; i ++ ) {
            if (range[i].l > ed) {
                res ++ ;
                ed = range[i].r;
            }
        }
        cout << res << endl;
    }
    return 0;
}