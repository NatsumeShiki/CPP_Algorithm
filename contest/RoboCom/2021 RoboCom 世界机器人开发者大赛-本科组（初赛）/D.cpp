#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
vector<int> alls;
int h[N], e[M], ne[M], idx;
bool destory[N];
bool st[N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int cnt){

}

bool dfs(int u, int target){
  if(destory[u]) return false;
  if(u == target) return true;
  for(int i = h[u]; ~i; i = ne[i]){
    int j = e[i];
    if(!st[j]){
      st[j] = true;
      if(dfs(j, target)) return true;
      st[j] = false;
    }
  }
  return false;
}

void solve(){
  cin >> n >> m >> q;
  memset(h, -1, sizeof h);
  while(m--){
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }

  while(q--){
    int x, y;
    cin >> x >> y;
    destory[x] = true;
    int res = 0;
    while(y--){
      memset(st, 0, sizeof st);
      int a, b;
      cin >> a >> b;
      st[a] = true;
      if(!dfs(a, b)) res++;
    }
    cout << res << endl;
  }
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