#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        int x = i;
        while (x) {
            int r = x % 10;
            if (r == 2 || r == 0 || r == 1 || r == 9) {
                res += i;
                break;
            }
            x /= 10;
        }
    }
    
    cout << res << endl;
    
    return 0;
    
}