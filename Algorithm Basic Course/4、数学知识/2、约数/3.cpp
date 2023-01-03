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
        LL a = p.first, b = p.second;
        LL t = 1;
        while (b -- ) {
            t = (t * a + 1) % mod; // mod不能少
        }
        res = res * t % mod;
    }
    
    cout << res << endl;
    
    return 0;
}