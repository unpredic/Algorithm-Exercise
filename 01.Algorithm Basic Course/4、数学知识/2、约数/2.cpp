#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 110, mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, int> primes;
    
    while (n -- ) {
        int a;
        cin >> a;
        // 质因数分解
        for (int i = 2; i <= a / i; i ++ ) {
            while (a % i == 0) {
                a /= i;
                primes[i] ++ ;
            }
        }
        if (a > 1) primes[a] ++ ;
    }
    
    LL res = 1;
    for (auto p : primes) {
        res = res * (p.second + 1) % mod;
    }
    
    cout << res << endl;
}