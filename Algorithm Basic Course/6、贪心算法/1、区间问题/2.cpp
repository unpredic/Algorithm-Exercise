#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;
    bool operator< (const Range &w)const {
        return r < w.r;
    }
}range[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> range[i].l >> range[i].r;
    }
    
    sort(range, range + n);
    
    int res = 0, ed = -1e9;
    for (int i = 0; i < n; i ++ ) {
        if (range[i].l > ed) {
            res ++ ;
            ed = range[i].r;
        }
    }
    
    cout << res << endl;
    
    return 0;
    
}