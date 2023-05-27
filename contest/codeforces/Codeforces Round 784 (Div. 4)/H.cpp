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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N], cnt[35];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      for(int j = 30; j >= 0; j--)
        if(a[i] >> j & 1)
          cnt[j]++;
    }

    for(int i = 30; i >= 0; i--){
      // cout << cnt[i] << endl;
      if(cnt[i] + m >= n){
        // cout << cnt[i] + m << " " << i << endl;
        for(int j = 0; j < n; j++)
          a[j] |= 1 << i;
        m -= (n - cnt[i]);
        // cout << m << endl;
      }
    }
//     2
// 4
// 2147483646
// 1073741825


    for(int i = 1; i < n; i++) a[0] &= a[i];

    cout << a[0] << endl;



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