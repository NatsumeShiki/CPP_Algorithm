#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 55, M = 5010, INF = 0x3f3f3f3f;
int n, m, k, t, cnt;
int tree[N][M];
int sz[N];
PII apple[M];
int len[N];
int x[M], y[M];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x, k, y;
        cin >> x >> k;
        while(k--){
            cin >> y;
            apple[cnt++] = {x, y};
        }
    }

    sort(apple, apple + cnt);

    for(int i = 0; i < cnt; i++) x[i] = apple[i].x, y[i] = apple[i].y;

    // for(int i = 0; i < cnt; i++) printf("%d %d\n", x[i], y[i]);

    int res = 0;
    for(int i = 0; i < cnt; ){
      int j = i;
      while(j + 1 < cnt && x[j] == x[j + 1]) j++;

      sort(y, y + j);
      int ans = 0;
      int k = m - x[i];
      for(int u = 0; u <= j; u++) 
        if(k - y[u] >= 0){
          ans++;
          k -= y[u];
        }

      res = max(res, ans);

      i = j + 1;
    }
    printf("%d\n", res);
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}