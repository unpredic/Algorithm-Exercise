#include <iostream>

using namespace std;

const int N = 100010;
//从1开始存
int stk[N],tt;

void init(){
    tt = 0;
}

void push(int x){
    stk[++tt] = x;
}

void pop(){
    tt --;
}

bool isEmpty(){
    if(!tt)return true;
    else return false;
}

int query(){
    return stk[tt];
}

int main(){
    int m;
    cin>>m;
    init();
    
    while(m -- ){
        string op;
        cin>>op;
        
        int x;
        if(op == "push"){
            cin>>x;
            push(x);
        }else if(op == "pop"){
            pop();
        }else if(op == "empty"){
            if(isEmpty()){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<query()<<endl;
        }
    }
    
    return 0;
}