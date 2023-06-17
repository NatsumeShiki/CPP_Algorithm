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
int a[N], b[N];
int cnt1[M], cnt2[N];

void solve(){
  int T;
  cin >> T;
  while(T--){

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; ){
      int j = i + 1;
      while(j < n && a[j] == a[i]) j++;
      cnt1[a[i]] = max(cnt1[a[i]], j - i);
      i = j;
    }
    for(int i = 0; i < n; ){
      int j = i + 1;
      while(j < n && b[j] == b[i]) j++;
      cnt2[b[i]] = max(cnt2[b[i]], j - i);
      i = j;
    }

    int res = 0;
    for(int i = 0; i <= n * 2; i++) res = max(res, cnt1[i] + cnt2[i]);
    cout << res << endl;

    memset(cnt1, 0, n * 2 * 4 + 4);
    memset(cnt2, 0, n * 2 * 4 + 4);
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