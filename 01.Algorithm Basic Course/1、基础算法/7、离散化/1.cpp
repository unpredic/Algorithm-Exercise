//https://blog.csdn.net/weixin_43061009/article/details/82083983?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.control
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    
    for (int i = 0; i < m; i ++ ) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }
    
    for (int i = 1; i <= alls.size(); i ++ ) s[i] = a[i] + s[i - 1];
    
    for (auto item : query) {
        int x = find(item.first);
        int y = find(item.second);
        cout << s[y] - s[x - 1] << endl;
    }
    
    return 0;
    
}
