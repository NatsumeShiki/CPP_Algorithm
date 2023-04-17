#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
 set<int> s;
typedef long long LL;
const int N = 2e6 + 10;
LL mod = 998244353;
int n, q;
int a[N];

void solve(){
  scanf("%d", &q);
  int first = 0, last = 0;
  a[0] = 1;
  while(q--){
    int op, x;
    scanf("%d", &op);
    if(op == 1){
      scanf("%d", &x);
      a[++last] = x;
    }else if(op == 2){
      first++;
    }else{
      LL res = 0;
      for(int i = first; i <= last; i++){
        res = res * 10 + a[i];
        if(res >= mod) res %= mod;
      }
      printf("%lld\n", res % mod);
      if(res >= mod){
        res = res % mod;
        first = last + 1;
        while(res){
          a[--first] = res % 10;
          res /= 10; 
        }
      }
    }
  }
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}


 