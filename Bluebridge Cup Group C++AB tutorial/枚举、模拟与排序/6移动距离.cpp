#include <iostream>

using namespace std;

const int N = 10010;

int w, m, n;

int main() {
    cin >> w >> m >> n;
    m -- ; n -- ;
    
    int x1 = m / w, x2 = n / w;
    int y1 = m % w, y2 = n % w;
    // 为真 说明是奇数  (二进制最后一位是1该数为奇数)
    if (x1 & 1) y1 = w - 1 - y1;
    if (x2 & 1) y2 = w - 1 - y2;
    // 曼哈顿距离
    int res = abs(x1 - x2) + abs(y1 - y2); 
    
    cout << res << endl;
        
    return 0;
}