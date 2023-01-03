#include <iostream>
#include <cstring>

using namespace std;

string a, b;

void turn(int i) {
    if (a[i] == '*') a[i] = 'o';
    else a[i] = '*';
}

int main() {
    
    cin >> a >> b;
    
    int res = 0;
    for (int i = 0; i < a.size() - 1; i ++ ) {
        if (a[i] != b[i]) {
            turn(i);
            turn(i + 1);
            res ++ ;
        }
    }
    
    cout << res << endl;
    
    return 0;
    
}