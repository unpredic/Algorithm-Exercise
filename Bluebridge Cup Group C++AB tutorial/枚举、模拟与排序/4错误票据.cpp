#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

const int N = 10010;

int n;
int a[N];

int main() {
    int cnt;
    cin >> cnt;
    string line;
    //C++ getline函数用法详解:http://c.biancheng.net/view/1345.html
    getline(cin, line); //把第一行的回车读入
    
    while (cnt -- ) {
        getline(cin, line);
        stringstream ssin(line);
        while (ssin >> a[n]) n ++ ;
    }
    
    sort(a, a + n);
    
    int res1, res2; // res1:断号    res2:重号
    for (int i = 1; i < n; i ++ ) {
        if (a[i] == a[i - 1]) {
            res2 = a[i];
        } else if (a[i] == a[i - 1] + 2) {
            res1 = a[i] - 1;
        } else {
            
        }
    }
    
    cout << res1 << " " << res2 << endl;
    
    return 0;
}