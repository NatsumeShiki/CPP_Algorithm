#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], b[N];

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a % b);
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    bool flag = true, flag1 = true;
    for(int i = 1; i < n; i++)
      if(a[i] != a[i - 1]){
        flag = false;
        break;
      }

    for(int i = 0; i <= n / 2; i++)
      if(a[i] != a[n - i - 1]){
        flag1 = false;
        break;
      }

    if(flag || flag1){
      puts("0");
      continue;
    }

    int cnt = 0;
    for(int i = 0; i <= n / 2; i++)
      b[cnt++] = abs(a[i] - a[n - i - 1]);
    int res = 0;
    for(int i = 0; i < cnt; i++) res = gcd(res, b[i]);
    cout << res << endl;

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