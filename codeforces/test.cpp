#include<iostream>
using namespace std;

const int N = 2e5 + 10;
unsigned int  a[N];
unsigned int  n, q;

void solve(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      a[i] += a[i - 1];
    }

    while(q--){
      unsigned int  l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      unsigned int  sum = a[n] + k * (r - l + 1) - (a[r] - a[l - 1]);
      if(sum % 2 == 1) puts("YES");
      else puts("NO"); 
    }
  }
}

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}