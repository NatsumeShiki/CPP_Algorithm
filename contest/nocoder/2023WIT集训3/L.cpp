#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
edge e[M];
int p[N];

int find(int x){
  if(x != p[x]) p[x] = find(p[x]);
  return p[x];
}


void solve(){
  cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      e[i] = {a, b, c};
    }

    sort(e, e + m);
    int res = 0;
    for(int i = 0; i < m; i++){
      int a = e[i].a, b = e[i].b, c = e[i].c;
      int pa = find(a), pb = find(b);
      if(pa == pb) continue;
      p[pa] = pb;
      res += c;
    }
    cout <<res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}