#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int n;

void solve()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n, k;
    cin >> n >> k;
    bool flag = false;
    for(int i = 1; i <= n; i++){
      int a = i * (i - 1) / 2;
      int b = (n - i) * (n - i - 1) / 2;
      if(a + b == k){
        flag = true;
        puts("YES");
        for(int j = 1; j <= i; j++) printf("1 ");
        for(int j = i + 1; j <= n; j++) printf("-1 ");
        puts("");
        break;
      }
    }
    if(!flag) puts("NO");
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
// ios::sync_with_stdio(false);
// cin.tie(0);
#endif

  solve();

  return 0;
}