#include <iostream>

using namespace std;

const int N = 1000010;

int head,n[N],ne[N],idx;

void init(){
    head = -1;
    idx = 0;
}

void add_head(int x){
    n[idx]=x;
    ne[idx]=head;
    head=idx++;
}

void add(int k,int x){
    n[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++;
}

void remove(int k){
    ne[k] = ne[ne[k]];
}


int main(){
    
    int m;
    cin>>m;
    init();
    while(m --){
        char op;
        int x,k;
        cin>>op;
        if(op == 'H'){
            cin>>x;
            add_head(x);
        }else if(op == 'D'){
            cin>>k;
            if(!k)head=ne[head];
            else remove(k-1);
        }else{
            cin>>k>>x;
            add(k-1,x);
        }
    }
    for(int i = head; i != -1; i=ne[i]){
        cout<<n[i]<<' ';
    }
    cout<<endl;
    return 0;
}