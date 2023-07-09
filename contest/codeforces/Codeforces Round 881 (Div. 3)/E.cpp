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

const int N = 1e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t, q;
int tr[N];
int l[N], r[N];
int a[N];
int s[N];

bool check(int x){
  for(int i = 0; i <= n; i++) s[i] = 0;
  // memset(s, 0, sizeof s);
  for(int i = 1; i <= x; i++) s[a[i]] = 1;
  for(int i = 1; i <= n; i++) s[i] += s[i - 1];
  for(int i = 0; i < m; i++){
    int a = l[i], b = r[i];
    int sum = s[b] - s[a - 1];
    int cnt = b - a + 1;
    if(sum > (cnt - sum)) return true;
  }
  return false;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d%d", &l[i], &r[i]);
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) scanf("%d", &a[i]);

    int l = 1, r = q;
    while(l < r){
      int mid = l + r >> 1;
      if(check(mid)) r = mid ;
      else l = mid + 1;
    }
    if(check(l)) printf("%d\n", l);
    else puts("-1");
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