#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 5010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N], backup[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    LL res = 0;
    for(int len = 1; len <= n; len++)
      for(int l = 1; l + len - 1 <= n; l++){
        int x = l, y = l + len - 1;
        int st = 0, ed = 0;
        for(int i = x; i <= y; i++, ed++)
          backup[ed] = a[i];
        
        sort(backup, backup + ed);
        // for(int i = 0; i < ed; i++) cout << backup[i] << " ";
        // cout << endl;
        ed--;
        while(x < y && a[x] == backup[st]) {
          // cout << a[x] << " " << backup[st] << endl;
          x++, st++;
        }
        while(y > x && a[y] == backup[ed]) y--, ed--;
        // printf("%d %d\n", x, y);
        res += y - x;
        // printf("%d %d %d %d\n",l, l + len - 1, x, y);
      }
    
    cout << res << endl;
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}