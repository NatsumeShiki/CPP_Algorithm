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

const int N = 3e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
string s, l, r;
int ne[N][10] = {N};

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> s >> m >> l >> r;
    n = s.size();

    // vector<vector<int>> next(n + 10, vector<int>(10, n + 1));
    for(int i = 0; i < 10; i++) ne[n][i] = N;
    for(int i = n - 1; i >= 0; i--){
      // ne[i] = ne[i + 1];
      for(int j = 0; j < 10; j++) ne[i][j] = ne[i + 1][j];
      ne[i][s[i] - '0'] = i + 1;
    }

    int now = 0;
    for(int i = 0; i < m; i++){
      int best = now;
      for(char c = l[i]; c <= r[i]; c++){
        best = max(best, ne[now][c - '0']);
      }
      now = best;
    }

    if(now >= n + 1) puts("YES");
    else puts("NO");

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