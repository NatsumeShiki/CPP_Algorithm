#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

typedef long long LL;
LL mod = 998244353, res = 1;
int q;
LL pw[15];

void solve(){
  
  scanf("%d", &q);
  while(q--){
    int op, x;
    scanf("%d", &op);
    if(op == 1){
      scanf("%d", &x);
      res = (res * 10 % mod + x) % mod; 
    }
  }
}

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  solve();

  return 0;
}