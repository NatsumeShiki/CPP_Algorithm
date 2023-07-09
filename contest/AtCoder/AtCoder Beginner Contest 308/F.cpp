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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N];
PII dis[N];

void solve(){
  scanf("%d%d", &n, &m);
  LL res = 0;
  for(int i = 0; i < n; i++) scanf("%d", &a[i]), res += a[i];
  for(int i = 0; i < m; i++) scanf("%d", &dis[i].x);
  for(int i = 0; i < m; i++) scanf("%d", &dis[i].y);

  sort(a, a + n);
  sort(dis, dis + m);

  // for(int i = 0; i < n; i++) printf("%d ", a[i]);
  // puts("");
  // for(int i = 0; i < m; i++) printf("%d %d\n", dis[i].x, dis[i].y);
  
  priority_queue<int, vector<int>, less<int>> heap;
  for(int i = 0, j = 0; i < n; i++){
    while(j < m && dis[j].x <= a[i]){
      heap.push(dis[j++].y);
    }
    if(heap.size()) {
      // cout << heap.top() << endl;
      res -= heap.top();
      heap.pop();
    }
  }

  printf("%lld\n", res);
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  #endif

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}