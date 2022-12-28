#include<iostream>
using namespace std;

const int N = 10;
bool st[N];
int num[N];
int n = 9, cnt;

int get(int l, int r){
    int res = 0;
    for(int i = l; i <= r; i++)
        res = res * 10 + num[i];
    return res;
}

void dfs(int u){
    
    if(u > n){
        for(int i = 1; i <= n - 2; i++){
            for(int j = i + 1; j <= n - 1; j++){
                int a = get(1, i);
                int b = get(i + 1, j);
                int c = get(j + 1, n);
                if(b * c == a && b < c){
                    printf("%d = %d x %d\n", a, b, c);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
        if(!st[i]){
            st[i] = true;
            num[u] = i;
            dfs(u + 1);
            st[i] = false;
        }
}

int main(){
    dfs(1);
    return 0;
}