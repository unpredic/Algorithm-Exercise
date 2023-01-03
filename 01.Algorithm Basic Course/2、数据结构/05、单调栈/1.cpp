#include <iostream>

using namespace std;

const int N = 100010;

int stk[N],tt;

int main(){
    int n;
    cin >> n;
    while (n -- ){
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt -- ;
        if (!tt) cout<<"-1 ";
        else cout<<stk[tt]<<" ";
        stk[ ++ tt] = x;
    }
    return 0;
}