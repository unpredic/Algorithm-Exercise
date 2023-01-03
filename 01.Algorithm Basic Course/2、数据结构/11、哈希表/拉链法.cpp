#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;

int h[N],e[N],ne[N],idx;

void insert(int x){
    // c++中如果是负数 那他取模也是负的 所以 加N 再 %N 就一定是一个正数
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}

bool find(int x){
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    
    memset(h, -1, sizeof(h));
    
    while (n -- ){
        char op[2];
        int x;
        cin >> op >> x;
        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}