#include<iostream>
#include<cstring>
using namespace std;

const int N = 25, M = 1e8 + 10;
int a[N];
bool st[N], sst[M];
int n, k, res;

bool is_primes(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++)
        if(x % i == 0) return false;
    return true;
}

void dfs(int u, int sum, int now){

    if(u > n){
                
        if(now == k && is_primes(sum)) res++;
        
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!st[i]) {
            st[i] = true;
            dfs(i + 1, sum + a[i], now + 1);
            st[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0, 0);
    
    cout << res << endl;
    
    return 0;
}