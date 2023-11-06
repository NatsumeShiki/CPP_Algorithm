#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
int g[N][N];
bool st[N];
int a, b, c;
int res = INF;
int h[M], e[M], w[M], ne[M], idx;

void add(int a, int b, int c){
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int bfs(){
  int res = INF;
  priority_queue<PIIII> heap;
  heap.push({{0, 1}, {-1, 1}});
  while(heap.size()){
    auto t = heap.top();
    heap.pop();

    int sum = t.x.x, u = t.x.y, la = t.y.x, flag = t.y.y;
    if(u == n){
      res = min(res, sum);
      continue;
    }
    if(sum >= res) continue;

    for(int i = h[u]; ~i; i = ne[i]){
      int j = e[i];
      if(j == la) continue;
      
    }
  }
}

void solve(){
  cin >> n >> a >> b >> c;
  memset(h, -1, sizeof h);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      add(i, j, x * a);
      add(j, i, x * a);
      add(i, j, x * b + c);
      add(j, i, x * b + c);
    }
  }

  bfs();
  
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}