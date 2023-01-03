#include <iostream>

using namespace std;

int lowbit(int x){
    return x&(-x);
}

int main(){
    int n;
    cin>>n;
    
    while(n--){
        int x;
        cin>>x;
        int res = 0;
        while(x){
            x -= lowbit(x);
            res ++;
        }
        cout<<res<<' ';
    }
    
    return 0;
}


#include <iostream>

using namespace std;

const int N = 100010;

int a[N];

int lowbit(int x){
    return x&(-x);
}

int main(){
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        int res = 0;
        while (a[i]){
            a[i] -= lowbit(a[i]);
            res ++ ;
        }
        cout << res << ' ';
    }
    
    return 0;
}