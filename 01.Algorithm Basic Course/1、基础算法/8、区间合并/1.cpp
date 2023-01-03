//1、按区间左端点排序

































#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;

}

int main(){
    int n;
    scanf("%d", &n);

    vector<PII> segs;
    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Range {
    int l, r;
    bool operator< (const Range &w)const {
        return l < w.l;
    }
}range[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> range[i].l >> range[i].r;
    }
    
    sort(range, range + n);
    
    int res = 0;
    int st = -2e9, ed = -2e9;
    for (int i = 0; i < n; i ++ ) {
        if (ed < range[i].l) {
            if (st != -2e9) res ++ ;
            st = range[i].l, ed = range[i].r;
        } else {
            ed = max(ed, range[i].r);
        }
    }
    
    if (st != -2e9) res ++ ;
    
    cout << res << endl;
    
    return 0;
    
}