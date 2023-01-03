#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
struct Range {
    int l, r;
    bool operator< (const Range &w)const {
        return l < w.l;
    }
}range[N];

int main() {
    
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> range[i].l >> range[i].r;
    }
    
    sort(range, range + n);
    
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for (int i = 0; i < n; i ++ ) {
        if (heap.empty() || heap.top() >= range[i].l) {
            heap.push(range[i].r);
        } else {
            heap.pop();
            heap.push(range[i].r);
        }
    }
    
    cout << heap.size() << endl;
    
    return 0;
    
}